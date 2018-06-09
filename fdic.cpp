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

int main() {
  set<string> dict;
  string filePath;

  const char *homedir = getenv("HOME");
  if (homedir == NULL) {
    homedir = getpwuid(getuid())->pw_dir;
  }

  fstream file(filePath.append(homedir).append("/.config/fdic/dict.txt"));
  copy(istream_iterator<string>(file), istream_iterator<string>(), inserter(dict, dict.end()));

  for (string word; getline(cin, word);) {
    if (dict.find(word) == dict.end()) {continue;}
    cout << word << '\n';
  }
}
