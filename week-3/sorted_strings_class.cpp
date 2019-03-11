#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
 public:
  void AddString(const string &s) {
    sorted_strings.push_back(s);
  }

  vector<string> GetSortedStrings() {
    sort(sorted_strings.begin(), sorted_strings.end());
    return sorted_strings;
  }
 private:
  vector<string> sorted_strings;
};