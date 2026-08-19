package Stack;

import java.util.Stack;
class Solution {
    public boolean isValid(String s) {
        Stack<Character> charStack = new Stack<>();
        for(int i = 0; i<s.length(); i++){
            if(s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '['){
                charStack.push(s.charAt(i));
            }else{
                char topParenthesis = ' ';
                if(charStack.isEmpty()) return false;
                if(charStack.size()>0){
                    topParenthesis = charStack.peek();
                }
                
                if((topParenthesis == '(' && s.charAt(i) == ')') || (topParenthesis == '{' && s.charAt(i) == '}') || (topParenthesis == '[' && s.charAt(i) == ']') ){
                    charStack.pop();
                }else{
                    return false;
                }
            }
        }
        if(charStack.size() == 0) return true;
        else return false;
        
    }
}
