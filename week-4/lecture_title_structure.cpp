#include <string>

using namespace std;

struct Specialization {
  string name;

  explicit Specialization(const string &value) {
    name = value;
  }
};

struct Course {
  string name;

  explicit Course(const string &value) {
    name = value;
  }
};

struct Week {
  string name;

  explicit Week(const string &value) {
    name = value;
  }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization sp, Course c, Week w) {
    specialization = sp.name;
    course = c.name;
    week = w.name;
  }
};