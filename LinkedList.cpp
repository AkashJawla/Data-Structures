#include<iostream>

using namespace std;

class Node{
  public:
  int data;
  Node *next;

  Node(int n){
    data=n;
    next=NULL;
  }
};

Node* head = NULL;

void display(){
  Node* n=head;
  cout<<"List -> ";
  while (n!=NULL) {
    cout<<n->data<<" ";
    n=n->next;
  }
}

void insert_beg(int data){
  Node* n = new Node(data);
  if(head==NULL){
    head=n;
  }
  else{
    n->next=head;
    head=n;
  }
}

void insert_end(int data){
  Node* n=new Node(data);
  if(head==NULL){
    head=n;
  }
  else{
    Node* f=head;
    while (f->next!=NULL) {
      f=f->next;
    }
    f->next=n;
  }
}

void insert_any(int data,int pos){
  if(pos==1) {insert_beg(data); return;}
  Node* n=new Node(data);
  if(head==NULL){
    return;
  }
  Node* f=head;
  for(int i=0;i<pos-2 && f!=NULL;i++){
    f=f->next;
  }
  n->next=f->next;
  f->next=n;
}

void del_beg(){
  Node* n=head;
  head=n->next;
  free(n);
}

void del_end(){
  Node* f=head;
  Node* n=f;
  if(head->next==NULL){head=NULL; return;}
  while (f->next!=NULL) {
    n=f;
    f=f->next;
  }
  n->next=NULL;
  free(f);
}

int main() {
  int data;
  while (1) {
  cout<<"\nSelect option\n";
  cout<<"1. insert Beg\n";
  cout<<"2. insert Any\n";
  cout<<"3. insert End\n";
  cout<<"4. delete Beg\n";
  cout<<"5. delete End\n";
  cout<<"7. display\n";
  int option;
  Start1:
  cin>>option;
  if(option==1 || option==2 || option==3){
    cout<<"Enter data : ";
    cin>>data;
  }
  switch (option) {
    case 1: insert_beg(data); break;
    case 2: cout<<"Enter position : "; int pos; cin>>pos; insert_any(data,pos); break;
    case 3: insert_end(data); break;
    case 4: del_beg(); break;
    case 5: del_end(); break;
    case 7: display(); break;
    default: cout<<"Wrong input. Enter again!!\n";
  }
}
  return 0;
}
