#include <stdio.h>
#include <setjmp.h>


typedef enum {
    DivideByZero = 1,
    Divide_10,
    OtherError
} Error_id;

jmp_buf buf;
int exception_code;
char *error_code = NULL;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, warning)       \
        error_code = warning;   \
        longjmp(buf, (x));


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

    int a = 90;
    int b = 8;
    double result = 0.0;

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
        error_code=NULL;
    }

    return 0;
}
