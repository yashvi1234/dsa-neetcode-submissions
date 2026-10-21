class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it:nums){
            s.insert(it);
        }

        int ans = 0;
        for(auto it:nums){
            if(s.find(it-1) != s.end()){
                continue;
            }

            int streak = 0, val=it;
            while(s.find(val) != s.end()){
                streak++;
                val++;
            }

            ans = max(ans, streak);
        }

        return ans;
    }
};
