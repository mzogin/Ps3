// Copyright 2020 Michael Zogin
#ifndef ED_H  // NOLINT
#define ED_H  // NOLINT

#include <SFML/System.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::endl;

class ED {
 public:
  ED();
  ED(const string &s1, const string &s2);
  ~ED();

  static int penalty(char a, char b);
  static int min(int a, int b, int c);
  int OptDistance();
  std::string Alignment();

  void PrintMatrix();

 private:
  string string1, string2;
  int N = 0;
  int M = 0;

  std::vector<std::vector<int>> *matrix;
};

#endif  // NOLINT
