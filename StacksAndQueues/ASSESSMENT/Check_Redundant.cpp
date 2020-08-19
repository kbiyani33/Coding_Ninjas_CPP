#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
bool checkRedundantBrackets(char *exp) {
	// Write your code here
    
    /*
    So what's the idea here ? We want to iterate throughout the string. We want to make sure that, any 
    of the subexpressions are not surrounded by an opening and a closing bracket. If we find a '(' or
    any of the operators (+,-,*,/) we push it to the stack. Once we find a '(' following conditions arise.
    
    1) If the top of the stack is '(' and not any of the operators, it means that the bracket is redundant.
    
    
    EX 1:
    (a+b)*(c+d)
    */
    
    
    stack<char> s;
    //int counter = 0;
    for(int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '(' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            //counter+=1;
            s.push(exp[i]);
        }
        
        else if(exp[i] == ')'){
            char a = s.top();
            if(a =='('){
                return true;
            }
        }
        else{
            continue;
        }
    }
    return false;
    
    
}
