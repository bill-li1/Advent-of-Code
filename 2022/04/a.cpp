#include <iostream>
#include <sstream>

using namespace std;

void solutionOne() {
	string line;
	int count = 0;
	while(getline(cin, line)) {
		istringstream iss(line);
		int start1, end1, start2, end2;
		char burner;
		iss >> start1;
		iss >> burner;
		iss >> end1;
		iss >> burner;
		iss >> start2;
		iss >> burner;
		iss >> end2;
		if((start1 <= start2 && end1 >= end2) ||
		  (start2 <= start1 && end2 >= end1)) {
			count++;
		}		
	}
	cout << count << endl;
}

void solutionTwo() {
	string line;
	int count = 0;
	while(getline(cin, line)) {
		istringstream iss(line);
		int start1, end1, start2, end2;
		char burner;
		iss >> start1;
		iss >> burner;
		iss >> end1;
		iss >> burner;
		iss >> start2;
		iss >> burner;
		iss >> end2;
		// end1 < start2
		// end2 < start1
		if(!((end1 < start2) ||
		  (end2 < start1))) {
			count++;
		}		
	}
	cout << count << endl;
}

int main() {
	solutionTwo();
}


