#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<pair<int, int>>> nodes;

int main() {
  string s;
  int row = 0;
  while (getline(cin, s)) {
    for (int col = 0; col < s.size(); col++) {
      if (s.at(col) != '.') {
        nodes[s.at(col)].push_back(pair{row, col});
      }
    }
    row++;
  }
}
