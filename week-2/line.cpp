#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* C stands for calm and W for worried */
void PeopleLine1() {
  int operations_number;
  cin >> operations_number;

  string operation;
  vector<char> line;
  for (int i = 0; i < operations_number; ++i) {
    cin >> operation;

    if (operation == "COME") {
      int value;
      cin >> value;

      long currentSize = line.size();
      auto new_size = static_cast<ulong>(currentSize + value);
      if (line.empty() && new_size != currentSize) {
        line.assign(new_size, 'C');
      } else if (!line.empty() && new_size != currentSize) {
        line.resize(new_size);
      }
    } else if (operation == "WORRY") {
      int value;
      cin >> value;

      line[value] = 'W';
    } else if (operation == "QUIET") {
      int value;
      cin >> value;

      line[value] = 'C';
    } else if (operation == "WORRY_COUNT") {
      int worriedCount = 0;

      for (auto &chr : line) {
        if (chr == 'W') {
          worriedCount += 1;
        }
      }
      cout << worriedCount << endl;
    }
  }
}

void PeopleLine2() {
  int q;
  cin >> q;
  vector<bool> is_nervous;

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "WORRY_COUNT") {
      // подсчитываем количество элементов в векторе is_nervous, равных true
      cout << count(begin(is_nervous), end(is_nervous), true) << endl;
    } else {
      if (operation_code == "WORRY" || operation_code == "QUIET") {
        int person_index;
        cin >> person_index;

        // выражение в скобках имеет тип bool и равно true для запроса WORRY,
        // поэтому is_nervous[person_index] станет равным false или true
        // в зависимости от operation_code
        is_nervous[person_index] = (operation_code == "WORRY");
      } else if (operation_code == "COME") {
        int person_count;
        cin >> person_count;

        // метод resize может как уменьшать размер вектора, так и увеличивать,
        // поэтому специально рассматривать случаи с положительным
        // и отрицательным person_count не нужно
        is_nervous.resize(is_nervous.size() + person_count, false);
      }
    }
  }
}