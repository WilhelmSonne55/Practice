/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** r= (char**)malloc((n)*sizeof(char*));
    int number;
    for(int i=0;i<n;i++){
        number = i+1;
        r[i] = (char*)malloc(1000*sizeof(char));

        if(number %15 == 0){
            r[i] = "FizzBuzz";
        }
        else if(number%3 ==0)
            r[i]="Fizz";
        else if(number%5 ==0)
            r[i]="Buzz";
        else{
            sprintf(r[i],"%d",number);
        }
    }
    return r;
}
