//整数数组不会以‘\0'作为结束符
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int N,min,K,copy_K;
    double total_time;
//N输入所要排序的数据个数,K循环要执行的次数
    scanf("%d %d",&N,&K);
    copy_K=K;
    int num[N],i,j;
    clock_t start,stop;
    double duration;
    srand(time(NULL));
    for(i=0;i<N;i++){
        num[i]=rand()%1000;//限制最小数的范围
    }
//记录开始时间
    start=clock();
//选择排序
while(K--){
    for(i=0;i<N-1;i++){
        min=i;
        for(j=i+1;j<N;j++){
            if(num[min]>num[j]){
                min=j;
            }
        }
        //找到最小值就交换(地址交换）
        if(min!=i){
        swap(&num[j],&num[min]);}
    }}
    //记录结束时间
    stop=clock();
    total_time=(((double)(stop-start))/CLOCKS_PER_SEC);
    duration=total_time/copy_K;
    printf("total_time:%llf seconds\n",total_time);
    printf("duration:%llf seconds\n",duration);
}
