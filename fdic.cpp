#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>

using namespace std;

int main() {
  set<string> dict;
  string firstWord;

  fstream file("/home/tyler/.config/fdic/dict.txt");
  copy(istream_iterator<string>(file), istream_iterator<string>(), inserter(dict, dict.end()));

  getline(cin, firstWord, ' ');
  if (dict.find(firstWord) != dict.end()) {cout << firstWord;}

  for (string word; getline(cin, word, ' ');) {
    if (dict.find(word) == dict.end()) {continue;}
    cout << ' ' << word;
  }
}
