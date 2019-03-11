#include <iostream>
#include <vector>

using namespace std;

struct Student {
  string name;
  string birthday;
};

void StudentsList() {
  int n, m;
  cin >> n;

  string first_name, last_name, day, month, year;
  vector<Student> students;
  for (int i = 0; i < n; ++i) {
    cin >> first_name >> last_name >> day >> month >> year;
    students.push_back({
                           first_name.append(" ").append(last_name),
                           day.append(".").append(month).append(".").append(year)
                       });
  }

  string query;
  int student_number;
  cin >> m;
  for (int j = 0; j < m; ++j) {
    cin >> query >> student_number;
    --student_number;
    if (query == "name" && student_number >= 0 && student_number < n) {
      cout << students[student_number].name << endl;
    } else if (query == "date" && student_number >= 0 && student_number < n) {
      cout << students[student_number].birthday << endl;
    } else {
      cout << "bad request" << endl;
    }
  }
}