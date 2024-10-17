#include<stdio.h>
typedef int Element;
typedef struct Snode *Slink;
#define Maxsize 100
struct Snode{
    Element data;
    Slink next;
};
Slink S;
void push(Slink Ptrl,Element val){
    struct Snode *tempcell;
    //是给链表头插入元素
    tempcell=(struct Snode *)malloc(sizeof(struct Snode));
    tempcell->data=val;
    tempcell->next=Ptrl->next;
    Ptrl->next=tempcell;
}
Element pop(Slink Ptrl){
    //Fistcell指向要删除的节点
    struct Snode *Fistcell;
    Element top;
    if(Ptrl->next==NULL){
        printf("error");
        return NULL;
    }
    else{
        Fistcell=Ptrl->next;
        Ptrl->next=Fistcell->next;
        top=Fistcell->data;
        free(Fistcell);
    }
    //返回要删除的节点指向的值
    return top;
}
int main(){
    FILE *fo,*fe;
    fo=fopen("C:\\Users\\lukarry\\Documents\\workspace\\CLionProjects\\untitled186\\cmake-build-debug\\input.txt","r");
    S=(Slink)malloc(sizeof(struct Snode));
    S->next=NULL;
    fe=fopen("C:\\Users\\lukarry\\Documents\\workspace\\CLionProjects\\untitled186\\cmake-build-debug\\output.txt","w");
    Element e;
    Element data,temp;
    while(fscanf(fo,"%d",&data)){
        if(data==-1)break;
        //因为需要保留原始数据，所以将它cp给另一个变量
        temp=data;
        while(temp){
            push(S,temp%2);
            temp/=2;}
        fprintf(fe,"%d->",data);
        while(S->next!=NULL){
            e=pop(S);
            fprintf(fe,"%d",e);
        }
        fprintf(fe,"\n");}
}
