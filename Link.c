#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode *List;
typedef int Elementype;
List Ptrl1,Ptrl2,Ptrl3;
struct Lnode{
    Elementype val;
    List next;
};
List MakeList(List Ptrl,FILE*fp)
{
    List p,r;
    int length;
    int dat;
    r=Ptrl;
    fscanf(fp,"%d",&length);
    for(int i=0;i<length;i++)
    {
        p=(List)malloc(sizeof(struct Lnode));
        fscanf(fp,"%d",&dat);
        p->val=dat;
        r->next=p;
        r=p;
    }
    r->next=NULL;
    return Ptrl;
}

void showList(List Ptrl, FILE *fo,int c){
    fprintf(fo,"Case %d: ",c);
    int cnt=0;
    List p=Ptrl;
    while(p!=NULL){
        cnt++;
        p=p->next;
    }
    fprintf(fo,"%d\n",cnt);
    while(Ptrl!=NULL){
        fprintf(fo,"%d  ",Ptrl->val);
        Ptrl=Ptrl->next;
    }
    fprintf(fo,"\n");

}
int main()
{
    FILE *fp,*fo;
    fp=fopen("C:\\Users\\lukarry\\Documents\\workspace\\CLionProjects\\untitled186\\cmake-build-debug\\input.txt","r");
    Ptrl1=(List )malloc(sizeof(struct Lnode));
    Ptrl2=(List )malloc(sizeof(struct Lnode));
    Ptrl3=(List )malloc(sizeof(struct Lnode));
    Ptrl1->next=NULL;
    Ptrl2->next=NULL;
    Ptrl3->next=NULL;
    fo=fopen("C:\\Users\\lukarry\\Documents\\workspace\\CLionProjects\\untitled186\\cmake-build-debug\\output.txt","w");
    for(int t=0;t<2;t++)
    {
        Ptrl1=MakeList(Ptrl1,fp);
        Ptrl2=MakeList(Ptrl2,fp);
        List pa,pb,pc;
        pa=Ptrl1->next;
        pb=Ptrl2->next;
        pc=Ptrl3;
        while(pa!=NULL && pb!=NULL)
        {
            if(pa->val<pb->val)
            {
                pc->next=pa;
                pc=pa;
                pa=pa->next;
            }
            else
            {
                pc->next=pb;
                pc=pb;
                pb=pb->next;
            }
        }
        pc->next=pa?pa:pb;
        showList(Ptrl3->next,fo,t+1);}
}
