#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mynode
{
    int val;
    struct mynode *next;
} node;

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
        printf("root_node pointer %p\n", root_node.next);
    }
    return current_node;
}

int main()
{
    node D = {3, NULL};
    node C = {2, &D};
    node B = {1, &C};
    node A = {0, &B};

    node afterA = insert(&A, -1, false);
    // [0, -1, 1, 2, 3]

    node test1 = access(A, 4);
    printf("test value %d\n", test1.val);

    printf("A points to %d\n", A.next->val);

    node test2 = access(A, 4);
    printf("test value %d\n", test2.val);

    /*
    node afterB = insert(&B, -2, false);
    // [0, -1, 1, -2, 2, 3]

    node Dclone = access(A, 5);
    printf("Dclone value %d\n", Dclone.val);
    */
    return 0;
}