#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
using namespace std;

int partition(int arr[],int s,int e){
    int i=s+1,j=e;
    int part=arr[s];
    do{
        while(arr[i]<=part && i<=e){
            i++;
        }
        while(arr[j]>part && j>=s){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }while(i<j);
    swap(arr[s],arr[j]);
    return j;
}

void quick_sort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
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
    quick_sort(arr,0,n-1);
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
