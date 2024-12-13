#include <iostream>
#include <string>

using namespace std;

void part_1() {
  string s;
  vector<string> m;
  int row = 0;
  pair<int, int> guard;
  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '^') {
        guard.first = row;
        guard.second = i;
      }
    }
    row++;
    m.push_back(s);
  }
  vector<vector<int>> step(m.size(), vector<int>(m[0].size()));
  step[guard.first][guard.second]++;
  /*for (int i = 0; i < step.size(); i++) {*/
  /*  for (int j = 0; j < step[0].size(); j++) {*/
  /*    cout << step[i][j] << " ";*/
  /*  }*/
  /*  cout << endl;*/
  /*}*/
  int guard_pos = 0;
  while (guard.first > 0 && guard.first < m.size() - 1 && guard.second > 0 &&
         guard.second < m[0].size() - 1) {
    step[guard.first][guard.second]++;
    if (guard_pos % 4 == 0) {
      if (m[guard.first - 1][guard.second] != '#') {
        guard.first--;
      } else {
        guard_pos++;
      }
    } else if (guard_pos % 4 == 1) {
      if (m[guard.first][guard.second + 1] != '#') {
        guard.second++;
      } else {
        guard_pos++;
      }
    } else if (guard_pos % 4 == 2) {
      if (m[guard.first + 1][guard.second] != '#') {
        guard.first++;
      } else {
        guard_pos++;
      }
    } else if (guard_pos % 4 == 3) {
      if (m[guard.first][guard.second - 1] != '#') {
        guard.second--;
      } else {
        guard_pos++;
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < step.size(); i++) {
    for (int j = 0; j < step[0].size(); j++) {
      if (step[i][j] > 0) {
        cout << 'X';
        ans++;
      } else {
        cout << '.';
      }
    }
    cout << endl;
  }
  cout << ans << endl;
}

vector<string> m;

int run_simulation(int row, int col, int guard_pos,
                   vector<vector<pair<int, int>>> step) {
  int dist = 0;
  while (row > 0 && row < m.size() - 1 && col > 0 && col < m[0].size() - 1) {
    if (step[row][col].first > 0 &&
        step[row][col].second % 4 == guard_pos % 4) {
      return 1;
    }
    dist++;
    step[row][col].first++;
    step[row][col].second = guard_pos;
    if (guard_pos % 4 == 0) {
      if (m[row - 1][col] != '#') {
        row--;
      } else {
        guard_pos++;
      }
    } else if (guard_pos % 4 == 1) {
      if (m[row][col + 1] != '#') {
        col++;
      } else {
        guard_pos++;
      }
    } else if (guard_pos % 4 == 2) {
      if (m[row + 1][col] != '#') {
        row++;
      } else {
        guard_pos++;
      }
    } else if (guard_pos % 4 == 3) {
      if (m[row][col - 1] != '#') {
        col--;
      } else {
        guard_pos++;
      }
    }
  }
  return 0;
}

void part_2() {
  string s;
  int row = 0;
  pair<int, int> guard;
  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '^') {
        guard.first = row;
        guard.second = i;
      }
    }
    row++;
    m.push_back(s);
  }
  vector<vector<pair<int, int>>> step(
      m.size(), vector<pair<int, int>>(m[0].size(), pair<int, int>{0, -1}));
  int ans = 0;
  step[guard.first][guard.second].first++;
  int guard_pos = 0;
  step[guard.first][guard.second].second = guard_pos % 4;
  while (guard.first > 0 && guard.first < m.size() - 1 && guard.second > 0 &&
         guard.second < m[0].size() - 1) {
    if (guard_pos % 4 == 0) {
      if (m[guard.first - 1][guard.second] != '#') {
        m[guard.first - 1][guard.second] = '#';
        ans += run_simulation(guard.first, guard.second + 1,
                              (guard_pos + 1) % 4, step);
        m[guard.first - 1][guard.second] = '.';
        guard.first--;
      } else {
        guard_pos++;
      }
    } else if (guard_pos % 4 == 1) {
      if (m[guard.first][guard.second + 1] != '#') {
        m[guard.first][guard.second + 1] = '#';
        ans += run_simulation(guard.first + 1, guard.second,
                              (guard_pos + 1) % 4, step);
        m[guard.first][guard.second + 1] = '.';
        guard.second++;
      } else {
        guard_pos++;
      }
    } else if (guard_pos % 4 == 2) {
      if (m[guard.first + 1][guard.second] != '#') {
        m[guard.first + 1][guard.second] = '#';
        ans += run_simulation(guard.first, guard.second - 1,
                              (guard_pos + 1) % 4, step);
        m[guard.first + 1][guard.second] = '.';
        guard.first++;
      } else {
        guard_pos++;
      }
    } else if (guard_pos % 4 == 3) {
      if (m[guard.first][guard.second - 1] != '#') {
        m[guard.first][guard.second - 1] = '#';
        ans += run_simulation(guard.first - 1, guard.second,
                              (guard_pos + 1) % 4, step);
        m[guard.first][guard.second - 1] = '.';
        guard.second--;
      } else {
        guard_pos++;
      }
    }
    step[guard.first][guard.second].first++;
    step[guard.first][guard.second].second = guard_pos % 4;
  }
  cout << ans << endl;
}

int main() { part_2(); }
