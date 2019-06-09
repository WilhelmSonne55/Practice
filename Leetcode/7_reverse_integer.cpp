/* 1. The reverse integer might overflow.
 *
 *
 */
class Solution {
public:
    int reverse(int x) {
        long ans = 0, i = 0, tmp = x;
        
        //digit
        while(tmp != 0)
        {
            i++;
            tmp /= 10;
        }
        
        while( i != 0)
        {
            int num = x % 10;
            x = x/10;
            ans += num*pow(10,i-1);
            i--;
        }
        
        if(fabs(ans) > INT_MAX)
            return 0;
        else
            return ans;
    }
};
