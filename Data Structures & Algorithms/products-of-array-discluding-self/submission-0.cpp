class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const auto l = nums.size();
        vector<int> sumFrom(l, nums[l-1]);
        vector<int> sumTill(l, nums[0]);
        for(int i = 1; i < l; i++) {
            sumTill[i] = sumTill[i-1] * nums[i];
        }
        for(int i = l-2; i >= 0; i--) {
            sumFrom[i] = sumFrom[i+1] * nums[i];
        }
        vector<int> ans(l, 1);
        for(int i = 0; i < l; i++) {
            int sF = i+1 < l ? sumFrom[i+1] : 1;
            int sT = i-1 >= 0 ? sumTill[i-1] : 1;
            ans[i] = sF*sT;
        }
        return ans;
    }
};
