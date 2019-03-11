#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SortByAbsoluteValues() {
  unsigned long n;
  cin >> n;

  vector<int> vec(n);
  for (auto &num : vec) {
    cin >> num;
  }
  sort(vec.begin(), vec.end(), [](int a, int b) { return abs(b) > abs(a); });
  for (const auto &num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}