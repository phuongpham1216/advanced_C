## Class

### Declaring Object
- Trong `C++` từ khóa Class được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa và các hàm thành viên liên quan.
- ex:  
~~~C
class ClassName {
    private:
    // Các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp
    // Dữ liệu thành viên, hàm thành viên, ...
    protected:
    // Các thành phần bảo vệ (protected) tương tự như private,
    //nhưng có thể truy cập từ lớp kế thừa
    public:
    // Các thành phần công khai (public) được truy cập từ bên ngoài lớp
    // Dữ liệu thành viên, hàm thành viên, ...
    // Hàm thành viên và các phương thức khác có thể được định nghĩa tại đây
    // ...
    };
~~~

### Constructor
-   Constructor trong `C++` là một method sẽ tự động được gọi khi khởi tạo object.
-   Constructor sẽ có tên trùng với tên của class.

### Destructor
-   Destructor trong `C++` là một method được tụ động gọi khi oject giải phóng.
-   Destructor có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.

### Static keyword
- Khi một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.
- Khi một method trong class được khai báo với từ khóa static:
    + Method này độc lập với bất kỳ đối tượng nào của lớp.
    + Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại.
    + Method này có thể được truy cập bằng cách sủa dụng tên class thông qua toán tử phạm vi ::.
    + Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class.
    + Method có phạm vi bên trong class và không thể truy cập con trỏ đối tượng hiện tại.
