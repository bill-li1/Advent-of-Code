#include <iostream>
#include <string>

using namespace std;

void part_1() {
  vector<string> search;
  string s;
  while (getline(cin, s)) {
    search.push_back(s);
  }
  int ans = 0;
  for (int i = 0; i < search.size(); i++) {
    for (int j = 0; j < search[i].size(); j++) {
      if (search[i][j] == 'X') {
        // top
        if (i >= 3 && search[i - 1][j] == 'M' && search[i - 2][j] == 'A' &&
            search[i - 3][j] == 'S') {
          ans++;
        }
        // down
        if (i < search.size() - 3 && search[i + 1][j] == 'M' &&
            search[i + 2][j] == 'A' && search[i + 3][j] == 'S') {
          ans++;
        }
        // left
        if (j >= 3 && search[i][j - 1] == 'M' && search[i][j - 2] == 'A' &&
            search[i][j - 3] == 'S') {
          ans++;
        }
        // right
        if (j < search[i].size() - 3 && search[i][j + 1] == 'M' &&
            search[i][j + 2] == 'A' && search[i][j + 3] == 'S') {
          ans++;
        }
        // up left
        if (i >= 3 && j >= 3 && search[i - 1][j - 1] == 'M' &&
            search[i - 2][j - 2] == 'A' && search[i - 3][j - 3] == 'S') {
          ans++;
        }
        // up right
        if (i >= 3 && j < search[i].size() - 3 && search[i - 1][j + 1] == 'M' &&
            search[i - 2][j + 2] == 'A' && search[i - 3][j + 3] == 'S') {
          ans++;
        }
        // down left
        if (i < search.size() - 3 && j >= 3 && search[i + 1][j - 1] == 'M' &&
            search[i + 2][j - 2] == 'A' && search[i + 3][j - 3] == 'S') {
          ans++;
        }
        // down right
        if (i < search.size() - 3 && j < search[i].size() - 3 &&
            search[i + 1][j + 1] == 'M' && search[i + 2][j + 2] == 'A' &&
            search[i + 3][j + 3] == 'S') {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}

void part_2() {
  vector<string> search;
  string s;
  while (getline(cin, s)) {
    search.push_back(s);
  }
  int ans = 0;
  for (int i = 1; i < search.size() - 1; i++) {
    for (int j = 1; j < search[i].size() - 1; j++) {
      if (search[i][j] == 'A') {
        // top left to bottom right
        if (((search[i - 1][j - 1] == 'M' && search[i + 1][j + 1] == 'S') ||
             (search[i - 1][j - 1] == 'S' && search[i + 1][j + 1] == 'M')) &&
            (((search[i - 1][j + 1] == 'M' && search[i + 1][j - 1] == 'S') ||
              (search[i - 1][j + 1] == 'S' && search[i + 1][j - 1] == 'M')))) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}

int main() { part_2(); }
