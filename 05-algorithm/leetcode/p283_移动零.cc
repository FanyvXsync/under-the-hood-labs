class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
       int i=0;
       int cur=-1;

        for(i=0;i<nums.size();i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i],nums[cur+1]);
                cur++;
            }
        }

    }
};
