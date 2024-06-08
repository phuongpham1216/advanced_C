## Bài 15: Standard Template Library
-   Standard Template Library (STL) là một thư viện trong ngôn ngũ lập trình C++
-   Cung cấp một tập hợp các template và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến.
-   STL đã trở thành một phần quan trọng của ngôn ngữ lập trình C++ và làm cho việc lập trình trở nên mạnh mẽ, linh hoạt và hiệu quả.
-   Một số thàn phần chính của STL:
    +   Container
    +   Iterator
    +   Algorithms
    +   Function

### Container
-   Một container là một cấu trúc dữ liệu chứa nhiều phần tử theo một cách cụ thể.
-   STL cung cấp một số container tiêu biểu giúp lưu trữ và quản lý dữ liệu.
-   Các container:
    +   Vector
    +   List
    +   Map
    +   Array

#### Vector
-   Vector là một trong những container quan trọng nhất trong STL của C++.
-   Nó cung cấp một mảng động với khả năng thay đổi kích thước linh hoạt.
-   Một số đặc điểm chính của vector:
    +   Vector là một mảng động, tức là có khả năng thay đổi kích thước một cách linh hoạt.
    +   Truy cập ngẫu nhiên: Việc truy cập các phần tử của vector có thể được thực hiện bằng cách sử dụng chỉ số.
    +   Hiệu suất chèn và xóa: Chèn và xóa phần tử ở cuối vector có hiệu xuất tốt. Tuy nhiên chèn và xóa ở vị trí bất kỹ có thể đòi hỏi di chuyển một số phần tử.

-   Một số method của vector:
    +   at(): Truy cập vào phần tử của vector
    +   size(): Trả vể kích thước của vector
    +   resize(): Thay đổi kích thước của vector
    +   begin(): Địa chỉ phẩn tử đầu tiên của vector
    +   end(): Địa chỉ phần tử cuối cùng của vector
    +   push_back(): Thêm phần tử vào vị trí cuối cùng của vector

#### List
-   List là một container trong STL của C++, triển khai dưới dạng danh sách liên kết hai chiều.
-   Dưới đây là một số đặc điểm của list:
    +   Truy cập tuần tự: Truy cập các thành phần của list chỉ có thể thực hiện tuần tự, không hỗ trợ truy cập ngẫu nhiên.
    +   Hiệu suát chèn và xóa: Chèn và xóa ở bất kỳ vị trí nào trong danh sách có hiệu suất tốt hơn so với vector. Điều này đặc biệt đúng khi thêm, xóa ở giữa danh sách.
-   Một số method của list:
    +   push_back():
    +   pop_back():
    +   insert(): Chèn một node vào list
    +   erase(): Xóa một node của list
    +   size(): Trả về kích thước của list


**  Sử dụng vector khi:  
    -   Cần truy cập ngẫu nhiên đến các phần tử.  
    -   Thực hiện nhiều thao tác chèn, xóa ở cuối danh sách.  
    -   Dung lượng có thể biết trước, hoặc thay đổi ít.  
  
    
**  Sử dụng list khi:    
    -   Thực hiện nhiều thao tác chèn, xóa ở bất kỳ vị trí nào trong danh sách.  
    -   Cần thực hiện nhiều thao tác chèn, xóa mà không làm ảnh hưởng đến các iterator hiện có.  
    -   Dung lượng không quan trọng hoặc thay đổi thường xuyên.  
  
**  Tùy thuộc vào yêu cầu cụ thể của vấn đề, để chọn sử dụng std::vector hoặc std::list.  


 #### Map
 -  Map là một container trong STL của C++, cung cấp một cấu trúc dữ liệu ánh xạ key-value.
 -  Map lưu trữ các phần tử dưới dạng cặp key-value, trong đó mỗi key phải là duy nhất trong map.
 -  Ta có thêm phần tử mới vào trong map bằng cách sử dụng operator[], hoặc hàn insert().
 -  Để xóa phần tử, bạn sử dụng hàm arase().
 -  Ta có thể sử dụng iterator để duyệt qua các phần tủ của map.
 

 #### Array
 -  Array là một container có kích thước cố định, và có sẵn trong thư viện STL của C++.
 -  Array có kích thước cố định được xác định tài thời điểm biên dịch và không thể thay đổi sau khi được khai báo.
 -  Array hỗ trợ truy cập ngẫu nhiên vào các phần tử thông qua toán tử [].
 
#### Iterator
-   Iterator cung cấp một cách chung để duyệt qua các phần tử của một container mà không cần biết chi tiết về cách container được triển khai.
-   Iterator là một đối tượng cho phép truy cập tuầ tự qua các phẩn tử của một container.
-   Nó giống như con trỏ, cho phép di chuyển qua các phần tử trong container.

#### Algorithm
-   Thư viện STL cung cấp một số thuật toán tiêu biểu thông qua algorithm.
-   Các thuật toán này hoạt động trên các phạm vi hoặc các lọai dữ liệu khác nhau, giúp thực hiện các như:
    +   Sắp xếp
    +   Tìm kiếm
    +   Chuyển đổi dữ liệu
    +   ...
