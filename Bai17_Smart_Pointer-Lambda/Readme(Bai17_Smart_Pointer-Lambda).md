## Bài 17: Smart Pointer - Lambda

### Cấp phát động trong C++
-   new và delete là hai toán tử quan trọng trong C++
-   Được sủ dụng để cấp phát và giải phóng bộ nhớ động tương ứng
-   Các toán tử này thường được sử dụng khi làm việc với đối tượng được cấp phát động, như là đối tượng được tạo trong vùng nhớ heap.

```C
    int *ptr = new int; // Cấp phát bộ nhớ động cho một biến kiểu int
    int *arr = new int[5]; // Cấp phát bộ nhớ cho một mảng kiểu int với 5 phần tử

    delete ptr; // Giải phóng bộ nhớ của biến động.
    delete[] arr; // Giải phóng bộ nhớ của mảng động.
```

### Smart Pointer
-   Trong C++, smart pointer là một cơ chế quản lý bộ nhớ tự động
-   Giúp giảm thiểu rủi ro của lỗi liên quan đến quản lý bộ nhớ
-   Giúp người lập trình quên giải phóng bộ nhớ đã được cấp phát.

### Unique Pointer // Con trỏ duy nhất.
-   Unique_ptr là một loại smart pointer trong C++.
-   Giúp quản lý bộ nhớ động và tự động giải phóng bộ nhớ khi không còn cần thiết.
-   Đặc điểm chính của unique_ptr là một unique_ptr chỉ có thể sở hữu một đối tượng hoặc mảng.
-   Và khi một unique_ptr bị hủy, bộ nhớ của đối tượng sẽ tự động được giải phóng.

### Shared Pointer // Con trỏ dùng chung.
-   shared_ptr là một smart poiter khác trong C++.
-   Giúp quản lý bộ nhớ động.
-   Điểm đặc biệt của shared_ptr là sử dụng một bộ đếm tham chiếu để theo dõi số lượng shared_ptr đang tham chiếu đến một đối tượng.
-   Và chỉ giải phóng khi không còn shared_ptr nào tham chiếu đến nó.

### Weak Pointer // Con trỏ yếu.
-   weak_ptr là một cơ chế giữ tham chiếu yếu (weak reference) đến một đối tượng được quản lý bởi shared_ptr.
-   Nó cung cấp một cách an toàn để theo dõi một đối tượng mà không tăng bộ đếm tham chiếu của shared_ptr.
-   weak_ptr không trực tiếp truy cập đến đối tượng (object) mà nó theo dõi.
-   weak_ptr có một phương thức là lock(), mà trả về một shared_ptr.
-   Nếu shared_ptr mà weak_ptr theo dõi vẫn tồn tại, lock() sẽ trả về một shared_ptr hợp lệ có thể truy cập đối tượng.
-   Ngược lại, nếu shared_ptr đã bị giải phóng, lock() sẽ trả về một shared_ptr rỗng.


### Lambda
-   Lambda là một tính năng mạnh mẽ được thêm vào ngôn ngữ lập trình C++ từ phiên bản C++11.
-   Lambda cho phép định nghĩa hàm ngắn gọn (anonymous function) mà không cần phải viết một hàm riêng biệt.
-   Cú pháp của Lambda rất linh hoạt và có thể được sử dụng để viết mã ngắn gọn và dễ đọc.
```C
[capture](parameters) -> return_type {
    // function body
}
```
-   Capture: Cho phép bắt giữ biến từ môi trường xung quanh vào lambda.
    +   []: Không bắt giữ bất kỳ biến nào từ môi trường xung quanh.
    +   [var]: Bắt giữ biến var theo giá trị.
    +   [&var]: Bắt giữ biến var theo tham chiếu.
    +   [=]: Bắt giữ tất cả các biến theo giá trị.
    +   [&]: Bắt giữ tất cả các biến theo tham chiếu.

-   Parameters (parameters): Tương tự như định nghĩa hàm, có thể bao gồm các tham số của lambda.
-   Return type (return_type): Kiểu dữ liệu trả về của lambda. Có thể bị bỏ qua nếu không cần.
-   Function body: Đặt trong dấu ngoặc nhọn {} và chứa mã nguồn thực thi của lambda.
