#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define SIZE 8

// only for formatting
int depth = 0;

int answer = 0;
vector<bool> colsOccupied(SIZE-1);
/*
Top left to bottom right diagnols
#diagnols: 2 * SIZE - 1
Property: 0 <= row - col + SIZE -1 <= 2 * SIZE - 2
*/
vector<bool> diag1Occupied(2 * SIZE - 1);
/*
Bottom left to top right diagnols
#diagnols: 2 * SIZE - 1
Property: 0 <= row + col <= 2 * SIZE - 2
*/
vector<bool> diag2Occupied(2 * SIZE - 1);

void place(int row, vector<string>& grid) {
    if(row == SIZE) {
        answer++;
        return;
    }

    // Search for the best column to place the queen in the current row
    for(int col = 0; col < SIZE; col++) {
        if(
            grid[row][col] == '.' && 
            !colsOccupied[col] &&
            !diag1Occupied[row - col + SIZE - 1] &&
            !diag2Occupied[row + col]
        ) {

            // cout << string(2 * depth, ' ') << "(" << row << ", " << col << ")\n";
            depth++;
            colsOccupied[col] = true;
            diag1Occupied[row - col + SIZE - 1] = true;
            diag2Occupied[row + col] = true;
            place(row+1, grid);
            depth--;
            // These need to be added for backtracking
            colsOccupied[col] = false;
            diag1Occupied[row - col + SIZE - 1] = false;
            diag2Occupied[row + col] = false;
        }
    }

}


int main() {
    vector<string> grid(SIZE);
    for(int i = 0; i < SIZE; i++) cin >> grid[i];

    place(0, grid);

    // for(int i = 0; i < SIZE; i++) cout << grid[i] << "\n";
    cout << answer << "\n";

    return 0;
}