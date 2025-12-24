#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define DIM 7

map<char, vector<int>> directions = {
    {'L', {0, -1}}, 
    {'U', {-1, 0}}, 
    {'R', {0, 1}}, 
    {'D', {1, 0}}
};

vector<vector<char>> grid(DIM, vector<char>(DIM, '?'));
int num_paths;
int N;
int cnt;

vector<vector<bool>> visited(DIM, vector<bool>(DIM, false));

void path(string s, int i, int row, int col) {
    
}

string s;

void bfs(int i, int row, int col) {
    if(i == DIM * DIM-1) {
        cnt++;
        cout << ":X\n";
        return;
    }

    if(s[i] != '?') {
        char ch = s[i];
        int r = directions[ch][0], c = directions[ch][1];
        if(
            row + r >= 0 &&
            row + r < DIM &&
            col + c >= 0 &&
            col + c < DIM &&
            !visited[row + r][col + c]
        ) {
            bfs(i+1, row+r, col+c);
        }
        return;
    }

    visited[row][col] = true;
    // cout << "cnt: " << cnt << "\n";

    for(auto pair : directions) {
        char ch = pair.first;
        int r = pair.second[0], c = pair.second[1];

        if(
            row + r >= 0 &&
            row + r < DIM &&
            col + c >= 0 &&
            col + c < DIM &&
            !visited[row+r][col+c]
        ) {
            cout << ch;
            bfs(i+1, row + r, col + c);
            i--;
            visited[row+r][col+c] = false;
        }
    }

}

int main() {
    // string s;
    cin >> s;
    // N = s.size();
    // num_paths = 0;


    // grid[0][0] = 'X';
    // path(s, 0, 0, 0);

    cnt = 0;
    bfs(0, 0, 0);
    cout << "\n" << cnt << "\n";

    return 0;
}