class Solution {
    public int myAtoi(String s) {
        StringBuilder str = new StringBuilder(s);
        while(str.length() >0 && str.charAt(0) == ' '){
            str.deleteCharAt(0);
        }
        if(str.length() == 0) return 0;

        boolean flag = false;
        if(str.charAt(0) == '-'){
            flag = true;
        }
        else if(str.charAt(0) == '+') str.deleteCharAt(0);

        while(str.length() >= 2 && flag == true && str.charAt(1) == '0' ) str.deleteCharAt(1);
        while(str.length() >0 && flag == false && str.charAt(0) == '0') str.deleteCharAt(0);
        if(str.length() == 0) return 0;

        long ans = 0;
        // int idx = 0;
        if(flag == true) str.deleteCharAt(0);
        while(str.length() >0 && str.charAt(0) >= 48 && str.charAt(0) <= 57){
            ans = ans*10 + (str.charAt(0) - 48);
            if(flag == true && ans > (long)Math.pow(2,31)) return Integer.MIN_VALUE;
            if(flag == false &&  ans > (long)Math.pow(2,31) - 1) return Integer.MAX_VALUE;
            str.deleteCharAt(0);
        }
        return flag == true ? -1*(int)ans : (int)ans;
    }
}