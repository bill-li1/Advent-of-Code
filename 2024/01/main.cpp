#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void part_2() {
  vector<int> list1;
  unordered_map<int, int> list2;
  int n, m;
  while (cin >> n >> m) {
    list1.push_back(n);
    if (list2[m]) {
      list2[m]++;
    } else {
      list2[m] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < list1.size(); i++) {
    int value = list1[i];
    int occurances = list2[value];
    ans += value * occurances;
  }
  cout << ans << endl;
}

void part_1() {
  vector<int> list1;
  vector<int> list2;
  int n, m;
  while (cin >> n >> m) {
    list1.push_back(n);
    list2.push_back(m);
  }
  sort(list1.begin(), list1.end());
  sort(list2.begin(), list2.end());
  int ans = 0;
  for (int i = 0; i < list1.size(); i++) {
    ans += abs(list1[i] - list2[i]);
  }
  cout << ans << endl;
}

int main() { part_2(); }
