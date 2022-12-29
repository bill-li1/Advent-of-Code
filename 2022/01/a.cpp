#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

void solution_one() {
  int ans = 0;
  int cur = 0;
  string line;
  while(getline(cin, line)) {
		if(line.empty()) {
			ans = max(ans, cur);
			cur = 0;
		} else {
			istringstream iss(line);
			int n;
			iss >> n;
			cur += n;
		}
	}
	ans = max(ans, cur);
	cout << ans << endl;
}

void solution_two() {
	priority_queue<int> pq;
	int cur(0);
	string line;
	while(getline(cin, line)) {
		if(line.empty()) {
			pq.push(cur);
			cur = 0;
		} else {
			istringstream iss(line);
			int n;
			iss >> n;
			cur += n;
		}
	}
	pq.push(cur);
	int ans(0);
	for(int i=0; i<3; i++) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << endl;
}

int main() {
	solution_two();
}
