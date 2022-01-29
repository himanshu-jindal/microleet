class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        int index = m+n-1;
        int i,j;
        i= m-1;
        j=n-1;
        
        while(j>=0 && i>=0){
            
            if(nums1[i] > nums2[j])
                nums1[index] = nums1[i--];
            else 
                nums1[index] = nums2[j--];

            index--;
            
        }
        
        if(j != -1){
            
            while(j >=0){
                nums1[j] = nums2[j];j--;
            }
            
        }
        
       return; 
    }
};
