#include <iostream>
#include <vector>

using namespace std;

vector<string> m;
int startx, starty;

int run_simulation() {
  vector<vector<string>> step(m.size(), vector<string>(m[0].size(), ""));
  int row = startx, col = starty;
  char pos = 'u';
  while (row > 0 && row < m.size() - 1 && col > 0 && col < m[0].size() - 1) {
    if (step[row][col].find(pos) != string::npos) {
      cout << step[row][col] << endl;
      return 1;
    }
    step[row][col] += pos;
    if (pos == 'u') {
      if (m[row - 1][col] != '#') {
        row--;
      } else {
        pos = 'r';
      }
    } else if (pos == 'r') {
      if (m[row][col + 1] != '#') {
        col++;
      } else {
        pos = 'd';
      }
    } else if (pos == 'd') {
      if (m[row + 1][col] != '#') {
        row++;
      } else {
        pos = 'l';
      }
    } else if (pos == 'l') {
      if (m[row][col - 1] != '#') {
        col--;
      } else {
        pos = 'u';
      }
    }
  }
  return 0;
}

int main() {
  string temp;
  while (getline(cin, temp)) {
    m.push_back(temp);
    vector<string> temp_v(temp.size(), "");
  }
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[i].size(); j++) {
      if (m[i][j] == '^') {
        startx = i;
        starty = j;
      }
    }
  }
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[i].size(); j++) {
      cout << m[i][j];
    }
    cout << endl;
  }
  int ans = 0;
  for (int r = 0; r < m.size(); r++) {
    for (int c = 0; c < m[r].size(); c++) {
      char before = m[r][c];
      if (before == '.') {
        m[r][c] = '#';
        int answer = run_simulation();
        if (answer == 1) {
          cout << r << " " << c << endl;
        }
        ans += run_simulation();
        m[r][c] = before;
      }
    }
  }
  cout << ans << endl;
}
