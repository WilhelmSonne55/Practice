int digitsIndex[] = {0,3,6,9, 12,15, 19, 22, 26};

void addNext(vector<string>& ans, char c);
void extendString(vector<string>& ans, string s, int index);

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        for(int i=0; i < digits.size(); i++)
        {
            //cout<<"digits[i]:"<<digits[i]<<endl;
            addNext(ans, digits[i]);
        }
        
        return ans;
    }
};


void extendString(vector<string>& ans, string s, int index)
{
    if(index <0 || index > 8)
    {
        cout<<"over flow:"<<index<<endl;
        return;
    }
    
    
        for(int j = digitsIndex[index]; j < digitsIndex[index+1];j++)   
        {    
            string tmp = s;

            //cout<<" j:"<<j<<" char:"<<(char)(97+j)<<endl;
            tmp.push_back((char)(97+j));
            ans.push_back(tmp);
        }
}

void addNext(vector<string>& ans, char c)
{
    int index = c-50;
    int size = ans.size();
    //cout<<"c:"<<c<<" index:"<<index<<endl;
    
    for(int i = 0; ans.size() == 0 || i< size; i++)
    {
        if(ans.size() != 0)
        {
            string stmp = ans[0];
            
            //cout<<stmp<<endl;
            ans.erase(ans.begin());
            extendString(ans, stmp, index);
        }
        else
        {
            string stmp;
            extendString(ans, stmp, index);
        }

    }
}
