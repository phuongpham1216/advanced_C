#include <iostream>

using namespace std;

template <typename A, typename B>

class AddExpr {
    private:
        const A& a;
        const B& b;

    public:
        AddExpr(const A& a, const B& b) : a(a), b(b) {}
        int eval() const {
            return a + b;
        }
};

template <typename A, typename B>
AddExpr<A, B> add(const A& a, const B& b) {
    return AddExpr<A, B> (a, b);
}

int main() {

    int x = 5, y = 3;

    auto expr = add(x, y);
    cout << "Result: " << expr.eval() << endl;  // Result: 8

    return 0;
}