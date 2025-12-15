#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void createString(vector<int> v, vector<string>& perms, string poss, size_t n, int& count) {
    if(poss.size() == n) {
        perms.push_back(poss);
        count++;
        return;
    }
    for(int i = 0; i < 26; i++) {

        if(v[i] > 0) {
            v[i]--;
            createString(v, perms, poss + char('a' + i), n, count);
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
    int count = 0;
    vector<string> perms;

    createString(v, perms, poss, s.size(), count);

    cout << count << "\n";
    for(auto s : perms) cout << s << "\n";


    return 0;
}