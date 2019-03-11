#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DailyPlanner1() {
  int operations_number;
  cin >> operations_number;

  vector<vector<string>> todo_list(31);
  vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int month_now = 0;
  for (int i = 0; i < operations_number; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "ADD") {
      int day;
      string todo;
      cin >> day >> todo;

      todo_list[day - 1].push_back(todo);
    } else if (operation_code == "DUMP") {
      int day;
      cin >> day;
      --day;

      string tasks;
      for (const auto &str : todo_list[day]) {
        tasks += str;
        tasks += " ";
      }
      cout << todo_list[day].size() << " " << tasks << endl;
    } else {
      int next_month_index = (month_now + 1) % 12;
      int days_diff = months[next_month_index] - months[month_now];

      if (days_diff > 0) {
        todo_list.resize(todo_list.size() + days_diff);
      } else if (days_diff < 0) {
        int next_month_end = months[next_month_index] - 1;

        for (int j = next_month_end + 1; j < todo_list.size(); ++j) {
          if (todo_list[j].empty()) continue;
          todo_list[next_month_end].insert(todo_list[next_month_end].end(),
                                           todo_list[j].begin(),
                                           todo_list[j].end());
        }
        todo_list.resize(todo_list.size() + days_diff);
      }
      month_now = next_month_index;
    }
  }
}

const vector<int> MONTH_LENGTHS =
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MONTH_COUNT = MONTH_LENGTHS.size();

void DailyPlanner2() {
  int q;
  cin >> q;

  // номер текущего месяца (от 0 до 11)
  int month = 0;

  // внешний вектор должен иметь длину, равную количеству дней в первом месяце;
  // все внутренние векторы по умолчанию пусты, потому что дел изначально нет
  vector<vector<string>> days_concerns(MONTH_LENGTHS[month]);

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "ADD") {
      int day;
      string concern;
      cin >> day >> concern;
      --day;  // элементы вектора нумеруются с нуля
      days_concerns[day].push_back(concern);

    } else if (operation_code == "NEXT") {
      // перед переходом к следующему месяцу запомним длину предыдущего
      // обьявляем эту переменную константной, потому что менять её не планируем
      const int old_month_length = MONTH_LENGTHS[month];

      // номер месяца должен увеличиться на 1, но после декабря идёт январь:
      // например, (5 + 1) % 12 = 6, но (11 + 1) % 12 = 0
      month = (month + 1) % MONTH_COUNT;

      const int new_month_length = MONTH_LENGTHS[month];

      // если новый месяц больше предыдущего, достаточно сделать resize;
      // иначе перед resize надо переместить дела с «лишних» последних дней
      if (new_month_length < old_month_length) {

        // далее понадобится добавлять новые дела в последний день нового месяца
        // чтобы не писать несколько раз days_concerns[new_month_length - 1],
        // создадим ссылку с более коротким названием для этого вектора
        vector<string>& last_day_concerns = days_concerns[new_month_length - 1];

        // перебираем все «лишние» дни в конце месяца
        for (int day = new_month_length; day < old_month_length; ++day) {
          // копируем вектор days_concerns[day]
          // в конец вектора last_day_concerns
          last_day_concerns.insert(
              end(last_day_concerns),
              begin(days_concerns[day]), end(days_concerns[day]));
        }
      }
      days_concerns.resize(new_month_length);

    } else if (operation_code == "DUMP") {

      int day;
      cin >> day;
      --day;

      // выводим список дел в конкретный день в нужном формате
      cout << days_concerns[day].size() << " ";
      for (const string& concern : days_concerns[day]) {
        cout << concern << " ";
      }
      cout << endl;
    }
  }
}