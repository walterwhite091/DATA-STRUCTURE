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

node*  insert(node *root , int val)
{
    node *temp = new node(val); 

    if(root==NULL)
    return temp ; 
    else
    {
        root->next =  insert(root->next , val) ;
    }
    
    return root ; 

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

node* del_a_node(node * root , int val)
{
    node * prev = NULL ; 
    node *curr = root ; 

    if(curr->data==val)
    {
        root = root->next ; 
        return root ; 
    }

    while(curr!=NULL  && curr->data!=val)
    {
        prev = curr ; 
        curr= curr->next ; 
    }
    
    if(curr==NULL)
    prev->next = NULL ; 
    else if(curr->data == val)
    {
        prev->next = curr->next ; 
    }

    return root ; 
  
}
node *dups(node *root )
{
    unordered_map< int, bool> m ; 

    node *curr = root ;
    node * prev = NULL ; 

    while(curr!=NULL)
    {
        if(m[curr->data]==true)
        {
            prev->next = curr->next ; 
            node *temp = curr ; 
            //prev = curr ; 
            curr=curr->next ; 
            delete temp ; 
        }
        else
        {
            m[curr->data] = true ; 
            prev = curr ; 
            curr=curr->next ; 
        }
        
    }
    return root ; 

}

node * partition_list(node *root , int val)
{
    node * l = root ; 
    node * r = root ;

    while(r!=NULL)
    {
        if(r->data < val)
        {
            int temp = r->data ; 
            r->data = l->data ; 
            l->data = temp ; 

            l= l->next ; 
        }
        r=r->next ; 
    }

    return root ;  
}

// node * delete_middle_node(node * root) // look into this
// {
//     node* prev = NULL ; 
//     node * slow = root ; 
//     node * fast = root->next ; 

//    cout<<slow->data<<" "<<fast->data;

//    while(fast!=NULL)
//    {
//        slow = slow->next ; 
//        if(fast->next)
//        fast = fast->next->next ;
       

//        if(fast->next==NULL)
//        break ; 
       
//    }
   
//    cout<<slow->data;
//     return root ; 

// }

int main()
{

 node *root  = NULL ; 
 int n ; 
 cin>>n ; 

 while(n--)
 {
    
     int x ;
     cin >> x ; 
     root = insert(root , x ) ; 
 }

//  int del ; 
//  cout<<"NUMBER YOU WANT TO DELETE"<<endl;
//  cin>>del;
//  root = del_a_node(root , del) ;  

// remove duplicate
// root = dups(root) ; 

/*******************************/
// Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
// the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
// that node.
// EXAMPLE
// Input: the node c from the linked list a - >b- >c - >d - >e- >f
// Result: nothing is returned, but the new linked list looks like a - > b - > d - > e - > f
//solution:-

//root = delete_middle_node(root) ; 
//print(root) ; 


/*******************************/
// Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
// before all nodes greater than or equal to x. Ifxis contained within the list, the values of x only need
// to be after the elements less than x (see below). The partition element x can appear anywhere in the
// "right partition"; it does not need to appear between the left and right partitions.
// EXAMPLE
// Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
// Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
// solution :- 

// int partition_val ; 
// cin>>partition_val ; 
// root = partition_list(root , partition_val) ; 
// print(root) ; 

/*****************************/
// Sum Lists: You have two numbers represented by a linked list, where each node contains a single
// digit. The digits are stored in reverse order, such that the Vs digit is at the head of the list. Write a
// function that adds the two numbers and returns the sum as a linked list.
// EXAMPLE
// Input: ( 7 - > 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
// Output: 2 -> 1 -> 9. That is, 912.
//solution :-

// int m  ;cin>> m ; 
// node* root1 = NULL ; 
// while(m--)
// {
//     int x ; cin >>x ; 
//     root1 = insert(root1 , x) ; 
// }

// node *temp1 = root ; 
// node *temp2 = root1 ;
// int carry =0 ; 

// while(temp1!=NULL && temp2!=NULL)
// {
//     int sum = temp1->data + temp2->data + carry ; 
//     temp1->data = sum%10 ; 
//     carry = sum/10 ; 

//     temp1 = temp1->next ; 
//     temp2 = temp2->next ; 
// }

// if(temp1==NULL && temp2==NULL)
// {
//     if(carry)
//     root = insert(root , carry) ; 
// }
// else if(temp1!=NULL)
// {
//     while(temp1!=NULL)
//     {
//         int sum = temp1->data + carry ;
//         temp1->data = sum%10 ; 
//         carry =sum/10 ; 
//        temp1=temp1->next ; 
//     }
//     if(carry)
//     root = insert(root , carry) ; 
    

// }
// else if(temp2!=NULL)
// {
//     while(temp2!=NULL)
//     {
//         int sum = temp2->data + carry ;
//         root= insert(root , sum%10) ; 
//         carry =sum/10 ; 
//        temp2=temp2->next ; 
//     }
//     if(carry)
//     root = insert(root , carry) ; 

// }




print(root) ; 

 


}