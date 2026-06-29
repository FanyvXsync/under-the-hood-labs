class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int retleft = 0;
        int retright = right;

        if( n == 0) return {-1,-1};

        while(left < right)
        {
            int mid = ( left + right ) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }

        if(nums[left] == target) retleft = left;
        else return {-1,-1};

        left = 0;
        right = n - 1;

        while(left < right)
        {
            int mid = ( left + right + 1 ) / 2;
            if(nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        
        if(nums[right] == target) retright = left;
        else return {-1,-1};

        return {retleft, retright};

    }
};