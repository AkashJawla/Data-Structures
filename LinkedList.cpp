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

void del_data(int data){
  Node* n = head;
  if(head->data==data){head=n->next; free(n); return;}
  Node* f=n;
  while(n!=NULL && n->data!=data){
    f=n;
    n=n->next;
  }
  f->next=n->next;
  free(n);
}

void count_del(int data){
  int ctr=0;
  int i=0;
  Node* n= head;
  while (n!=NULL) {
    n=n->next;
    i++;
  }
  int ctr_pos[i];
  n=head;
  i=0;
  int pos;
  while(n!=NULL){
    if(n->data==data){
      ctr_pos[ctr++]=i;
    }
    i++;
    n=n->next;
  }
  if(ctr>1){
    cout<<"\nmultiple instances found!!!\n"<<"positions ->";
    for(i=0;i<ctr;i++){
    cout<<ctr_pos[i]+1<<" ";
    }
    cout<<" \nEnter position to delete or Press 0 to delete all :";
    cin>>pos;
    if(pos!=0) del_any(pos);
    else{
      for(i=0;i<ctr;i++){
        del_data(data);
      }
    }
  }
  else{
    del_any(ctr_pos[0]+1);
  }
}


int main() {
  int data;
  int option;
  int pos;
  int *ctr_pos;
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
      cout<<"4. Delete a particular number\n";
      cin>>option;
      option+=3;
      }
   else if(option==3) option=8;
    else if(option==4) option=99;
    else option=999;
  switch (option) {
    case 1: insert_beg(data); break;
    case 2: cout<<"Enter position : "; cin>>pos; insert_any(data,pos); break;
    case 3: insert_end(data); break;
    case 4: del_beg(); break;
    case 5: del_end(); break;
    case 6: cout<<"Enter position : "; cin>>pos; del_any(pos); break;
    case 7: cout<<"Enter the data : "; cin>>data; count_del(data); break;
    case 8: display(); break;
    case 99: break;
    default: cout<<"Wrong input. Enter again!!\n";
  }
}while(option!=99);
  return 0;
}
