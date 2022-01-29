class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
    std::sort(nums.begin(), nums.end());
    
    int diff = 10001;
    int result = 0;
    
    
    for(int i=0; i<nums.size(); i++){
        
        int left = i+1;
        int right = nums.size()-1;
        
        while(left < right){
            int sum = nums[left] + nums[right] + nums[i];
            
            if(sum == target)
                return sum;
            else if(sum > target){
                
                if(diff > (sum-target)){
                    diff = sum - target;
                    result = sum;
                }
                    
                
                right--;
                
            }
            else{
                
                if(diff > (target-sum)){
                    diff = target-sum;
                    result = sum;
                }
                    
                left++;                
                  
            }
            
        }  
    }
    
    return result;
  }
};
