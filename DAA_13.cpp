#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
using namespace std;

void count_sort(int a[],int n){
    int m=a[0];
    int s=a[0];
    int c[n];
    for(int i=0;i<n;i++){
        if(a[i]>m){
            m=a[i];
        }
        if(s>a[i]){
            s=a[i];
        }
    }
    int * b;
    b=new int[m-s+1];
    for(int i=0;i<m-s+1;i++){
        b[i]=0;
    }
    for(int i=0;i<n;i++){
        a[i]=a[i]-s;
        b[a[i]]=b[a[i]]+1;
    }
    for(int i=1;i<m-s+1;i++){
        b[i]+=b[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[a[i]]--;
        c[b[a[i]]]=a[i]+s;
    }
    delete b;
    for(int i=0;i<n;i++){
        a[i]=c[i];
    }
    return;
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

    //Calculating the time of sorting.
    clock_gettime(CLOCK_MONOTONIC,&start);
    count_sort(arr,n);
    clock_gettime(CLOCK_MONOTONIC,&stop);
    double time_taken;
    time_taken=(stop.tv_sec-start.tv_sec)*1e9;
    time_taken=(time_taken+(stop.tv_nsec-start.tv_nsec))*1e-9;
    /*for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }*/
    cout<<"\nTime taken to sort the array is "<<fixed<<time_taken<<setprecision(9)<<" sec"<<endl;
    return 0;
}
