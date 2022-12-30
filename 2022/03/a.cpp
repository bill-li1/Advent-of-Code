#include <iostream>

using namespace std;

void solution_one() {
	string line;
	int sum = 0;
	while(getline(cin, line)) {
		int compartmentSize = line.size() / 2;
		bool found = false;
		for(int i=0; i<compartmentSize; i++) {
			for(int j=compartmentSize; j<line.size(); j++) {
				if(line[i] == line[j]) {
					if(line[i]>='a') {
						sum += line[i]-'a'+1;
					} else {
						sum += line[i]-'A'+1+26;
					}
					found = true;
					break;
				}
			}
			if(found) break;
		}
	}
	cout << sum << endl;
}

bool findChar(string s, char c) {
	for(int i=0; i<s.size(); i++) {
		if(s[i] == c) {
			return true;
		}
	}
	return false;
}

void solution_two() {
	string line;
	int sum = 0;
	while(getline(cin, line)) {
		string lineTwo, lineThree;
		getline(cin, lineTwo);
		getline(cin, lineThree);
		for(int i=0; i<line.size(); i++) {
			if(findChar(lineTwo, line[i]) && findChar(lineThree, line[i])) {
				if(line[i]>='a') {
					sum += line[i]-'a'+1;
				} else {
					sum += line[i]-'A'+1+26;
				}
				break;
			}
		}
	}
	cout << sum << endl;
}

int main() {
	solution_two();
}
