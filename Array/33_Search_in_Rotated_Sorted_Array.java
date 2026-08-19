
package Array;
class Solution {
    public int search(int[] nums, int target) {
        int i = 0;
        int j = nums.length - 1;
        int last = nums[j];
        int first = nums[i];
        while(i <= j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < last){
                if(target > last) j = mid-1;
                else if(target > nums[mid]) i = mid + 1;
                else j = mid - 1;
            }
            else{
                if(target < first) i = mid+1;
                else if(target > nums[mid]) i = mid + 1;
                else j = mid - 1;
            }
        }

        return - 1;
    }
}