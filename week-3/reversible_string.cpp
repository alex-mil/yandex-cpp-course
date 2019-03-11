#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
 public:
  ReversibleString() = default;;

  explicit ReversibleString(const string &str) {
    data = str;
  }

  void Reverse() {
    reverse(data.begin(), data.end());
  }

  string ToString() const {
    return data;
  }

 private:
  string data;
};