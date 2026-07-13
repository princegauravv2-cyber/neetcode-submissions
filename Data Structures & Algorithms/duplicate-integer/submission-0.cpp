class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for(auto i : nums) {
            //cout << i << endl;
            if(s.find(i) != s.end())
                return true;
            s.insert(i);
        }
        return false;
    }
};