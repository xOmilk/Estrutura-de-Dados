#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int data;
    struct no *left;
    struct no *right;
} Node;

Node *insert(Node *head, int element)
{
    Node *new = (Node *)malloc(sizeof(Node));

    new->data = element;
    new->right = NULL;
    new->left = NULL;

    if (head == NULL)
    {
        head = new;
    }
    return head;
}
