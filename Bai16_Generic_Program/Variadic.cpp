#include <iostream>

using namespace std;

// void print1() {
//     cout << endl;
// }

// template <typename T, typename... Rest>

// void print1(T first, Rest... rest) {
//     cout << first << endl;
//     print1(rest...);
// }

template <typename... Args>
void print(Args... args) {
    (cout << ... << args) << endl;
}

int main() {
    print(1, 2, 3, 4, "Hello", 4.5, "Trung", 3.15);
    return 0;
}