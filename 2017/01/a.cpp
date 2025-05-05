#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void part_one() {
	ifstream file("input.txt");
	string content;
	getline(file, content);
	content += content[0];
	int ans = 0;
	for(int i=0; i<content.size() - 1; i++) {
		if(content[i] == content[i+1]) {
			ans += content[i] - '0';
		}
	}
	cout << ans << endl;
}

void part_two() {
	ifstream file("input.txt");
	string content;
	getline(file, content);
	int ans = 0;
	int half = content.size() / 2;
	for(int i=0; i<content.size(); i++) {
		if(content[i] == content[(i+half) % content.size()]) {
			ans += content[i] - '0';
		}
	}
	cout << ans << endl;
}

int main() {
	part_two();
}