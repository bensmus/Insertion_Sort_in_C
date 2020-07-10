#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct node insert(struct node *ptr, int val, bool insert_root)
{
    if (!insert_root)
    {
        // make a new node that points to the one that ptr points to
        struct node newnode = {val, ptr->next};

        // change the one that ptr points to
        (ptr->next) = &newnode;

        return newnode;
    }

    else
    {
        // make a node that points to ptr... that's it!
        struct node newnode = {val, ptr};
        return newnode;
    }
}

// access the node value a certain amount of nodes down the linked list
int access(struct node *ptr, int index)
{
    printf("entering access\n");
    for (size_t i = 0; i < index; i++)
    {
        printf("currently on %d\n", ptr->val);
        ptr = ptr->next;
    }
    return ptr->val;
}

int main()
{
    int len = 3;
    int data_arr[] = {-1, 2, 0};
    struct node node_arr[len];
    linked_list(data_arr, node_arr, len);
    printf("%d\n", access(node_arr, 2));

    // group 1
    struct node a_node = insert(&node_arr[0], 999, false);
    printf("%d\n", access(&node_arr[0], 3));
    

    // group 2
    struct node root_node = insert(&node_arr[0], -6, true);
    printf("%d\n", access(&root_node, 3));
    
    // each of the groups can execute fine on its own, but when
    // together, they cause segfault

    return 0;
} 