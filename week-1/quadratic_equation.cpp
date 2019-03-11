#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// A*x^2 + B*x + C = 0
void Equation() {
  double a, b, c, discriminant, x1, x2;
  cin >> a >> b >> c;

  discriminant = pow(b, 2) - 4 * a * c;
  if (a != 0 && b != 0 && c != 0) {
    if (discriminant > 0) {
      x1 = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
      x2 = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
      cout << x1 << " " << x2 << endl;
    } else if (discriminant == 0) {
      x1 = x2 = (-1 * b) / (2 * a);
      cout << x1 << endl;
    } else {
      cout << "" << endl;
    }
  } else if (a != 0 && b == 0 && c == 0) {
    cout << 0 << endl;
  } else if (a != 0 && b != 0 && c == 0) {
    cout << 0 << " " << -1 * (b / a) << endl;
  } else if (a != 0 && b == 0 && c != 0) {
    double temp = -1 * (c / a);
    if (temp > 0) {
      cout << sqrt(temp) << " " << -sqrt(temp) << endl;
    } else {
      cout << "" << endl;
    }
  } else if (a == 0 && b != 0 && c != 0) {
    cout << -1 * (c / b) << endl;
  } else if (a == 0 && b == 0 && c != 0) {
    cout << "" << endl;
  } else if (a == 0 && b != 0 && c == 0) {
    cout << 0 << endl;
  }
}
