#include<iostream>
#include<functional>
#include<bits/stdc++.h>
#include<random>
#include<chrono>
using namespace std;

#define MIN 10
#define MAX 1e3

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

vector<vector<int>> test_cases() {
    int num_test_cases = 4;
    vector<int> num_inputs = {10, 100, 1000, 10000};

    // Obtain a random seed from the hardware
    random_device rd;
    // Init the standard generator (Mersenne Twister)
    mt19937 gen(rd());
    // Define the range
    uniform_int_distribution<> distr(MIN, MAX);
   

    vector<vector<int>> inputs(num_test_cases, vector<int>());

    for(int i = 0; i < num_test_cases; i++) {
        for(int j = 0; j < num_inputs[i]; j++) {
            inputs[i].push_back(distr(gen));
        }
    }

    return inputs;
}

bool check(
    function<vector<int>(vector<int>)> func, 
    vector<int>& input,
    const vector<int>& sorted
) {
    vector<int> ret = func(input);

    if(ret.size() != input.size()) return false;

    for(int i = 0; i < ret.size(); i++) {
        if(ret[i] != sorted[i]) return false;
    }

    return true;
}


// vector<int> merge_sort(vector<int> v) {

// }


// vector<int> quick_sort(vector<int> v) {

// }


vector<int> ins_sort(vector<int> v) {
    for(int i = 1; i < v.size(); i++) {
        for(int j = i; j >= 0; j--) {
            if(v[j] < v[j-1]) swap(v[j], v[j-1]);
        }
    }

    return v;
}


vector<int> sel_sort(vector<int> v) {
    int min, minIndex;
    for(int i = 0; i < v.size()-1; i++) {
        min = v[i], minIndex = i;
        for(int j = i+1; j < v.size(); j++) {
            if(v[j] < min) {
                min = v[j];
                minIndex = j;
            }

        }
        swap(v[i], v[minIndex]);
    }
    return v;
}


void format(
    function<vector<int>(vector<int>)> func, 
    vector<int> input, 
    vector<int> sorted,
    string sort_type
) {
    bool success;

    cout << "\t" << sort_type << ": ";
    auto start = chrono::high_resolution_clock::now();
    success = check(func, input, sorted);
    auto stop = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::microseconds>(stop - start);
    if(success) {
        cout << "\t✅Passed " << dur.count() /1000.0 << "ms\n";
    } else {
        cout << "\t❌Failed\n\n";
    }

}

void test() {
    vector<vector<int>> inputs = test_cases();

    vector<int> sorted;

    cout << "Inputs are randomly generated between " << MIN << " and " << MAX << "\nTimes in miliseconds\n\n";

    for(vector<int> input : inputs) {
        sorted = input;
        sort(sorted.begin(), sorted.end());

        cout << "Number of Inputs: " << input.size() << "\n";
        format(sel_sort, input, sorted, "Selection Sort");
        format(ins_sort, input, sorted, "Insertion Sort");
        // format(merge_sort, input, sorted, "Merge Sort");
        // format(quick_sort, input, sorted, "Quick Sort");

        cout << "\n";
    }

}


int main() {
    test();
    return 0;
}
