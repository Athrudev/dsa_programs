#include<iostream>
#include<cctype>
#include<algorithm>
#include<stack>
using namespace std;
struct node
{
  char data;
  node* left;
  node* right;
};
node* createNode(char input)
{
   node* newnode=new node();
   newnode->data=input;
   newnode->left=NULL;
   newnode->right=NULL;
   return newnode;
}

node* BuildExpressionTreeFromPostfix(string input)
{
    stack<node*>stack;
    for(int i=0;i<input.length();i++)
    {
        if(isalpha(input[i]) || isdigit(input[i]))
        {
           node* new_node=createNode(input[i]);
           stack.push(new_node);
        }
        else if(input[i]=='+' || input[i]=='-' || input[i]=='/' || input[i]=='*')
        {
             node* new_node=createNode(input[i]);
             new_node->right=stack.top();
             stack.pop();
             new_node->left=stack.top();
             stack.pop();
             stack.push(new_node);
        }
   }
   return stack.top();
}

node* BuildExpressionTreeFromPrefix(string input)
{
    stack<node*>stack;
   //read prefix expression from right to left
    for(int i=input.length()-1;i>=0;i--)
    {
        if(isalpha(input[i])||isdigit(input[i]))
        {
           node* new_node=createNode(input[i]);
           stack.push(new_node);
        }
        else if(input[i]=='+'||input[i]=='-' ||input[i]=='/' || input[i]=='*')
        {
            node* new_node=createNode(input[i]);
            new_node->left=stack.top();
            stack.pop();
            new_node->right=stack.top();
            stack.pop();
            stack.push(new_node);
        }
    }
    return stack.top();
}

void Inorder(node* root)
{
   if(root)
   {
      Inorder(root->left);
      cout <<root->data;
      Inorder(root->right);
   }
}

void Preorder (node* root)
{
   if(root)
   {
      cout << root->data;
      Preorder(root->left);
      Preorder(root->right);
   }
}

void PostOrder(node* root)
{
    if(root)
    {
    PostOrder(root->left);
    PostOrder (root->right);
    cout<<root->data;
    }
}
int main()
{
    int choice;
    char continueChoice; 
    node* tree;
    do{
    cout << "Enter your choice whether expression is 1.Postfix or 2. Prefix =" << endl;
    cin >> choice;
    string input;
    switch(choice)
    {
       case 1: cout << "Enter input string =" << endl;
               cin >> input;
               tree=BuildExpressionTreeFromPostfix(input);
               cout<<"Inorder =";
               Inorder(tree);
               cout<< endl;
               cout<<"PostOrder =";
               PostOrder(tree);
               cout<<endl;
               cout<<"Preorder =";
               Preorder(tree);
               cout<<endl;
               break;
               
         case 2:cout << "Enter prefix string =" << endl;
              cin>>input;
              tree=BuildExpressionTreeFromPrefix(input);
              cout<<"Inorder =";
               Inorder(tree);
               cout<< endl;
               cout<<"PostOrder =";
               PostOrder(tree);
               cout<<endl;
               cout<<"Preorder =";
               Preorder(tree);
               cout<<endl;
             break;    
    }
    cout<<"Do you wants to continue (y|n)=";
    cin>>continueChoice;
   }while(continueChoice=='y');
    
    
}