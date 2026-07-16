class Solution {
public:
    int characterReplacement(string s, int k) {
        // Brute force
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            unordered_map<char, int> freq;
            int maxF = 0;
            for(int j = i; j < s.size(); j++) {
                freq[s[j]]++;
                maxF = max(maxF, freq[s[j]]);
                int l = j-i+1;
                if(l - maxF <= k) {
                    ans = max(ans, l);
                }
            }
        }
        return ans;
    }
};
