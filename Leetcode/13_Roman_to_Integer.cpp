class Solution {
public:
    int romanToInt(string s) {
        map<char, int> smap = {{'I', 1}, {'V',5}, {'X',10}, {'L',50}, {'C', 100}, {'D',500}, {'M',1000}};
        
        int num = 0;
        int pre = 0;

        while(s.size()!=0)
        {
            int tmp = smap[s.back()];
            if(tmp < pre)
            {
                num -= tmp;
                
            }
            else
            {
                num += tmp;
            }
            pre = tmp;
            s.pop_back();
        }
        
        return num;
    }
};
