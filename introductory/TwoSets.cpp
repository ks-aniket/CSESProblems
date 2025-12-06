#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ll n;
    cin >> n;

    vector<int> a, b;
    ll A = 0, B = 0;
    
    for(int i = n; i >= 1; --i) {
        if(A > B) {
            b.push_back(i);
            B += i;
        } else {
            a.push_back(i);
            A += i;
        }
    }

    if(A == B) {
        cout << "YES\n";
        cout << a.size() << "\n";
        for(auto x : a) cout << x << " ";
        cout << "\n";
        cout << b.size() << "\n";
        for(auto x : b) cout << x << " ";
        cout << "\n";
    } else {
        cout << "NO";
    }
    
    return 0;
}