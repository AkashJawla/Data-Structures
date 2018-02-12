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
void del_any(int pos){
    if(pos==1){del_beg(); return;}
    if(head==NULL){return;}
    Node* f=head;
    for(int i=0;i<pos-2 && f!=NULL;i++){
    f=f->next;
    }
    Node* n=f->next;
    f->next=n->next;
    free(n);
}
int main() {
  int data;
  int option;
  int pos;
  do {
  cout<<"\nSelect option\n";
  cout<<"1. Insert\n";
  cout<<"2. Delete\n";
  cout<<"3. Display\n";
  cout<<"4. Exit\n";


  cin>>option;
  if(option==1){
      cout<<"1. Insert in the Beggining.\n";
      cout<<"2. Insert at any Position.\n";
      cout<<"3. Insert in the End.\n";
      cin>>option;
      cout<<"Enter data : ";
      cin>>data;
      }
  else if(option==2){
      cout<<"1. Delete in the Beggining.\n";
      cout<<"2. Delete in the End.\n";
      cout<<"3. Delete at any Position.\n";
      cin>>option;
      option+=3;
      }
   else if(option==3) option=7;
    else if(option==4) option=8;
    else option=9;
  switch (option) {
    case 1: insert_beg(data); break;
    case 2: cout<<"Enter position : "; cin>>pos; insert_any(data,pos); break;
    case 3: insert_end(data); break;
    case 4: del_beg(); break;
    case 5: del_end(); break;
    case 6: cout<<"Enter position : "; cin>>pos; del_any(pos); break;
    case 7: display(); break;
    case 8: break;
    default: cout<<"Wrong input. Enter again!!\n";
  }
}while(option!=8);
  return 0;
}
