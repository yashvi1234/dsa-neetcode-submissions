class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> temp;
        for(int i=0; i<nums.size(); ++i){
            temp[nums[i]]++;
        }

        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); ++i){
            temp[nums[i]]--;//do not add it back or remove even if continue case so that the case already covered do not cover again
            if(i!=0 && nums[i]==nums[i-1]){
                continue; //remove all duplicates which will come if first elements are same 
            }
            for(int j=i+1; j<nums.size(); ++j){
                temp[nums[j]]--; //remove this for a specific i and also remove it for continue case too so that no duplicate for a specific i case 
                int k = 0-nums[i]-nums[j];
                if(j>i+1 && nums[j]==nums[j-1]){
                continue; //remove all duplicates which will come if second elements are same 
                }

                if(temp[k] > 0){
                    ans.push_back({nums[i], nums[j], k});
                }
            }
            for(int j=i+1; j<nums.size(); ++j){
                temp[nums[j]]++;//put it back for other i's 
            }
        }

        return ans;
    }//tc - O(n^2), sc - O(n)
};
