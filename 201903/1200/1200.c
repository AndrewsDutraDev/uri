#include <stdio.h>
#include <stdlib.h>

struct node
{
    char key;
    struct node *left, *right;
};

struct node *new_node(char key)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->key = key;
    tmp->left = tmp->right = NULL;
    return tmp;
}

struct node *insert(struct node *root, char key)
{
    if (root == NULL)
        return new_node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

int exist(struct node *root, char key)
{
    if (root == NULL)
        return 0;
    else if (root->key == key)
        return 1;

    int left = exist(root->left, key);
    int right = exist(root->right, key);
    return left + right;
}

void search(struct node *root, char key)
{
    if (exist(root, key))
        printf("%c existe\n", key);
    else
        printf("%c nao existe\n", key);
}

int f;

void print_node(char key)
{
    if (f)
        printf("%c", key), f = 0;
    else
        printf(" %c", key);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        print_node(root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        print_node(root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void posorder(struct node *root)
{
    if (root != NULL)
    {
        posorder(root->left);
        posorder(root->right);
        print_node(root->key);
    }
}

int main(void)
{
    char op[10], key[2];

    struct node *root = NULL;

    while (scanf("%s", op) != EOF)
    {
        if (op[1] == '\0')
        {
            scanf("%s", key);
            if (op[0] == 'I')
                root = insert(root, key[0]);
            else if (op[0] == 'P')
                search(root, key[0]);
        }
        else if (op[0] == 'I')
            f = 1, inorder(root), printf("\n");
        else if (op[1] == 'R')
            f = 1, preorder(root), printf("\n");
        else if (op[1] == 'O')
            f = 1, posorder(root), printf("\n");
    }

    return 0;
}