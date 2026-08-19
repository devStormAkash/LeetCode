package BackTracking;
import java.util.*;

class Solution {
    public void helper(List<List<Integer>> ans , List<Integer> path,boolean[] visited, int[] nums , int ind){
        if(path.size() == nums.length){
            ans.add(new ArrayList<>(path));
            return;
        }
        for(int i = 0 ; i<nums.length ; i++){
            if(visited[i]) continue;
            if(i>0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            if(!visited[i]){
                visited[i] = true;
                path.add(nums[i]);
                helper(ans,path,visited,nums,i+1);
                visited[i] = false;
                path.remove(path.size()-1);
            }
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        helper(ans,new ArrayList<>() ,visited,nums,0 );
        return ans;
        
    }
}