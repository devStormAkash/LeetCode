import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Map<Character,Integer> mp = new HashMap<>();
        // int i = 0, j = 0, maxlen = 0;
        // while(j<s.length()){
        //     if(mp.get(s.charAt(j)) == null){
        //         mp.put(s.charAt(j),1);
        //         j++;
        //     }else{
        //         i++;
        //         j=i;
        //         mp.clear();
        //     }
        //     maxlen = Math.max(maxlen,j-i);
        // }
        
        // return maxlen;
        Map<Character, Integer> lastIndex = new HashMap<>();
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            // if we’ve seen c before and its lastIndex >= left, move left just past it
            if (lastIndex.containsKey(c) && lastIndex.get(c) >= left) {
                left = lastIndex.get(c) + 1;
            }
            // record/update the latest index of c
            lastIndex.put(c, right);
            // window is [left..right], length = right-left+1
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}