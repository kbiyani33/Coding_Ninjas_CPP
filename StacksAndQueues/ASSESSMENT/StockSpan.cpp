#include<stack>

int* stockSpan(int *price, int size) {
	
    // Create a stack and push index of first element to it 
    stack<int> st; 
    st.push(0); 
    int *S = new int[size];
  
    // Span value of first element is always 1 
    S[0] = 1; 
  
    // Calculate span values for rest of the elements 
    for (int i = 1; i < size; i++) { 
        while (!st.empty() && price[st.top()] < price[i]) 
        {
            st.pop(); 
        } 
        S[i] = (st.empty()) ? (i + 1) : (i - st.top()); 
  
        // Push this element to stack 
        st.push(i); 
    }
    return S;
}
