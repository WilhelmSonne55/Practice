/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *array = malloc(sizeof(int)*2);
    array[0] = 0;
    array[1] = 0;
        

    for(int i = 0; i < numsSize ; i++)
    {
        int ans1 = nums[i];
        int ans2 = target - ans1;
        array[0] = i;
        printf("%d %d\n",ans1,ans2);
        for(int j = numsSize -1 ; 0 < j ; j--)
        {

            if(nums[j] == ans2 && i!=j)
            {
                //equal 
                array[1] = j;

                return array;
            }
        }
    }
    
    return array;
}
