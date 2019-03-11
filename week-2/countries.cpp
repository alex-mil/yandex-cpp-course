#include <iostream>
#include <map>
using namespace std;

void CountriesCatalog1() {
  int q;
  cin >> q;

  map<string, string> countries;
  for (int i = 0; i < q; ++i) {
    string command;
    cin >> command;

    if (command == "CHANGE_CAPITAL") {
      string country, new_capital, output;
      cin >> country >> new_capital;

      if (countries.count(country) == 0) {
        output = "Introduce new country ";
        output += country;
        output += " with capital ";
        output += new_capital;
        std::cout << output << std::endl;
      } else if (countries[country] == new_capital) {
        output = "Country ";
        output += country;
        output += " hasn't changed its capital";
        std::cout << output << std::endl;
      } else {
        output = "Country ";
        output += country;
        output += " has changed its capital from ";
        output += countries[country];
        output += " to ";
        output += new_capital;
        std::cout << output << std::endl;
      }
      countries[country] = new_capital;
    } else if (command == "RENAME") {
      string old_country_name, new_country_name, output;
      cin >> old_country_name >> new_country_name;

      if (old_country_name == new_country_name ||
          countries.count(old_country_name) == 0 ||
          countries.count(new_country_name) > 0) {
        std::cout << "Incorrect rename, skip" << std::endl;
        continue;
      }
      output = "Country ";
      output += old_country_name;
      output += " with capital ";
      output += countries[old_country_name];
      output += " has been renamed to ";
      output += new_country_name;
      std::cout << output << std::endl;

      countries[new_country_name] = countries[old_country_name];
      countries.erase(old_country_name);
    } else if (command == "ABOUT") {
      string country, output;
      cin >> country;

      if (countries.count(country)) {
        output = "Country ";
        output += country;
        output += " has capital ";
        output += countries[country];
        std::cout << output << std::endl;
      } else {
        output = "Country ";
        output += country;
        output += " doesn't exist";
        std::cout << output << std::endl;
      }
    } else if (command == "DUMP") {
      string output;

      if (countries.empty()) {
        std::cout << "There are no countries in the world" << std::endl;
      } else {
        for (const auto &pair : countries) {
          output += pair.first;
          output += "/";
          output += pair.second;
          output += " ";
        }
        std::cout << output << std::endl;
      }
    }
  }
}

void CountriesCatalog2() {
  int q;
  cin >> q;

  map<string, string> country_to_capital;

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "CHANGE_CAPITAL") {
      string country, new_capital;
      cin >> country >> new_capital;
      if (country_to_capital.count(country) == 0) {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
      } else {
        const string &old_capital = country_to_capital[country];
        if (old_capital == new_capital) {
          cout << "Country " << country << " hasn't changed its capital" << endl;
        } else {
          cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital
               << endl;
        }
      }
      country_to_capital[country] = new_capital;
    } else if (operation_code == "RENAME") {
      string old_country_name, new_country_name;
      cin >> old_country_name >> new_country_name;
      if (old_country_name == new_country_name || country_to_capital.count(old_country_name) == 0
          || country_to_capital.count(new_country_name) == 1) {
        cout << "Incorrect rename, skip" << endl;
      } else {
        cout << "Country " << old_country_name << " with capital " << country_to_capital[old_country_name] <<
             " has been renamed to " << new_country_name << endl;
        country_to_capital[new_country_name] = country_to_capital[old_country_name];
        country_to_capital.erase(old_country_name);
      }
    } else if (operation_code == "ABOUT") {
      string country;
      cin >> country;
      if (country_to_capital.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
      } else {
        cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
      }
    } else if (operation_code == "DUMP") {

      if (country_to_capital.empty()) {
        cout << "There are no countries in the world" << endl;
      } else {
        for (const auto &country_item : country_to_capital) {
          cout << country_item.first << "/" << country_item.second << " ";
        }
        cout << endl;
      }
    }
  }
}