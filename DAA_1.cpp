#include<iostream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
using namespace std;

int linear_search(int arr[],int len,int x){
    for(int i=0;i<len;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main()
{
    int *a;
    int n,key,found;
    struct timespec start,stop;

    //Taking size of array from user and element to be searched.
    cout<<"Enter the size of array: ";
    cin>>n;
    a=(int *)malloc(n*sizeof(int));
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i]=int((double)rand()/RAND_MAX*n);
    }
    /*for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }*/
    cout<<"Enter an element to be searched between 1 to "<<n<<": ";
    cin>>key;

    //Calculating the time of searching.
    clock_gettime(CLOCK_MONOTONIC,&start);
    found=linear_search(a,n,key);
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
    cout<<"Time taken by the linear search is "<<fixed<<time_taken<<setprecision(9)<<" sec"<<endl;
    return 0;
}