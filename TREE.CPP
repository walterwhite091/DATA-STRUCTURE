// UNCOMPLETE QUESTIONS :-

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
    public:
     int data ;
     node * left; 
     node * right;
     node *next ; 
 
       node()
      {
          left = NULL ; 
          right = NULL ; 
          next =NULL ; 
      }

      node(int i)
      {
          data = i ; 
          left = NULL ; 
          right = NULL ; 
          next = NULL ; 
      }
    

} ;

node * insert(node *root , int val)
{
    // node *root = *head ; 
    node* temp = new node(val) ; 

    if(root==NULL)
    {
        return temp ; 
    }
    else if(root->data < val)
    {
        root->right =  insert(root->right , val) ; 
    }
    else
    {
         root->left =  insert(root->left , val) ; 
    }

    return root ; 
    
}

void preorder(node *root)
{
   
    if(root==NULL)
    return ;

    cout<<root->data << " ";
    preorder(root->left) ; 
     
    preorder(root->right) ; 
   
}

int height(node *root )
  {
      if(root==NULL)
      {
          return 0 ; 
      }
      
      return max(height(root->left) , height(root->right)) + 1 ; 
  }

int diameter(node *root)
{
   if(root==NULL)
   return 0 ; 

   int left_height = height(root->left) ; 
   int right_height = height(root->right) ; 

   return max( diameter(root->left) ,  max(diameter(root->right)  , left_height + right_height+1    ))  ;   
}
int diameter_dp(node *root ,  unordered_map<node* , int >&dp)
{
   if(root==NULL)
   return 0 ; 

   int left_height , right_height ; 
   if(dp[root->left])
   {
       left_height = dp[root->left] ; 
   }
   else
   {
        left_height = height(root->left) ; 
   }
   
   if(dp[root->right])
   {
        right_height = dp[root->right] ; 
   }
   else
   {
        right_height = height(root->right) ; 
   }
   

   return max( diameter_dp(root->left , dp ) ,  max(diameter_dp(root->right , dp)  , left_height + right_height+1    )  )  ;   
}

vector<node * > left_view(  node * root )
{
    vector<node *>ans ; 

    if(root==NULL)
    return ans ;

    queue<node *> q ; 
    q.push(root) ; 
    ans.push_back(root) ; 
    int sum = 1 ; 

    while(!q.empty())
    {
        node *temp = q.front() ; 
        q.pop() ; 
        sum--; 
        
        if(temp->left)
        q.push(temp->left);

        if(temp->right)
        q.push(temp->right) ; 

        if(sum==0)
        {
            sum = q.size() ; 

            if(sum!=0)
            {
                ans.push_back(q.front()) ; 
            }
        }

    } 

    return ans ; 
}

vector<int> right_view(  node * root )
{
    vector<int>ans ; 

    if(root==NULL)
    return ans ;

    queue<node *> q ; 
    q.push(root) ; 
   // ans.push_back(root->data) ; 
    int sum = 1 ; 

    while(!q.empty())
    {
        node *temp = q.front() ; 
        q.pop() ; 
        sum--; 
        
        if(temp->left)
        q.push(temp->left);

        if(temp->right)
        q.push(temp->right) ; 

        if(sum==0)
        {
            sum = q.size() ; 

            ans.push_back(temp->data) ; 
        }

    } 

    return ans ; 
}

node *lowest_common_ancestor(node *root , int a , int b) // for bst
{
    if(a>b)
    swap(a,b) ; 

    if(root==NULL)
    return root ; 
    else if(a<=root->data && b >= root->data)
    return root ; 
    else if(a<root->data && b < root->data)
    return lowest_common_ancestor(root->left , a,b) ; 
    
    return lowest_common_ancestor(root->right , a, b) ; 
}

node * minimum_insertion(node *root , int l , int r , vector<int>&v)
{
    if(l<=r)
    {

        int n = l-r +1 ; 
    if(n==1)
    {
       return insert(root , v[l]) ; 
    }
    else if(n==2)
    {
        root = insert(root , v[l] ) ; 
        root = insert(root , v[r]) ; 
        return root ; 
    }

    int mid = (l+r ) / 2 ; 
    root = insert(root , v[mid] ) ; 
    root = minimum_insertion(root , l , mid-1 , v) ; 
    root = minimum_insertion(root , mid+1 , r , v) ; 
    return root ; 

    }

    return root ; 
}

