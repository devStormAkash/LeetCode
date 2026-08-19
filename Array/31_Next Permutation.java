package Array;

class Solution {
    private void swap(int[] arr, int i , int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    private void reverse(int[] arr, int i , int j){
        while(i<j){
            swap(arr,i,j);
            i++;
            j--;
        }
    }
    public void nextPermutation(int[] nums) {
        int i = nums.length-1;
        while(i>0 && nums[i-1]>=nums[i]){
            i--;
        }
        if(i==0){
            reverse(nums,0,nums.length-1);
            return;
        }
        i--;
        int nextSmallVal = nums[i];
        int nextLargeIdx = -1;
        int nextLargeVal = -1;
        int k = 0;
        for( k = nums.length - 1; k>=i ; k--){
            if(nums[k]>nextSmallVal){
                nextLargeVal = nums[k];
                nextLargeIdx = k;
                break;
            }
        }

        // for(int l = k - 1; l>=i ; l--){
        //     if(nums[l]>nextSmallVal && nums[l]<nextLargeVal){
        //         nextLargeVal = nums[l];
        //         nextLargeIdx = l;
        //     }
        // }
        swap(nums,i,nextLargeIdx);
        reverse(nums,i+1,nums.length-1);
    }
}