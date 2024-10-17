#include<stdio.h>
#include<stdlib.h>
//将指向结构体struct Tree的指针命名为Bintree
typedef struct Tree *Bintree;
typedef int Element;
//创建结构体
struct Tree{
    Element val;
    Bintree left;
    Bintree right;
};
//创建二叉树
Bintree createBintree(){
    Bintree bt=NULL;
    char ch;
    scanf("%c",&ch);
    if(ch!='#'){
        bt=(Bintree)malloc(sizeof(struct Tree));
        bt->val=ch;
        bt->left=createBintree();
        bt->right=createBintree();
    }
    return bt;
}
void Preorder(Bintree BT){
    if(BT){
        printf("%c",BT->val);
        Preorder(BT->left);
        Preorder(BT->right);
    }

}
void Inorder(Bintree BT){
    if(BT){
        Inorder(BT->left);
        printf("%c",BT->val);
        Inorder(BT->right);
    }

}
void postorder(Bintree BT){
    if(BT){
        postorder(BT->left);
        postorder(BT->right);
        printf("%c",BT->val);

    }
}
int main() {
    Bintree tree = createBintree();
    printf("Pre-order:");
    Preorder(tree);
    printf("\n");
    printf("in-order:");
    Inorder(tree);
    printf("\n");
    printf("post-order:");
    postorder(tree);
}
