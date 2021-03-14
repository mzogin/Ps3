// Copyright 2020 Michael Zogin
#include "ED.h"
#include <SFML/System.hpp>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
  sf::Clock clock;  // starts automatically
  // sf::Time t;

  auto getTime = [&](sf::Clock c){ sf::Time t = clock.getElapsedTime();
    return t.asSeconds();
  };

  string string1, string2;
  std::cin >> string1 >> string2;  // read the two strings and make the obj

  ED ed(string1, string2);

  int dist = ed.OptDistance();

  string alignment = ed.Alignment();

  std::cout << "Edit distance: " << dist << "\n";

  std::cout << alignment;

  // t = clock.getElapsedTime();

  std::cout << "Execution time: " << getTime(clock) << " seconds \n";
  return 0;
}
