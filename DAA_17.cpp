#include<iostream>
#include<iomanip>
using namespace std;

struct weight{
    int a;
    int b;
    int c;
};

void heapify(struct weight arr[],int i,int n){
    int l=i;
    int left=2*i+1;
    int right=2*(i+1);
    if(left<n && arr[left].a>arr[l].a){
        l=left;
    }
    if(right<n && arr[right].a>arr[l].a){
        l=right;
    }
    if(l!=i){
        swap(arr[l],arr[i]);
        heapify(arr,l,n);
    }
}
void heap_sort(struct weight arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}

void reheapify(struct weight arr[],int i,int n){
    int s=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[s].a>arr[left].a){
        s=left;
    }
    if(right<n && arr[s].a>arr[right].a){
        s=right;
    }
    if(s!=i){
        swap(arr[i],arr[s]);
        reheapify(arr,s,n);
    }
}

int find_set(int i,int arr[]){
    while(arr[i]!=-1){
        i=arr[i];
    }
    return i;
}

void make_set(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=-1;
    }
}

void union_set(int i,int j,int arr[],int n){
    int x=find_set(i,arr);
    int y=find_set(j,arr);
    if(x!=y){
        arr[y]=x;
    }
    else{
        cout<<"Elements in same set\n";
    }
}

void kruskal(struct weight arr[],int v[],int n,int count,struct weight t[]){
    int i=0;
    int mincost=0;
    make_set(v,n);
    while(i<n-1 && count>0){
        count--;
        swap(arr[0],arr[count]);
        reheapify(arr,0,count);
        int j=find_set(arr[count].b,v);
        int k=find_set(arr[count].c,v);
        if(j!=k){
            mincost+= arr[count].a;
            t[i].a=arr[count].a;
            t[i].b=arr[count].b;
            t[i].c=arr[count].c;
            union_set(j,k,v,n);
            i=i+1;
        }
    }
    if(i!=n-1){
        cout<<"No Spanning Tree "<<endl;
    }
    else{
        cout<<"\nMinimum Cost of minimum spanning tree is: "<<mincost<<endl;
    }
}

int main(){
    int n;
    int count=0;
    cout<<"Enter the number of the vertices: ";
    cin>>n;
    int v[n];
    struct weight arr[(n*(n-1))/2];
    struct weight t[n-1];
    cout<<"Vertices in the graph are: ";
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    cout<<"Enter the edges of the graph\n";
    for(int i=0;i<n;i++){
        cout<<"Edges starting with vertex "<<i<<": ";
        for(int j=0;j<n;j++){
            cin>>arr[count].a;
            arr[count].b=i;
            arr[count].c=j;
            if(arr[count].a!=0 && j>=i){
                count++;
            }
        }
    }
    heap_sort(arr,count);
    kruskal(arr,v,n,count,t);
    cout<<"\nThe edges present in minimum spanning tree is:\n";
    for(int i=0;i<n-1;i++){
        cout<<"\t"<<t[i].a<<" "<<t[i].b<<"-"<<t[i].c<<"  "<<endl;
    }
    return 0;
}
