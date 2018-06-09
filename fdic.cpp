#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <fstream>
#include <iterator>
#include <iostream>
#include <set>

using namespace std;

void populate_dictionary_from_file(set<string>&, const char *);
void populate_dictionary_from_args(set<string>&, int, char *[]);
void filter_input(set<string>);

int main(int argc, char *argv[]) {
  set<string> dict;

  if (argc > 1) {
    populate_dictionary_from_args(dict, argc, argv);
  } else {
    populate_dictionary_from_file(dict, getenv("HOME"));
  }

  if (dict.size() == 0) {
    string err = "No dictionary found in $HOME/.config/fdic/dict.txt "
                 "and no words provided as command line arguments.";

    cout << err << endl;
    return 1;
  }

  filter_input(dict);
}

void populate_dictionary_from_args(set<string> &dict, int argc, char *argv[]) {
  copy(argv + 1, argv + argc, inserter(dict, dict.end()));
}

void populate_dictionary_from_file(set<string> &dict, const char *homedir) {
  string filePath;

  if (homedir == NULL) {
    homedir = getpwuid(getuid())->pw_dir;
  }

  fstream file(filePath.append(homedir).append("/.config/fdic/dict.txt"));
  copy(istream_iterator<string>(file), istream_iterator<string>(), inserter(dict, dict.end()));
}

void filter_input(set<string> dict) {
  for (string word; getline(cin, word);) {
    if (dict.find(word) == dict.end()) {continue;}
    cout << word << '\n';
  }
}
