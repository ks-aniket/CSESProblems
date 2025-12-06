#include<iostream>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll m, n;
        cin >> m >> n;

        // 0-indexed grid;
        m--, n--;

        ll greater = (m > n ? m : n);
        ll diagVal = 1 + (greater * (greater + 1));

        ll diffFactor;
        // increase vertically if the diagonal indices are even 
        if(greater % 2 == 0) diffFactor = 1;
        else diffFactor = -1;

        ll rowDiff = (greater - m) * diffFactor;
        ll colDiff = (greater - n) * (-1 * diffFactor);

        ll result = diagVal + rowDiff + colDiff;

        cout << result << "\n";
    }
    return 0;
}