#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void PrintFromFile(const string &path) {
  ifstream input("input.txt");
  if (input) {
    int rows, columns;
    input >> rows;
    input.ignore(1);
    input >> columns;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        int number;
        input >> number;
        cout << setw(10) << number;
        input.ignore(1);
        if (j != columns - 1) {
          cout << " ";
        }
      }
      if (i != rows - 1) {
        cout << endl;
      }
    }
  }
}