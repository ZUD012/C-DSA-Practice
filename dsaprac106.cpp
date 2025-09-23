#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    public:
    int V ;
    vector<list<int>> L ;

    Graph(int V){
        this->V = V ; 
      L.resize(V) ; 
    }

    void addEdge(int u , int v){
        L[u].push_back(v);
        L[v].push_back(u);
    }
    void DFS_helper(int u ,  vector<bool> &check){
        cout<<u<<" " ;
        check[u] = true ;
        for(int i : L[u]){
            if(!check[i]){
              DFS_helper(i , check) ; 
            }
        }
    }
    void DfsTraversal(){
        int u  = 0 ; 
        vector<bool> check(V , false) ; 
        DFS_helper(u , check); 
    }
};
int main(){
Graph g(5) ;
g.addEdge(0 , 1) ;
g.addEdge(1 , 2) ;
g.addEdge(1 , 3) ;
g.addEdge(2 , 3) ;
g.addEdge(2 , 4) ;
g.DfsTraversal() ; 
return 0;
}