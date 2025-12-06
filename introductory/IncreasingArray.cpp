#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    long long moves = 0;
    for(int i = 1; i < n; i++) {
        long long diff = v[i-1] - v[i];
        if(diff > 0) {
            v[i] += diff;
            moves += diff;
        }
        // cout << moves << " ";
    }

    cout << moves;
    return 0;
}