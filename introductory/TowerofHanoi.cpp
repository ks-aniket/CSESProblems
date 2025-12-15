#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(
    int n, 
    u_int& count, 
    vector<pair<int, int>>& trans, 
    int a, 
    int b,
    int c
) 
{

    if(n > 1)
        towerOfHanoi(n-1, count, trans, a, c, b);

    trans.push_back({a, b});
    count++;

    if(n > 1)
        towerOfHanoi(n-1, count, trans, c, b, a);

}

int main() {
    int n;
    cin >> n;

    u_int count = 0;
    int a = 1, b = 3, c = 2;
    vector<pair<int, int>> transitions;
    towerOfHanoi(n, count, transitions, a, b, c);

    cout << count << "\n";
    for(pair<int, int> p : transitions)
        cout << p.first << " " << p.second << "\n";

    return 0;
}