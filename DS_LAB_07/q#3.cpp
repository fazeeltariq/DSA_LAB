#include<bits/stdc++.h>

bool isoperator () {

}
string convertToPostfix (string infix) {
    string ans;
    stack<char> st;

    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i]>='A' && infix[i]<='Z') || (infix[i]>='a' && infix[i]<='b') || (infix[i]>='0' && infix[i]<='9')) {
            ans += infix[i];
        }
        else if (infix[i]=='(') {
            st.push (infix[i]);
        }
        else {
            
        }
    }
    
}
using namespace std;
int main()
{
    string infix = "a+b*(c^d-e)";
    string postfix = convertToPostfix(infix);
    cout << postfix;
    return 0;
}