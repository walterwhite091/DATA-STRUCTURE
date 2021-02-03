#include<bits/stdc++.h>
using namespace std ;

#define hell 1000000007
#define ll long long
#define vvl vector<long>
#define loop(i,n) for(int i=0; i<n; i++)
#define pll pair<ll,ll>
#define pb push_back




int main()
{
    int n  , m ; 
    cin >> n >> m ; 

    vector<int> first  , second ; 

    while(n--)
    {
        int x ; cin>>x ; 
        first.push_back(x) ;
    }
    while(m--)
    {
        int x ; cin >> x ; 
        second.push_back(x) ; 
    }

    int  l = 0 , r =0 , len =first.size() + second.size() ;
    int p ; 
    int flag =0 , count =0    ; double ans=0; 
   
    if(len%2==0)
    {
        flag =1 ; // need two value ; 
    }
    len = len/2 ; 
    
   

    if(first[l] < second[r])
    {
        l++ ; 
        p =0 ; 
        count++ ; 

         if(len==count)
        {
            if(flag==0)
            ans +=first[p] ; 
            else
            {
                ans+=first[p] ;
                ans+=min(first[l] , second[r] ) ;  
                ans = ans /2 ; 
            }
             cout<<ans<<endl;
             return 0;
        }
    }
    else
    {
        r++ ; 
        p=0 ; 
        count++ ; 
    }


    while(l<first.size() && r < second.size())
    {
         if(first[l] < second[r])
         {
              p = l ; 
              l++ ; 
              count++ ; 

               if(len==count)
        {
            if(flag==0)
            ans +=first[p] ; 
            else
            {
                ans+=first[p] ;
                ans+=min(first[l] , second[r] ) ;  
                ans = ans / 2 ; 
            }
            cout<<ans<<endl;
            return 0 ;
        }

         }
         else
         {
             p= r ; 
             r++ ; 
             count++ ; 
             if(len==count)
        {
            if(flag==0)
            ans +=second[p] ; 
            else
            {
                ans+=second[p] ;
                ans+=min(first[l] , second[r] ) ;  
                ans = ans / 2 ; 
            }
            cout<<ans<<endl;
            return 0 ;
        }

         }
         
    }

    if(l==first.size())
    {
        for(int i = r ; i <second.size() ; i++)
        {
            count++ ;
            if(len==count)
        {
            if(flag==0)
            ans +=second[i] ; 
            else
            {
                ans+=second[i] ;
                ans+=second[i+1];  
                ans = ans / 2 ; 

            }
            cout<<ans<<endl;
            return 0;
        }

        }
    }

    if(r==second.size())
    {
        for(int  i = l ; i <first.size() ; i++)
        {
            count++ ; 
            if(len==count)
        {
            if(flag==0)
            ans +=first[i] ; 
            else
            {
                ans+=first[i] ;
                ans+=first[i+1];  
                ans = ans/2 ; 
            }
            cout<<ans<<endl;
            return 0 ;
        }
            
        }
    }
    

 

}