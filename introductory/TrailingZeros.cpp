#include<iostream>
using namespace std;

#define ll long long
int main() {
    ll n;
    cin >> n;

    int fives = 0;
    int fact = 5;
    int quot;

    while(n / fact != 0) {
        quot = n / fact;
        fives += quot;
        fact *= 5;
    }

    cout << fives;
    return 0;
}