/*
 *- Watch out numRows ==1;
 *- push_back, s[] using char
 *- find regularity of number
*/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> svec;
        string ans;
        int i = 0, j = 1, k = 0, Rows = 0;
        Rows = numRows - 2;

        if(numRows == 1)
            return s;
        
        while(j <= numRows)
        {
            ans.push_back(s[i]);
            i += (numRows + Rows - (k*2)); //k is for middle number |  <=| |  |
            
            //after 1st & last row for middle number
            if(i < s.size() && j != 1 && j != numRows)
            {
                ans.push_back(s[i]);
                i += (k*2);//shift back
            }            

            //nest rows
            if(i >= s.size())
            {
                i = j;
                
                //last Row without middle number
                if(j == numRows-1)
                    k = 0;
                else
                    k = j;
    
                j++;
            }
        }
        return ans;
    }
};
