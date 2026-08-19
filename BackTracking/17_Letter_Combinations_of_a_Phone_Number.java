package BackTracking;
import java.util.*;

class Solution {
    public void helper(int ind , String path, List<String> ans , String s , String[] map){
        if(ind == s.length()){
            ans.add(path);
            return;
        }
        for(int i = 0 ; i<map[s.charAt(ind) - '0'].length() ; i++){
            path+=map[s.charAt(ind)-'0'].charAt(i);
            helper(ind+1,path,ans,s,map);
            path = path.substring(0,path.length()-1);
        }
    }
    public List<String> letterCombinations(String digits) {
        String[] map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        List<String> ans = new ArrayList<>();
        helper(0,"",ans,digits,map);
        return ans;
    }
}
