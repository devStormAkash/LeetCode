// class Solution {
//     public int reverse(int x) {
//         long ans = 0;
//         while(x != 0){
//             ans = ans*10 + x%10;
//             x = x/10;
//         }
//         if(ans > (long)Math.pow(2,31) - 1 || ans < -1*Math.pow(2,31) ) return 0;
//         return (int)ans;
//     }
// }

class Solution {
    public int reverse(int x) {
       int rev=0;
      int num=x;
      while(num!=0){
          int rem=num%10;
          int prev=rev;
          rev=rev*10+rem;
          if((rev-rem)/10!=prev)
              return 0;
          num=num/10;
      }
      return rev;  
    }
}