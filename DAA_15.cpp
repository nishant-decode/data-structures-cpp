#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
using namespace std;

struct node{
    int data;
    struct node * next;
};

int hash_func(int num,int n){
    num=num/10;
    int i=num%n;
    return i;
}

void hashing_sort(struct node arr[],int n,int loc,int k){
    if(arr[loc].data==-1){
        arr[loc].data=k;
    }
    else{
        struct node *ptr=&arr[loc];
        struct node *p=(struct node *)malloc(sizeof(struct node));
        struct node *temp=ptr;
        p->data=-1;
        while(ptr!=NULL){
            if(ptr->data>=k){
                p->data=k;
                break;
            }
            temp=ptr;
            ptr=ptr->next;
        }
        if(p->data==-1){
            temp->next=(struct node *)malloc(sizeof(struct node));
            temp=temp->next;
            temp->data=k;
            temp->next=NULL;
        }
        else if(ptr==(&arr[loc])){
            p->next=ptr->next;
            temp->next=p;
            p->data=temp->data;
            temp->data=k;
        }
        else{
            p->next=ptr;
            temp->next=p;
        }
    }
}

void bucket_sort(int arr[],int n,struct node a[]){
    int loc;
    for(int i=0;i<n;i++){
        loc=hash_func(arr[i],n);
        hashing_sort(a,n,loc,arr[i]);
    }
    int k=0;
    for(int i=0;i<n;i++){
        if(a[i].data!=-1){
            arr[k]=a[i].data;
            k++;
        }
        struct node * ptr=&a[i];
        while(ptr->next!=NULL){
            ptr=ptr->next;
            arr[k]=ptr->data;
            k++;
        }
    }
}

int main()
{
    struct node *a;
    int * arr;
    int n;
    struct timespec start,stop;

    //Taking size of array from user and element to be searched.
    //Creating a hash table.
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(struct node *)malloc(n*sizeof(struct node));
    arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i].data=-1;
        a[i].next=NULL;
    }
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=int((double)rand()/RAND_MAX*n*10);
    }

    //Calculating the time of sorting.
    clock_gettime(CLOCK_MONOTONIC,&start);
    bucket_sort(arr,n,a);
    clock_gettime(CLOCK_MONOTONIC,&stop);
    double time_taken;
    time_taken=(stop.tv_sec-start.tv_sec)*1e9;
    time_taken=(time_taken+(stop.tv_nsec-start.tv_nsec))*1e-9;
    /*for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;*/

    cout<<"Time taken for the direct search is "<<fixed<<time_taken<<setprecision(9)<<" sec"<<endl;
    return 0;
}
