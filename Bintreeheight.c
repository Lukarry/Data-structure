#include <stdio.h>
#include <stdlib.h>

typedef struct tree *Bintree;
struct tree {
    char val;
    Bintree left;
    Bintree right;
};
Bintree createtree() {
    char ch;
    scanf(" %c", &ch); // 跳过空白字符
    if (ch == '#') return NULL;

    Bintree P = (Bintree)malloc(sizeof(struct tree));
    if (!P) {
        printf("Memory allocation failed!\n");
        exit(1); // 内存分配失败，直接退出程序
    }
    P->val = ch;
    P->left = createtree();
    P->right = createtree();
    return P;
}

int accumlateleaf(Bintree bt) {
    if (bt) {
        if (!bt->left && !bt->right)
            return 1;
        return accumlateleaf(bt->left) + accumlateleaf(bt->right);
    }
    return 0;
}

int Height(Bintree bt) {
    if (bt) {
        int HL = Height(bt->left);
        int HR = Height(bt->right);
        return (HL > HR ? HL : HR) + 1;
    }
    return 0;
}

void freeTree(Bintree bt) {
    if (bt) {
        freeTree(bt->left);
        freeTree(bt->right);
        free(bt);}
}

int main() {
    Bintree bt = NULL;
    bt = createtree();
    int leaf = accumlateleaf(bt);
    int H = Height(bt);
    printf("The number of leaves is: %d\n", leaf);
    printf("The height of the tree is: %d\n", H);
    freeTree(bt);
    return 0;
}
