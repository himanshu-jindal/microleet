class Solution {
public:
    
    void heapify(vector<int>& nums, int i, int size){
        
        int left = (2*i)+1;
        int right = (2*i)+2;
        int max = i;
        if(left <= size && nums[left] > nums[i])
            max = left;
        if(right <= size && nums[max] < nums[right])
            max = right;
        
        if(max == i)
            return;
        else{
            int store = nums[i];
            nums[i] = nums[max];
            nums[max] = store;
            heapify(nums, max, size); 
        }
        
       return; 
    }
    
    void make_heap(vector<int>& nums, int h){
        
        int first_non_leaf = (h-1)/2;
        for(int i=first_non_leaf; i>=0; i--)
            heapify(nums, i, h);
        return;
        
    }
    
    
    
    int findKthLargest(vector<int>& nums, int k) {
        
	// you can implement this using priority queue, but here we have shown behind code for priority        // queue which is binary heap
	
        int size = nums.size()-1;
        int temp = 0;
        make_heap(nums, size);
        
        for(int i=1; i<k; i++){
            
            
            temp = nums[size];
            nums[size] = nums[0];
            nums[0] = temp;
            size--;
            heapify(nums, 0, size);
             
        }
        return nums[0];
        
    }
};
