class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        int count = 0;
        for(int i = 0; i< nums.size();i++)
        {
            if(nums[i] == val)
            {
                if(nums[j] != val)
                    j = i;
                count++;
            }
            else
            {
                //cout<<"j:"<<j<<" i:"<<i<<endl;
                if(nums[j]==val)
                {
                    nums[j] = nums[i];
                    nums[i] = val;
                    j++;
                }
            }
        }
        
        return nums.size()-count;
    }
};
