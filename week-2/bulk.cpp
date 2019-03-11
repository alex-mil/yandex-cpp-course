#include "include/week_two.h"

using namespace std;

int factorial(int num) {
  int result = 1;

  if (num < 0) {
    return 1;
  }

  for (int i = 2; i <= num; ++i) {
    result *= i;
  }

  return result;
}

bool isPalindrome(string str) {
  for (size_t i = 0; i < str.size() / 2; ++i) {
    if (str[i] != str[str.size() - i - 1]) {
      return false;
    }
  }
  return true;
}

vector<string> palindromeFilter(vector<string> words, int minLength) {
  vector<string> filteredWords;

  for (const auto &word:words) {
    if (word.size() >= minLength && isPalindrome(word)) {
      filteredWords.push_back(word);
    }
  }

  return filteredWords;
}

void UpdateIfGreater(int first, int &second) {
  if (first > second) {
    second = first;
  }
}

void MoveStrings(vector<string> &source, vector<string> &destination) {
  for (const auto &str:source) {
    destination.push_back(str);
  }
  source.clear();
}

void Reverse(vector<int> &v) {
  long limit = v.size() / 2;
  for (int index = 0; index < limit; ++index) {
    int temp = v[index];
    long backwardIndex = v.size() - 1 - index;
    v[index] = v[backwardIndex];
    v[backwardIndex] = temp;
  }
}

vector<int> Reversed(const vector<int> &v) {
  vector<int> reversed;
  auto lastIndex = static_cast<int>(v.size() - 1);

  for (int i = lastIndex; i > -1; --i) {
    reversed.push_back(v[i]);
  }
  return reversed;
}

vector<int> AverageTemperature(const vector<int> &measures) {
  int sum = 0;
  vector<int> aboveAverage;

  for (auto t : measures) {
    sum += t;
  }
  auto average = static_cast<int>(sum / measures.size());

  for (int i = 0; i < measures.size(); ++i) {
    if (measures[i] > average) {
      aboveAverage.push_back(i);
    }
  }

  return aboveAverage;
}

/* BLOCK START */
void Add(int month_length, int day_in_month, const string &task, vector<vector<string>> &vec) {
  if (day_in_month <= month_length) {
    vec[day_in_month - 1].push_back(task);
  }
}

void Next(int month_length, int next_month_length, vector<vector<string>> &vec) {
  int days_diff = next_month_length - month_length;

  if (days_diff > 0) {
    vec.resize(static_cast<unsigned long>(next_month_length));
  } else if (days_diff < 0) {
    vector<string> tmp_vec;
    int start_index = month_length - abs(days_diff);

    for (int i = start_index; i < month_length; ++i) {
      for (const auto &task : vec[i]) {
        tmp_vec.push_back(task);
      }
    }
    vec.resize(static_cast<unsigned long>(next_month_length));
    for (const auto &s : tmp_vec) {
      vec[next_month_length - 1].push_back(s);
    }
  }
}

string Dump(int day_in_month, vector<vector<string>> &vec) {
  if (day_in_month <= vec.size()) {
    string result;
    ulong tasks_number = vec[day_in_month - 1].size();

    for (int i = 0; i < tasks_number; ++i) {
      int last_task = static_cast<int>(tasks_number - 1);

      if (i != last_task) {
        result += vec[day_in_month - 1][i] + " ";
      } else {
        result += vec[day_in_month - 1][i];
      }
    }
    if (result.empty()) { return to_string(tasks_number); }
    else { return to_string(tasks_number) + " " + result; }
  }
  return "";
}
/* BLOCK END */

/* BLOCK START */
map<char, int> BuildCharMap(const string &word){
  map<char, int> counters;
  for (const auto &chr : word) {
    ++counters[chr];
  }
  return counters;
}

string IsAnagram(const string &first_word, const string &second_word) {
  if (BuildCharMap(first_word) == BuildCharMap(second_word)) {
    return "YES";
  } else {
    return "NO";
  }
}
/* BLOCK END */

/* BLOCK START */
string ChangeCapital(const string &country_name, const string &capital_name, map<string, string> &m) {
  if (m.count(country_name) == 0) {
    m[country_name] = capital_name;
    return "Introduce new country " + country_name + " with capital " + capital_name;
  }

  if (m[country_name] != capital_name) {
    string old_capital = m[country_name];
    m[country_name] = capital_name;
    return "Country " + country_name + " has changed its capital from " + old_capital + " to " + capital_name;
  }

  return "Country " + country_name + " hasn't changed its capital";
}

string Rename(const string &old_country, const string &new_country, map<string, string> &m) {
  if (m.count(old_country) != 0 && old_country != new_country) {
    m[new_country] = m[old_country];
    m.erase(old_country);
    return "Country " + old_country + " with capital " + m[new_country] + " has been renamed to " + new_country;
  }
  return "Incorrect rename, skip";
}

string About(const string &country, map<string, string> &m) {
  if (m.count(country) != 0) {
    return "Country " + country + " has capital " + m[country];
  }
  return "Country " + country + " doesn't exist";
}

string Dump(map<string, string> &m) {
  string response;

  ulong backward_index = m.size();
  for (const auto &pair : m) {
    --backward_index;
    response += pair.first + "/" + pair.second;
    if (backward_index != 0) response += " ";
  }

  if (response.empty()) {
    return "There are no countries in the world";
  }
  return response;
}
/* BLOCK END */
