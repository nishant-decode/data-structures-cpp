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
//DIVISION METHOD
    int i=num%n;
    return i;
}

void hashing(struct node arr[],int n,int loc,int k){
//CHAINING / BUCKETING
    if(arr[loc].data==-1){
        arr[loc].data=k;
    }
    else{
        struct node *ptr=&arr[loc];
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=(struct node *)malloc(sizeof(struct node));
        ptr=ptr->next;
        ptr->data=k;
        ptr->next=NULL;
    }
}

int direct_Search(struct node arr[],int n,int x){
//CHAINING / BUCKETING
    int p=hash_func(x,n);
    if(arr[p].data==x){
        return p;
    }
    else{
        struct node * ptr=&arr[p];
        while(ptr->next!=NULL){
            ptr=ptr->next;
            if(ptr->data==x){
                return p;
            }
        }
    }
    return -1;
}

int main()
{
    struct node *a;
    int k,loc;
    int n,key,found;
    struct timespec start,stop;
    //Taking size of array from user and element to be searched.
    //Creating a hash table.
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(struct node *)malloc(n*sizeof(struct node));
    for(int i=0;i<n;i++){
        a[i].data=-1;
        a[i].next=NULL;
    }
    srand(time(0));
    for(int i=0;i<n;i++){
        k=int((double)rand()/RAND_MAX*n*10);
        loc=hash_func(k,n);
        hashing(a,n,loc,k);
    }
    /*for(int i=0;i<n;i++){
        cout<<a[i].data;
        struct node * ptr=&a[i];
        while(ptr->next!=NULL){
            ptr=ptr->next;
            cout<<" -> "<<ptr->data;
        }
        cout<<endl;
    }*/
    cout<<"Enter an element to be searched between 1 to "<<n<<": ";
    cin>>key;

    //Calculating the time of searching.
    clock_gettime(CLOCK_MONOTONIC,&start);
    found=direct_Search(a,n,key);
    clock_gettime(CLOCK_MONOTONIC,&stop);
    double time_taken;
    time_taken=(stop.tv_sec-start.tv_sec)*1e9;
    time_taken=(time_taken+(stop.tv_nsec-start.tv_nsec))*1e-9;

    //Checking whether element is found or not.
    if(found==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at position "<<found<<endl;
    }
    cout<<"Time taken for the direct search is "<<fixed<<time_taken<<setprecision(9)<<" sec"<<endl;
    return 0;
}
