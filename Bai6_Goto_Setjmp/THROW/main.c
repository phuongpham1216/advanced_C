#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h> // Để sử dụng hàm free
#include <string.h> // Để sử dụng hàm strlen và strcpy

jmp_buf buf;
int exception_code;
char *error_code = NULL;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, warning)       \
        error_code = warning;   \
        longjmp(buf, (x));
        

typedef enum {
    DivideByZero = 1,
    Divide_10,
    OtherError
} Error_id;

// /// from main.i
// double divide(int a, int b) {
//     if (b == 0) {
//         error_code = "test cai";
//         longjmp(buf, (DivideByZero));
//     }
//     return (double)a / b;
// }

// ///


double divide(int a, int b) {
    if (b == 0) {
        THROW(DivideByZero, "Khong duoc chia cho 0");
    }
    else if (b==10) {
        THROW(Divide_10, "Dang thuc hien phep chia cho 10");
    }
    return (double)a / b;
}

int main() {
    // error_code = "Test thu xem nao, them chuoi!";
    // printf("%s\n", error_code);
    int a = 90;
    int b = 0;
    double result = 0.0;

    // /// from main.i
    // if ((exception_code = setjmp(buf)) == 0) {
    //     result = divide(a, b);
    //     printf("Result: %f\n", result);
    // } else if (exception_code == (DivideByZero)) {
    //     printf("Error message: %s\n", error_code);
    // }
    // ///

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(DivideByZero) {
        printf("%s\n", error_code);
    } CATCH(Divide_10) {
        printf("%s\n", error_code);
    }

    // Các xử lý khác của chương trình

    // Giải phóng bộ nhớ cho error_code nếu cần
    if (error_code != NULL) {
        free(error_code);
    }

    return 0;
}
