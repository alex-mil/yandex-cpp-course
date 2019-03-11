#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

void SortByCaseInsensitive() {
  int n;
  cin >> n;

  vector<string> s(static_cast<unsigned long>(n));
  for (auto &str : s) {
    cin >> str;
  }

  sort(s.begin(), s.end(),
      // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
      [](const auto &l, const auto &r) {
        // сравниваем лексикографически
        return lexicographical_compare(
            // все символы строки l
            l.begin(), l.end(),
            // со всеми символами строки r
            r.begin(), r.end(),
            // используя в качестве компаратора сравнение отдельных символов без учёта регистра
            [](const char &a, const char &b) { return tolower(a) < tolower(b); });
  });

  for (const auto &str : s) {
    std::cout << str << " ";
  }
  std::cout << std::endl;
}