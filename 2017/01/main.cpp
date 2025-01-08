#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  s += s[0];
  cout << s << endl;
  int ans = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == s[i + 1]) {
      ans += s[i] - '0';
    }
  }
  cout << ans << endl;
}
