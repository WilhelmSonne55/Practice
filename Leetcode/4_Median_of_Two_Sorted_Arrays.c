

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(); //A smaller
    int n = nums2.size(); //B bigger
        
    //hope n >= m
    if(n < m)
        return findMedianSortedArrays(nums2 , nums1);
        
    int max = m, min = 0;        
    int halflen = (m+n+1)/2;
    while(min<=max)
    {
        int i = (min + max)/2; //A
        int j = halflen - i; //B
        if(i<max && nums2[j-1] > nums1[i])
        {
            min = i+1;
        }
        else if(i>min && nums2[j] < nums1[i-1])
        {
            max = i-1;
        }
        else
        {
            int maxleft = 0;
            if(i == 0)
                maxleft = nums2[j-1];
            else if(j==0)
                maxleft = nums1[i-1];
            else
                maxleft = (nums2[j-1] < nums1[i-1])?nums1[i-1]:nums2[j-1];
            
            if((m+n)%2 ==1 )
                return maxleft;
            
            int minright = 0;
            if(i==m)
                minright = nums2[j];
            else if(j==n)
                minright = nums1[i];
            else
                minright = (nums2[j] < nums1[i])?nums2[j]:nums1[i];
            
            return (maxleft + minright) /2.0;
            
        }
    }
    
    return 0;
    }
};
