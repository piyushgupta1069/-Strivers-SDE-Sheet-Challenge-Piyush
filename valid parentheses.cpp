bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.empty())return false;
            if(st.top()=='('){
                if(s[i]!=')')return false;
            }else if(st.top()=='{'){
                if(s[i]!='}')return false;
            }else if(st.top()=='['){
                if(s[i]!=']')return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
