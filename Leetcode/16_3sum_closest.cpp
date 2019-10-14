// 0, 0 ,0

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closeNum = 65535, ansNum = 0;
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i< nums.size();i++)
        {
            int lowIndex = i+1;
            int highIndex = nums.size()-1;
            
            if(i == 0 || nums[i] != nums[i-1]) //exclude the same num
            {
                while(lowIndex < highIndex)
                {
                    int highNum = nums[highIndex];
                    int lowNum = nums[lowIndex];
                    int sum = nums[i] + lowNum + highNum;

                    if( sum > target )
                    {                    
                        highIndex--;
                        while(lowIndex < highIndex && nums[highIndex] == highNum)
                        {
                            highIndex--;
                        }
                    }
                    else //if(sum < target)
                    {
                        lowIndex++;
                        while(lowIndex < highIndex && nums[lowIndex] == lowNum)
                        {
                            lowIndex++;
                        }                
                    }

                    if( abs(sum - target) < closeNum )
                    {
                        closeNum = abs(sum-target);
                        ansNum = sum;
                        //cout<<"closeNum:"<<closeNum<<" highNum:"<<highNum<<" lowNum:"<<lowNum<<" nums"<<nums[i]<<endl;
                    }
                }
            }
        }
        
        return ansNum;
    }
};
