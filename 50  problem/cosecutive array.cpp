#include<bits/stdc++.h>
using namespace std ;

#define hell 1000000007
#define ll long long
#define vvl vector<long>
#define loop(i,n) for(int i=0; i<n; i++)
#define pll pair<ll,ll>
#define pb push_back

// nlongn || space O(1)
void solution1(vector<int> v)
{
    sort(v.begin() , v.end()) ; 
    int global_max = 1 ; 
    int curr_max = 1 ; 
    for(int i=1 ;i <v.size() ; i++)
    {
        if(v[i-1]+1 == v[i])
         curr_max+=1 ;
        else
        {
            curr_max =1 ; 
        }
        

        global_max = max(global_max , curr_max) ; 
    }

    cout<<global_max;
    cout<<endl;
}

// using set o(N) || space = o(N) 
void solution2(vector<int>v)
{
    set<int>s ; 
    int curr_max = 1 ;
    int global_max = 1 ; 

    for(auto x : v)
    {
        s.insert(x) ; 
    }
    int pre , i=0;

    for(auto x : s)
    {
        if(i==0)
        {
            pre = x ; 
        }
        else if(i && x==pre+1)
        {
            curr_max+=1 ;
            pre = x ; 
        }
        else if(i && x!=pre+1)
        {
            curr_max = 1;
            pre = x ;
        }
        global_max = max(global_max , curr_max);
        i++ ; 
    }

    cout<<global_max;



    cout<<endl;
}


int main()
{
    int n ; 
    cin>>n ; 
    vector<int> v; 
    while(n--)
    {
        int x ; 
        cin >> x; 
        v.pb(x) ; 
    }
    solution1(v) ; 
    solution2(v) ; 
    

 

}

/*
5
4 2 1 6 5

4
5 5 3 1

*/