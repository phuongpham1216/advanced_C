#include <iostream>

using namespace std;

class HinhChuNhat {
public:
	double ChieuDai;
	double ChieuRong;

	double dienTich() {
		return ChieuDai * ChieuRong;
	}
};
int main() {
	HinhChuNhat hinh1;
	hinh1.ChieuDai = 10.0;
	hinh1.ChieuRong = 5.0;
	std::cout << "Dien Tich Hinh Chu Nhat: " << hinh1.dienTich() << endl;
	return 0;
}