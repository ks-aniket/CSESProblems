#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
vector<string> graycode(int n) {

    if(n == 1) {
        return {"0", "1"};
    }

    vector<string> a = graycode(n-1);
    vector<string> b = a;
    reverse(b.begin(), b.end());

    // Add 0 to each string in a
    for(string& s : a) s += "0";
    for(string& s : b) s += "1";

    a.insert(a.end(), b.begin(), b.end());
    return a;
}
*/

vector<int> graycode(int n) {
    if(n == 1) {
        return {0, 1};
    }

    vector<int> a = graycode(n-1);
    vector<int> b = a;
    reverse(b.begin(), b.end());
    
    // Add 1 to each int in b
    for(int& i : b) {
        i = i*2 + 1;
    }

    a.insert(a.end(), b.begin(), b.end());

    return a;
}

void printbin(int n, int len) {
    int count = 0;

    string s = "";

    while(n) {
        s += n % 2 + '0';
        n /= 2;
        count++;
    }
    reverse(s.begin(), s.end());

    while(count++ < len) s += "0";
    cout << s << "\n";
}

int main() {
    int n;
    cin >> n;

    vector<int> vs;
    vs = graycode(n);

    for(int& i : vs) printbin(i, n);

    return 0;
}