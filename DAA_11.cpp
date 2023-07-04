#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
using namespace std;

void merge(int arr[],int mid,int lo,int hi){
    int i=lo,j=mid+1,k=lo;
    int b[hi+1];
    while(i<=mid && j<=hi){
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
            k++;
        }
        else{
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    while(j<=hi){
        b[k]=arr[j];
        j++;
        k++;
    }
    while(i<=mid){
        b[k]=arr[i];
        i++;
        k++;
    }
    for(i=lo;i<=hi;i++){
        arr[i]=b[i];
    }
    return;
}

void merge_sort(int arr[],int lo,int hi){
    int mid;
    if(lo<hi)
    {
        mid=(lo+hi)/2;
        merge_sort(arr,lo,mid);
        merge_sort(arr,mid+1,hi);
        merge(arr,mid,lo,hi);
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
    merge_sort(arr,0,n-1);
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
