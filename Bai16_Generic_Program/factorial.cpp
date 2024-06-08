#include <iostream>

using namespace std;

template <unsigned int n>

struct Factorial {
    enum {
        value = n * Factorial<n-1>::value
    };
};

template <>
struct Factorial<0> {
    enum {
        value = 1
    };
};

int main() {
    cout << "Factorial of 5 is: " << Factorial<5>::value << endl;
    return 0;
}