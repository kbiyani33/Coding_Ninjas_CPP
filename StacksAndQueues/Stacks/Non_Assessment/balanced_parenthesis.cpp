#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
bool checkBalanced(char *exp) {
	// Write your code here
    char a[] = "({[";
    char b[] = ")}]";
    sort(a, a+3);
    sort(b, b+3);
    if(exp[0] == '\0'){
        return true;
    }
    stack<char> cc;
    for(int i=0; exp[i] != '\0'; i++){
        if(binary_search(a, a+3, exp[i])){
            cc.push(exp[i]);
        }
        else if(binary_search(b, b+3, exp[i])){
            if(!cc.empty())
            {
            	char d = cc.top();
            	cc.pop();
            	if((exp[i] == ')' && d == '(') ||  (exp[i] == '}' && d == '{') || (exp[i] == ']' && d == '[')){
                	continue;
            	}
            	else{
                	return false;
            	}
            }
            else{
                return false;//if a closing bracket is found before any opening bracket, it should be unbalanced
            }
        }
        else{
            continue;
        }
    }
    if(!cc.empty()){
        return false;
    }
    return true;
}
