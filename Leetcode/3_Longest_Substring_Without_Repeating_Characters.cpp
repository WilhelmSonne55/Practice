

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
        {
            return 0;
        }
        
        vector<char> substring;
        int length = 1;
        char now = s[0];
        char next;
        substring.push_back(now);
        
        int ret = true;
        for(int i = 1; i<s.size();i++)
        {
            next = s[i];
            
            for(int j = 0; j <substring.size();j++)
            {
                if(substring[j] == next)
                {
                   if(substring.size() > length)
                    {
                        length = substring.size();
                    }
                    
                    //flush
                    if(j ==0)
                        substring.erase(substring.begin());
                    else if(j == substring.size()-1)
                        substring.clear();
                    else
                        substring.erase(substring.begin(), substring.begin()+j+1);

                    substring.push_back(next);

                    ret = false;
                    break;
                }
                ret = true;
            }
            
            if(ret == true)
            {
                substring.push_back(next);
            }
            
            if(substring.size() > length)
            {
                length = substring.size();
            }
        }

        return length;
    }
};
