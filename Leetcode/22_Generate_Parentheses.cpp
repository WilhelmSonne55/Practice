vector<string> ans;
void generateString (string s, int ln, int rn);

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        if(n == 0)
            return ans;
        else
        {
            string s("");
            ans.clear();
            generateString(s+'(', n-1, n);
            return ans;
        }
    }
};

void generateString (string s, int ln, int rn)
{    
    if(rn == 0 && ln == 0)
    {
        ans.push_back(s);
        return;
    }
    
    if(ln == 0)
    {
        generateString(s+')', ln, rn-1);
    }
    else
    {
        generateString(s+'(', ln-1, rn);
        if(ln < rn)
            generateString(s+')', ln, rn-1);
    }
}
