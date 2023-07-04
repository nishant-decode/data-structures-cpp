#include<iostream>
using namespace std;

void construct_obst(int **s,int i,int j,int last,int n){
    if(last==0){
        cout<<"k"<<s[i][j]<<" is the root"<<endl;
    }
    else if(j<last){
        cout<<"k"<<s[i][j]<<" is the left child of "<<"k"<<last<<endl;
    }
    else{
        cout<<"k"<<s[i][j]<<" is the right child of "<<"k"<<last<<endl;
    }
    if(i==j){
        cout<<"d"<<i-1<<" is the left child of "<<"k"<<j<<endl;
        cout<<"d"<<i<<" is the right child of "<<"k"<<j<<endl;
        return;
    }
    if(s[i][j]-1>=i){
        construct_obst(s,i,s[i][j]-1,s[i][j],n);
    }
    else{
        cout<<"d"<<j-1<<" is the left child of "<<"k"<<j<<endl;
    }
    if(s[i][j]+1<n){
        construct_obst(s,s[i][j]+1,j,s[i][j],n);
    }
    else{
        cout<<"d"<<j<<" is the right child of "<<"k"<<j<<endl;
    }
}

void obst(int p[],int q[],int n){
    int **e=new int *[n+2];
    int **w=new int *[n+2];
    int **r=new int *[n+1];
    for(int i=0;i<n+2;i++){
        e[i]=new int[n+1];
        w[i]=new int[n+1];
        if(i!=n+1){
            r[i]=new int[n+1];
        }
    }
    int l,t;
    for(int i=1;i<=n+1;i++){
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            l=i+j-1;
            e[j][l]=INT_MAX;
            w[j][l]=w[j][l-1]+p[l]+q[l];
            for(int k=j;k<=l;k++){
                t=e[j][k-1]+e[k+1][l]+w[j][l];
                if(t<e[j][l]){
                    e[j][l]=t;
                    r[j][l]=k;
                }
            }
        }
    }
    cout<<endl;
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=n;j++){
            if(j<i-1){
                cout<<"  ";
            }
            else{
                cout<<e[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;    cout<<"\nThe optimal searching cost is: "<<e[1][n]<<endl;
    cout<<"\nThe optimal binary tree structure is:\n";
    construct_obst(r,1,n,0,n);
}

int main()
{
    int n;
    cout<<"Enter the number of keys: ";
    cin>>n;
    cout<<"Enter the search probability of keys: ";
    int p[n+1];
    int q[n+1];
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    cout<<"Enter the search probability of dummy keys: ";
    for(int i=0;i<=n;i++){
        cin>>q[i];
    }
    obst(p,q,n);
}
