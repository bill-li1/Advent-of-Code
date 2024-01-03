#include <iostream>
#include <map>

using namespace std;

void sol1() {
	string s;
	int total = 0;
	while(cin >> s) {
		int first, last;
		for(int i=0; i<s.size(); i++) {
			if(isdigit(s.at(i))) {
				first = s.at(i) - '0';
				break;
			}
		}
		for(int i=s.size()-1; i>=0; i--) {
			if(isdigit(s.at(i))) {
				last = s.at(i) - '0';
				break;
			}
		}
		total += first * 10 + last;
	}
	cout << total << endl;
}

void sol2() {
	vector<string> m{
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};
	string s;
	int total = 0;
	while(cin >> s) {
		int first, last;
		for(int i=0; i<s.size(); i++) {
			if(isdigit(s.at(i))) {
				first = s.at(i) - '0';
				break;
			} else {
				bool found_first = false;
				for(int j=0; j<m.size(); j++) {
					bool found = true;
					for(int x=0; x<m[j].size(); x++) {
						if(i+x < s.size() && m[j].at(x) != s.at(i+x)) {
							found = false;
							break;
						}
					}
					if(found) {
						first = j+1;
						found_first = true;
						break;
					}
				}
				if(found_first) {
					break;
				}
			}
		}
		for(int i=s.size()-1; i>=0; i--) {
			if(isdigit(s.at(i))) {
				last = s.at(i) - '0';
				break;
			} else {
				bool found_last = false;
				for(int j=0; j<m.size(); j++) {
					bool found = true;
					for(int x=0; x<m[j].size(); x++) {
						if(i+x >= s.size()) {
							found = false;
							break;
						}
						if(i+x < s.size() && m[j].at(x) != s.at(i+x)) {
							found = false;
							break;
						}
					}
					if(found) {
						last = j+1;
						found_last = true;
						break;
				  }
				}
				if(found_last) {
					break;
				}
			}
		}
		// cout << first << " " << last << endl;
		total += first * 10 + last;
	}
	cout << total << endl;
}

int main() {
	sol2();
}
