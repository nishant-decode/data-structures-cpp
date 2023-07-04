#include<iostream>
#include<iomanip>
using namespace std;

struct weight{
    int a;
    int b;
    int c;
};
struct vertices{
    int d;
    int u;
    int v;
};

int ext_min(struct vertices a[],int n){
    int j=-1;
    int min_edge=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i].d<min_edge && a[i].d!=-1){
            min_edge=a[i].d;
            j=i;
        }
    }
    return j;
}

void prims(int n,int **matrix,int s,struct vertices arr[],struct weight t[]){
    arr[s].d=-1;
    int near=s;
    int mincost=0;
    int x=0;
    while(near!=-1){
        for(int i=0;i<n;i++){
            if(arr[i].d>matrix[near][i] && matrix[near][i]!=0){
                arr[i].d=matrix[near][i];
                arr[i].v=near;
            }
        }
        arr[near].d=-1;
        near=ext_min(arr,n);
        if(near==-1){
            break;
        }
        mincost+= arr[near].d;
        t[x].a=arr[near].d;
        t[x].b=arr[near].u;
        t[x].c=arr[near].v;
        x++;
    }
    if(x!=n-1){
        cout<<"\nNo Spanning Tree "<<endl;
    }
    else{
        cout<<"\nMinimum Cost of minimum spanning tree is: "<<mincost<<endl;
        cout<<"\nThe edges present in minimum spanning tree is:\n";
        for(int i=0;i<n-1;i++){
            cout<<"\t"<<t[i].a<<" "<<t[i].b<<"-"<<t[i].c<<"  "<<endl;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of the vertices: ";
    cin>>n;
    int **matrix=new int*[n];
    cout<<"Vertices in the graph are: ";
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        matrix[i]=new int[n];
    }
    cout<<endl<<endl;
    cout<<"Enter the edges of the graph\n";
    int minedge=INT_MAX;
    int minedge_v=0;
    for(int i=0;i<n;i++){
        cout<<"Edges starting with vertex "<<i<<": ";
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]!=0 && minedge>matrix[i][j]){
                minedge=matrix[i][j];
                minedge_v=i;
            }
        }
    }
    struct vertices arr[n];
    struct weight t[n];
    for(int i=0;i<n;i++){
        arr[i].d=INT_MAX;
        arr[i].u=i;
        arr[i].v=-1;
    }
    prims(n,matrix,minedge_v,arr,t);
    return 0;
}
