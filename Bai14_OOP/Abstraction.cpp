/**
 * Giải phương trình bậc 2:
 * ax^2 + bx + c = 0
 * Tính delta = b^2 - 4ac
 * Nếu delta < 0; -> Phương trình vô nghiệm
 * Nếu delta = 0; Phương trình có nghiệm chung x=...
 * Nếu delta > 0; Phương trình có nghiệm    x1 = ...
 *                                          x2 = ...
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class GiaiPhuongTrinh
{
    private:
        double a;
        double b;
        double c;
        double x1;
        double x2;
        double delta;

        void tinhNghiem()
            {
                delta = b*b - 4*a*c;
                if (delta<0)
                    {
                        delta = -1;
                    }
                else if (delta==0)
                    {
                        x1 = x2 = -b/(2*a);
                    }
                else if (delta>0)
                    {
                        x1 = (-b + sqrt(delta))/(2*a);
                        x2 = (-b - sqrt(delta))/(2*a);
                    }
            }
    
    public:
        void enterNumber(double num_a, double num_b, double num_c);
        void printResult();

};

void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c)
{
    a = num_a;
    b = num_b;
    c = num_c;
}

void GiaiPhuongTrinh::printResult()
{
    tinhNghiem();
    if (delta == -1)
        {
            cout << "Phương trình vô nghiệm." << endl;
        }
    else if (delta==0)
        {
            cout << "Phương trình có nghiệm chung: " << x1 << endl;
        }
    else if (delta>0)
        {
            cout << "Phương trình có 2 nghiệm: " << endl;
            cout << "x1: " << x1 << endl;
            cout << "x2: " << x2 << endl;
        }
}

int main()
{
    GiaiPhuongTrinh phuongtrinh1;
    phuongtrinh1.enterNumber(4,8,4);
    phuongtrinh1.printResult();

    return 0;
}