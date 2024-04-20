#include <stdio.h>

void tong(int a, int b){
    printf("Tong cua %d va %d: %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("Hieu cua %d va %d: %d\n", a, b, a-b);
}

void tich(int a, int b){
    printf("Tich cua %d va %d: %d\n", a, b, a*b);
}

void thuong(int a, double b){
    printf("Thuong cua %d va %f: %f\n", a, b, a/b);
}

void tinhtoan(void (*pheptoan)(int,int), int a, int b){
    printf("Thuc hien phep toan\n");
    pheptoan(a, b);
}
int main (int argc, char const *argv[])
{
    void (*pheptoan)(int, int);
    void (*Test)(int, double);
    pheptoan = tong;
    pheptoan(7,9);
    pheptoan = hieu;
    pheptoan(3,8);
    pheptoan = tich;
    pheptoan(3,5);
    Test = thuong;
    Test(7,3.3);
    tinhtoan(&tong, 9, 22);
    tinhtoan(&hieu, 1, 10);
    tinhtoan(&tich, 2, 55);
    return 0;
}