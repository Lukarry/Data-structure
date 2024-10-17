#include <stdio.h>
#include <stdlib.h>

typedef struct SNode *stack;
typedef int Element;
#define MAXSIZE 100

struct SNode {
    Element val[MAXSIZE];
    int top;
};

// 创建一个栈的初始化函数
stack createStack() {
    stack newStack = (stack)malloc(sizeof(struct SNode));
    newStack->top = -1; // 初始化栈顶指针为-1，表示栈空
    return newStack;
}

// 入栈
void push(stack Ptrl, Element data) {
    if (Ptrl->top == MAXSIZE - 1) {
        printf("Stack overflow error\n");
    } else {
        Ptrl->val[++(Ptrl->top)] = data;
    }
}

// 出栈
Element pop(stack Ptrl) {
    if (Ptrl->top == -1) {
        printf("Stack underflow error\n");
        return -1; // 返回一个错误值，表示栈空
    } else {
        return Ptrl->val[(Ptrl->top)--];
    }
}

// 主函数示例
int main() {
    FILE *fo,*fp;
    Element data,temp;
    stack myStack = createStack();
    fo=fopen("C:\\Users\\lukarry\\Documents\\workspace\\CLionProjects\\untitled186\\cmake-build-debug\\input.txt","r");
    fp=fopen("C:\\Users\\lukarry\\Documents\\workspace\\CLionProjects\\untitled186\\cmake-build-debug\\output.txt","w");
    while(fscanf(fo,"%d",&data)==1 && data!=-1){
        temp=data;
        while(temp){
            push(myStack,temp%2);
            temp=temp/2;
        }
        fprintf(fp,"%d->",data);
        while( myStack->top!=-1){
            fprintf(fp,"%d",pop(myStack));
        }
        fprintf(fp,"\n");
    }
    free(myStack);
    fclose(fo);
    fclose(fp);


    return 0;
}
