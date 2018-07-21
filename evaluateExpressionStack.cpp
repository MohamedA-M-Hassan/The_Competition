///https://www.interviewbit.com/problems/evaluate-expression/
bool isOperator(string op)
{
    if(op == "+" || op == "-" || op == "/" || op == "*")
        return true;
    else
        return false;
}


int Solution::evalRPN(vector<string> &A) {
    stack<int> a;
    int result;
    for(int i = 0; i < A.size(); i++) {
        if (isOperator(A[i])) {
            int second = a.top();
            a.pop();
            int first = a.top();
            a.pop();
            if (A[i] == "+")
               result = first + second;
            else if (A[i] == "-")
                result = first - second;
            else if (A[i] == "*")
                result = first * second;
            else
                result = first / second;
            a.push(result);
        }
        else {
            a.push(stoi(A[i]));
        }
    }
    return a.top();
}
