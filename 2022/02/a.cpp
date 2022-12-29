#include <iostream>
#include <sstream>

using namespace std;

void solution_one() {
	string line;
	int score = 0;
	while(getline(cin, line)) {
		istringstream iss(line);
		char opp, me;
		iss >> opp >> me;
		if(me == 'X') {
			score += 1;
			if(opp == 'A') {
				score += 3;
			} else if(opp == 'B') {
				score += 0;
			}
			else if(opp == 'C') {
				score += 6;
			}
		}
		else if(me == 'Y') { 
			score += 2;
			if(opp == 'A') {
				score += 6;
			} else if(opp == 'B') {
				score += 3;
			}
			else if(opp == 'C') {
				score += 0;
			}
		}
		else if(me == 'Z') {
			score += 3;
			if(opp == 'A') {
				score += 0;
			} else if(opp == 'B') {
				score += 6;
			}
			else if(opp == 'C') {
				score += 3;
			}
		}
	}
	cout << score << endl;
}

void solution_two() {
	string line;
	int score = 0;
	while(getline(cin, line)) {
		istringstream iss(line);
		char me, opp;
		iss >> opp >> me;
		if(me == 'X') {
			score += 0;
			if(opp == 'A') {
				score += 3;
			} else if(opp == 'B') {
				score += 1;
			}
			else if(opp == 'C') {
				score += 2;
			}
		}
		else if(me == 'Y') { 
			score += 3;
			if(opp == 'A') {
				score += 1;
			} else if(opp == 'B') {
				score += 2;
			}
			else if(opp == 'C') {
				score += 3;
			}
		}
		else if(me == 'Z') {
			score += 6;
			if(opp == 'A') {
				score += 2;
			} else if(opp == 'B') {
				score += 3;
			}
			else if(opp == 'C') {
				score += 1;
			}
		}
	}
	cout << score << endl;
}

int main() {
	solution_two();
}
