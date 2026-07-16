class Solution {
public:
    int trap(vector<int>& height) {
        auto l = height.size();
        vector<int> prefixHigh(l, 0), suffixHigh(l, 0), water(l, 0);
        for(int i = 1, m = height[0]; i < l; i++) {
            m = max(m, height[i-1]);
            prefixHigh[i] = m;
        }
        for(int i = l-2, m = height[l-1]; i >= 0; i--) {
            m = max(m, height[i+1]);
            suffixHigh[i] = m;
        }
        int ans = 0;
        for(int i = 0; i < l; i++) {
            ans += max(min(prefixHigh[i], suffixHigh[i]) - height[i], 0);
        }
        return ans;
    }
};
