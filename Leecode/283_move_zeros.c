void moveZeroes(int* nums, int numsSize) {
    int* zn = malloc(sizeof(int)*numsSize);
    int n = 0, tmp;
    int i=0;
    
    //find zero & size of 0
    for(i=0;i<numsSize;++i){
        tmp = nums[i];
        
        if(tmp == 0){
            zn[n]=i; //0's position
            ++n; //size
        }
    }
    
    //move n times = 0
    for(i=0;i<n;++i){  
        int s = zn[i];
        int d;
        int next_p;

        if(i+1 < n)
            d = zn[i+1]-(i+1); //next 0, one step might be j+x, x=0,1... depends on xst zero 
        else
            d = numsSize;   //no more zero, just trace back to the last one
        
        //moving forward
        for(int j=s-i;j<d;++j){ 
            next_p = j+i+1; //step 
            nums[j]=nums[next_p];
        }
    }
    
    //fill zero
    for(i=0;i<n;++i){ 
        int p = numsSize -1 -i;
        nums[p] = 0;
    }
    
}
