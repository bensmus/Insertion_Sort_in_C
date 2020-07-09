#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

// fill a preinitialized array of nodes with data
void linked_list(int *data_arr, struct node *node_arr, int arr_len)
{
    for (size_t i = 0; i < arr_len; i++)
    {
        node_arr[i].val = data_arr[i];

        if (i < (arr_len - 1))
        {
            // having our node point to the next node
            node_arr[i].next = &node_arr[i + 1];
        }
    }
}

struct node insert(struct node *ptr, int val)
{
    // insert a new node after this one (*ptr) with the following value
    struct node newnode = {val, ptr->next};
    (ptr->next) = &newnode;

    return newnode;
}

// access the node value a certain amount of nodes down the linked list
int access(struct node *ptr, int index)
{
    for (size_t i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }
    return ptr->val;
}

int main()
{
    int arr_len = 5;
    int data_arr[] = {2, 8, 3, 4, 1};
    struct node node_arr[arr_len];

    linked_list(data_arr, node_arr, arr_len);

    // making a node that will be one node down after root node
    struct node node1 = insert(&node_arr[0], -1);

    int access_index = 1;
    int number = access(node_arr, access_index);
    printf("%d\n", number);

    return 0;
}