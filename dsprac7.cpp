//Stock buy and sell problems -->

#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

//Basic approach -->

void basic_stock_buy_sell(vector<int> &prices , int size){
int max_profit = 0 ;
int bestbuy = prices[0] ;
for (int i = 1 ; i < size ; i++){
    if (prices[i] > bestbuy){
        max_profit = max(max_profit , prices[i] - bestbuy) ; 
    }
    bestbuy = min(bestbuy , prices[i]) ; 
} 
cout<<"The best price to buy the stock is : "<<bestbuy<<endl ; 
cout<<"The maximum profit you can get on buying stocks at price "<<bestbuy<<" is : "<<max_profit ; 
}


int main(){

vector<int>prices = {7,1,5,3,6,4} ; 
int n = prices.size() ; 

return 0;

}