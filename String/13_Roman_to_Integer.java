class Solution {
    public int romanToInt(String str) {
        int i = 0;
        int ans = 0;
        while (i <= str.length() - 2) {
            if ((str.charAt(i) == 'I' && (str.charAt(i+1) == 'V' || str.charAt(i+1) == 'X'))
                    || (str.charAt(i) == 'X' && (str.charAt(i+1) == 'L' || str.charAt(i+1) == 'C'))
                    || (str.charAt(i) == 'C' && (str.charAt(i+1) == 'D' || str.charAt(i+1) == 'M'))) {
                if(str.charAt(i) == 'I' && str.charAt(i+1) == 'V') 
                    ans+=4;
                else if(str.charAt(i) == 'I' && str.charAt(i+1) == 'X') 
                    ans+=9;    
                else if(str.charAt(i) == 'X' && str.charAt(i+1) == 'L')
                    ans+=40;
                else if(str.charAt(i) == 'X' && str.charAt(i+1) == 'C')      
                    ans+=90;    
                else if(str.charAt(i) == 'C' && str.charAt(i+1) == 'D') 
                    ans+=400;
                else if(str.charAt(i) == 'C' && str.charAt(i+1) == 'M')   
                    ans+=900; 
                i+=2;
                
            }
            else{
            if(str.charAt(i)=='I') 
                ans+= 1;
            else if(str.charAt(i)=='V') 
                ans+= 5;    
            else if(str.charAt(i)=='X') 
                ans+= 10;
            else if(str.charAt(i)=='L')
                ans+= 50;
            else if(str.charAt(i)=='D') 
                ans+= 500;
            else if(str.charAt(i)=='C')
                ans+=100;
            else if(str.charAt(i)=='M') 
                ans+= 1000;

            i++;    
            }
        }
           if(i==str.length()-1) {
            if(str.charAt(str.length()-1)=='I') 
                ans+= 1;
            else if(str.charAt(str.length()-1)=='V') 
                ans+= 5;
            else if(str.charAt(str.length()-1)=='X') 
                ans+= 10;
            else if(str.charAt(str.length()-1)=='L')
                ans+= 50;
            else if(str.charAt(str.length()-1)=='D') 
                ans+= 500;
            else if(str.charAt(str.length()-1)=='C')
                ans+=100;
            else if(str.charAt(str.length()-1)=='M') 
                ans+= 1000;
           }
        return ans;
    }
}