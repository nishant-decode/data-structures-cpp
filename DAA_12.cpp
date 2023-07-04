#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
using namespace std;

void heapify(int arr[],int n,int i){
    int l=i;
    int left=2*i+1;
    int right=2*(i+1);
    if(left<n && arr[left]>arr[l]){
        l=left;
    }
    if(right<n && arr[right]>arr[l]){
        l=right;
    }
    if(l!=i){
        swap(arr[l],arr[i]);
        heapify(arr,n,l);
    }
}

void heap_sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main()
{
    int *arr;
    int n;
    struct timespec start,stop;

    //Taking size of array from user.
    cout<<"Enter the size of array: ";
    cin>>n;
    arr=(int *)malloc(n*sizeof(int));
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=int((double)rand()/RAND_MAX*n);
    }
    //Calculating the time of searching.
    clock_gettime(CLOCK_MONOTONIC,&start);
    heap_sort(arr,n);
    clock_gettime(CLOCK_MONOTONIC,&stop);
    double time_taken;
    time_taken=(stop.tv_sec-start.tv_sec)*1e9;
    time_taken=(time_taken+(stop.tv_nsec-start.tv_nsec))*1e-9;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\nTime taken to sort the array is "<<fixed<<time_taken<<setprecision(9)<<" sec"<<endl;
    return 0;
}
