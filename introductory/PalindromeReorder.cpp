#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    string s;
    cin >> s;

    unordered_map<char, ll> m;
    for(char c : s) m[c] = (m[c] ? m[c] + 1 : 1);

    string pdrome(s);
    ll size = pdrome.size();

    ll i = 0;
    int oddcount = 0;
    for(auto pair : m) {
        if(pair.second % 2 != 0) {
            oddcount++; 
            pdrome[size/2] = pair.first;
            pair.second--;
        }


        for(ll j = 0; j < (pair.second/2); j++) {
            pdrome[i] = pair.first;
            pdrome[size-i-1] = pair.first;
            i++;
        }
        
        if(oddcount > 1) {
            cout << "NO SOLUTION";
            return 0;
        }
    }


    cout << pdrome;


    return 0;
}