class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0, max1=0, j=0, found;
        string s1;
        
            while( j< s.size()){
                found = s1.find(s[j]);
                
                if(found == string::npos){
                    
                    s1.push_back(s[j]);
                    count++;
                }
                
                else{
                    
                    s1.erase(0, found+1);
                    s1.push_back(s[j]);
                    count -= found;
                }
                
                max1 = max(max1,count);
                j++;
            }
            
        return max1;
    }
};

//optimised
//
//


int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
