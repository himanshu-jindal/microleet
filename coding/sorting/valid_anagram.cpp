class Solution {
public:
    bool solution1(string s, string t){
        
        if(s.size() != t.size())
            return false;
        
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i] != t[i])
                return false;
            
        }
        
        return true;    
        
    }
    
    
    bool solution2(string s, string t){
        
        
        unordered_map<char,int> map;
        
        for(auto e:s)
            map[e]++;

        for(auto e:t)
            map[e]--;
        
        for(auto e:map){
            if(e.second != 0)
                return false;
            
        }
        return true;
        
        
    }
    
    bool solution3(string s, string t){
        
        vector<int> counts(26,0);
        
        for(auto e:s)
            counts[e - 'a']++;
        for(auto e:t)
            counts[e - 'a']--;
        for(auto e:counts){
            
            if(e != 0)
                return false;
            
        }
        return true;
        
        
    }
    
    bool isAnagram(string s, string t) {

        
        vector<int> counts(26,0);
        
        for(auto e:s)
            counts[e - 'a']++;
        for(auto e:t)
            counts[e - 'a']--;
        for(auto e:counts){
            
            if(e != 0)
                return false;
            
        }
        return true;
        
    }
};
