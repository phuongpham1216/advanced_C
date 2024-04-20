# advanced_C
## Bài 1: Compiler - Macro
## Bài 2: STDARG - ASSERT
## Bài 3: Pointer

  Trong ngôn ngữ lập trình C, Con trỏ `pointer` dùng để chứa địa chỉ bộ nhớ của một biến, hàm ...
___
### Biến con trỏ
___
  - Khai báo `int *ptr` : Thêm dấu * trước tên biến.
  - Con trỏ `ptr` là một biến. Nhưng nó lưu giá trị là địa chỉ.
  - Ép kiểu con trỏ.
  ~~~~C
  int *ptr = (int *)0x12233;
  ~~~~
  `*ptr` Lấy `giá trị` tại `địa chỉ` của con trỏ ptr.
  -eg:  
  ~~~C
  #include <stdio.h>

      int main (int argc, char const *argv[])
      {
          int var = 10;

      printf("Dia chi var: %p\n", &var);

          int *ptr = &var;

      printf("Dia chi con tro ptr: %p\nGiá trị con trỏ ptr: %d\n", ptr, *ptr);
          return 0;
      }
  ~~~
  ~~~
  Dia chi con tro ptr: 000000d7619ff8f4
  Giá trị con trỏ ptr: 10
  ~~~

  ~~~C
  int var = 10;
  int *ptr = &var;
  //Hai câu lệnh tương đương:
  printf("Dia chi con tro ptr: %p\nGiá trị con trỏ ptr: %d\n", ptr, *ptr);
  // Và
  printf("Dia chi con tro ptr: %p\nGiá trị con trỏ ptr: %d\n", ptr,*(&var));,
  ~~~

___
### Con trỏ hàm
___

eg:  
~~~C
void (*pheptoan)(int, int) = &tong;
pheptoan(7,9);
~~~
- Khai báo con trỏ hàm.
- Kiểu trả về `void`
- Tham số truyền vào `int`, `int`. Viết `(int, int)` là cách rút gọn của `(int a, int b)` cách viết tường minh.
- Gán giá trị của một đối tượng `pheptoan = &tong;` hoặc `pheptoan = tong;`
- Con trỏ hàm phép toán trỏ đến hàm `tong` và truyền tham số vào hàm `tong`.

Ứng dụng:
- Làm input parameter của hàm khác. (Thêm ví dụ: .. )

### Con trỏ void
Trỏ được đến các địa chỉ, int, char, float, ...
Sử dụng cần phải ép kiểu.
~~~C
int i;
void *ptr = &i;
printf("Gia tri con tro: %d\n", *(int *)ptr);
~~~
> Cú pháp viết:
>*(int *)ptr;
> - Dấu * - Lấy giá trị tại địa chỉ con trỏ trỏ đến.
> - (int *) - Ép kiểu con trỏ void về kiểu int.
> - ptr - Tên con trỏ.

___
Ép kiểu con trỏ hàm:

~~~C
void tong(int a, intb){
  printf("Tong %d va %d: %d\n", a, b, a+b);
}

void main(){
  void *ptr;
  ptr = &tong;
  ((void (*)(int, int))ptr)(8, 9);
}
~~~
~~~C
> ptr : Tên con trỏ.  
> ()ptr : () Ép kiểu con trỏ.  
> (void (*))ptr: void (*) Ép kiểu con trỏ hàm void, nên không đặt tên.  
> (void(*)(int,int))ptr: (int, int): Đối số truyền vào.  
> (void(*)(int,int))ptr: Đây là con trỏ hàm.  
> ((void(*)(int,int))ptr)(8, 9): Truyền tham số cho nó (8, 9).  
~~~

- "Thêm ví dụ void *array[]?


## Bài 4: Memory layout
  Chương trình main.exe (Trên windown), main.hex (nạp vào vi điều khiển), được lưu trong ổ cứng hoặc Flash của vi điều khiển. Khi nhấn "run" chương trình (trên window) hoặc cấp nguồn cho vi điều khiển. Thì những chương trình này được copy vào Ram để thực thi.
