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
    1,  Xóa giá trị tại ô nhớ `0x05`.
        ![xóa phần tử buoc1](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/XoaPhanTuThu2_Buoc1.jpg)  
    2,  Coppy giá trị tại ô nhớ `0x09`, sang ô nhớ `0x05`, coppy giá trị tại ô nhớ `0x0D` sang ô nhớ `0x09`, và coppy giá trị tại ô nhớ `0x11` sang ô nhớ `0x0D`.
        ![xóa phần tử buoc2](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/XoaPhanTuThu2_Buoc2.jpg)  
    3,  Xóa giá trị tại ô nhớ `0x11` và giải phóng nó.
        ![xóa phần tử buoc3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/XoaPhanTuThu2_Buoc3.jpg)  
    4,  Mảng mới nhận được còn 4 phần tử:
        ![xóa phần tử kết quả](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/XoaPhanTuThu2_KetQua.jpg)

-   Và sau đó nếu cần chèn thêm một giá trị vào vị trí thứ 3 của mảng như sau:
    ![Chèn vào phẩn tủ thứ 3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3.jpg)  
-   Thì các bước thực hiện là:

    1,  Lấy thêm một ô nhớ tiếp theo có địa chỉ `0x11`.
        ![Chèn vào phần tử thứ 3 buoc 1](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3_Buoc1.jpg)  
    2,  Coppy giá trị tại ô nhớ `0x0D` sang ô nhớ `0x11`. Tiếp theo coppy giá trị tại ô nhớ `0x09` sang ô nhớ `0x0D`.
        ![Chèn vào phần tử thứ 3 buoc 2](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3_Buoc2.jpg)  
    3,  Xóa giá trị tại ô nhớ thứ 3 có địa chỉ `0x09`.
        ![Chèn vào phần tử thứ 3 buoc 3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3_Buoc3.jpg)  
    4,  Ghi giá trị cần thêm vào ô nhớ thứ 3 tại địa chỉ `0x09`. Sẽ nhận được một mảng mới có giá trị như sau:
        ![Chèn vào phần tử thứ 3 buoc 3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/ChenVaoPhanTuThu3_KetQua.jpg)  

-   Và tương tự thế, nếu mảng dữ liệu mà có nhiều phần tử hơn chẳng hạn 1000 phần tử thì...

    Các bước xóa một phần tử:
    ![Mang 1000 phan tu xoa](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Mang1000_Xoa1.jpg)
    ![Mang 1000 phan tu xoa](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Mang1000_Xoa2.jpg)
    ![Mang 1000 phan tu xoa](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Mang1000_Xoa3.jpg)
    ![Mang 1000 phan tu xoa](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Mang1000_Xoa4.jpg)

    Các bước thêm một phần tử:
    ![Mang 1000 phan tu them](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Mang1000_Them1.jpg)
    ![Mang 1000 phan tu them](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Mang1000_Them2.jpg)
    ![Mang 1000 phan tu them](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Mang1000_Them3.jpg)
    ![Mang 1000 phan tu them](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Mang1000_Them4.jpg)

### 3.  Linked list
-   Như các ví dụ ở trên ta nhận thấy, sử dụng mảng để lưu các giá trị, sau đó cần thêm một phần tử nào đó, hoặc xóa bớt đi một số phần tử, thì quá trình diễn ra phức tạp và tốn thời gian xử lý.
-   Để giải quyết vấn đề đó thì Linked list được sử dụng.
-   So với cấu trúc của mảng, Linked list là một mảng các cấu trúc dữ liệu như sau:
    ![Linked List 1](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Linked_list_1.jpg)
-   Các node được liên kết vói nhau bằng các cho con trỏ của node thứ nhất trỏ đến địa chỉ ô nhớ đầu tiên của node thứ 2:
    ![Linked List 2](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Linked_list_2.jpg)
-   Và tiếp theo con trỏ của node thứ 2 lại trỏ đến ô nhớ đầu tiên của node thứ 3:
    ![Linked List 3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Linked_list_3.jpg)
-   Node cuối cùng của Linked list thì con trỏ sẽ có giá trị `NULL`.
    ![Linked List 4](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Linked_list_4.jpg)

-   Và nếu cần thêm một node vào cuối của Linked list. Cấp phát thêm một không gian nhớ tương đương với một node. Và cho con trỏ cuối của Linked list trỏ tới địa chỉ đầu tiên của node mới, con trỏ trong node mới có giá trị `NULL`.
    ![Linked List them node cuoi list](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Linked_list_Them_Node_Cuoi_List.jpg)
    ![Linked List them node cuoi list 2](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Linked_list_Them_Node_Cuoi_List_2.jpg)

-   Ví dụ chèn một node có địa chỉ `0xa3` vào vị trí thứ 2 của list:
    ![List chen node vao vi tri thu 2_1](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/List_Chen_Vi_Tri_Thu_2_1.jpg)  
        Cấp phát vùng nhớ cho một node, có địa chỉ `0xa3`.
    ![List chen node vao vi tri thu 2_2](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/List_Chen_Vi_Tri_Thu_2_2.jpg)
        Cho con trỏ của node trước vào địa chỉ `0xa3`, gán con trỏ của node mới bằng giá trị của node phía sau `0xef`.
    ![List chen node vao vi tri thu 2_3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/List_Chen_Vi_Tri_Thu_2_3.jpg)

-   Ví dụ xóa một node tại vị trí thứ 1 của list:
    ![Xoa not tai vi tri thu 1 cua list 1](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Xoa_Node_Tai_Vi_Tri_Thu_1_List_1.jpg)
        Gắn giá trị của `node 0 = 0xa3` để trỏ sang vị trí node 2.
    ![Xoa not tai vi tri thu 1 cua list 2](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Xoa_Node_Tai_Vi_Tri_Thu_1_List_2.jpg)
        Giải phóng vùng nhớ của node thứ 1.
    ![Xoa not tai vi tri thu 1 cua list 3](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Xoa_Node_Tai_Vi_Tri_Thu_1_List_3.jpg)
        Kết quả được một list mới.
    ![Xoa not tai vi tri thu 1 cua list 4](https://github.com/phuongpham1216/advanced_C/blob/main/Bai10_Linked_List/Practice/Slide/Xoa_Node_Tai_Vi_Tri_Thu_1_List_4.jpg)
    
