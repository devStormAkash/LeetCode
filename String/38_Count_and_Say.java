class Solution {
    private String countString(String s){
        StringBuilder sb = new StringBuilder("");
        
        int first = 0;
        int second = 0;
        while(second < s.length()){
            int count = 0;
            while(second < s.length() && s.charAt(first) == s.charAt(second)){
                count++;
                second++;
            }
            sb.append(count);
            sb.append(s.charAt(first));
            first = second;
        }
        return sb.toString();
    }
    public String countAndSay(int n) {
        String s1 = "1";
        String s2 = "";

        for(int i = 2; i<= n ; i++){

            s2 = countString(s1);
            s1 = s2;

        }
    
        if(n == 1) return s1;
        return s2;
    }
}