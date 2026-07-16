class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Brute force
        /*int maxL = 0;
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
        return maxL;*/
        // Optimised sliding window solution O(n) time with O(m) space
        int maxL = 0;
        int l = 0, r = 0;
        unordered_set<char> hashSet;
        while(r < s.size()) {
            if(hashSet.find(s[r]) != hashSet.end()) {
                while(s[l] != s[r]) {
                    hashSet.erase(s[l]);
                    l++;
                }
                l++;
            } else {
                hashSet.insert(s[r]);
            }
            maxL = max(maxL, r-l+1);
            r++;
        }
        return maxL;
    }
};
