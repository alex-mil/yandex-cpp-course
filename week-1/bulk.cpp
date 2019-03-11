using namespace std;

string division(double n1, double n2) {
  if (n2 == 0) {
    return "Impossible";
  }

  return to_string(static_cast<int>(n1 / n2));
}

double discount(double total, double minPurchase1, double minPurchase2, double discount1, double discount2) {
  double closingPrice = total;
  if (total > minPurchase2) {
    closingPrice *= (1 - discount2 / 100);
  } else if (total > minPurchase1) {
    closingPrice *= (1 - discount1 / 100);
  }
  return closingPrice;
}

string evenNumbers(int start, int end) {
  stringstream ss;
  for (int i = start; i <= end; ++i) {
    if (i % 2 == 0) {
      ss << i;
      ss << " ";
    }
  }
  return ss.str();
}

int indexOfChar(string str, char ch) {
  int index = -2;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == ch && index == -2) {
      index += 1;
    } else if (str[i] == ch && index == -1) {
      index = i;
    }
  }
  return index;
}

int greatestCommonDivisor(int n1, int n2) {
  // Euclidean algorithm
  while (n1 > 0 && n2 > 0) {
    if (n1 > n2) {
      n1 = n1 % n2;
    } else {
      n2 = n2 % n1;
    }
  }
  return n1 + n2;
}

vector<int> displayInBinary(int n) {
  int quotient = -1;
  vector<int> remainders;

  do {
    if (quotient == -1) {
      remainders.push_back(n % 2);
      quotient = n / 2;
    } else {
      remainders.push_back(quotient % 2);
      quotient = quotient / 2;
    }
  } while (quotient > 0);

  reverse(begin(remainders), end(remainders));

  return remainders;
}
