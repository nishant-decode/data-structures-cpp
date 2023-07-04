#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    struct node * next;
};

void dfs_visit(int n,int **adm,int s,int color[],stack<int> &st){
    int ptr=s;
    if(color[ptr]==1){
        color[ptr]=0;
    }
    for(int i=0;i<n;i++){
        if(adm[ptr][i]==1 && color[i]==1){
            color[i]=0;
            dfs_visit(n,adm,i,color,st);
        }
    }
    st.push(ptr);
    color[ptr]=-1;
}

void topo_sort(int n,int **adm,int s){
    stack<int> st;
    int color[n];
    for(int i=0;i<n;i++){
        color[i]=1;
    }
    dfs_visit(n,adm,s,color,st);
    for(int i=0;i<n;i++){
        if(color[i]==1){
            dfs_visit(n,adm,i,color,st);
        }
    }
    cout<<"The Topological Sort for the given graph is: ";
    while(st.empty()==0){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl<<endl;
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
    cout<<"Enter the edges of the graph\n";
    for(int i=0;i<n;i++){
        cout<<"Edges starting with vertex "<<i<<": ";
        for(int j=0;j<n;j++){
            cin>>adm[i][j];
        }
    }
    cout<<endl;
    int s;
    cout<<"Enter the starting vertex: ";
    cin>>s;
    topo_sort(n,adm,s);
    int x,exit=0;
    while(exit==0){
        cout<<"1.Change staring vertex\n2.Exit\n";
        cout<<"What do you want to perform: ";
        cin>>x;
        cout<<"\n";
        switch(x){
            case 1:
                cout<<"Enter the starting vertex: ";
                cin>>s;
                topo_sort(n,adm,s);
                break;
            case 2:
                cout<<"Program Exited";
                exit=1;
                break;
            default:
                cout<<"ERROR\nThe input is invalid. Please try again.\n\n";
                break;
        }
    }
}
