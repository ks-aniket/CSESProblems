#include<iostream>
using namespace std;

#define ll long long
int main() {
    int n;
    cin >> n;

    
    ll total_moves, total_cells; 
    ll moves;
    ll bad_moves;
    for(int i = 1; i <= n; i++) {
        total_cells = i * i;
        total_moves = (total_cells * (total_cells-1)) /2; 
        bad_moves = 0;

        // bad moves for 2
        if(i - 2 == 1) bad_moves += 2 * (8);
        if(i - 2 > 1) bad_moves += 2* (4);

        // bad moves for 3
        if(i - 3 > 0) bad_moves += 3* (8);

        // bad moves for 4
        if(i - 3 > 0) bad_moves += 4*(4 * (i - 3));

        // bad moves for 6
        if(i - 4 > 0) bad_moves += 6*(4 * (i - 4));

        // bad moves for 8
        if(i - 4  >= 1) bad_moves += 8 * (i -4) * (i - 4);

        // every bad move is counted twice;
        bad_moves /= 2;

        moves = total_moves - bad_moves;

        cout << moves << "\n";
    }
    return 0;
}