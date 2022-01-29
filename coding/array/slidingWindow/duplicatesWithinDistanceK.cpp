class Solution {
public:
  /*    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,int> him;
        
        for(int i=0; i<nums.size(); i++){
            
            if(him.find(nums[i]) != him.end() && (i - him[nums[i]]) <= k) 
                return true;
            
            him[nums[i]] = i;    
            
        }
        
        return false;
        
    }
    
 */   
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        //using set
        // much faster than map
        
        unordered_set<int> him;
        
        for(int i=0; i<nums.size(); i++){

            
            if(i>k){
                
                him.erase(nums[i-k-1]);
                
            }
            
            auto flag = him.insert(nums[i]);
            
            if(!flag.second)
                return true;
            
        }
        
        return false;
        
    }
    
};
