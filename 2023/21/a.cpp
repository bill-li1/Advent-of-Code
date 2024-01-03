#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int num = 64;

int main() {
    string temp;
    vector<string> m;
    while(cin >> temp) {
        m.push_back(temp);
    }
    int startr, startc;
    int rows = m.size();
    int cols = m[0].size();
    for(int r=0; r<rows; r++) {
        for(int c=0; c<cols; c++) {
            if(m[r][c] == 'S') {
                startr = r;
                startc = c;
            }
        }
    }
    vector<vector<int>> step(rows, vector<int>(cols, -1));
    queue<int> rowq;
    queue<int> colq;
    rowq.push(startr);
    colq.push(startc);
    step[startr][startc] = 0;
    while(!rowq.empty() && !colq.empty()) {
        int r = rowq.front();
        int c = colq.front();
        rowq.pop();
        colq.pop();
        if(r-1 >= 0 && m[r-1][c] != '#' && step[r-1][c] < 0 && step[r][c] < num) {
            step[r-1][c] = step[r][c] + 1;
            rowq.push(r-1);
            colq.push(c);
        }
        if(r+1 < rows && m[r+1][c] != '#' && step[r+1][c] < 0 && step[r][c] < num) {
            step[r+1][c] = step[r][c] + 1;
            rowq.push(r+1);
            colq.push(c);
        }
        if(c-1 >= 0 && m[r][c-1] != '#' && step[r][c-1] < 0 && step[r][c] < num) {
            step[r][c-1] = step[r][c] + 1;
            rowq.push(r);
            colq.push(c-1);
        }
        if(c+1 < cols && m[r][c+1] != '#' && step[r][c+1] < 0 && step[r][c] < num) {
            step[r][c+1] = step[r][c] + 1;
            rowq.push(r);
            colq.push(c+1);
        }
    }
    int count = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(step[i][j] % 2 == 0) count++;
            if(step[i][j] == -1) {
                cout << "X ";
            } else {
                cout << step[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << count << endl;
}
