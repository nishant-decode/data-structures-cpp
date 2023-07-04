#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
using namespace std;

void insertion_sort (int a[], int n){
    int temp;
    int i,j;
    for (i = 1; i < n; i++){
        temp = a[i];
        for (j = i; j > 0 && a[j-1]>temp; j--){
            a[j] = a[j - 1];
        }
        a[j] = temp;
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

    //Calculating the time of searching.
    clock_gettime(CLOCK_MONOTONIC,&start);
    insertion_sort(arr,n);
    clock_gettime(CLOCK_MONOTONIC,&stop);
    double time_taken;
    time_taken=(stop.tv_sec-start.tv_sec)*1e9;
    time_taken=(time_taken+(stop.tv_nsec-start.tv_nsec))*1e-9;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n\nTime taken to sort the array is "<<fixed<<time_taken<<setprecision(9)<<" sec"<<endl;
    return 0;
}
