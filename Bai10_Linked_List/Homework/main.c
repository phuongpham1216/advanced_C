#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node
{
    int value;
    struct node* next;
}node;

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
            return 0;
        }

        else                // if array has some node
        {
            int i=0;  // Dem so node
            node* p = *array;   // use p instead of array because we are using pointer, 
                                //use array will change the structure of linkedlist
            while (p->next != NULL) // which mean the current node is not the last node
            {
                p = p->next;    // continue check next node until it a last node
                i++;
            }

            return i=i+1;
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
Them node vao phia truoc cua list
input:  list (dia chi cua list)
        value (gia tri cua node)

output: List add 1 node at begin
return: none
================================================================
*/

void push_front(node **array, int value){ 

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
        temp->next = *array;     // change it next member point to address of new node have just create
        *array = temp;  // Gán node moi tao vao luon
    }
} // them 1 node vao phia truoc

/*==============================================================
Xoa node dau tien
input:  list (dia chi cua list)

output: Remove 1 node at begin
return: none
================================================================
*/
void pop_front(node **array){    
    node * temp;
    temp = *array;
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
void push_back(node** array, int value)
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
Xoa node tai vi tri cuoi cua list
input:  list (dia chi cua list)

output: List remove 1 node
return: none
================================================================
*/
void pop_back(node** array)
{
    node* p, * temp;
    p = *array; // use p instead of array because we are using pointer, 
                //use array will change the structure of linkedlist

    // while (p->next->next != NULL)     // free the last node in the list
    while (p->next->next != NULL)   //Kiem tra dia chi tai next cua next (con cho cua node tiep thep)
    {
        p = p->next;
    }

    temp = p->next;
    p->next = NULL;
    free(temp);

}

/*==============================================================
Doc gia tri cua node dau tien
input:  list (dia chi cua list)

output: none
return: Value of node begin
================================================================
*/
int front(node *array){
    int value = array->value;
    return value;

} // lay gia tri cua node dau tien

/*==============================================================
Doc gia tri cua node cuoi cung
input:  list (dia chi cua list)

output: none
return: Value of node end
================================================================
*/
int back(node *array){
    int value;
    node* p, * temp;
    p = array; // use p instead of array because we are using pointer, 
                //use array will change the structure of linkedlist

    while (p->next!= NULL)
    {
        p = p->next;
    }

    value = p->value;
    return value;
} // lay gia tri cua node cuoi cung

/*==============================================================
Doc gia tri cua node tai mot vi tri
input:  list (dia chi cua list)
        position (vi tri)

output: none
return: Value of node
================================================================
*/
int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

// Home Work

// void push_front(node **array, int value); // them 1 node vao phia truoc
// void pop_front(node **array); // xoa node dau tien
// int front(node *array); // lay gia tri cua node dau tien
// int back(node *array); // lay gia tri cua node cuoi cung

void insert(node **array, int value, int pos); // them 1 node vao mot vi tri bat ky
void deletee(node **array, int pos); // xoa 1 node tai mot vi tri bat ky

// int size(node **array); // lay kich thuoc cua list

// bool listCheckEmpty(node **array); // kiem tra list co rong hay khong


//



int main()
{
    int i, indexNode;
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);
    
    indexNode = size(&arr);
    printf("so node cua list = %d\n", indexNode);

    for(i=0; i<indexNode; i++){
        printf("Value test: %d\n", get(arr, i));
    }
    // printf("Value test: %d\n", get(arr, 2));
    // printf("Value test: %d\n", get(arr, 0));
    // printf("Value test: %d\n", get(arr, 5));

    // pop_back(&arr);

    // indexNode = size(&arr);
    // printf("so node cua list = %d\n", indexNode);

    // for(i=0; i<indexNode; i++){
    //     printf("Value test: %d\n", get(arr, i));
    // }

    // push_front(&arr, 50);

    // indexNode = size(&arr);
    // printf("so node cua list = %d\n", indexNode);

    // for(i=0; i<indexNode; i++){
    //     printf("Value test: %d\n", get(arr, i));
    // }

    pop_front(&arr);

    indexNode = size(&arr);
    printf("so node cua list = %d\n", indexNode);

    for(i=0; i<indexNode; i++){
        printf("Value test: %d\n", get(arr, i));
    }

    printf("Gia tri dau tien cua list = %d\n",front(arr));

    push_back(&arr, 200);

    printf("Gia tri cuoi cung cua list = %d\n",back(arr));
    
	return 0;
}
