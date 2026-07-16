class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        int maxP = 0;
        for(int l = 0, r = 1; r < s; r++) {
            if(prices[r] > prices[l]) {
                maxP = max(maxP, prices[r] - prices[l]);
            } else {
                l = r;
            }
        }
        return maxP;
    }
};
