#include<bits/stdc++.h>
using namespace std ;

#define hell 1000000007
#define ll long long
#define vvl vector<long>
#define loop(i,n) for(int i=0; i<n; i++)
#define pll pair<ll,ll>
#define pb push_back

class Graph{
    public : 
    int  V ; 
    map<int , vector<int> > adjList ; 

    Graph(int x)
    {
        this->V = x; 
    }

    void addEdge(int node1 , int node2)
    {
        adjList[node1].pb(node2) ; 
    }

    void printAdjList()
    {
        for(auto x : adjList)
        {
            for(auto y : x.second)
             cout<<y<<" ";
            
            cout<<endl; 

        }
    }
    void BFS() ;   
    void recurBFS() ; 
    void recurBFShelp(queue<int>&q , vector<int>&v) ; 
    void DFS();
    void recurDFS() ; 
    void recurDFShelp(int i , vector<int>&v) ; 
    bool isCycle();
    bool isCycle_recur_helper(int i , vector<bool>&visited);
    bool isCycle_recur();
    bool isCycle_Using_BFS() ; 

};

bool Graph:: isCycle_Using_BFS()
{
    unordered_map<int,int>degree ; 
    for(int  i =0 ; i <V ;i ++)
    {
        for(auto x : adjList[i])
        {
            degree[x]++ ; 
        }
    }

    queue<int>q ; 
    int count =0 ; 
    int flag =0 ; 
    for(auto x : degree)
    {
        if(x.second==0)
        {
            q.push(x.first) ; 
            flag =1 ; 
        }
    }

    while(!q.empty())
    {
        int curr = q.front() ; 
        count++ ; 
        q.pop();

        for(auto x : adjList[curr])
        {
            degree[x]-- ; 
            if(degree[x]==0)
            {
                q.push(x) ; 
            }
        }

    }

    if(count==V)
    return false ;

    return true ; 
}
/**********************************************************************************/

bool Graph:: isCycle_recur_helper(int i , vector<bool>&visited)
{
    if(visited[i]==false)
       visited[i] = true ; 
    else
    {
        return true ; 
    }

    bool flag = 0 ; 

    for(auto x : adjList[i])
    {
       flag =  isCycle_recur_helper(x , visited);
    }    

    if(flag)
    return true ; 

    return false ;
}

bool Graph:: isCycle_recur()
{
    bool flag = false ; 
    for(int i= 0 ; i <V ; i++)
    {
        vector<bool>visited(V, false) ; 
        flag = isCycle_recur_helper(i , visited) ;
        if(flag)
        return true ; 
    }

    return false ; 
}

/****************************************************************************/

bool Graph:: isCycle()
{
    unordered_map<int,int> child_parent_tracker ; 
    vector<int>flag(V , -1);

    for(int  i =0 ; i <V ; i ++)
    {
        if(flag[i]==-1)
        {
            stack<int> s ; 
            s.push(i) ; 
            while (!s.empty())
            {
                int curr = s.top() ; 
                flag[curr] = 0 ; 
                int cnt = 0 ; 

                for(auto x : adjList[curr])
                {
                    if(flag[x]==-1)
                    {
                        s.push(x);
                        cnt = 1 ; 
                        child_parent_tracker[x] = curr ; 
                        break;
                    }
                    else if(flag[x]==0)
                    {
                        int cycle_root =curr ;

                        while (cycle_root!=x)
                        {
                            cout<<cycle_root<<"<--";
                            cycle_root = child_parent_tracker[cycle_root];
                        }
                        cout<<cycle_root<<" ";
                        
                        return true ; 
                    }
                }

                if(cnt==0)
                {
                    flag[curr] = 1 ; 
                    s.pop() ; 
                }
            }
            
        }
    }

    return false ; 

}

/*****************************************************************************************/
void Graph :: recurDFShelp(int i , vector<int>&visited)
{
    if(visited[i]==0)
     cout<<i<<" ";

    visited[i] = 1 ; 
    for(auto x : adjList[i])
    {
        if(visited[x]==0)
        {
            recurDFShelp(x , visited) ; 
        }
    }
}
void Graph :: recurDFS()
{
    vector<int>visited(V , 0 ) ; 
    for(int i =0 ; i <V ; i++)
    {
        if(visited[i]==0)
        {
            recurDFShelp(i , visited) ; 
        }
    }
}
/*********************************************************************/

void Graph :: DFS()
{
    vector<int>visited(V,0) ; 

    for(int  i =0 ; i < V ; i++)
    {
        if(visited[i]==0)
        {
            stack<int> s ; 
            s.push(i) ; 

            while(!s.empty())
            {
                int curr = s.top() ; 
                if(visited[curr]==0) // we come back to same node after DFS through all its child complete and we dont want to print it twice.  
                {   
                    cout<<curr<<" ";      
                }
                visited[curr] = true ; 
                int flag = 0 ; 

                if(!adjList[curr].empty())
                {
                    
                    for(auto x : adjList[curr])
                    {
                        if(visited[x]==0)
                        {
                            flag = 1 ; 
                            s.push(x) ; 
                            break ; 
                        }
                    }

                }

                if(flag ==0)
                {
                    s.pop() ; 
                }
            }
        }
    }
}
/****************************************************************/
void Graph::BFS()
{
   vector<int>visited(V , 0) ; 
   

   for(int  i =0 ;i <V ; i ++)
   {
       if(visited[i]==0)
       {
           queue<int> q ; 
           q.push(i) ; 
           visited[i] = 1 ; 
           while(!q.empty())
           {
               int curr = q.front() ; 
               cout<<curr<<" ";
               q.pop() ; 

               if(!adjList[curr].empty())
               {
                   for(auto x : adjList[curr])
                   {
                       if(visited[x]==0)
                       {
                           q.push(x) ; 
                            visited[x] =1 ; 
                       }
                   }
               }
               
           }
       }
   }
}
/********************************************************************************/
void Graph::recurBFShelp(queue<int>&q , vector<int>&visited)
{
    if(q.empty())
    return;

    int curr = q.front() ; 
    q.pop() ; 
    cout<<curr<<" ";
    for(auto x : adjList[curr])
    {
        if(visited[x]==0)
        {
            q.push(x) ; 
            visited[x] =1 ; 
        }
    }
    recurBFShelp(q , visited) ; 
}

void Graph :: recurBFS()
{
    vector<int> visited(V , 0) ; 
    for(int  i =0 ; i < V ; i++)
    {
        if(visited[i]==0)
        {
            queue<int>q ; 
            q.push(i) ;
            visited[i] = 1 ; 
            recurBFShelp(q , visited) ; 
        }
    }
}
/*******************************************************************************/
int main()
{
      Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    cout<<g.isCycle_Using_BFS() ;
    
    //g.addEdge(3, 3);
    // cout << "Following is Breadth First Traversal \n";
    // g.DFS();
    // cout<<endl;
    // g.recurDFS();

    

    // int vertex ; 
    // cin>>vertex ; 
    // Graph myGraph(vertex) ; 
    // int connection ;
    // cin>>connection ; 

    // for(int i=0 ; i <connection; i++)
    // {
    //     int node1 , node2 ; 
    //     cin>>node1>>node2 ; 
    //     myGraph.addedge(node1,node2) ; 

    // }

    // myGraph.printAdjList();
    

 

}