class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size()-1;
        int maxarea = 0;
        while(i<j)
        {
            int volume = (j-i)*min(height[i], height[j]);
            if(maxarea < volume)
            {
                maxarea = volume;
            }
            
            if(height[i] < height[j])
                i++;
            else
                j--;
            
        }
        
        return maxarea;
    }
};
