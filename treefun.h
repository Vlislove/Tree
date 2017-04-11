#include <stdio.h>
#include <stdlib.h>
#define N 1000
typedef struct t {
    int value;
    struct t* left;
    struct t* right;
} tree;

int add(int value, tree** root) {
    if(*root == NULL){
        *root = (tree*)malloc(sizeof(tree));
        if(*root == NULL){
            printf("first");
            return -1;
        }
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;

        return 0;
    }
    if(value == ((*root)->value)){
        printf("second");
        return -1;
    }
    if(value < ((*root)->value)){
        return add(value, (&(*root)->left));
    }
    else{
        return add(value, (&(*root)->right));
    }
}


void free_tree(tree* root){
    if(NULL != root){
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int max(int fir, int sec){
    int Max;
    if(fir > sec){
        Max = fir;
    }
    else{
        Max = sec;
    }
    return Max;
}

int height(tree* root){
    if(NULL == root){
        return 0;
    }
    return max(height(root->left), height(root->right))+1;
    }

void tests(){
    tree* root;
    int i;
    int error;
    error = 0;
    root = NULL;
    for(i = 1; i < N; i++) {
        add(i, &root);
        if (-1 == add(i, &root)) {
            error = 1;
            break;
        }
    }
    int h = height(root);
    printf("  %d\n  ",h);
    if(!error){
        int h = height(root);
        printf("%d\n",h);
    }
    free_tree(root);
}

//Уже АВЛ
int insert(tree** root, int key, int value){
    if(NULL == (*root)){
        *root = (tree*)malloc(sizeof(tree));
        if(NULL == (*root)){
            return 0;
        }
    *root->key = key;
    *root->value = value;
    *root->left = NULL;
    *root->right = NULL;
    return 1;
    }

    if(*root->key == key){
        return 0;
    }

    if(*root->key < key){
        return insert(&(*root->left), key, value);
    }
    else{
        return insert(&(root->right), key, value);
    }
}
