#include<stdio.h>
#include<stdlib.h>
typedef struct Node *Tree;
typedef
struct Node{
    char val;
    Tree left;
    Tree right;
};
Tree createtree(){
    Tree bt=NULL;
    char ch;
    scanf("%c",&ch);
    if(ch!='#'){
    bt=(Tree)malloc(sizeof(struct Node));
    bt->val=ch;
    bt->left=createtree();
    bt->right=createtree();
    }
    return bt;
}
void levelorder(Tree bt){
    if(bt){
        Tree queue[100];
        int front=0,rear=0;
        queue[rear++]=bt;
        while(front<rear){
            Tree current=queue[front++];
            printf("%c",current->val);
            if(current->left){
                queue[rear++]=current->left;
            }
            if(current->right){
                queue[rear++]=current->right;
            }
        }
    }

}
int main(){
    Tree bt=createtree();
    printf("level-order:");
    levelorder(bt);
}
