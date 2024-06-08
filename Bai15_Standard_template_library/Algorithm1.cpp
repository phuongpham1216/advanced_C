#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector <int> arr = {3, 5, 7, 4, 1};

    cout << "-------------------------" << endl;
    for (auto const var:arr) {
        cout << "Vector: " << var << endl;
    }

    cout << "-------------------------" << endl;
    cout << "-Vector after sort ascending-" << endl;
    sort(arr.begin(), arr.end());
    for (auto const var:arr) {
        cout << "Vector: " << var << endl;
    }

    cout << "-------------------------" << endl;
    cout << "-Vector after sort descending-" << endl;
    sort(arr.begin(), arr.end(), greater<int>());
    for(auto const var:arr) {
        cout << "Vector: " << var << endl;
    }

    return 0;
}