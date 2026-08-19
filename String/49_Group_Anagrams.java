import java.util.*;
class Solution {
    public static String sortLowercaseString(String s) {
    // 1) Count frequencies of each letter
    int[] freq = new int[26];
    for (char c : s.toCharArray()) {
        freq[c - 'a']++;
    }

    // 2) Rebuild sorted string
    StringBuilder sb = new StringBuilder(s.length());
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < freq[i]; j++) {
            sb.append((char) ('a' + i));
        }
    }
    return sb.toString();
}

    public List<List<String>> groupAnagrams(String[] strs) {
       Map<String , List<String>> mp = new HashMap<>();
       for(int i = 0; i<strs.length ; i++){
            String s = sortLowercaseString(strs[i]);
            if(!mp.containsKey(s)){
                mp.put(s , Arrays.asList(strs[i]));
            }
            else{
                List<String> lst = new ArrayList<>(mp.get(s));
                lst.add(strs[i]);
                mp.put(s,lst);
            }
       }

       List<List<String>> ans = new ArrayList<>();

       for(Map.Entry<String , List<String>> entry : mp.entrySet() ){
            ans.add(entry.getValue());
       }

        mp.clear();

       return ans;
    }
}