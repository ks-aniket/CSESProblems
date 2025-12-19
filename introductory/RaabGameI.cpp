#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void raab() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;

    if((x == 0 && y != 0) || (x != 0 && y == 0)) {
        cout << "NO";
        return;
    }

    if((x + y) > n) {
        cout << "NO";
        return;
    }

    cout << "YES\n";
    int commons = (n - (x + y));
    int start = (n - x + 1 - commons);

    for(int i = 0; i < x; i++) {
        cout << start++ << " ";
    }

    for(int i = 1; i <= y; i++) {
        cout << i << " ";
    }

    for(int i = start; i <= n; i++) {
        cout << i << " ";
    }

    cout << "\n";

    for(int i = 1; i <= n; i++) {
        cout << i << " ";
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        raab();
        cout << "\n";
    }
}