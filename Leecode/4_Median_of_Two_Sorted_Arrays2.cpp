#define MAXNUMER 100000000000000000
#define MINNUMER -10000000000000000

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int size1 = nums1.size(); //always smaller
        int size2 = nums2.size();
        
        if(size1 > size2)
            return findMedianSortedArrays(nums2, nums1);
    
        
        int high = size1;
        int low = 0;
        int mid = (size1 + size2 + 1)/2;
        
        while(low <= high)
        {        
            int i = (high + low)/2; //mid in 2
            int j = mid - i; //mid in 1
            
            int leftmax1 = (i == 0)?MINNUMER:nums1[i-1];
            int rightmin1 = (i == size1)?MAXNUMER:nums1[i];
            
            int leftmax2 = (j == 0)?MINNUMER:nums2[j-1];
            int rightmin2 = (j == size2)?MAXNUMER:nums2[j];
            
            if(leftmax1 <= rightmin2 && leftmax2 <= rightmin1)
            {

                if((size1+size2)%2 == 1)
                {
                    return (leftmax1 > leftmax2)?leftmax1:leftmax2;
                }
                else
                {
                    int left = (leftmax1 < leftmax2)?leftmax2:leftmax1;
                    int right = (rightmin1 < rightmin2)?rightmin1:rightmin2;
                    return (left+right)/2.0;            
                }

           }
           else if(leftmax2 > rightmin1)
           {
                //j shift left, i shift right
               low = i+1;
            }
            else
            {
                high = i-1;
            }
        }
        return 0;
    }
};
