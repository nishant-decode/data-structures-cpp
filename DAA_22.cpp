#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    struct node * next;
};

void dfs_visit(int n,int **adm,int s,int color[]){
    int ptr=s;
    if(color[ptr]==1){
        color[ptr]=0;
    }
    for(int i=0;i<n;i++){
        if(adm[ptr][i]==1 && color[i]==1){
            color[i]=0;
            dfs_visit(n,adm,i,color);
        }
    }
    color[ptr]=-1;
}

void connect(int n,int **adm,int s=0){
    int color[n];
    int count=0;
    for(int i=0;i<n;i++){
        color[i]=1;
    }
    dfs_visit(n,adm,s,color);
    for(int i=0;i<n;i++){
        if(color[i]==1){
            cout<<"The graph is not connected";
            count++;
            break;
        }
    }
    if(!count){
        cout<<"The graph is connected";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of vertices in graph: ";
    cin>>n;
    int **adm=new int*[n];
    cout<<"Vertices in the graph are: ";
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        adm[i]=new int[n];
    }
    cout<<endl<<endl;
    cout<<"Enter the edges of the graph to check its connectivity\n";
    for(int i=0;i<n;i++){
        cout<<"Edges starting with vertex "<<i<<": ";
        for(int j=0;j<n;j++){
            cin>>adm[i][j];
        }
    }
    cout<<endl;
    connect(n,adm);
    int x,exit=0;
}
