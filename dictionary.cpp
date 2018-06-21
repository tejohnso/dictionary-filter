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
void populate_dictionary_from_file(set<string> &);

void populate_dictionary(set<string> &dict, int argc, char *argv[]) {
  if (argc > 1) {
    populate_dictionary_from_args(dict, argc, argv);
  } else {
    populate_dictionary_from_file(dict);
  }
}

void populate_dictionary_from_args(set<string> &dict, int argc, char *argv[]) {
  copy(argv + 1, argv + argc, inserter(dict, dict.end()));
}

void populate_dictionary_from_file(set<string> &dict) {
  string FILE_PATH;

  if (getenv("SNAP_NAME")) {
    string SNAP_USER_COMMON = getenv("SNAP_USER_COMMON");
    FILE_PATH = SNAP_USER_COMMON.append("/dict.txt");
  } else {
    string homedir = getenv("HOME");
    if (!homedir.size()) {homedir = getpwuid(getuid())->pw_dir;}
    FILE_PATH = homedir.append("/.config/fdic/dict.txt");
  }

  fstream file (FILE_PATH);
  copy(istream_iterator<string>(file), istream_iterator<string>(), inserter(dict, dict.end()));
  if (dict.size() == 0) {throw runtime_error("Provide " + FILE_PATH + " or arguments.");}
}
