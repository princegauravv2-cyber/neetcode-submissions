class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(const auto& i: strs) {
            ans += (char)(i.size());
            ans += i;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.size(); ) {
            uint8_t sz = (uint8_t)s[i];
            ans.emplace_back(s.substr(i+1, sz));
            i += sz+1;
        }
        return ans;
    }
};
