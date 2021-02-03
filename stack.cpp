#include<bits/stdc++.h>
using namespace std ;

#define hell 1000000007
#define ll long long
#define vvl vector<long>
#define loop(i,n) for(int i=0; i<n; i++)
#define pll pair<ll,ll>
#define pb push_back

class node
{
   public : 
        int data ; 
        node * next ; 

   node(int x)
   {
       data = x ; 
       next = NULL ; 
   }
   node()
   {
       next=NULL ; 
   }
} ;

node*  push(node *root , int val)
{
    node *temp = new node(val); 

    if(root==NULL)
    return temp ; 
    else
    {
        temp->next = root ; 
        root = temp ; 
    }
    
    return root ; 

}

node * pop(node *root)
{
    node *temp = root ; 
    if(root==NULL)
    {
        return NULL ; 
    }
    else
    {
        root = root->next ; 
        delete temp ; 
    }
    return root ; 
    
}

bool isempty(node *root)
{
    if(root=NULL)
    return true ; 

    return false ; 
}

int peek(node *root)
{
    if(isempty(root))
     {
         cout<<"OOPS STACK IS EMPTY"<<endl ; 
         return -1 ; 
     }
     
     return root->data ; 
}

void print(node *root)
{
    if(root==NULL)
    {
       return ; 
    }
   

    cout<<root->data<<" " ; 
    print(root->next) ; 
}

int main()
{

  node *root = NULL ; 
  node *minstack  = NULL ; 
  minstack = push(minstack , INT_MAX) ; 
  int n ; 
  cin>>n ; 
  while(n--)
  {
      int x ; 
      cin >> x;
      root= push(root , x) ; 
      if(x< peek(minstack))
      {
          minstack = push(minstack, x) ; 
      }
      else
      {
          minstack = push(minstack , peek(minstack)) ; 
      }
      
      print(root) ;  
      cout<<endl;

  }
  

// Stack Min: How would you design a stack which, in addition to p u s h and pop, has a function m i n
// which returns the minimum eiement? Push, p o p and m i n should ail operate in 0 ( 1 ) time.

//solution:-

//   cout<<"MIN VALUE OF STACK TILL NOW "<<peek(minstack)<<endl;

//   root = pop(root) ;
//   minstack = pop(minstack) ; 
//  cout<<"MIN VALUE OF STACK TILL NOW "<<peek(minstack)<<endl;


//   root = pop(root) ;
//   minstack = pop(minstack) ; 
//   cout<<"MIN VALUE OF STACK TILL NOW "<<peek(minstack)<<endl;

//   root = pop(root) ;
//   minstack = pop(minstack) ; 
//   cout<<"MIN VALUE OF STACK TILL NOW "<<peek(minstack)<<endl;
  
//   print(root) ; 
 


}