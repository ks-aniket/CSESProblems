#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
int largest;
int num;
unordered_set<int> haveOccurred;

void mesh(int n) {
    if(n == 1) {
        grid[0][0] = 0;
        return;
    }

    mesh(n-1);

    // fill the nth row, except the (n-1, n-1)th element
    for(int col = 0, row = n-1; col < n-1; col++) {
        // grid[n-1][i];
        // search through to the left 

        haveOccurred.clear();
        for(int c = col-1; c >= 0; c--) {
            haveOccurred.insert(grid[row][c]);
        }
        // if(col == 0 && row == 3) {
        //     cout << "\n(3,1): row: ";
        //     for(auto s : haveOccurred) cout << s << " ";
        //     cout << "\n";
        // }

        // search above
        for(int r = row-1; r >= 0; r--) {
           haveOccurred.insert(grid[r][col]);
        }

        // if(col == 0 && row == 3) {
        //     cout << "\n(3,1): ";
        //     for(auto s : haveOccurred) cout << s << " ";
        //     cout << "\n";
        // }

        num = 0;
        while(true) {
            if(!haveOccurred.count(num)) {
                grid[row][col] = num;
                break;
            }
            num++;
        }

    }

    // fill the nth column
    for(int row = 0, col = n-1; row < n-1; row++) {
        // grid[n-1][i];
        largest = -1;

        haveOccurred.clear();
        // Put the elements in a set
        // search to the left
        for(int c = col-1; c >= 0; c--) {
            haveOccurred.insert(grid[row][c]);
        }

        for(int r = row-1; r >= 0; r--) {
            haveOccurred.insert(grid[r][col]);
        }

        // for(auto s : haveOccurred) {
        //     cout << s << " ";
        // }
        // cout << "\n";
        // Search for the first non-negative number that's not in the set
        num = 0;
        while(true) {
            if(!haveOccurred.count(num)) {
                grid[row][col] = num;
                break;
            }
            num++;
        }

    }

    haveOccurred.clear();
    // Fill the n-1, n-1)th element
    for(int c = n-2; c >= 0; c--) {
        haveOccurred.insert(grid[n-1][c]);

    }
    for(int r = n-2; r >= 0; r--) {
        haveOccurred.insert(grid[r][n-1]);
    }

    num = 0;
    while(true) {
        if(!haveOccurred.count(num)) {
            grid[n-1][n-1] = num;
            break;
        }
        num++;
    }
}

int main() {
    int n;
    cin >> n;
    // cout << "start\n";
    grid = vector<vector<int>>(n, vector<int>(n, -1));
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    mesh(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}