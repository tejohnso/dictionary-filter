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

int main(int argc, char *argv[]) {
  set<string> dict;
  string filePath;

  if (argc > 1) {
    copy(argv, argv + argc, inserter(dict, dict.end()));
  } else {
    const char *homedir = getenv("HOME");
    if (homedir == NULL) {
      homedir = getpwuid(getuid())->pw_dir;
    }

    fstream file(filePath.append(homedir).append("/.config/fdic/dict.txt"));
    copy(istream_iterator<string>(file), istream_iterator<string>(), inserter(dict, dict.end()));
    if (dict.size() == 0) {
      cout << "No dictionary found in $HOME/.config/fdic/dict.txt and no words provided as command line arguments." << endl;
      return 1;
    }
  }

  for (string word; getline(cin, word);) {
    if (dict.find(word) == dict.end()) {continue;}
    cout << word << '\n';
  }
}
