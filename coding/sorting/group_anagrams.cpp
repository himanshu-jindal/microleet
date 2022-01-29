class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        //here instead of using inbuilt sort, which is generally quicksort with o(nlogn) time           complexity, we are implementing counting sort with time complexity o(n), as we have lowercase letters only in input
        
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};
