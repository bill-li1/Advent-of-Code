#include<iostream>
#include<queue>
#include<utility>
#include<vector>

using namespace std;

int main() {
    string s;
    vector<string> m;
    while(cin >> s) {
        m.push_back(s);
    }
    pair<int, int> start;
    int rows = m.size();
    int cols = m[0].size();
    vector<vector<int>> step(rows, vector<int>(cols, -1));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(m[i][j] == 'S') {
                start.first = i;
                start.second = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(start.first, start.second));
    step[start.first][start.second] = 0;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int r = cur.first;
        int c = cur.second;
        if(r-1 >= 0 && step[r-1][c] < 0 && m[r-1][c] != '#' && step[r][c] < 64) {
            step[r-1][c] = step[r][c] + 1;
            q.push(make_pair(r-1, c));
        }
        if(r+1 < rows && step[r+1][c] < 0 && m[r+1][c] != '#' && step[r][c] < 64) {
            step[r+1][c] = step[r][c] + 1;
            q.push(make_pair(r+1, c));
        }
        if(c-1 >= 0 && step[r][c-1] < 0 && m[r][c-1] != '#' && step[r][c] < 64) {
            step[r][c-1] = step[r][c] + 1;
            q.push(make_pair(r, c-1));
        }
        if(c+1 >= 0 && step[r][c+1] < 0 && m[r][c+1] != '#' && step[r][c] < 64) {
            step[r][c+1] = step[r][c] + 1;
            q.push(make_pair(r, c+1));
        }
    }
    int count = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(step[i][j] % 2 == 0) {
                count++;
            }
        }
    }
    cout << count << endl;
}
