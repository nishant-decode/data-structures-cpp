#include<iostream>
using namespace std;

void print_optimal_paren(int **s,int i,int j){
    if(i==j){
        cout<<"A"<<i+1;
    }
    else{
        cout<<"(";
        print_optimal_paren(s,i,s[j][i]);
        print_optimal_paren(s,s[j][i]+1,j);
        cout<<")";
    }
}

void mat_chain_m(int arr[],int n){
    int **min_matrix=new int *[n];
    for(int i=0;i<n;i++){
        min_matrix[i]=new int[n];
    }
    int p,q;
    for(int i=0;i<n;i++){
        min_matrix[i][i]=0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            p=i+j;
            min_matrix[j][p]=INT_MAX;
            for(int k=j;k<p;k++){
                q=min_matrix[j][k]+min_matrix[k+1][p]+arr[j]*arr[k+1]*arr[p+1];
                if(q<min_matrix[j][p]){
                    min_matrix[j][p]=q;
                    min_matrix[p][j]=k;
                }
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<i){
                cout<<"  ";
            }
            else{
                cout<<min_matrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"\nThe minimum cost of multiplication is: "<<min_matrix[0][n-1]<<endl;
    cout<<"The order of multiplication is: ";
    print_optimal_paren(min_matrix,0,n-1);
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter the length of matrix chain: ";
    cin>>n;
    cout<<"Enter the matrix chain: ";
    int chain[n];
    for(int i=0;i<n;i++){
        cin>>chain[i];
    }
    mat_chain_m(chain,n-1);
}
