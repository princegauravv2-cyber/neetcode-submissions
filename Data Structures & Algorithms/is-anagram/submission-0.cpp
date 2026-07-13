class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> freq;
        if(s.size() != t.size())
            return false;
        for(int i = 0; i < s.size(); i++) {
            if(freq.find(s[i]) == freq.end()) {
                freq[s[i]] = 0;
            }
            if(freq.find(t[i]) == freq.end()) {
                freq[t[i]] = 0;
            }
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(auto i : freq) {
            if(i.second != 0)
                return false;
        }
        return true;
    }
};
