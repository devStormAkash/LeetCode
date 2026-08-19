class Solution {
    double powLog(double a,int b){
        if(b == 0) return 1;
        double x = powLog(a,b/2);
        if(b%2 == 0) return x*x;
        else return x*x*a;
    }
    public double myPow(double x, int n) {
        if(x==0) return 0;
        if(x>0 && n >0) return powLog(x,n);
        else if(x<0 && n>0){
            if(n%2==0) return powLog(-1*x,n);
            else return -powLog(-1*x,n);
        }
        else if(x>0 && n<0) return 1/powLog(x,-1*n);
        else {
            if(n%2 == 0) return 1/powLog(-x,n);
            else return -(1/powLog(-x,n));
        }
    }
}