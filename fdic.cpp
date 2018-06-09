#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> dict {"dog", "cat", "car"};
  std::string firstWord;

  getline(std::cin, firstWord, ' ');
  std::cout << firstWord;

  for (std::string word; std::getline(std::cin, word, ' ');) {
    std::cout << ' ' << word;
  }

  std::copy(dict.begin(), dict.end(), std::ostream_iterator<std::string>(std::cout, " "));
}
