#include<iostream>
#include<cctype>
#include<algorithm>
#include<stack>
using namespace std;



struct node{
   char data;
   node* left;
   node* right;
};


node* createNode(char val){
   node* new_node=new node();
   new_node->data=val;
   new_node->left=NULL;
   new_node->right=NULL;
   return new_node;
}


node*PostfixTree(string s){
   stack<node*> Stack;

   for(int i=0;i<s.length();i++){
      if(isalpha(s[i]) || isdigit(s[i]) ){
         node* new_node=createNode(s[i]);
         Stack.push(new_node);
      }else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){

         node* new_node=createNode(s[i]);
         new_node->right=Stack.top();
         Stack.pop();
         new_node->left=Stack.top();
         Stack.pop();
         Stack.push(new_node);

      }

   }

   return Stack.top();

}


node* PrefixTree(string s){
   stack<node*>stack;
   for(int i=s.length();i>=0;i--){

      if(isalpha(s[i]) || isdigit(s[i])){
         node* new_node=createNode(s[i]);
         stack.push(new_node);
      }else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
         node* new_node=createNode(s[i]);
         new_node->left=stack.top();
         stack.pop();
         new_node->right=stack.top();
         stack.pop();

         stack.push(new_node);
      }

   }

   return stack.top();
}


node* InOrder(node* root){
   if(root){
      InOrder(root->left);
      cout<<root->data;
      InOrder(root->right);
   }
}

node* PreOrder(node* root){
   if(root){
      cout<<root->data;
      PreOrder(root->left);
      PreOrder(root->right);
   }
}

node* PostOrder(node* root){
   if(root){
      PostOrder(root->left);
      PostOrder(root->right);
      cout<<root->data;
   }
}


int main(){
   bool loop=true;
   int ch;
   string input;
   node* tree;

   while(loop){

   cout<<"\n1.Postfix";
   cout<<"\n2.Prefix";
   cout<<"\n3.Exit";
   cout<<"\nChoice:";
   cin>>ch;

      switch (ch)
      {
      case 1:
         
         cout<<"Enter the postfix Expression:";
         cin>>input;
         tree=PostfixTree(input);
         cout<<"\nInorder:";
         InOrder(tree);
         cout<<"\nPreorder:";
         PreOrder(tree);
         cout<<"\nPostOrder:";
         PostOrder(tree);
      
         break;
      
      case 2:
         cout<<"Enter the prefix Expression:";
         cin>>input;
         tree=PrefixTree(input);
         cout<<"\nInorder:";
         InOrder(tree);
         cout<<"\nPreorder:";
         PreOrder(tree);
         cout<<"\nPostOrder:";
         PostOrder(tree);
         break;

      case 3:
         loop=false;
         break;

      default:
         cout<<"Invalid choice";
         break;
      }

   }


   return 0;
}