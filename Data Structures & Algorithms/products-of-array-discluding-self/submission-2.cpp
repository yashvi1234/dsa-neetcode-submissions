class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int prefix = 1;
    
        for(int i=0; i<nums.size(); ++i){
            ans[i] = prefix;
            prefix*= nums[i];
        }

        int postfix = 1;
        for(int i=nums.size()-1; i>=0; --i){
            ans[i]*= postfix;
            postfix*= nums[i];
        }

        return ans;
    } //tc - O(n), sc - O(n) output
};
