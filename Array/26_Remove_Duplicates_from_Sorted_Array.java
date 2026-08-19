package Array;

// class Solution {
//     public int removeDuplicates(int[] nums) {
//         int i1 = 0;
//         while(i1<nums.length){
//             int count = 0;
//             int num = nums[i1];
//             while(i1 < nums.length && num == nums[i1]){
//                 i1++;
//                 count++;
//             }
//             int j = i1 - 1;
//             if(count > 1){
//                 for(int k = 1 ; k<= count - 1 ; k++){
//                     nums[j--] = 100000;
//                 }
//             }
//         }

//         int i2 = 0; int ans = 0; int j = 0;
//         while(i2 < nums.length && nums[i2] != 100000){
//             i2++;
//             ans++;
//         }
//         j = i2;

//         if(ans == nums.length) return ans;

//         while(j < nums.length){
//             while(j < nums.length && nums[j] == 100000) j++;
//             if(j < nums.length && nums[i2] == 100000 && nums[j] != 100000){
//                 ans++;
//                 int temp = nums[i2];
//                 nums[i2] = nums[j];
//                 nums[j] = temp;
//                 i2++;
//                 j++;
//             }
//         }

//         return ans;

//     }
// }

class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        for(int n : nums){
            if(i < 1 || n > nums[i-1]){ // found our next unique number
                nums[i++] = n;
            }
        }
        return i;
    }
}
