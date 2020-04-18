void twosum(vector<int>& nums, int begin, int end, int target);

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        if(nums.size()<4)
            return ans;
        else if(nums.size() == 4)
        {
            if(nums[0]+nums[1]+nums[2]+nums[3] == target)
                return ans={nums};
            else
                return ans;
        }
        
        for(int i = 0; i<= nums.size()-4; i++)
        {
            //cout<<"i:"<<i<<endl;
           if(i!=0 && nums[i] == nums[i-1])
               continue;            
            
            for(int j = i+1; j <= nums.size()-3; j++)
            {
                int begVal = nums[i];
                int endVal = nums[j];
                int secTarget = target - begVal - endVal;
                int left = j+1;
                int right = nums.size()-1;            
                //cout<<"j:"<<j<<endl;
                //cout<<"secTarget:"<<secTarget<<endl;
                
                if(j!=i+1 && nums[j] == nums[j-1])
                    continue;

                //two sum
                while(left < right)
                {
                    int leftVal = nums[left];
                    int rightVal = nums[right];
                    int sum = leftVal + rightVal;
                    //cout<<"left:"<<left<<" right:"<<right<<endl;
                    //cout<<"sum:"<<sum<<" leftVal:"<<leftVal<<" rightVal:"<<rightVal<<endl;      
                    
                    if(sum < secTarget)
                    {
                        while(left<nums.size() && leftVal == nums[left]) left++;
                    }
                    else if(sum > secTarget)
                    {
                        //cout<<"2"<<endl;

                        while(j+1<right && rightVal == nums[right]) right--;
                    }
                    else
                    {
                  
                        vector<int> ivec = {begVal, endVal, leftVal, rightVal};
                        ans.push_back(ivec);
                        //cout<<"3"<<endl;
                        while(left < right && leftVal == nums[left]) left++;
                        while(left < right && rightVal == nums[right]) right--;
                    }
                }
            }
        }

        return ans;
    }
};




