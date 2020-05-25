class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;
        if(words.size()==0 || s.size() == 0)
            return ans;
        
        int len = words[0].size();
        unordered_map<string, int> count;
        
        for(string word: words)
            count[word]++;
        
        for(int i = 0; i < s.size() - words.size()* len +1; i++)
        {
            unordered_map<string, int> seen;
            
            //should have the numbers of words
            int j = 0;
            for(; j < words.size(); j++)
            {
                string word = s.substr(i+j*len, len);

                if(count.find(word) != count.end())
                {
                    seen[word]++;
                    if(seen[word] > count[word])
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }                
            }
            if(j == words.size())
                ans.push_back(i);
        }
        
        return ans;
    }
};
