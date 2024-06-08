#include <iostream>

using namespace std;

class SmartPtr {
    private:
        int* ptr;

    public:
        SmartPtr(int* p = NULL) {ptr = p; }
        ~SmartPtr() { delete (ptr); }

        // Overloading dereferencing operator
        int& operator*() { return *ptr; }

        int getValue() {
            return *ptr;
        }

        void setValue(int value) {
            *ptr = value;
        }
};

int main() {
    
    SmartPtr ptr(new int);

    // *ptr = 20;
    ptr.setValue(50);
    
    cout << "Value: " << ptr.getValue() << endl;
    cout << "Value: " << *ptr << endl;

    return 0;
}