#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public :
    int V ;
    vector<list<int>> l ;
    
 Graph(int V){
   this->V = V ; 
   l.resize(V) ;    

 }
 void addEdge(int u , int v ){
    l[u].push_back(v) ;
    l[v].push_back(u) ; 
 }
 void BFStraversal(){
    queue<int> Q ;
    vector<bool> vis(V ,false) ;
    Q.push(0) ; 
    vis[0] = true ;
    while(Q.size() > 0){
       int u = Q.front() ;
       Q.pop() ;
       cout<<u<<" " ;
       for(int v : l[u]){
          if(! vis[v]){
            vis[v] = true  ;
            Q.push(v);
          }
       }
    }
    cout << endl ;
 }
};

int main(){
Graph g(5) ;
g.addEdge(0 , 1) ;
g.addEdge(1 , 2) ;
g.addEdge(1 , 3) ;
g.addEdge(2 , 3) ;
g.addEdge(2 , 4) ;
g.BFStraversal() ; 



return 0;
}