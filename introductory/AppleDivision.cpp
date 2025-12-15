#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<ll> args(n, -1);
    for(int i = 0; i < n; i++) cin >> args[i];

    vector<ll> a;
    vector<ll> b;
    ll sum_a = 0, sum_b = 0;

    for(int i = 0; i < n; i++) {
        if(sum_a > sum_b) {
            b.push_back(args[i]);
            sum_b += args[i];
        }
        else {
            a.push_back(args[i]);
            sum_a += args[i];
        }
    }

    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << "\n";
    for(int i = 0; i < b.size(); i++) cout << b[i] << " ";
    cout << "\n";

    cout << abs(sum_a - sum_b);

    return 0;
}