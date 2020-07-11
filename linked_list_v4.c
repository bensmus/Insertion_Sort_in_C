#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mynode
{
    int val;
    struct mynode *next;
} node;

// fill a preinitialized array of nodes with data
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
        current_node = next(root_node);
        root_node = current_node;
    }
    return current_node;  
}

int main()
{
    int arr_len = 5;
    int data_arr[] = {2, 8, 3, 4, 1};
    node node_arr[arr_len];

    linked_list(data_arr, node_arr, arr_len);

    // making a node that will be one node down after root node
    node a_node = insert(&node_arr[0], -1, false);

    // current state of linked list should be {2, -1, 8, 3, 4, 1}

    int access_index = 5;
    node node1 = access(node_arr[0], access_index);  // expecting 1
    printf("Value of node1: %d\n", node1.val);

    // making a node that will become the root node
    node b_node = insert(&node_arr[0], -99, false);

    // current state of linked list should be {-99, 2, -1, 8, 3, 4, 1}

    node node4 = access(root_node, access_index);  // expecting 4
    printf("%d\n", node4.val);

    return 0;
}