#include<bits/stdc++.h>
using namespace std ;

#define hell 1000000007
#define ll long long
#define vvl vector<long>
#define loop(i,n) for(int i=0; i<n; i++)
#define pll pair<ll,ll>
#define pb push_back

// hashmap
void solution1(vector<int> v)
{
    unordered_map<int,int>m ; 
    for(auto x : v)
    {
        m[x]++ ; 
    }

    for(auto x : m)
    {
        int k = x.second ; 
        k-- ; 
        if(k)
        {
            cout<<x.first<<" ";
        }
    }
    cout<<endl;
}

void solution2(vector<int>v)
{
    sort(v.begin() , v.end()) ; 
    int curr = v[0] , flag = 0  ; 
    for(int i =1 ; i <v.size() ; i++)
    {
        if(curr==v[i] && flag ==0)
        {
            flag  =1 ; 
            cout<<v[i]<<" "; 
        }
        else if(curr!=v[i])
        {
            flag = 0 ; 
            curr = v[i] ; 
        }
    }
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
3
1 2 3

3
1 2 2

3
3 3 3

4
2 1 2 1

*/