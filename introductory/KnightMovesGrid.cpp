#include<iostream>
#include<bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
int n;
int num_directions = 8;
int directions[][2] = {{-1, -2}, {1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}};

void moves(vector<vector<int>>& grid) {
    q.push({0, 0});
    grid[0][0] = 0;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        int row = p.first, col = p.second;
        q.pop();

        for(int i = 0; i < num_directions; i++) {
            int r = directions[i][0], c = directions[i][1];
            if(
                0 <= row + r &&
                row + r < n &&
                0 <= col + c &&
                col + c < n &&
                grid[row+r][col+c] == -1
            ) {
                grid[row+r][col+c] = grid[row][col] + 1;
                q.push({row+r, col+c});
            }
        }

    }


}

int main() {
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, -1));
    moves(grid);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}