#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
// using next_permutation() method from cpp

*/

void createString(vector<int> v, vector<string>& perms, string poss, const size_t& n) {
    if(poss.size() == n) {
        perms.push_back(poss);
        return;
    }
    for(int i = 0; i < 26; i++) {

        if(v[i] > 0) {
            v[i]--;
            createString(v, perms, poss + char('a' + i), n);
            v[i]++;
        }
    }
}

int main() {
    vector<int> v(26, 0);
    string s;
    cin >> s;
    for(char c : s) v[c - 'a']++;

    string poss = "";
    vector<string> perms;

    createString(v, perms, poss, s.size());

    cout << perms.size() << "\n";
    for(auto s : perms) cout << s << "\n";


    return 0;
}