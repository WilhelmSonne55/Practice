class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
        {
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        
        int preNum;
        for(auto it = nums.begin(); it != nums.end()-2; it++)
        {
            auto itlow = it+1;
            auto ithigh = nums.end()-1;

            if(preNum == *it && it !=nums.begin())  //0 0 0 cases
                continue;
                while(itlow < ithigh)
                {

                    int num = *it;
                    int low = *itlow;
                    int high = *ithigh;
                    int sum = -1*(low+num);
                    preNum = *it;

                    if(sum < 0)
                        break;
                    if(high == sum)
                    {
                        vector<int> tmp = {num, low, high};
                        ans.push_back(tmp);
                        ++itlow;       
                        --ithigh;
                        while(itlow < nums.end() && low == *itlow)
                        {
                            itlow++;
                        }
                        while(ithigh > nums.begin() && high == *ithigh)
                        {
                            ithigh--;
                        }
                    }
                    else if(high > sum)
                    {
                        ithigh--;
                    }
                    else
                    {
                        itlow++;
                    }
                }                   
        }
        return ans;
    }
};
