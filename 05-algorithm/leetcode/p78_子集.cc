class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        int sz = nums.size();
        for(int st = 0; st < (1 << sz); st++)
        {
            vector<int> tmp;
            for(int i = 0; i < sz; i++)
            {
                if((st >> i) & 1) tmp.push_back(nums[i]);
            }

            ret.push_back(tmp);
         }

         return ret;
    }
};