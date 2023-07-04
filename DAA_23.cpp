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

void graph_reverse(int n,int **adm){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(adm[i][j],adm[j][i]);
        }
    }
    return;
}

void SCC(int n,int **adm){
    stack<int> st;
    int color[n];
    for(int i=0;i<n;i++){
        color[i]=1;
    }
    dfs_visit(n,adm,0,color,st);
    for(int i=0;i<n;i++){
        if(color[i]==1){
            dfs_visit(n,adm,i,color,st);
        }
    }
    for(int i=0;i<n;i++){
        color[i]=1;
    }
    graph_reverse(n,adm);
    cout<<"The Strongly connected components for the given graph are:\n";
    stack<int> scc;
    int ptr;
    while(st.empty()==0){
        ptr=st.top();
        st.pop();
        if(color[ptr]==1){
            dfs_visit(n,adm,ptr,color,scc);
            cout<<"\tSet of vertices: ";
            while(scc.empty()==0){
                cout<<scc.top()<<" ";
                scc.pop();
            }
            cout<<endl;
        }
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
    SCC(n,adm);
    return 0;
}
