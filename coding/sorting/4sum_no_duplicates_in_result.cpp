class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size =nums.size();
        for(int i=0; i<size; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1; j<size; j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                continue;
            }
                int left = j + 1, right = size - 1, remain;
                while(left < right){
                    remain = target - nums[i] - nums[j];
                    if(remain == (nums[left] + nums[right])){
                        vector<int> him {nums[i], nums[j], nums[left], nums[right]};
                        result.push_back(him);
                        while(left < right && nums[left] == nums[left+1]){
                            left++;
                        }
                        left++; right--;
                    }
                    else if(remain < (nums[left] + nums[right])){
                        right--;
                        
                    }
                    else {
                        left++;
                    }
                    
                }
            }
        }
        return result;
    }
};
