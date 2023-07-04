#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void bfs(int n, int **adm,int s){
    queue<int> q;
    int color[n];
    int ptr=s;
    int found=0;
    for(int i=0;i<n;i++){
        color[i]=0;
    }
    cout<<"The BFS for the given graph from vertex "<<ptr<<" is: ";
	if(color[ptr]==0){
        q.push(ptr);
        color[ptr]=1; //1 represents grey
	}
	while(q.empty()!=1){
        for(int i=0;i<n;i++){
            if(adm[ptr][i]==1 && color[i]==0){
                q.push(i);
                color[i]=1;
            }
        }
        ptr=q.front();
        q.pop();
        color[ptr]=2;
        cout<<ptr<<" ";
    }
    cout<<endl<<endl;
}

void dfs(int n, int **adm,int s){
    stack<int> st;
    int color[n];
    int ptr=s;
    int found=0;
    for(int i=0;i<n;i++){
        color[i]=0;
    }
    cout<<"The BFS for the given graph from vertex "<<ptr<<" is: ";
	if(color[ptr]==0){
        st.push(ptr);
        color[ptr]=1; //1 represents grey
	}
	while(st.empty()!=1){
        ptr=st.top();
        st.pop();
        color[ptr]=2;
        cout<<ptr<<" ";
        for(int i=0;i<n;i++){
            if(adm[ptr][i]==1 && color[i]==0){
                st.push(i);
                color[i]=1;
            }
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
    int s;
    cout<<"Enter the starting vertex:";
    cin>>s;
    int x,exit=0;
    while(exit==0){
        cout<<"1.BFS\n2.DFS\n3.Change staring vertex\n4.Exit\n";
        cout<<"What do you want to perform: ";
        cin>>x;
        cout<<"\n";
        switch(x){
            case 1:
                bfs(n,adm,s);
                break;
            case 2:
                dfs(n,adm,s);
                break;
            case 3:
                cout<<"Enter the starting vertex:";
                cin>>s;
                break;
            case 4:
                exit=1;
                break;
            default:
                cout<<"ERROR\nThe input is invalid. Please try again.\n\n";
                break;
        }
    }
}
