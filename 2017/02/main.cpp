#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void part_one() {
	ifstream file("input.txt");
	string line;
	int ans = 0;
	while(getline(file, line)) {
		stringstream ss(line);
		int temp; ss >> temp;
		int max = temp;
		int min = temp;
		while(ss >> temp) {
			if(temp > max) max = temp;
			if(temp < min) min = temp;
		}
		ans += max - min;
	}
	cout << ans << endl;
}

void part_two() {
	ifstream file("input.txt");
	string line;
	int ans = 0;
	while(getline(file, line)) {
		vector<int> nums;
		stringstream ss(line);
		int temp; 
		while(ss >> temp) {
			nums.push_back(temp);
		}
		for(int i=0; i<nums.size(); i++) {
			for(int j=0; j<nums.size(); j++) {
				if(i != j && nums[i] % nums[j] == 0) {
					ans += nums[i] / nums[j];
					cout << nums[i] << " " << nums[j] << endl;
				}
			}
		}
		cout << ans << endl;
	}
	cout << ans << endl;
}

int main() {
	part_two();
}