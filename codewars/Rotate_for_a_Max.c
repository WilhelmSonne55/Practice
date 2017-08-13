long long maxRot(long long n){
    long long tmp =n, max = n;
    long long digit = 1;

    while(digit*10 < n) digit *=10;       //get the digit of the n

    while(digit !=0 ){
        long long k_digit = digit*10;     //the digit of the number we keep 
        long long k_n = tmp / k_digit;    //the number we kepp
        long long b_n = tmp % digit;      //bottom number should shift one bit
        long long t_n = (tmp/digit)%10;   //origin top number => first bit

        tmp = k_n * k_digit + b_n*10 + t_n; // xx (k_n) 0 (t_n) xxxx (b_n) 0 <==== move to here
        digit /= 10;
        max = tmp>max?tmp:max;
    }
    return max;
}
