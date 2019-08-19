class Solution {
public:
    bool isMatch(string s, string p) {
        bool firstmatch = false;
        
        if(p.empty())
        {
            return s.empty();
        }
            
        if(!s.empty() && (s[0] == p[0] || p[0] == 0x2E))
        {
            firstmatch = true;
        }
        
        if(p.size() > 1 && p[1] == 0x2A)
        {
            return isMatch(s, p.substr(2)) || (firstmatch && isMatch(s.substr(1), p));
        }
        else
        {
            return firstmatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};
