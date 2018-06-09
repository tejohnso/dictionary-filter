#include <string>
#include <iostream>
#include <set>
#include "dictionary.h"

using namespace std;

int main(int argc, char *argv[]) {
  set<string> dict;

  try {
    populate_dictionary(dict, argc, argv);
  } catch (const exception &e) {
    cout << e.what() << endl;
    return 1;
  }

  for (string word; getline(cin, word);) {
    if (dict.find(word) == dict.end()) {continue;}
    cout << word << '\n';
  }
}
