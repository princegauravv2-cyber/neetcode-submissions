class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, int> index;
        int idx=0;
        for(const auto& i : strs) {
            vector<int> freq(26, 0);
            for(const auto& c: i) {
                freq[c-'a']++;
            }
            if(index.find(freq) == index.end()) {
                index[freq] = idx++;
                ans.emplace_back(vector<string>());
            }
            ans[index[freq]].emplace_back(i);
        }
        return ans;
    }
};
