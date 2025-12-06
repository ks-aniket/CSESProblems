#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n, -1);
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        v[num-1]++;
    }

    for(int i = 0; i < n; i++) {
        if(v[i] == -1) cout << (i+1);
    }
    return 0;
}