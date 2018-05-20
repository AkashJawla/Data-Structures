#include <iostream>
using namespace std;
class Node {
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

void swap(int n1,int n2){
  Node *node2=head;
  Node *node1=NULL,*prev1,*prev2;
  if(n1!=n2){
    while(node2){
      if(node2->data==n1){
        node1=node2;
        break;
      }
      prev1=node2;
      node2=node2->next;
    }
    node2=head;
    while(node2){
      if(node2->data==n2){
        break;
      }
      prev2=node2;
      node2=node2->next;
    }
  }
  else{
    cout<<"same elements!!";
    return;
  }
  if(node1==NULL || node2==NULL){
    cout<<"no match found";
    return;
  }
  if((node1==head || node2==head) && (node1==prev2 || node2==prev1)){
      if(node2==head){
      node2=node1;
      node1=head;
    }
    head=node2;
    node1->next=node2->next;
    node2->next=node1;
    return;
  }
  if(node1==head || node2==head){
    if(node2==head){
      node2=node1;
      node1=head;
      prev2=prev1;
    }
    head=head->next;
    prev2->next=node1;
    node1->next=node2->next;
    node2->next=head;
    head=node2;
    return;
  }
  if(node1==prev2 || node2==prev1){
      if(node2==prev1){
          node2=node1;
          node1=node2;
          prev1=prev2;
      }
      prev1->next=node2;
      node1->next=node2->next;
      node2->next=node1;
      return;
  }
  prev1->next=node2;
  prev2->next=node2->next;
  node2->next=node1->next;
  node1->next=prev2->next;
  prev2->next=node1;
}

int main(){
  Node *n1=new Node(1);
  Node *n2=new Node(2);
  Node *n3=new Node(3);
  Node *n4=new Node(4);
  Node *n5=new Node(5);
  head=n1;
  n1->next=n2;
  n2->next=n3;
  n3->next=n4;
  n4->next=n5;
  display();
  swap(1,2);
  display();
}
