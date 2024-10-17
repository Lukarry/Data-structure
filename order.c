#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
//将int类型取别名为Elementype,方便改变数据结构中的数组存储的数据类型发生变化时的修改
typedef int Elementype;
//使用typedef定义List为指向结构体Node的指针
typedef struct Node *List;
//定义结构体
struct Node{
    Elementype Data[Maxsize];
    int last;
};
//声明结构体指针
List Ptrl1,Ptrl2,Ptrl3;
//创建一个返回结构体指针的函数
List Makelist(List Ptrl,FILE *p){
    int length,data;
    //获取列表长度
    fscanf(p,"%d",&length);
    int i;
    //获取列表中的元素
    for(i=0;i<length;i++){
        fscanf(p,"%d",&data);
        Ptrl->Data[i]=data;
    }
    //让列表的last等于数组元素-1,因为是从0开始存储
    Ptrl->last=length-1;
    return Ptrl;
}
//定义打印函数
int cnt=1;
void showlist(List Ptrl, FILE *p){
    //cnt是记录当前是第几组数据，last+1是合并后列表的长度
    fprintf(p,"case %d:%d\n",cnt,Ptrl3->last+1);
    for(int i=0;i<=Ptrl->last;i++){
        fprintf(p,"%d ",Ptrl->Data[i]);
    }
    fprintf(p,"\n");
    cnt++;
}
int main(){
    //定义文件指针
    FILE *fp,*fo;
    fp=fopen("C:\\Users\\lukarry\\Documents\\workspace\\CLionProjects\\untitled186\\cmake-build-debug\\input.txt","r");
    if(fp==NULL){
        printf("Failed to open input file");
        return 1;
    }
    fo=fopen("C:\\Users\\lukarry\\Documents\\workspace\\CLionProjects\\untitled186\\cmake-build-debug\\output.txt","w");
    if(fo==NULL){
        printf("Failed to open output file");
        fclose(fp);
    }
    //为三个列表动态分配空间
    Ptrl1=(List)malloc(sizeof(struct Node));
    Ptrl2=(List)malloc(sizeof(struct Node));
    Ptrl3=(List)malloc(sizeof(struct Node));
    if(Ptrl1==NULL||Ptrl2==NULL||Ptrl3==NULL){
        printf("Failed to allocate memory");
        fclose(fp);
        fclose(fo);
        return 1;
    }
    //将last值赋值为0是因为要从0开始存储数据
    Ptrl1->last=-1;
    Ptrl2->last=-1;
    Ptrl3->last=-1;
//因为有两组数据所以用个循坏
    for(int t=0;t<2;t++){
        //创建三个列表，ptrl1,ptrl2存储从文件中得到的列表，ptrl3存储最后排列好的列表
        Ptrl1=Makelist(Ptrl1,fp);
        Ptrl2=Makelist(Ptrl2,fp);
        //ptrl3的last值重置为-1
        Ptrl3->last=-1;
        //用i,j两个变量来跟踪两个结构体指针中Data数组的长度
        int i=0,j=0;
        //当没有到达两个列表中任何一个元素的最后时执行循环，通过i,j的追踪比较大小存储到ptrl3的列表中
        while(i<=Ptrl1->last && j<=Ptrl2->last){
            if(Ptrl1->Data[i]<Ptrl2->Data[j]){
                Ptrl3->Data[++(Ptrl3->last)]=Ptrl1->Data[i];
                i++;
            }
            else{
                Ptrl3->Data[++(Ptrl3->last)]=Ptrl2->Data[j];
                j++;
            }
        }
        //如果ptrl2这个指针指向的列表中的元素已经读取完毕，那就按顺序将ptrl1指针指向的列表中的元素依次存放到ptrl3中（因为初始列表1，列表2都是已排序的列表）
        while(i<=Ptrl1->last){
            Ptrl3->Data[++(Ptrl3->last)]=Ptrl1->Data[i];
            i++;
        }
        //如果ptrl1这个指针指向的列表中的元素已经读取完毕，那就按顺序将ptrl2指针指向的列表中的元素依次存放到ptrl3中
        while(j<=Ptrl2->last){
            Ptrl3->Data[++(Ptrl3->last)]=Ptrl2->Data[j];
            j++;
        }
        //调用答应函数
        showlist(Ptrl3,fo);
    }
    //关闭文件
    fclose(fp);
    fclose(fo);
    //释放空间
    free(Ptrl1);
    free(Ptrl2);
    free(Ptrl3);
    return 0;}
