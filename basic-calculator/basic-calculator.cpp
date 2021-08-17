class Solution {
public:
    int calculate(string s) {
        stack<int> evaluator;
        int sign = 1;
        int res = 0;
        int num = 0;
        for(char &c: s){
            if(isdigit(c)){
                num = num*10 + (c - '0');
            }
            else if(c == '-'){
                res += sign*num;
                num = 0;
                sign = -1;
            }
            else if(c == '+'){
                res += sign*num;
                num = 0;
                sign = 1;
            }
            else if(c == '('){
                evaluator.push(res);
                evaluator.push(sign);
                num = 0;
                res = 0; 
                sign = 1;
            }
            else if(c==')'){
                res += sign*num;
                num = 0;
                int sign = evaluator.top();
                evaluator.pop();
                int prevSum = evaluator.top();
                evaluator.pop();
                res *= sign;
                res += prevSum;
            }
        }
        res += sign*num;
        return res;
    }
};