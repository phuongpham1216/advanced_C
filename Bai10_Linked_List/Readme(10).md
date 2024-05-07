## Linked List

### 1.  Khái niệm.

-   Linked list là một cấu trúc dữ liệu trong lập trình máy tính.
-   Được sử dụng để tổ chức và lưu trữ dữ liệu.
-   Một linked list bao gồm một chuỗi các "nút" `node`.
-   Mỗi nút chứa một giá trị dữ liệu và một con trỏ `pointer` đến nút tiếp theo trong chuỗi.

### 2.  Đặt vấn đề.

-   Giả sử có mảng các phần tử như sau:
    ```C
    int arr[] = {2, 7, 4, 5, 3};
    ```
-   Và nó được lưu trong bộ nhớ tại các ô như sau:
    ![phần tử mảng](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/arr_1.jpg)

-   Vấn đề đặt ra là cần xóa đi một phần tử thứ 2 ` arr[1] ` có địa chỉ `0x05` như hình dưới.
    ![xóa phần tử thứ 2](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/XoaPhanTuThu2_arr.jpg)
-   Các bước thực hiện như sau:  
    1   Xóa giá trị tại ô nhớ `0x05`.
        ![xóa phần tử buoc1](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/XoaPhanTuThu2_Buoc1.jpg)  
    2   Coppy giá trị tại ô nhớ `0x09`, sang ô nhớ `0x05`, coppy giá trị tại ô nhớ `0x0D` sang ô nhớ `0x09`, và coppy giá trị tại ô nhớ `0x11` sang ô nhớ `0x0D`.
        ![xóa phần tử buoc2](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/XoaPhanTuThu2_Buoc2.jpg)  
    3   Xóa giá trị tại ô nhớ `0x11` và giải phóng nó.
        ![xóa phần tử buoc3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/XoaPhanTuThu2_Buoc3.jpg)  
    4   Mảng mới nhận được còn 4 phần tử:
        ![xóa phần tử kết quả](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/XoaPhanTuThu2_KetQua.jpg)  
-   Và sau đó nếu cần chèn thêm một giá trị vào vị trí thứ 3 của mảng như sau:
    ![Chèn vào phẩn tủ thứ 3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3.jpg)  
-   Thì các bước thực hiện là:
    1   Lấy thêm một ô nhớ tiếp theo có địa chỉ `0x11`.
        ![Chèn vào phần tử thứ 3 buoc 1](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3_Buoc1.jpg)  
    2   Coppy giá trị tại ô nhớ `0x0D` sang ô nhớ `0x11`. Tiếp theo coppy giá trị tại ô nhớ `0x09` sang ô nhớ `0x0D`.
        ![Chèn vào phần tử thứ 3 buoc 2](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3_Buoc2.jpg)  
    3   Xóa giá trị tại ô nhớ thứ 3 có địa chỉ `0x09`.
        ![Chèn vào phần tử thứ 3 buoc 3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3_Buoc3.jpg)  
    4   Ghi giá trị cần thêm vào ô nhớ thứ 3 tại địa chỉ `0x09`. Sẽ nhận được một mảng mới có giá trị như sau:
        ![Chèn vào phần tử thứ 3 buoc 3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3_KetQua.jpg)  
    