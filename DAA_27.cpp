#include<iostream>
using namespace std;

void print_lcs(char **arrow,char s1[],int i,int j){
    if(i==-1 || j==-1){
        return;
    }
    if(arrow[i][j]=='D'){
        print_lcs(arrow,s1,i-1,j-1);
        cout<<s1[i];
    }
    else if(arrow[i][j]=='U'){
        print_lcs(arrow,s1,i-1,j);
    }
    else{
        print_lcs(arrow,s1,i,j-1);
    }
}

void lcs(char s1[],char s2[],int m,int n){
    int len[m+1][n+1];
    char **arrow=new char *[m];
    for(int i=0;i<m;i++){
        arrow[i]=new char[n];
    }
    for(int i=0;i<=m;i++){
        len[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        len[0][i]=0;
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                len[i][j]=len[i-1][j-1]+1;
                arrow[i-1][j-1]='D';
            }
            else if(len[i-1][j]>=len[i][j-1]){
                len[i][j]=len[i-1][j];
                arrow[i-1][j-1]='U';
            }
            else{
                len[i][j]=len[i][j-1];
                arrow[i-1][j-1]='L';
            }
        }
    }
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<len[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nThe length of longest common subsequence is: "<<len[m][n]<<endl;
    cout<<"The longest common subsequence is: ";
    print_lcs(arrow,s1,m-1,n-1);
}

int main()
{
    int m,n;
    cout<<"Enter the length of string_1: ";
    cin>>m;
    char str1[m];
    cout<<"Enter string_1: ";
    cin>>str1;
    cout<<"Enter the length of string_2: ";
    cin>>n;
    char str2[n];
    cout<<"Enter string_2: ";
    cin>>str2;
    lcs(str1,str2,m,n);
    cout<<endl;
}