### Text segment
  - Chứa mã máy, tập hợp các lệnh thực thi chương trình.
  - Có quyền đọc, không có quyền ghi.
  - Lưu hằng số, con trỏ kiểu 'char'.
  - Chỉ thu hồi khi kết thúc chương trình
### Data segment
  Initiazed Data segment (Dữ liệu đã khởi tạo)
    - Chứa các biến toàn cục được khởi tạo với giá trị khác 0.
    - Chứa các biến static được khởi tạo với giá trị khác 0.
    - Các biến đều có quyền truy cập đọc và ghi.
    - Tất cả các biến được thu hồi sau khi chương trình kết thúc    
### Bss segment
  Uninitialized Data segment (Dữ liệu chưa khởi tạo)
    - Chứa các biến toàn cục được khởi tạo với giá trị bằng 0, hoặc không gán giá trị.
    - Chứa các biến static được khởi tạo với giá trị bằng 0, hoặc chưa gán giá trị.
    - Các biến đều có quyền truy cập đọc và ghi.
    - Tất cả các biến được thu hồi khi chương trình kết thúc.
### Stack
  - Chứa các biến cục bộ, tham số truyền vào.
  - Có thể đọc và ghi giá trị của biến khi chương trình chạy.
  - Sau khi ra khỏi hàm, sẽ thu hồi vùng nhớ.

  - Vùng nhớ được quản lý bới hệ điều hành.
  - Dữ liệu được lưu trong Stack sẽ tự động giải phóng khi hàm thực hiện xong.
  - Bộ nhớ Stack cố định, nếu chương trình sử dụng vượt quá khả năng lưu trữ của Stack sẽ sảy ra tình trạng tràn bộ nhớ (Stack overflow). Các trường hợp sảy ra như khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn...
### Heap
  - Vùng nhớ cấp phát động:
      + Dùng cấp phát bộ nhớ động trong quá trình thực thi chương trình
      + Điều này cho phép tạo ra và giải phóng vùng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chương trình chạy.
      + Các hàm như malloc(), calloc(), realloc(), và free() được dùng để cấp phát và giải phóng bộ nhớ trên Heap.
  - Vùng nhớ Heap được quản lý bởi lập trình viên trong C, hoặc C++.
  - Dữ liệu trong vùng Heap không tự hủy khi hàm thực hiện xong. Mà lập trình viên phải tự giải phóng vùng nhớ bằng câu lệnh free (trong C) và delete hoặc delete[] (Trong C++). Nếu không sẽ sảy ra hiện tượng rò rỉ bộ nhớ.
  - Nếu liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.

## Bài 5 Extern - Static - Volatile - Register

### Extern:
 - eg:
      ```C
      extern int var;
      extern void delay (void);
      ```
 - Khai báo biến đã được sử dụng, tại một nơi khác, file khác. Giúp chương trình hiểu được biến, hoặc hàm đã được khai báo và sự ở một vị trí khác.

### Static
  - Static local variables: Sử dụng với biến cục bộ, biến khai báo bên trong hàm. Để nó giữ lại giá trị qua các lần gọi hàm. Và phạm vi của biến chỉ trong hàm đó.
  - Static global variables: Sử dụng với biến toàn cục, biến khai báo bên ngoài hàm. Nó hạn chế phạm vi của biến chỉ sử dụng trong file nguồn hiện tại. Ứng dụng để thiết kế các file thư viện.
  
### Volatile
  - Từ khóa trong C. Được sử dụng cho biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình.
  - Ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã định nghĩa.

### Regiter
  - Từ khóa sử dụng chỉ ra biến được sử dụng thường xuyên.
  - Biến có thể được lưu trữ trong thanh ghi chứ không phải trong bộ nhớ Ram.
  - Mục đích tăng tốc độ truy cập.
  - ***Lưu ý:*** Việc sử dụng Register chỉ là một đề xuất cho trình biên dịch. Và không đảm bảo rằng biến được lưu trữ trong thanh ghi. Trong thực tế trình biên dịch có thể quyết định không tuân thủ đề xuất này.