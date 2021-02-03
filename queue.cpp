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

node *front =NULL ;
node *back = NULL ; 

node*  push(node *root , int val)
{
    node *temp = new node(val); 
    // node *front = *f ;
    // node *back = *b ; 

    if(root==NULL)
    {
        root =temp ; 
        front = temp ; 
        back = temp ; 
        return root ; 
    }
    else
    {
        back->next = temp ; 
        back = temp ; 
    }
    
    return root ; 

}

 node * pop(node *root)
{
    node *temp = root ; 
    if(root==NULL || front==back)
    {
        front =NULL ;
        back = NULL ; 
        return NULL ; 
    }
    else
    {
        root = root->next ; 
        front = root ; 
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

int front_element(node *root)
{
    if(isempty(root))
     {
         cout<<"OOPS STACK IS EMPTY "<<endl ; 
         return -1 ; 
     }
     
     return front->data ; 
}
int back_element(node *root)
{
    if(isempty(root))
     {
         cout<<"OOPS STACK IS EMPTY "<<endl ; 
         return -1 ; 
     }
     
     return back->data ; 
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
  node *front =NULL ;
  node *back = NULL ; 
  int n ; 
  cin>>n ; 
  while(n--)
  {
      int x ; 
      cin >> x;
      root= push(root , x) ; 
      print(root) ;  
      cout<<endl;
      cout<<front_element(root)<<" "<<back_element(root)<<endl;

  }
  
//   root = pop(root) ;
//     print(root) ;  
//       cout<<endl;
// //   cout<<peek(root)<<endl;


//   root = pop(root) ;
//     print(root) ;  
//       cout<<endl;
// //   cout<<peek(root)<<endl;

// //   root = pop(root) ;
// //     print(root) ;  
// //       cout<<endl;
// //   cout<<peek(root)<<endl;
  
//   //print(root) ; 
 


}