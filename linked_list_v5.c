#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mynode
{
    int val;
    struct mynode *next;
} node;

/*
node insert(node *ptr, int val, bool insert_root)
{
    if (!insert_root)
    {
        // make a new node that points to the one that ptr points to
        node newnode = {val, ptr->next};

        // change the one that ptr points to
        (ptr->next) = &newnode;  // THIS IS THE PROBLEM!!!
        return newnode;
    }

    else
    {
        // make a node that points to ptr... that's it!
        node newnode = {val, ptr};
        return newnode;
    }
}
*/
void insert(node *oldptr, node *newptr, bool insert_root)
{
    if (!insert_root)
    {
        newptr->next = oldptr->next;
        oldptr->next = newptr;
    }

    else
    {
        newptr->next = oldptr;
    }
}

int access(node root_node, int index)
{
    node current_node = root_node;
    for (size_t i = 0; i < index; i++)
    {
        current_node = *(current_node.next);
    }
    return current_node.val;
}

int main()
{
    node D = {3, NULL};
    node C = {2, &D};
    node B = {1, &C};
    node A = {0, &B};

    node afterA = {-1, };
    insert(&A, &afterA, false);

    printf("POINTERS after standard insertion\n");
    printf("A points to %d\n", A.next->val);
    printf("afterA points to %d\n", afterA.next->val);
    printf("B points to %d\n", B.next->val);
    printf("C points to %d\n", C.next->val);

    int three = access(A, 4);
    printf("The number three: %d\n", three);

    node root = {100, };
    insert(&A, &root, true);

    printf("POINTERS after root insertion\n");
    printf("root points to %d\n", root.next->val);
    printf("A points to %d\n", A.next->val);
    printf("afterA points to %d\n", afterA.next->val);
    printf("B points to %d\n", B.next->val);
    printf("C points to %d\n", C.next->val);

    int hundred = access(root, 0);
    printf("The number hundred: %d\n", hundred);

    return 0;
}