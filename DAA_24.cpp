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

void dijkstra(int n,int **matrix,int s,struct vertices arr[],struct weight t[]){
    arr[s].d=0;
    int parent=s;
    int mincost=0;
    int x=0;
    while(parent!=-1){
        for(int i=0;i<n;i++){
            if(arr[i].d>matrix[parent][i]+arr[parent].d && matrix[parent][i]!=0){
                arr[i].d=matrix[parent][i]+arr[parent].d;
                arr[i].v=parent;
            }
        }
        arr[parent].d=-1;
        parent=ext_min(arr,n);
        if(parent==-1){
            break;
        }
        mincost=arr[parent].d;
        t[x].a=arr[parent].d;
        t[x].b=arr[parent].u;
        t[x].c=arr[parent].v;
        x++;
    }
    if(x!=n-1){
    cout<<"\nNo Shortest path to all vertices"<<endl;
    }
    cout<<"\nShortest path  from the source vertex "<<s<<" to furthest vertex is: "<<mincost<<endl;
    cout<<"The edges present in shortest path are:\n";
    cout<<"\tWeight  Vertex  Parent\n";
    for(int i=0;i<x;i++){
        cout<<"\t  "<<t[i].a<<"\t  "<<t[i].b<<"\t  "<<t[i].c<<"  "<<endl;
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
    for(int i=0;i<n;i++){
        cout<<"Edges starting with vertex "<<i<<": ";
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int s;
    cout<<"\nEnter the starting vertex: ";
    cin>>s;
    struct vertices arr[n];
    struct weight t[n];
    for(int i=0;i<n;i++){
        arr[i].d=INT_MAX;
        arr[i].u=i;
        arr[i].v=-1;
    }
    dijkstra(n,matrix,s,arr,t);
    return 0;
}
