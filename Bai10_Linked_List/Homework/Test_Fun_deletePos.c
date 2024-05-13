#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node
{
    int value;
    struct node* next;
}node;

int getPosition(node* array, int pos);

/*==============================================================
Funtion check List is empty

input:  dia chi cua mot list

return: 1- list empty
        0- list not empty
================================================================
*/
bool listCheckEmpty(node **array) {
    if (*array == NULL)   // if array doesn't have any node yet
        return 1;
    else
        return 0;
}

/*==============================================================
Funtion lay kich thuoc cua list

input: dia chi cua mot list

return: value (so node)
================================================================
*/
int size(node **array){ // lay kich thuoc cua list

    if(listCheckEmpty(&*array))
        {
            printf("Size = NULL - List is Empty!!!\n");
            return 0;
        }

        else                // if array has some node
        {
            int i=1;  // Dem so node
            node* p = *array;   // use p instead of array because we are using pointer, 
                                //use array will change the structure of linkedlist
            while (p->next != NULL) // which mean the current node is not the last node
            {
                p = p->next;    // continue check next node until it a last node
                i++;
            }
            printf("Size of list = %d node!!!\n", i);
            return i;
        }
} 

/*==============================================================
Tao mot Node
input:  value

output: Tao ra 1 node
return: pointer node
================================================================
*/
node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

/*==============================================================
Xoa node dau tien
input:  list (dia chi cua list)

output: Remove 1 node at begin
return: none
================================================================
*/
void popFront(node **array){    
    node * temp = *array;
    if(listCheckEmpty(&temp)) return;

    *array = temp->next;
    free(temp);
} // xoa node dau tien

/*==============================================================
Them node vao vi tri cuoi cua list
input:  list (dia chi cua list)
        value

output: List add 1 node
return: none
================================================================
*/
void pushBack(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
    
    // if (*array == NULL)   // if array doesn't have any node yet
    if(listCheckEmpty(&*array))
    {
        // List empty
        *array = temp;  // Gán node moi tao vao luon
    }

    else                // if array has some node
    {
        node* p = *array;   // use p instead of array because we are using pointer, 
                            //use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // continue check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}

/*==============================================================
Xoa node vao vi tri bat ky cua list
input:  list (dia chi cua list)
        position: vi tri node

output: remove 1 node in list
return: none
================================================================
*/
void deleteNode(node **array, int pos) {
    node *p = *array;
    int n = size(&p);
    if((pos<1)||(pos>n)) return;    //Ko xoa
    if(pos==1){
        printf("Xoa node tai vi tri dau\n");
        popFront(&p);
    }
    else{
        int i;
        for(i=1; i<pos-1;i++){
            p=p->next;
        }
        printf("dang xoa node tai vi tri: %d", i+1);
        //p : Tai pos-1
        node *temp = p->next;
        // Cho pos-1 ket noi vs pos+1
        p->next=temp->next;
        free(temp); // Xoa node tai pos
    }

} // xoa 1 node tai mot vi tri bat ky


/*==============================================================
In gia tri cac Node trong List
input:  list (dia chi cua list)

output: In ra man hinh (=printf();)
return: none
================================================================
*/
void listDisplay(node* array)
{
    node *temp = array;
    if(listCheckEmpty(&temp)) {
        printf("List chua co Node nao!\n");
        return;
    }
    else {
        int i=1;
        printf("Cac Node cua List:\n");
        while ((temp!=NULL)&&(i<10))
        {
            printf("-> Node %d = %d\n", i, temp->value);
            i++;
            temp=temp->next;
        }
        
    }
}

int main()
{
    int key;
    int value;
    int vitri;

    node* arr = NULL;

    pushBack(&arr, 2);
    pushBack(&arr, 7);
    pushBack(&arr, 4);
    pushBack(&arr, 5);
    pushBack(&arr, 3);
    pushBack(&arr, 10);

    printf("+++++++++++++++++++++++++++++++++++++++++\n");
    listDisplay(arr);
     while (1)   {
        printf("=========================================\n");
        printf("Cac lua chon thao tac voi list:\n");
        printf("------------------------------------------\n");
        printf("->>  Nhap vao <1> de thuc hien popFront - Xoa node dau tien.\n");
        printf("->>  Nhap vao <2> de thuc hien deletePos - Xoa node tai vi tri nhap vao.\n");
        printf("->>  Nhap vao <3> Thoat.\n");
        printf("=========================================\n");

        scanf("%d", &key);
        printf("Key vua nhap: %d\n", key);

        switch (key)
        {
        case 1:
            printf("Lua chon \"popFront\".\n");
            popFront(&arr);
            printf("-----------------------------------------\n");
            listDisplay(arr);
            break;
        case 2:
            printf("Lua chon xoa node - Nhap vao vi tri can xoa.\n");
            scanf("%d", &vitri);
            deleteNode(&arr, vitri);
            printf("-----------------------------------------\n");
            listDisplay(arr);
            break;
        case 3:
            return 0;
            break;
        default:
            printf("Lua chon khong phu hop!\n");
            break;
        }
        
     }
    return 0;
}
