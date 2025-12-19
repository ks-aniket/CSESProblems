#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
// Another solution using masks
*/
int n;
ll answer = LONG_LONG_MAX;
vector<ll> vals;

void minDiff(int index, ll X, ll Y) {
    if(index == n) {
        answer = min(answer, abs(X - Y));
        return;
    }

    minDiff(index+1, X + vals[index], Y);
    minDiff(index+1, X, Y + vals[index]);
}

int main() {
    cin >> n;
    vals = vector<ll>(n, 0);
    for(int i = 0; i < n; i++) cin >> vals[i];
    minDiff(0, 0, 0);

    cout << answer;

    return 0;
}