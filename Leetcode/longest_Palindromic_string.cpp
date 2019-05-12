int findSubString(int left, int right, string s);


class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int size = 0;
        
        for(int i = 0; i< s.size(); i++)
        {
           int size_l = 0;
           int size_r = 0;
           size_l = findSubString(i, i, s);
           size_r = findSubString(i, i+1, s);s
            :
            if(size_l > size_r && size_l >= size)
            {
                size = size_l;
                int start = i - (size -1)/2 ;
                ans = s.substr(start, size);
            }
            else if(size_r > size_l && size_r >= size )
            {
                size = size_r;
                int start = i - (size - 1)/2;
                ans = s.substr(start, size);
            }
            
        }
        
        return ans;
    }
};


int findSubString(int left, int right, string s)
{
    while(0 <= left && right < s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left -1;
}
