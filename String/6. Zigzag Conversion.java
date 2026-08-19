// import java.util.*;

class Solution {
    public String convert(String s, int numRows) {
        if(s.length() == 1) return s;
        if(numRows >= s.length()) numRows = s.length();
        int r = numRows;
        int i = 0;
        String finalStr = "";
        for(; r>0 ; r--){
            int dwnSkpVal = r*2 - 3;
            int upSkpVal = (numRows - r )*2 - 1;
            i = (numRows - r);
            finalStr+=s.charAt(i);
            while(i<s.length()){
                if(dwnSkpVal > 0){
                    i+=dwnSkpVal+1;
                    if(i<s.length()){
                        finalStr += s.charAt(i);
                    }
                }
                if(upSkpVal > 0){
                    i+=upSkpVal+1;
                    if(i<s.length()){
                        finalStr += s.charAt(i);
                    }
                }
                if(dwnSkpVal <= 0 && upSkpVal <= 0) {
                    i++;
                    if(i<s.length()){
                        finalStr+=s.charAt(i);
                    }
                }
            }

        }
        return finalStr;
    }
}