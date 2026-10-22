class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); ++i){
            if(i>0 && nums[i]==nums[i-1]){
                continue;//for duplicate
            }

            int j=i+1, k=nums.size()-1;
            while(j<k){//for duplicates
            if(j>i+1 && nums[j]==nums[j-1]){
                j++;
                continue;//duplicates
            }

            if(k<nums.size()-1 && nums[k]==nums[k+1]){
                k--;
                continue;//duplicates
            }

            int sum = nums[j]+nums[k];
            if(sum<(-nums[i])){
                j++;
            } else if(sum>(-nums[i])){
                k--;
            } else if(sum==(-nums[i])){
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            }
        }

        return ans;
    }//tc - O(n), sc - O(1)
};
