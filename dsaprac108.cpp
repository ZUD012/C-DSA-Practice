#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    public :
    int V ;
    vector<list<int>> L ;

    Graph(int V ){
        this->V = V ;
        L.resize(V) ;
    }
    void addEdge(int u , int v){
       L[u].push_back(v) ;
       L[v].push_back(u) ; 
    }

    bool Cycle_detector_helper(int u  , vector<bool>& check){
        queue<pair<int , int >> q ;
        q.push({u , -1}) ;
        check[u] = true ;
        while(q.size() > 0 ){
            int v = q.front().first ;
            int parentU = q.front().second ;  
            q.pop() ; 
            for(int i : L[v]){
                if(!check[i]){
                    q.push({i , v}) ; 
                    check[i] = true ; 
                }
                else if(i != parentU){
                   return  true ;  
                }           
            }
        }  
        return false ; 
    }
     
    bool MainCycle_Checker(){
        int u = 0 ;
        vector<bool> check(V , false) ;
        if(Cycle_detector_helper(u,check)){
            cout<<"Cycle Exist : " ;
        }
        else{
            cout<<"No cycle exist : ";
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
g.MainCycle_Checker() ; 

return 0;
}