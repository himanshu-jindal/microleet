class Solution {
public:
    
    
    void mergeSort(vector<int>& nums, int left, int right){
        
        if(left < right){
            
            int mid = (left+right)/2;
            
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);
            merge(nums, left, right, mid);
            
        }
        
        
        return;
    }
    
    void merge(vector<int>& nums, int left, int right, int mid){
        
        int size = right-left+1;
        vector<int> temp(size,0);
        int index = 0;
        int left_end = mid+1;
        
        while(left<left_end && (mid+1)<=right){
            
            if(nums[left] <= nums[mid+1]){
                temp[index] = nums[left];
                left++;
               
            }
            else{
                
                temp[index] = nums[mid+1];
                mid++;
                
            }
            
            index++;
               
        }
        
        while(left < left_end){
            
            temp[index] = nums[left];
            left++;
            index++;
            
        }
        while(mid+1 <= right){
            
            temp[index] = nums[mid+1];
            mid++;
            index++;
        }
        
        for(int i=temp.size()-1; i>=0; i--){
            
            nums[right] = temp[i];
            right--;
            
        }
        
       return; 
        
        
        
        
    }
    
    void quickSort(vector<int>& nums, int left, int right){
        
        if(left < right){
            
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot-1);
            quickSort(nums, pivot+1, right);
            
        }
        
        
        
        return;
    }
    
    void swap(int& a, int& b){
        int temp = b;
        b = a;
        a = temp;
      return;  
    }
    
    int partition(vector<int>& nums, int left, int right){
        
        //int pivot_index = left+((right-left)/2);
        int pivot_index = left + rand() % (right - left);
        //swap(nums[pivot_index], nums[left]);
        
        //pivot_index = left;
        int pivot_data = nums[pivot_index];
        
        while(left < right){
            
            while(left <= right && nums[left] <= pivot_data)
                left++;
            
            while(right >= left && nums[right] > pivot_data)
                right--;
            
            if(left < right)
                swap(nums[left], nums[right]);
            
        }
        
        nums[pivot_index] = nums[right];
        nums[right] = pivot_data;
        return right;
        
        
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
