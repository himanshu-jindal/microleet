class Solution {
public:
    // radix sort and bucket sort
    
    void count_sort(vector<int>& nums, int exp){
        
        int size = nums.size();
        vector<int> count_vector(10, 0);
        int digit=0;
        
        
        
        for(auto e:nums){
            digit = ((e/exp)%10);
            count_vector[digit]++;
            
        }
        
        for(int i=1; i<10; i++)
            count_vector[i] = count_vector[i] + count_vector[i-1];
            
        
        vector<int> result(size+1,0);
        for(int i=size-1; i>=0; i--){
            
            digit = (nums[i]/exp)%10;
            
            result[count_vector[digit]] = nums[i];
            count_vector[digit]--;
            
        }
        
        for(int i=0; i<size; i++)
            nums[i] = result[i+1];
        
    }
    int maximumGap(vector<int>& nums) {
        
        if(nums.size() < 2)
            return 0;
        
        int max = *max_element(nums.begin(), nums.end());
        
        for(int exp=1; (max/exp) >0; exp=exp*10)
            count_sort(nums, exp);
        
        int max_diff = 0;
        for(int i=0; i<nums.size()-1; i++){
            
            if((nums[i+1]-nums[i]) > max_diff)
                max_diff = nums[i+1]-nums[i];
            
        }
        
        return max_diff;
    }
};
