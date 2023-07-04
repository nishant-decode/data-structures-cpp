#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
#include<cmath>
using namespace std;

int hash_func1(int num,int n){
//DIVISION METHOD
    int i=num%n;
    return i;
}

int hash_func2(int num,int n){
//MULTIPICATION METHOD
    float constant=0.357480;
    int i=floor(n*(num*constant-int(num*constant)));
    return i;
}

int hash_func3(int num,int n){
//MID SQUARE METHOD
    long int a=n*n;
    int b=1;
    int c=0;
    while(a>0){
        if(a<10){
            c++;
        }
        else{
            c+=2;
        }
        a/=100;
        b*=10;
    }
    b/=10;
    if(c%2==0){
        return ((n*n)/b)%100;
    }
    else{
        return ((n*n)/b)%10;
    }
}

void hashing(int arr[],int n,int loc,int k){
//DOUBLE HASHING
    int i=0;
    int p=loc;
    if(arr[loc]==-1){
        arr[loc]=k;
    }
    else{
        i++;
        int loc2=hash_func2(k,n);
        while(arr[p]!=-1 && i<n){
            p=(loc+i*loc2)%n;
            i++;
        }
        arr[p]=k;
    }
}

int direct_Search(int arr[],int n,int x){
//DOUBLE HASHING
    int p=hash_func1(x,n);
    int i=0;
    if(arr[p]==x){
        return p;
    }
    else{
        i++;
        int p2=hash_func2(x,n);
        while(i<n){
            if(arr[(p+i*p2)%n]==x){
                return (p+i*p2)%n;
            }
            else{
                i++;
            }
        }
    }
    return -1;
}

int main()
{
    int *a;
    int k,loc;
    int n,key,found;
    struct timespec start,stop;

    //Taking size of array from user and element to be searched.
    //Creating a hash table.
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i]=-1;
    }
    srand(time(0));
    for(int i=0;i<n;i++){
        k=int((double)rand()/RAND_MAX*n*10);
        loc=hash_func1(k,n);
        hashing(a,n,loc,k);
    }
   /* for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
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
