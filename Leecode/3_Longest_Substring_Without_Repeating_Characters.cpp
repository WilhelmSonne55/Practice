
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
        {
            return 0;
        }
        
        unordered_map<char, int> substring;
        unordered_map<char, int>::const_iterator it, it2;
        int length = 0, tmp = 0;
        int i = 0, j =0;
        
        while( i < s.size() && j < s.size() )
        {
            char right = s[j];
            char left = s[i];
            it = substring.find(right);
            
            if( it == substring.end())
            {
                //can't find
                substring[right] = j;
                j++;
            }
            else
            {
                //it2 = substring.find(left);
                substring.erase(left);
                i++;
            }
            
            tmp = j - i;
            if(tmp > length)
            {
                 length = tmp;
            }
        }
        return length;
    }
};
