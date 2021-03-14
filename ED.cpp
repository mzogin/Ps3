// Copyright 2020 Michael Zogin
#include "ED.h"  // NOLINT 
#include <string>
#include <algorithm>
#include <vector>

ED::ED(const string &s1, const string &s2) {
  string1 = s1;
  string2 = s2;
  N = string1.length();
  M = string2.length();

  // allocate the matrix
  matrix = new vector<vector<int>>(N + 1, vector<int>(M + 1));
}

ED::~ED() {
  delete matrix;
  N = 0;
  M = 0;
}

int ED::penalty(char a, char b) {
  if (a == b) {
    return 0;
  } else if (a != b) {
    return 1;
  }
  return -1;
}

int ED::min(int a, int b, int c) {
  if ((a < b) && (a < c)) {
    return a;
  } else if ((b < a) && (b < c)) {
    return b;
  } else if (c < a && c < b) {
    return c;
  }
  return a;
}

int ED::OptDistance() {
  int i, j;
  int N = string1.length();
  int M = string2.length();

  for (i = 0; i <= M; i++) {
    for (j = 0; j <= N; j++) {
      matrix->at(i).push_back(0);
    }
  }

  // this will fill far right column with base cases
  for (i = 0; i <= M; i++) {
    matrix->at(i).at(N) = 2 * (M - i);
  }

  // this will fill bottom row with base cases
  for (j = 0; j <= N; j++) {
    matrix->at(M).at(j) = 2 * (N - j);
  }

  // go from bottom row up
  for (i = (M - 1); i >= 0; i--) {
    // go from rigth to left
    for (j = (N - 1); j >= 0; j--) {
      int opt1 = matrix->at(i + 1).at(j + 1) + penalty(string1[j], string2[i]);
      int opt2 = matrix->at(i + 1).at(j) + 2;
      int opt3 = matrix->at(i).at(j + 1) + 2;

      matrix->at(i).at(j) = min(opt1, opt2, opt3);
    }
  }

  // return final calculated ED(top left of matrix)
  return matrix->at(0).at(0);
}

string ED::Alignment() {
  std::ostringstream ret;

  int i = 0;
  int j = 0;
  int opt1, opt2, opt3;
  int pen;
  string ret_str;

  // runs until we hit bottom right corner
  while (i < M || j < N) {
    try {
      pen = penalty(string1[j], string2[i]);
      opt1 = matrix->at(i + 1).at(j + 1) + pen;
    } catch (const std::out_of_range &error) {
      opt1 = -1;
    }

    try {
      opt2 = matrix->at(i + 1).at(j) + 2;
    } catch (const std::out_of_range &error) {
      opt2 = -1;
    }

    try {
      opt3 = matrix->at(i).at(j + 1) + 2;
    } catch (const std::out_of_range &error) {
      opt3 = -1;
    }

    if (matrix->at(i).at(j) == opt1) {
      ret << string1[j] << " " << string2[i] << " " << pen << endl;

      // moves diagonal
      i++;
      j++;
    } else if (matrix->at(i).at(j) == opt2) {
      ret << "- " << string2[i] << " 2" << endl;

      // moves down
      i++;
    } else if (matrix->at(i).at(j) == opt3) {
      ret << string1[j] << " - 2" << endl;
      
      // moves right
      j++;
    }
  }
  ret_str = ret.str();
  return ret_str;
}
