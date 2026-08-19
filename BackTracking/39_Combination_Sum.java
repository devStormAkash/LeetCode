package BackTracking;
import java.util.*;

class Solution {
    public void helper(int i , int target ,List<List<Integer>> ans, List<Integer> ds, int[] arr,int n){
       
        if(target == 0){
                ans.add(new ArrayList<>(ds));
                return;
        }
        
        if(i==n){
            return;
        }
        
        if(arr[i]<=target){
            ds.add(arr[i]);
            helper(i,target-arr[i],ans,ds,arr,n);
            ds.remove(ds.size()-1);
        }
        
        helper(i+1,target,ans,ds,arr,n);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        helper(0,target,ans,ds,candidates,candidates.length);
        return ans;
    }
}