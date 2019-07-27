class Solution {
public:
    bool isPalindrome(int x) {
        int digit = 0, half = 0;
        int r = 0, l = 0;
        int tmp = x, l_tmp = x, r_tmp =x;

        if(x == 0)
            return true;
        else if(x < 0)
            return false;
        else if(x < 10)
            return true;
        
        while(tmp>=10)
        {
            tmp /= 10;
            digit++;
        }
        half = digit/2 ;
        digit = pow(10, digit);
        half = pow(10, half);
        
        while(r == l && digit >= half)
        {
            r = r_tmp%10;
            l = l_tmp/digit;
            r_tmp /=10;
            l_tmp -= l*digit;
            digit /= 10;
        }
        if(r==l)
            return true;
        else
            return false;
    }
};
