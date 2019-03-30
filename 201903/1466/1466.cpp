#include <iostream>
#include <queue>

using namespace std;

struct node
{
    node(int _key)
    {
        key = _key;
        left = right = NULL;
    }

    int key;
    struct node *left, *right;
};

struct node *insert(node *root, int key)
{
    if (root == NULL)
        return new node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void print_tree(node *root)
{
    queue<node *> q;
    q.push(root);
    bool f = true;

    while (!q.empty())
    {
        node *n = q.front();
        q.pop();

        cout << (f ? "" : " ") << n->key, f = false;
        if (n->left)
            q.push(n->left);
        if (n->right)
            q.push(n->right);
    }
}

int main(void)
{
    int c, n, i, x;

    struct node *root = NULL;

    cin >> c;

    for (i = 1; i <= c; i++)
    {
        root = NULL;
        cin >> n;

        while (n--)
        {
            cin >> x;
            root = insert(root, x);
        }

        cout << "Case " << i << ":" << endl;
        print_tree(root);
        cout << endl << endl;
    }

    return 0;
}