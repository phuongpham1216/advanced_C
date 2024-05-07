#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Hàm để truy cập node đầu tiên trong danh sách
struct Node* getFirstNode(struct Node* anyNodeInList) {
    struct Node* current = anyNodeInList;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

int main() {
    // Tạo danh sách liên kết
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Truy cập node đầu tiên
    struct Node* firstNode = getFirstNode(node1);

    // In giá trị của node đầu tiên
    printf("Gia tri cua node dau tien: %d\n", firstNode->data);

    return 0;
}
