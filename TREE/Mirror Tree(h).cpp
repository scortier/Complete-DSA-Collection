
// Write your code here

#include<stdio.h>

#include<malloc.h>

struct node {

    int data;

    struct node *left;

    struct node *right;

};

struct node *root = NULL;

struct node *tree_build[1001] = {NULL};




struct node *insert_val(int parent[], int child[], char ch[], int i) {

    if (tree_build[child[i]] == NULL) {

        tree_build[child[i]] = (struct node *)malloc(sizeof(struct node));

        tree_build[child[i]]->data = child[i];

        tree_build[child[i]]->left = tree_build[child[i]]->right = NULL;

    }

    if (tree_build[parent[i]] == NULL)

        insert_val(parent, child, ch, parent[i]);




    struct node *p = tree_build[parent[i]];

    if (ch[i] == 'R')

        p->right = tree_build[child[i]];

    else

        p->left = tree_build[child[i]];

    return root;

}

int mirror_sub(struct node *p, struct node *q, int num) {

    if (p == NULL || q == NULL)

        return -1;

    if (p->data == num)

        return q->data;

    else if (q->data == num)

        return p->data;

    int res = mirror_sub(p->left, q->right, num);

    if (res > 0)

        return res;

    return mirror_sub(p->right, q->left, num);

}




int mirror(struct node *root, int num) {

    if (root->data == num)

        return num;

    return mirror_sub(root->left, root->right, num);

}

int main() {

    int n, q;

    scanf("%d%d", &n, &q);

    int parent[n], child[n];

    char dir[n];

    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = 1;

    new_node->left = new_node->right = NULL;

    root = new_node;

    tree_build[1] = root;

    for (int i = 1; i < n; i++) {

        scanf("%d%d ", &parent[i], &child[i]);

        scanf("%c", &dir[i]);

    }

    for (int i = 1; i < n; i++)

        insert_val(parent, child, dir, i);

    // preorder(root);

    for (int i = 0; i < q; i++) {

        scanf("%d", &n);

        printf("%d\n", mirror(root, n));

    }

    return 0;

}