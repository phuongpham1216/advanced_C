## Bài 14: OOP

### Encapsulation

- Tính đóng gói (Encapsulation) là ẩn đi các property "mật" khỏi người dùng.
- Và để làm được điều này, ta sẽ khai báo các property ở quyền truy cập private (Tức là không thể truy cập trực tiếp tới các property này).
- Trong trường hợp ta muốn đọc hoặc ghi các property này, thì ta cung cấp các method ở quyền truy cập public.

### Inheritance

- Tính kế thừa (Inheritance) là khả năng sử dụng lại các property và method của một class trong một class khác.
- Ta chia làm 2 loại class cha và class con.
- Để kế thừa từ class khác, ta dùng ký tự ":".
- Tất cả những property và method có quyền truy cập là public và protected ở class cha sẽ được class con kế thừa.
- Có 3 kiểu kế thừa là public, private và protected.
- Những property và method được kế thừa từ class cha sẽ nằm ở quyền truy cập của class con tương ứng với kiểu kế thừa.

### Polymorphism

- Tính đa hình (Polymorphism) có nghĩa là "nhiều dạng", và nó sảy ra khi chúng ta có nhiều class liên quan với nhau thông qua tính kế thừa.
- Tính đa hình là cách dùng những method được kế thừa để thực hiện các tác vụ khác nhau. Điều này giúp chúng ta thể hiện một hành động theo nhiều cách khác nhau. (Function overriding)
- Function overloading cung cấp nhiều định nghĩa cho một function bằng cách thay đổi số lượng input parameter, kiểu dữ liệu của input parameter.

### Abstraction

- Tính trừu tượng đề cập đến việc ẩn đi các chi tiết cụ thể của một đối tượng.
- Và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.