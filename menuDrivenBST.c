#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root -> left);
        printf("%d\t", root -> key);
        inorder(root -> right);
    }
}

struct node* insert(struct node* node, int key) {
    if(node == NULL) {
        return newNode(key);
    }
    if(key < node -> key) {
        node -> left = insert(node -> left, key);
    }
    else if(key > node -> key) {
        node -> right = insert(node -> right, key);
    }
    return node;
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while(current && current -> left != NULL) {
        current = current -> left;
    }
    return current;
}

struct node* deleteNode(struct node* root, int key) {
    if(root == NULL) {
        return root;
    }
    if(key < root -> key) {
        root -> left = deleteNode(root -> left, key);
    }
    else if(key > root -> key) {
        root -> right = deleteNode(root -> right, key);
    }
    else {
        if(root -> left == NULL) {
            struct node* temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL) {
            struct node* temp = root -> left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root -> right);
        root -> key = temp -> key;
        root -> right = deleteNode(root -> right, temp -> key);
    }
    return root;
}

int main() {
    int choice, val;
    struct node* root = NULL;
    printf("Binary Search Tree using Linked List\n");
    while(1) {
        printf("\nChoose an option:\n1. Insert an element\n2. Delete an element\n3. Display the tree (inorder traversal)\n4. Exit\n\nYour choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            }
            case 2: {
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            }
            case 3: {
                inorder(root);
                printf("\n");
                break;
            }
            case 4: {
                exit(0);
            }
        }
    }
    return 0;
}