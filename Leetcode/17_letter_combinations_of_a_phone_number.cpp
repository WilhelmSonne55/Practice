
int numIndex[]={0,3, 6, 9, 12, 15, 19, 22, 26};

vector<string> ans;
void backtrace(string, string digits);

class Solution {
public:
    vector<string> letterCombinations(string digits) {
         //ans.clear();

        if(digits.size()!=0)
        {
            string com;              
            backtrace(com, digits);
        }
        
        return ans;
    }
};


void backtrace(string com, string digits)
{
    if(digits.size() == 0)
    {
        ans.push_back(com);
        return;
    }
    else
    {
        int index = (digits[0])-50;
        for(int i = numIndex[index]; i< numIndex[index+1];i++)
        {
            string s = com;
            char c = 97 + i;            
            cout<<"c:"<<c<<endl;

            s.push_back(c);
            backtrace(s, digits.substr(1, digits.size()-1));
        }
        return;
    }  
}
