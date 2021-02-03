#include<bits/stdc++.h>
using namespace std ;

#define hell 1000000007
#define ll long long
#define vvl vector<long>
#define loop(i,n) for(int i=0; i<n; i++)
#define pll pair<ll,ll>
#define pb push_back

void matrix_product(vector< vector<int> > v1 , vector< vector<int> >v2)
{
    int a,b,c,d ; 
    a=v1.size() ; 
    b= v1[0].size();
    c = v2.size() ; 
    d = v2[0].size() ; 

    if(b!=c)
    {
        cout<<"NOT POSSIBLE" ; 
        return ; 
    }

    vector< vector<int> > ans(a , vector<int>(d,0)) ;

    for(int r = 0 ; r <a ; r++) 
    {
        vector<int>row = v1[r] ; 
        for(int c =0 ; c <d ; c++)
        {
            int sum =0 ; 
            for(int i = 0 ; i <row.size() ; i++)
            {
                sum += ( row[i] * v2[i][c] ); 
            }
            ans[r][c] = sum ; 
        }
    }

    for(auto x : ans)
    {
        for(auto y : x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }



}


int main()
{
    int a ,b,c ,d ;
    cin>>a>>b ; 

    vector< vector<int> > v1(a , vector<int>(b,0)); 

    for(int  i =0 ;i < a ; i++)
    {
        for(int  j =0 ; j <b;j++)
        {
            int x; cin >> x ; 
            v1[i][j] = x ; 
        }
    }

    cin>>c>>d ; 
    vector< vector<int> > v2(c , vector<int>(d,0)); 

    for(int  i =0 ;i < c ; i++)
    {
        for(int  j =0 ; j <d;j++)
        {
            int x; cin >> x ; 
            v2[i][j] = x ; 
        }
    }

    matrix_product(v1 , v2) ; 


 

}

/*
3 3
1 2 3
4 5 6
7 8 9
3 3
-1 2 3
4 5 -6
7 8 9
*/