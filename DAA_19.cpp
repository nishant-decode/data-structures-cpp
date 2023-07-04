#include<iostream>
#include<time.h>
#include<iomanip>
#include<algorithm>
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

int R_S(int arr[],int beg,int end,int i){
	int q,k;
	if(beg==end){
		return arr[beg];
	}
    q=partition(arr,beg,end);
    k=q-beg+1;
    if(i==k){
    	return arr[q];
    }
    else if(i<k){
    	return R_S(arr,beg,q-1,i);
    }
    else{
    	return R_S(arr,q+1,end,i-k);
    }
}

int main()
{
    int *a;
    int n,key,found;
    struct timespec start,stop;

    //Taking size of array from user and element to be searched.
    cout<<"Enter the size of array: ";
    cin>>n;
    a=new int[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i]=int((double)rand()/RAND_MAX*n*10);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl<<endl;
    cout<<"Enter an index of the element in the sorted array: ";
    cin>>key;

    //Calculating the time of searching.
    clock_gettime(CLOCK_MONOTONIC,&start);
    found=R_S(a,0,n-1,key);
    clock_gettime(CLOCK_MONOTONIC,&stop);
    double time_taken;
    time_taken=(stop.tv_sec-start.tv_sec)*1e9;
    time_taken=(time_taken+(stop.tv_nsec-start.tv_nsec))*1e-9;
    sort(a,a+n);
    cout<<"\nSorted array: \n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl<<endl;

    //Checking whether element is found or not.
    cout<<"Element present at position "<<key<<" in the sorted array is: "<<found<<endl;
    cout<<"Time taken for the searching element using median order statastics is "<<fixed<<time_taken<<setprecision(9)<<" sec"<<endl;
    return 0;
}
