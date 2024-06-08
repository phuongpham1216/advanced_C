## Bài 16: Generic Programming

### Function template
-   Trong C++, function templates là một tính năng mạnh mẽ giúp viết các function hoặc class chung có thể được sử dụng cho nhiều kiểu dữ liệu khác nhau mà không cần phải triển khai nhiều phiên bản của cùng một function hoặc class

```C
    template <typename T>
    T myFunction(T a, T b) {
        return a+b;
    }

    int result1 = myFunction(5, 10);    // Tự động suy luân T là int
    double result2 = myFunction(3.14, 2.71); // Tự động suy luận T là double
```

### Class template
-   Class templates trong C++ là một khái niệm tương tự như function templates, nhưng được áp dụng cho class thay vì function.
-   Class templates cho phép bạn viết một lớp chung mà có thể sử dụng với nhiều kiểu dữ liệu khác nhau.


### Advanced template techniques
1.  Metaprogramming:
    -   Mục đích: Tính toán giai thừa tại thời điểm biên dịch.
2.  Expression Template
    -   Thực hiện phép cộng đơn giản giữa hai số nguyên.
3.  Variadic Templates
    -   Mục đích tạo một hàm có thể chấp nhận số lượng tham số đầu vào không xác định.