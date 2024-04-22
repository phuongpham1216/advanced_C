#include <stdio.h>
#include <setjmp.h>

typedef enum {
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CACULATION_ERROR,
    OTHER_ERROR
} Error_id;

jmp_buf buf;
int exception_code;
char *error_message = NULL;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, warning)       \
        error_message = warning;   \
        longjmp(buf, (x));


void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation() {
    // Bổ sung chương trình
    printf("Dang ket noi mang...\n");
    THROW(NETWORK_ERROR, "Loi ket noi, khong ket noi duoc.");
}

void calculateData() {
   // Bổ sung chương trình
    printf("Dang tinh toan...\n");
    THROW(CACULATION_ERROR, "Loi tinh toan, Data khong hop le.");
}


int main() {
    TRY {
    read_File:
        readFile();
    network_Operation:
        networkOperation();
    calculation_Data:
        calculateData();
    }   CATCH(FILE_ERROR) {
            printf("%s\n", error_message);
            goto network_Operation;
        } // Bổ sung thêm nhiều CATCH
        CATCH(NETWORK_ERROR) {
            printf("%s\n", error_message);
            goto calculation_Data;
        }
        CATCH(CACULATION_ERROR) {
            printf("%s\n", error_message);
            // goto read_File;
        }
}

