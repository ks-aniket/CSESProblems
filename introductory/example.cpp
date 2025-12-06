#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    unordered_set<int> s1 = {1, 2, 3, 4};

    for(auto i : s1) {
        if(i == 2) {
            s1.erase(i);
            s1.insert(5);
        }
    }

    for(auto i : s1) cout << i << " ";

    return 0;
}