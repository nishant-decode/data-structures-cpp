#include<iostream>
#include<vector>
using namespace std;

void activity_selection(int s[],int f[],int n){
    vector<int> arr;
    arr.push_back(1);
    int k=0;
    for(int i=1;i<n;i++){
        if(s[i]>=f[k]){
            arr.push_back(i+1);
            k=i;
        }
    }
    cout<<"\nThe maximum subset of mutually compatible activities is: ";
    for(int i=0;i<arr.size();i++){
        cout<<"A"<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the number of activities: ";
    cin>>n;
    int start[n];
    cout<<"Enter the starting time of activities: ";
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    int finish[n];
    cout<<"Enter the finishing time of activities: ";
    for(int i=0;i<n;i++){
        cin>>finish[i];
    }
    activity_selection(start,finish,n);
    return 0;
}
