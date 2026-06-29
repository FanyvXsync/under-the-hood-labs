void reverse(int* begin,int* end)
{

    int tmp = 0;
    while(begin < end)
    {
        tmp = *end;
        *end = *begin;
        *begin = tmp;

        begin++;
        end--;
    }

}


void rotate(int* nums, int numsSize, int k) 
{
    k = k%numsSize;
    if(k==0) return;
    
    
    reverse(nums+numsSize-k,nums+numsSize-1);
    reverse(nums,nums+numsSize-1-k);
    reverse(nums,nums+numsSize-1);
    
}