node *linked_list(node *root)
{
    queue<node *> q ; 
    q.push(root) ; 
    int sum =1 ; 

    while(!q.empty())
    {
        node *temp = q.front() ; 
        q.pop() ; 
        sum-- ; 

        if(temp->left)
        q.push(temp->left) ; 

        if(temp->right)
        q.push(temp->right) ; 

        if(sum==0)
        {
            sum = q.size() ; 
            queue<node *> link = q ; 

            while(!link.empty())
            {
                node *ok = link.front() ; 
                link.pop() ; 
                if(!link.empty())
                {
                    ok->next = link.front(); 

                }
                else
                {
                    ok->next = NULL ; 
                }
                
            }
        }
    }

    return root ; 
}

void print_linked_list(node *root)
{
    if(root==NULL)
    return ; 

    cout<<root->data<<" ";
    print_linked_list(root->next) ; 
}

bool isBalanced(node *root)
{
    if(root==NULL)
    return true ; 

    int left_height = height(root->left) ;
    int right_height = height(root->right) ; 

    if(abs(left_height-right_height) >1)
    return false ; 

    return isBalanced(root->left) && isBalanced(root->right); 


}

bool validBST(node *root , int mini , int maxi)
{
    if(root==NULL)
    return true ; 

    return (root->data >mini && root->data < maxi) && (validBST(root->left , mini , root->data) ) && (validBST(root->right , root->data , maxi)) ; 
}


void inorder_successor(node *root , node *curr , int &flag , int &ans)
{
    if(root==NULL)
    return ; 
    inorder_successor(root->left , curr , flag , ans) ; 

    if(flag==0 && root==curr)
    flag= 1 ;
    else if(flag==1)
    {
        flag =0 ; 
        ans = root->data ; 
    }
    
    //cout<<root->data<<" ";
    inorder_successor(root->right , curr ,flag , ans);
}

vector< vector<int> > bstSequences (node *root)
{
    vector< vector<int> > ans ; 
    if(root==NULL)
    return ans ; 

        int value = root->data ; 
        vector<int>temp ; 
        temp.push_back(value) ;
        ans.push_back(temp) ; 

    vector< vector<int> > left_box = bstSequences(root->left) ; 
    vector< vector<int> > right_box = bstSequences(root->right) ;  

    if(left_box.size() || right_box.size())
    {
        ans.pop_back() ; 
    }
    

    for(auto x : left_box)
    {
        vector<int>temp ; 
        temp.push_back(value) ; 

        for(auto z : x)
        {
            temp.push_back(z) ; 
        }

        for(auto y : right_box)
        {
            vector<int>temp2 = temp ;
            for( auto i : y)
            {
                temp2.push_back(i) ; 
            }
            ans.push_back(temp2) ; 
        }
        
    }

      for(auto x : right_box)
    {
        vector<int>temp ; 
        temp.push_back(value) ; 

        for(auto z : x)
        {
            temp.push_back(z) ; 
        }

        for(auto y : left_box)
        {
            vector<int>temp2 = temp ;
            for(auto i : y)
            {
                temp2.push_back(i) ; 
            }
            ans.push_back(temp2) ; 
        }
        
    }
    return ans ; 



    
}


int main()
{

   int n ; 
   cin>> n ; 
   vector<int> v ; 

   node* root_old = NULL ;
   node* root_new =NULL ; 

   while(n--)
   {
       int  t ; cin >> t ; 
       root_old = insert(root_old , t) ; 
       v.pb(t) ; 
   }
    int l=0 , r = v.size()-1 ; 
    root_new = minimum_insertion(root_new , l , r , v) ; 

    // preorder(root_old);
    // cout<<endl;
    // preorder(root_new) ; 
    // cout<<endl;

    vector<vector<int> > ans = bstSequences(root_new) ; 

    for(auto x : ans)
    {
        for(auto y : x)
           cout<<y<<" " ;

        cout<<endl;
    }

 
    








}