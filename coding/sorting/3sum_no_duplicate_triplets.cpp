class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0; i< nums.size(); i++){
            if( i >0 && (nums[i] == nums[i-1])){
                continue;
            }
            int left=i+1;
            int right= nums.size()-1;
            while(left < right){
                int sum = nums[left] +nums[right]+ nums[i];
                if(sum == 0){
                    vector<int> aa {nums[left], nums[right], nums[i]};
                    result.push_back(aa);
                    while(left<right && (nums[left] == nums[left+1])){
                        left++;
                    }
                    left++;right--;
                }
                else if(sum > 0){
                    right = right - 1;
                }
                else if(sum <0){
                    left = left +1;
                }
            }
            
        }
        return result;
    }
};
