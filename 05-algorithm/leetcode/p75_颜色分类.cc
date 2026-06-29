class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int left= -1,right = nums.size();
        int i = 0;
        
        while(i < right)
        {
            if(nums[i] == 0)
            {
                swap(nums[++left],nums[i++]);
            }
            else if(nums[i]==1)
            {
                i++;
            }
            else
            {
                swap(nums[--right],nums[i]);
            }

        }

    }
};