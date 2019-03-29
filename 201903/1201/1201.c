#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *new_node(int key)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->key = key;
    tmp->left = tmp->right = NULL;
    return tmp;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
        return new_node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

struct node *delete_node(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (root->key > key)
        root->left = delete_node(root->left, key);
    else if (root->key < key)
        root->right = delete_node(root->right, key);
    else if (root->left == NULL && root->right == NULL)
        free(root), root = NULL;
    else if (root->left != NULL && root->right == NULL)
        root = root->left;
    else if (root->left == NULL && root->right != NULL)
        root = root->right;
    else
    {
        struct node *aux = root->left;
        struct node *lst = NULL;

        while (aux->right)
            lst = aux, aux = aux->right;

        if (lst)
            lst->right = aux->left;

        aux->right = root->right;
        if (aux == root->left)
            aux->left = root->left->left;
        else
            aux->left = root->left;

        free(root), root = NULL;
        return aux;
    }

    return root;
}

int exist(struct node *root, int key)
{
    if (root == NULL)
        return 0;
    else if (root->key == key)
        return 1;

    int left = exist(root->left, key);
    int right = exist(root->right, key);
    return left + right;
}

void search(struct node *root, int key)
{
    if (exist(root, key))
        printf("%d existe\n", key);
    else
        printf("%d nao existe\n", key);
}

int f;

void print_node(int key)
{
    if (f)
        printf("%d", key), f = 0;
    else
        printf(" %d", key);
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
    char op[10];
    int key;

    struct node *root = NULL;

    while (scanf("%s", op) != EOF)
    {
        if (op[1] == '\0')
        {
            scanf("%d", &key);
            if (op[0] == 'I')
                root = insert(root, key);
            else if (op[0] == 'P')
                search(root, key);
            else if (op[0] == 'R')
                root = delete_node(root, key);
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