class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> numIdx;
        for(int i = 0 ; i < nums.size(); i++) {
            if(numIdx.find(target - nums[i]) != numIdx.end()) {
                ans.push_back(numIdx[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            numIdx[nums[i]] = i;
        }
        return ans;
    }
};
