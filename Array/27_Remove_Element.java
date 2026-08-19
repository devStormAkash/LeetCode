package Array;

class Solution {
    public int removeElement(int[] nums, int val) {
        int k = 0;
        for(int i  = 0 ; i<nums.length ; i++){
            if(nums[i] == val) k++;
        }
        k = nums.length - k;
        // for(int i = 0 ; i< nums.length ; i++){
        //     for(int j = 0 ; j<nums.length - 1 - i ; j++){
        //         if(nums[j] == val){
        //             int temp = nums[j];
        //             nums[j] = nums[j+1];
        //             nums[j+1] = temp;
        //         }
        //     }
        // }
        int insertPos = 0;
        for(int i = 0 ; i<nums.length ; i++ ){
            if(nums[i]!= val){
                nums[insertPos++] = nums[i];
            }
        }
        return k;
    }
}