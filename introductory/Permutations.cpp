#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    int num = (n % 2 != 0 ? n : n-1);
    while(num >= 1) {
        cout << num << " ";
        num -= 2;
    }
    // Make it even
    num = n/2 * 2; 
    while(num >= 2) {
        cout << num << " ";
        num -= 2;
    }

    
    
    return 0;
}