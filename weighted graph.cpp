#include<bits/stdc++.h>
using namespace std ; 

class Graph
{
private:
    int V ; 
    map< int , vector< pair<int,int> >  > adjList ; 
public:
    Graph(int x) ; 
    void addEdge(int u , int v , int data)
    {
        adjList[u].push_back({v,data}) ; 
        return ; 
    }
    vector<int> dijkstraAlgo(int source) ; 
};

Graph::Graph(int x){
    this->V = x ; 
}

vector<int> Graph:: dijkstraAlgo(int source)
{
    // priority_queue< int , vector<int> , greater<int> > find_min ;
    // unordered_map<int,int>value_to_index ;  
    vector<int> distance (V , INT_MAX) ; 
    vector<int>visited(V , 0) ; 
    distance[source] = 0 ;  

    // for(int i =0 ;i <V ; i++)
    // {
    //     find_min.push(distance[i]) ; 
    //     value_to_index[distance[i]] = i ; 
    // }
    int flag = true ; 
    while(flag )
    { 
        int find_min =INT_MAX ; 
        int check =0 ; 
        for(int  i =0 ; i <distance.size() ; i++)
        {
            if(visited[i]==0)
            {
               if(distance[i] < find_min)
               {
                   find_min = distance[i] ; 
                   source = i ; 
                   check = 1 ; 
               }
            }
        }
        if(check==0)
        {
            flag = false ; 
            break ; 
        }
        cout<<source<<" ";
        visited[source] = 1 ; 


        for(auto x :adjList[source] )
      {

         int node = x.first ; 
         int value = x.second ; 

         if(value + distance[source] <  distance[node])
         {
             distance[node] = value + distance[source] ; 
             //cout<<distance[node]<<" ";
         }
         
      }
    }

    return distance ; 



}




int main()
{
    Graph g(7) ;
    g.addEdge(1,2,2);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1); 
    g.addEdge(2,4,7);  
    g.addEdge(3,5,3);  
    g.addEdge(4,6,1); 
    g.addEdge(5,4,2);
    g.addEdge(5,6,5);
    vector<int> v ; 
    v = g.dijkstraAlgo(1);
    cout<<endl; 
    for(auto x : v)
    {
        cout<<x<<" ";
    }
    

}