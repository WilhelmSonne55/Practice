class Solution {
public:
    bool isValid(string s) {
        string ans;
        
        for(int i = 0; i< s.size(); i++)
        {
            char c = s[i];
            
            if(c == '[')
                ans.push_back(']');
            else if(c == '(')
                ans.push_back(')');
            else if(c == '{')
                ans.push_back('}');
            else if(ans.size() == 0 || ans.back() != c)
                return false;
            else
                ans.pop_back();
        }
   
        return ans.size()==0?true:false;
    }
};
