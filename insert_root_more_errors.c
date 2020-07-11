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

node next(node a_node)
{
    return *(a_node.next);
}

node access(node root_node, int index)
{
    printf("Entering access\n");
    node current_node = root_node;
    for (size_t i = 0; i < index; i++)
    {
        printf("%d\n", current_node.val);
        current_node = next(current_node);
    }
    return current_node;  
}

int main()
{
    int len = 5;
    int data_arr[] = {-1, 2, 0, 4, 9};  
    node node_arr[len];
    linked_list(data_arr, node_arr, len);
    
    printf("Access result: %d\n", access(node_arr[0], 4).val);
    
    node a_node = insert(&node_arr[0], -99, false);
    // {-1, -99, 2, 0, 4, 9}

    node node9 = access(node_arr[0], 5);
    printf("Access result: %d\n", node9.val);

    node b_node = insert(&node_arr[3], 111, false);
    // {-1, -99, 2, 0, 4, 111, 9}

    node node111 = access(node_arr[0], 5);
    printf("Access result: %d\n", node111.val);

    return 0;
} 