#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mynode 
{
    int val;
    struct mynode *next;
} node;

// fill a preallocated array of nodes with data
void linked_list(int *data_arr, node *node_arr, int arr_len)
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

node insert(node *ptr, int val, bool insert_root)
{
    if (!insert_root)
    {
        // make a new node that points to the one that ptr points to
        node newnode = {val, ptr->next};

        // change the one that ptr points to
        (ptr->next) = &newnode;

        return newnode;
    }

    else
    {
        // make a node that points to ptr... that's it!
        node newnode = {val, ptr};
        return newnode;
    }
}

// access the node value a certain amount of nodes down the linked list
// we are modifying stuff!! THIS IS BAD!!!
int access(node *ptr, int index)
{
    printf("entering access\n");
    for (size_t i = 0; i < index; i++)
    {
        printf("currently on %d\n", ptr->val);
        ptr = ptr->next;
    }
    return ptr->val;
}

node next(node a_node)
{
    return *(a_node.next);
}


int main()
{
    int len = 3;
    int data_arr[] = {-1, 2, 0};  // passing an arrya is confusing, use struct
    node node_arr[len];
    linked_list(data_arr, node_arr, len);
    printf("%d\n", access(node_arr, 2));

    // group 1
    node a_node = insert(&node_arr[0], 999, false);
    printf("%d\n", access(&node_arr[0], 3));

    // expecting linked list to be {-1, 999, 2, 0}
    

    // group 2
    node b_node = insert(&node_arr[0], -6, false);
    printf("%d\n", access(&node_arr[0], 3));

    // expecting linked list to be {-1, -6, 999, 2, 0}
    
    // getting logical errors
    // unable to access next elements in linked list

    return 0;
} 