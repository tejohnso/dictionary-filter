#include <string>
#include <unistd.h>
#include <pwd.h>
#include <fstream>
#include <iterator>
#include <set>
#include <stdexcept>
#include "dictionary.h"

using namespace std;

void populate_dictionary_from_args(set<string> &, int, char *[]);
void populate_dictionary_from_file(set<string> &, const char *);
const string NO_DICTIONARY_ERROR = "No dictionary found in $HOME/.config/fdic/dict.txt "
                                   "and no words provided as command line arguments.";

bool populate_dictionary(set<string> &dict, int argc, char *argv[]) {
  if (argc > 1) {
    populate_dictionary_from_args(dict, argc, argv);
  } else {
    populate_dictionary_from_file(dict, getenv("HOME"));
  }

  if (dict.size() == 0) {throw runtime_error(NO_DICTIONARY_ERROR);}

  return true;
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
