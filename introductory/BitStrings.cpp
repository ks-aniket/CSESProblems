#include<iostream>
using namespace std;

#define ll long long
int main() {
    int n;
    cin >> n;

    ll mod = 1e9 + 7;

    ll i = 1;
    ll ans = 1;
    while(i++ <= n) {
        ans *= 2;
        ans = ans % mod;
    }


    cout << ans;
    
    return 0;
}