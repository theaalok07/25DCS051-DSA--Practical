
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data)
{
    Node* newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node* insert(Node* root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }

    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Node* root=NULL;
    int n;
    int code;

    cout<<"Enter number of books: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter book code: ";
        cin>>code;
        root=insert(root,code);
    }

    cout<<"Inorder sequence: ";
    inorder(root);

    cout<<endl;

    return 0;
}

