class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Brute force
        int maxL = 0;
        for(int i = 0; i < s.size(); i++) {
            unordered_set<char> hashSet;
            for(int j = i; j < s.size(); j++) {
                if(hashSet.find(s[j]) != hashSet.end()) {
                    break;
                } else {
                    hashSet.insert(s[j]);
                }
            }
            maxL = max(maxL, static_cast<int>(hashSet.size()));
        }
        return maxL;
    }
};
