#include <iostream>
#include <memory>

using namespace std;

class HinhChuNhat {
    private:
        int ChieuDai;
        int ChieuRong;

    public:
        HinhChuNhat(int dai, int rong) {
            ChieuDai = dai;
            ChieuRong = rong;
            cout << "Constructor called. " << endl;

        }

        void tinhDienTich() {
            cout << "Dien tich: " << ChieuDai * ChieuRong << endl;
        }

        ~HinhChuNhat() {
            cout << "Destructor called. " << endl;
        }
};

int main() {

    unique_ptr <HinhChuNhat> ptr1(new HinhChuNhat(10, 5));
    cout << "----ptr1--------" << endl;
    (*ptr1).tinhDienTich();

    //unique_ptr <HinhChuNhat> ptr2(ptr1); // Khong cho phep

    unique_ptr <HinhChuNhat> ptr2 = move(ptr1); // gan object HinhChuNhat(10, 5) cho ptr2,
                                                // sau do remove ptr1
    cout << "----ptr2--------" << endl;
    (*ptr2).tinhDienTich();
    // cout << "----ptr1--------" << endl;
    // (*ptr1).tinhDienTich();
    // cout << "----ptr2--------" << endl;
    (*ptr2).tinhDienTich();


    return 0;
}