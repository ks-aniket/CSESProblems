#include<iostream>
using namespace std;

#define ll long long

int main() {
    int T;
    cin >> T;

    while(T--) {
        ll a, b;
        cin >> a >> b;

        ll larger = (a > b ? a : b);
        ll smaller = (a < b ? a : b);


        ll diff = larger - smaller;
        // cout << "diff: " << diff << "\n";

        larger -= 2 * diff;
        if(smaller - diff < 0) {
            cout << "NO\n";
            continue;
        } else smaller -= diff;

        // cout << "l: " << larger << ", s: " << smaller << "\n";

        if(larger % 3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}