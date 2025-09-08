// GAS STATION --> 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas = 0;
        int totcost = 0;
        
        // Calculate total gas and total cost
        for(int val : gas) {
            totgas += val;
        }
        for(int val : cost) {
            totcost += val;
        }
        
        // If total gas is less than total cost, it's impossible
        if(totgas < totcost) {
            return -1;
        }
        
        int start = 0;
        int currgas = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            currgas += (gas[i] - cost[i]);
            
            if(currgas < 0) {
                // Cannot start from 'start', so reset at next station
                start = i + 1;
                currgas = 0;
            }
        }
        
        return start;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    
    int result = sol.canCompleteCircuit(gas, cost);
    cout << "Start index: " << result << endl;
    
    return 0;
}
