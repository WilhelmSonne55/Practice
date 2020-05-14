class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        int val = 65535;
        
        for(int i=0;i<nums.size();i++)
        {
            if(val != nums[i])
            {
                val = nums[i];
                nums[j] = val;
                j++;
            }            
        }
        return j;
    }
};
