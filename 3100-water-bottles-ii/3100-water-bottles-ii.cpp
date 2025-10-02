class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drink  = numBottles;
        int empty  = numBottles;
        int filled = 0;

        while(empty >= numExchange){
            empty -= numExchange;
            drink++;
            empty++;
            numExchange++;
        }
        return drink;
    }
};