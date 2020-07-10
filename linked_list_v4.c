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
    int arr_len = 5;
    int data_arr[] = {2, 8, 3, 4, 1};
    struct node node_arr[arr_len];

    linked_list(data_arr, node_arr, arr_len);

    // making a node that will be one node down after root node
    struct node a_node = insert(&node_arr[0], -1, false);

    // current state of linked list should be {2, -1, 8, 3, 4, 1}

    int access_index = 5;
    int number99 = access(&node_arr[0], access_index);
    printf("%d\n", number99);

    // making a node that will become the root node
    struct node root_node = insert(&node_arr[0], -99, true);

    // current state of linked list should be {-99, 2, -1, 8, 3, 4, 1}

    int number4 = access(&root_node, access_index);
    printf("%d\n", number4);

    return 0;
}