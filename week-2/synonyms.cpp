#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void Synonyms1() {
  int commands_number;
  string command, w1, w2;
  map<set<string>, int> synonyms;
  map<string, int> words_counter;

  cin >> commands_number;
  for (int i = 0; i < commands_number; ++i) {
    cin >> command;

    if (command == "ADD") {
      cin >> w1 >> w2;
      set<string> new_pair = {w1, w2};
      synonyms[new_pair]++;
      if (synonyms[new_pair] == 1) {
        words_counter[w1]++;
        words_counter[w2]++;
      }
    } else if (command == "COUNT") {
      cin >> w1;
      cout << words_counter[w1] << endl;
    } else if (command == "CHECK") {
      cin >> w1 >> w2;
      string answer{"NO"};
      set<string> test_pair = {w1, w2};
      if (synonyms.count(test_pair)) {
        answer = "YES";
      }

      std::cout << answer << std::endl;
    }
  }
}

void Synonyms2() {
  int commands_number;
  string command, w1, w2;
  cin >> commands_number;

  map<string, set<string>> synonyms;
  for (int i = 0; i < commands_number; ++i) {
    cin >> command;

    if (command == "ADD") {
      string first_word, second_word;
      cin >> first_word >> second_word;
      // второе слово добавляем в список синонимов первого...
      synonyms[first_word].insert(second_word);
      // и наоборот
      synonyms[second_word].insert(first_word);
    } else if (command == "COUNT") {
      string word;
      cin >> word;
      cout << synonyms[word].size() << endl;
    } else if (command == "CHECK") {
      string first_word, second_word;
      cin >> first_word >> second_word;
      // ищём второе слово во множестве синонимов первого
      // (можно было сделать и наоборот)
      if (synonyms[first_word].count(second_word) == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}