#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

int main() {
  std::string firstWord;

  getline(std::cin, firstWord, ' ');
  std::cout << firstWord;

  for (std::string word; std::getline(std::cin, word, ' ');) {
    std::cout << ' ' << word;
  }
}
