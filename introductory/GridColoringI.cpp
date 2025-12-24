#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> grid;
int rows, cols;

// void color() {
//     for(int i = 0; i < rows; i++) {
//         for(int j = 0; j < cols; j++) {
//             set<char> s;
//             if(i != 0) {
//                 s.insert(grid[i-1][j]);
//             }

//             if(j != 0) {
//                 s.insert(grid[i][j-1]);
//             }

//             s.insert(grid[i][j]);

//             char c = 'A';
//             for(char ch : s) {
//                 if(c == ch) c++;
//             }

//             grid[i][j] = c;
//         }
//     }
// }

// second solution
void color() {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            if((r + c) % 2) {
                grid[r][c] = (grid[r][c] == 'A' ? 'C' : 'A');
            } else {
                grid[r][c] = (grid[r][c] == 'B' ? 'D' : 'B');
            }
        }
    }
}

int main() {
    cin >> rows >> cols;

    grid = vector<string>(rows);
    for(string& s : grid) {
        cin >> s;
    }

    color();

    for(string s : grid) {
        cout << s << "\n";
    }
    return 0;
}