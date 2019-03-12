#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>
using namespace std;

class Rational
{
public:
  Rational()
  {
    p_numerator = 0;
    p_denominator = 1;
  }

  Rational(int numerator, int denominator)
  {
    if (denominator == 0)
    {
      throw invalid_argument("denominator value cannot be zero");
    }

    if (denominator < 0)
    {
      numerator = -numerator;
      denominator = -denominator;
    }

    if (numerator == 0)
    {
      p_numerator = 0;
      p_denominator = 1;
    }
    else
    {
      const int divisor = GreatestCommonDivisor(abs(numerator),
                                                abs(denominator));
      p_numerator = numerator / divisor;
      p_denominator = denominator / divisor;
    }
  }

  int Numerator() const
  {
    return p_numerator;
  }

  int Denominator() const
  {
    return p_denominator;
  }

private:
  int p_numerator, p_denominator;

  // implementation for negative and positive numbers
  int GreatestCommonDivisor(int n1, int n2)
  {
    if (n2 == 0)
    {
      return n1;
    }
    else
    {
      return GreatestCommonDivisor(n2, n1 % n2);
    }
  }
};

Rational operator+(const Rational &r1, const Rational &r2)
{
  if (r1.Denominator() == r2.Denominator())
  {
    int newNumerator = r1.Numerator() + r2.Numerator();
    int newDenominator = r1.Denominator();
    return Rational(newNumerator, newDenominator);
  }

  int newDenominator = r1.Denominator() * r2.Denominator();
  int newNumerator = r2.Denominator() * r1.Numerator() +
                     r1.Denominator() * r2.Numerator();
  return Rational(newNumerator, newDenominator);
}

Rational operator-(const Rational &r1, const Rational &r2)
{
  if (r1.Denominator() == r2.Denominator())
  {
    int newNumerator = r1.Numerator() - r2.Numerator();
    int newDenominator = r1.Denominator();
    return Rational(newNumerator, newDenominator);
  }
  int newDenominator = r1.Denominator() * r2.Denominator();
  int newNumerator = r2.Denominator() * r1.Numerator() -
                     r1.Denominator() * r2.Numerator();
  return Rational(newNumerator, newDenominator);
}

bool operator==(const Rational &r1, const Rational &r2)
{
  return r1.Numerator() == r2.Numerator() &&
         r1.Denominator() == r2.Denominator();
}

Rational operator*(const Rational &r1, const Rational &r2)
{
  return {r1.Numerator() * r2.Numerator(),
          r1.Denominator() * r2.Denominator()};
}

Rational operator/(const Rational &r1, const Rational &r2)
{
  if (r2.Numerator() == 0)
  {
    throw domain_error("division by zero");
  }

  return r1 * Rational(r2.Denominator(), r2.Numerator());
}

bool operator<(const Rational &r1, const Rational &r2)
{
  return (r1 - r2).Numerator() < 0;
}

ostream &operator<<(ostream &stream, const Rational &r)
{
  stream << r.Numerator() << '/' << r.Denominator();
  return stream;
}

istream &operator>>(istream &stream, Rational &r)
{
  int n, d;
  char math_operator;
  stream >> n >> math_operator >> d;
  if (stream && math_operator == '/')
    r = {n, d};
  return stream;
}

int main()
{
  Rational r1, r2;
  char math_operation;

  try
  {
    cin >> r1;
    cin >> math_operation;
    cin >> r2;
  }
  catch (const invalid_argument &e)
  {
    cout << "Invalid argument" << '\n';
    return 0;
  }

  switch (math_operation)
  {
  case '+':
    cout << r1 + r2;
    break;

  case '-':
    cout << r1 - r2;
    break;

  case '*':
    cout << r1 * r2;
    break;

  case '/':
    try
    {
      cout << r1 / r2;
    }
    catch (const domain_error &e)
    {
      cout << "Division by zero" << '\n';
      break;
    }

  default:
    break;
  }
  return 0;
}
