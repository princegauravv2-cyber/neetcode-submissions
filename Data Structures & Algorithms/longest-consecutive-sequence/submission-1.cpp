class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int m = 0;
        for(const auto& i : nums) {
            int l = 0;
            if(numsSet.find(i-1) == numsSet.end()) {
                l++;
                int j=i;
                while(numsSet.find(++j) != numsSet.end()) {
                    l++;
                }
                m = max(m,l);
            }
        }
        return m;
    }
};
