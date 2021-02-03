#include<bits/stdc++.h>
using namespace std ;

#define hell 1000000007
#define ll long long
#define vvl vector<long>
#define loop(i,n) for(int i=0; i<n; i++)
#define pll pair<ll,ll>
#define pb push_back

//  mn(m+n) || space O(mn)
void solution1(vector< vector<int> >  v)
{
    vector< pair<int , int> > temp ;
    int m = v.size() ;
    int n = v[0].size() ; 
     

    for(int  i =0 ; i <m ;  i++)
    {
        for(int j =0 ;j <n ; j++)
        {
            if(v[i][j]==1)
            temp.pb({i,j}) ; 
        }
    }

    for(auto x : temp)
    {
        int r = x.first ; 
        int c = x.second ; 

        for(int i =0 ; i<n ; i++)
        {
            v[r][i] = 1 ; 
        }
        for(int i=0 ; i <m ; i++)
        {
            v[i][c]  =1 ; 
        }
    }

    for(auto x : v)
    {
        for(auto y : x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}

// o(mn) || o(m+n)
//hints:-
// back_up_to_row_no 
// back_up_to_col_no
void solution2(vector< vector<int> >  v)
{
    int m = v.size() ;
    int n = v[0].size() ; 
    vector<int> col(n , 0) ; 
    vector<int> row(m , 0) ; 
    int  i =0 ; 
    for(auto x: v)
    {
        for(auto y : x)
        {
         if(y==1)
         { row[i] =1 ;  
              break ; }   
        }
        i++ ; 
    }

    for(int  j = 0 ; j <n ; j ++)
    {
        for(int  i =0 ; i < m ; i++)
        {
            if(v[i][j]== 1)
            {
                col[j] = 1 ; 
                break ; 
            }
        }
    }

    for(int i =0 ; i <m ; i++)
    {
       if(row[i]==1)
       {
            for(int  j =0 ; j <n ; j++)
        {
            v[i][j] =1 ; 
        }
       }
    }

    for(int j =0 ; j < n ;j ++)
    {
        if(col[j]==1)
        {
            for(int i = 0 ; i < m ; i++)
            {
                v[i][j] = 1 ; 
            }
        }
    }
    
    for(auto x : v)
    {
        for(auto y : x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }


    cout<<endl;
}


int main()
{
    int m , n ; 
    cin>>m>>n ; 
    vector<vector<int> > v(m , vector<int>(n , 0)); 
    for(int  i =0 ; i < m ; i ++)
    {
        for(int  j =0 ;j < n ; j++)
        {
            int x ; cin >> x ; 
            v[i][j] = x ; 
        }
    }
    cout<<endl;
    solution1(v) ; 
    cout<<"SOLUTION 2"<<endl ; 
    solution2(v) ; 
    

 

}

/*
4 4
true true false true
false true true true
true false true true
true true true true

4 4
1 1 0 1
0 1 1 1
1 0 1 1
1 1 1 1

3 3
0 0 0
0 1 0
0 0 0

3 3
false false false
false true false
false false false




*/