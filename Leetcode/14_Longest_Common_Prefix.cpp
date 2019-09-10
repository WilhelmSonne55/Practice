string findPrefix(string str1, string str2);
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        
        if(strs.size() > 1)
        {
            prefix = findPrefix(strs[0], strs[1]);
			for(int i = 2; i< strs.size(); i++)
			{
				prefix = findPrefix(prefix, strs[i]);
				
				if(prefix.size() == 0)
					return "";
			}
        }
        else if(strs.size() == 1)
            return strs[0];
        else
            return "";
   
        return prefix;
    }
};

string findPrefix(string str1, string str2)
{
        int i = 0;
        for(; i<str1.size() && i<str2.size();i++)
        {
            if(str1[i] != str2[i])
                break;

        }

    return str1.substr(0,i);
}

//Devide and Conquer
#if 0
string findPrefix(string str1, string str2);
string Devide(vector<string>& strs, int l, int r);

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        
        if(strs.size() > 1)
        {
            return Devide(strs, 0, strs.size()-1);
        }
        else if(strs.size() == 1)
            return strs[0];
        else
            return "";
        }
};

string Devide(vector<string>& strs, int l, int r)
{
    string str1, str2;
    if( l == r)
        return strs[l];
    else
    {
        int mid = (l+r)/2;
        str1 = Devide(strs, l, mid);
        str2 = Devide(strs, mid+1, r);
        
    }
    
    return findPrefix(str1,str2);
}


string findPrefix(string str1, string str2)
{
        int i = 0;
        for(; i<str1.size() && i<str2.size();i++)
        {
            if(str1[i] != str2[i])
                break;

        }

    return str1.substr(0,i);
}
#endif
