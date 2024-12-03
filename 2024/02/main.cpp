#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isIncreasing(vector<int> nums) {
  for (int i = 1; i < nums.size(); i++) {
    if (!(nums[i] > nums[i - 1] && nums[i] - nums[i - 1] <= 3)) {
      return false;
    }
  }
  return true;
}

bool isDecreasing(vector<int> nums) {
  for (int i = 1; i < nums.size(); i++) {
    if (!(nums[i] < nums[i - 1] && nums[i - 1] - nums[i] <= 3)) {
      return false;
    }
  }
  return true;
}

void part1() {
  string line;
  int ans = 0;
  while (getline(cin, line)) {
    stringstream ss(line);
    int n, prev;
    vector<int> nums;
    while (ss >> n) {
      nums.push_back(n);
    }
    if (isIncreasing(nums) || isDecreasing(nums)) {
      ans++;
    }
  }
  cout << ans << endl;
}

void part2() {
  string line;
  int ans = 0;
  while (getline(cin, line)) {
    stringstream ss(line);
    int n, prev;
    vector<int> nums;
    while (ss >> n) {
      nums.push_back(n);
    }
    for (int i = 0; i < nums.size(); i++) {
      vector<int> nums2;
      for (int j = 0; j < nums.size(); j++) {
        if (j == i)
          continue;
        nums2.push_back(nums[j]);
      }
      if (isIncreasing(nums2) || isDecreasing(nums2)) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}

int main() { part2(); }
