class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0;
        int count = 0;
        int start = 0;
        int result = INT_MAX;
        // link for question-  https://leetcode.com/problems/minimum-size-subarray-sum/
        for(int i=0; i<nums.size(); i++){
            
            sum += nums[i];
            count++;
            
            if(sum >= target){
                
                result = min(count, result);
                
                while(sum >= target){
                    
                    sum -= nums[start];
                    start++;
                    count--;
                    
                    if(sum >= target)
                        result = min(count, result);
                    
                }
                  
            }
            
            else
                continue;
                
        }
        
        return result==INT_MAX ? 0 : result;
        
    }
};
