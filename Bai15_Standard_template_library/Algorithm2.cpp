#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector <int> arr1 = {2, 5, 7, 4, 9};

    auto it = find(arr1.begin(), arr1.end(), 3);

    if(it!=arr1.end()) {
        cout << "Đã tìm thấy! " << endl;
    }
    else {
        cout << "Không tìm thấy! " << endl;
    }


    return 0;
}