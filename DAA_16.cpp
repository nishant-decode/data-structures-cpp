#include<iostream>
#include<iomanip>
using namespace std;

int find_set(int i,int arr[]){
    while(arr[i]!=-1){
        i=arr[i];
    }
    return i;
}

void display(int arr[],int n){
    int j,l;
    cout <<setw(5)<<"Root"<<setw(10)<< "Parent"<<setw(25)<<"Set of Parent element"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(5)<<i<<setw(10)<<arr[i]<<setw(15)<<"{";
        j=find_set(i,arr);
        for(int k=0;k<n;k++){
            l=find_set(k,arr);
            if(l==j){
                cout<<k<<",";
            }
        }
        cout<<"\b}\n";
    }
}

void make_set(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=-1;
    }
    display(arr,n);
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
    display(arr,n);
}

struct Set{
    struct element * next;
    struct element * tail;
};
struct element{
    int data;
    struct Set * head;
    struct element * next;
};

void display_ll(struct element * arr[],int n){
    cout <<setw(5)<<"Element"<<setw(10)<< "Set"<<endl;
    for(int i=0;i<n;i++){
        struct element *ptr=(arr[i]->head)->next;
        cout<<setw(5)<<i<<setw(10)<<"{";
        while(ptr!=NULL){
            cout<<ptr->data<<",";
            ptr=ptr->next;
        }
        cout<<"\b}\n";
    }
}

void make_set_ll(struct element * arr2[],int n){
    for(int i=0;i<n;i++){
        struct Set * s = (struct Set *)malloc(sizeof(struct Set));
        struct element * e = (struct element *)malloc(sizeof(struct element));
        e->data=i;
        e->next=NULL;
        e->head=s;
        s->next=e;
        s->tail=e;
        arr2[i]=e;
    }
    display_ll(arr2,n);
}

int find_set_ll(struct element * e){
     return ((e->head)->next)->data;
}

void union_set_ll(struct element * e1,struct element * e2,struct element * arr[],int n){
    int x=find_set_ll(e1);
    int y=find_set_ll(e2);
    if(x!=y){
        ((e1->head)->tail)->next=(e2->head)->next;
        struct Set * s=e2->head;
        struct element * ptr=(e2->head)->next;
        while(ptr->next!=NULL){
            ptr->head=e1->head;
            ptr=ptr->next;
        }
        (e1->head)->tail=ptr;
        ptr->head=e1->head;
        free(s);
    }
    else{
        cout<<"Elements in same set\n";
    }
    display_ll(arr,n);
    return;
}

int main()
{
    int n;
    cout<<"Enter the number of the vertices: ";
    cin>>n;
    int *arr;
    arr=new int[n];
    cout<<"Vertices in the graph are: ";
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    struct element * arr2[n];
    int i,j;
    int k;
    int x;
    int option;
    int exit=0;
    int loop=1;
    while(loop){
        cout<<"\n1)Set using linked list\n2)Set using array\n3)Exit\n";
        cout<<"Enter the option you want to perform: ";
        cin>>x;
        switch(x){
            case 1:
            exit=0;
            while(!exit){
                cout<<"\n1)Make_Set\n2)Find_Set\n3)Union\n4)Exit\n";
                cout<<"Enter the option you want to perform: ";
                cin>>option;
                switch(option){
                    case 1:
                    make_set_ll(arr2,n);
                    break;
                    case 2:
                    cout<<"\nEnter the element to find its set:";
                    cin>>k;
                    k=find_set_ll(arr2[k]);
                    cout<<"Representative element of the set is: "<<k<<"\n";
                    break;
                    case 3:
                    cout<<"\nEnter the Vertices for union\n";
                    cout<<"Vertex 1: ";
                    cin>>i;
                    cout<<"Vertex 2: ";
                    cin>>j;
                    union_set_ll(arr2[i],arr2[j],arr2,n);
                    break;
                    case 4:
                    exit=1;
                    break;
                    default:
                    printf("ERROR\nThe input is invalid. Please enter again\n\n");
                    break;
                }
            }
            break;
            case 2:
            exit=0;
            while(!exit){
                cout<<"\n1)Make_Set\n2)Find_Set\n3)Union\n4)Exit\n";
                cout<<"Enter the option you want to perform: ";
                cin>>option;
                switch(option){
                    case 1:
                    make_set(arr,n);
                    break;
                    case 2:
                    cout<<"\nEnter the element to find its set: ";
                    cin>>k;
                    k=find_set(k,arr);
                    cout<<"Representative element of the set is: "<<k<<"\n";
                    break;
                    case 3:
                    cout<<"\nEnter the Vertices for union\n";
                    cout<<"Vertex 1: ";
                    cin>>i;
                    cout<<"Vertex 2: ";
                    cin>>j;
                    union_set(i,j,arr,n);
                    break;
                    case 4:
                    exit=1;
                    break;
                    default:
                    printf("ERROR\nThe input is invalid. Please enter again\n\n");
                    break;
                }
            }
            break;
            case 3:
            loop=0;
            break;
            default:
            printf("ERROR\nThe input is invalid. Please enter again\n\n");
            break;
        }
    }
    return 0;
}
