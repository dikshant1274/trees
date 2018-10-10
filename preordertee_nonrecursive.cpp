#include<iostream>
using namespace std;
#define MAX 100
struct node
{
  int data;
  node *right;
  node *left;
};
node *stack[MAX];
int top=-1;
void push(node *item)
{
  if(top==MAX-1)
  {
    cout<<"stack overflow"<<endl;
    return;
  }
  top++;
  stack[top]=item;
}
node* pop()
{
  if(top==-1)
  {
    cout<<"stack underflow"<<endl;
    return NULL;
  }
  node *item;
  item=stack[top--];
  return item;
}
int isempty()
{
  if(top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
node* newnode(int data)
{
  node *temp=new node;
  temp->data=data;
  temp->right=NULL;
  temp->left=NULL;
  return temp;
}
void preorder(node *root)
{
  node *ptr=root;
  if(ptr==NULL)
  {
    cout<<"tree is empty"<<endl;
    return;
  }
  push(ptr);
  while(!isempty())
  {
    ptr=pop();
    cout<<ptr->data<<endl;
    if(ptr->right!=NULL)
    push(ptr->right);
    if(ptr->left!=NULL)
    push(ptr->left);
  }
}
int main()
{
  node *root=newnode(10);
  root->left=newnode(12);
  root->left->left=newnode(13);
  root->left->right=newnode(14);
  root->right=newnode(15);
  root->right->left=newnode(16);
  preorder(root);
}
