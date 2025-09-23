#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    public : 
    int V ;
    vector<list<int>>L ;
   
    Graph(int V){
        this->V = V ;
        L.resize(V) ;
    }
    void addEdge(int v , int u){
      L[u].push_back(v);
      L[v].push_back(u);
    }
    bool Check_Cycle_DFS(int strt , int parent , vector<bool> &check){
        check[strt] = true ;  
        for(int i : L[strt]){
          if(! check[i]){
            check[i] = true ;
            if(Check_Cycle_DFS(i , strt , check)){
                return true ;
            } 
       
          }
          else if (i != parent){
            return true ;
          }
        }
        return false;
    }

    bool chech_cycle(){
        int strt =0 ;
        vector<bool> check(V , false );
        if(Check_Cycle_DFS( strt ,  -1 , check)){
            cout<<"Cycle exists : " ;
        } 
        else{
            cout<<"No cycle Exist : " ; 
        }
    }
    

};
int main(){
Graph g(5) ;
g.addEdge(0 , 1) ;
g.addEdge(1 , 2) ;
g.addEdge(1 , 3) ;
g.addEdge(2 , 3) ;
g.addEdge(2 , 4) ;
g.chech_cycle() ; 

return 0;
}