#include<iostream>
using namespace std;

int main() {

    string s;

    cin >> s;

    char curr = s[0];
    int freq = 0, largest = 1;
    for(char c : s) {
        if(curr == c) freq += 1;
        else {
            freq = 1;
            curr = c;
        }
        if(freq > largest) largest = freq;
    }

    cout << largest;
    return 0;
}