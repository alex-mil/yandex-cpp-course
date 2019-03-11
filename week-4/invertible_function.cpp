#include <vector>
#include <algorithm>

using namespace std;

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

class FunctionPart {
 public:
  FunctionPart(char math_operator, double number) {
    operation = math_operator;
    value = number;
  }

  double Apply(double source_value) const {
    if (operation == '+') { return source_value + value; }
    else if (operation == '*') { return source_value * value; }
    else if (operation == '/') { return source_value / value; }
    else { return source_value - value; }
  }

  void Invert() {
    if (operation == '+') { operation = '-'; }
    else if (operation == '*') { operation = '/'; }
    else if (operation == '/') { operation = '*'; }
    else { operation = '+'; }
  }
 private:
  char operation;
  double value;
};

class Function {
 public:
  void AddPart(const char &operation, double number) {
    parts.emplace_back(operation, number);
  }

  double Apply(double number) const {
    for (const auto &part : parts) {
      number = part.Apply(number);
    }
    return number;
  }

  void Invert() {
    for (auto &part : parts) {
      part.Invert();
    }
    reverse(begin(parts), end(parts));
  }
 private:
  vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params &params,
                            const Image &image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params &params, const Image &image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params,
                              const Image &image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}
