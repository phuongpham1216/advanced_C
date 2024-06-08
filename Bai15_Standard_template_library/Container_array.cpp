#include <iostream>
#include <array>

using namespace std;

int main()
{
    array <int, 5> arr = {2, 3, 1, 7, 6};
    if(arr.empty()) {
        cout << "Array is empty" << endl;
    }
    else {
        cout << "Array it not empty" << endl;
    }

    cout << "------------------" << endl;
    for(int i=0; i<arr.size(); i++) {
        cout << "Value: " << arr[i] << endl;
    }

    cout << "------------------" << endl;
    for(int i=0; i<arr.size(); i++) {
        cout << "Value: " << arr.at(i) << endl;
    }

    return 0;
}