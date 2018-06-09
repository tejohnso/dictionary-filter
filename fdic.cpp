#include <string>
#include <iostream>
#include <set>
#include "dictionary.h"

using namespace std;

int main(int argc, char *argv[]) {
  set<string> dict;

  if (!populate_dictionary(dict, argc, argv)) {return 1;}

  for (string word; getline(cin, word);) {
    if (dict.find(word) == dict.end()) {continue;}
    cout << word << '\n';
  }
}
