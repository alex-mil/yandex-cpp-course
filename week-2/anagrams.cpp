#include <iostream>
#include <map>
using namespace std;

map<char, int> BuildCharCounters(const string &word) {
  map<char, int> counters;
  for (const auto &chr : word) {
    ++counters[chr];
  }
  return counters;
}

void Anagrams() {
  int q;
  cin >> q;

  string w1, w2;
  for (int i = 0; i < q; ++i) {
    cin >> w1 >> w2;

    if (BuildCharCounters(w1) == BuildCharCounters(w2)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}