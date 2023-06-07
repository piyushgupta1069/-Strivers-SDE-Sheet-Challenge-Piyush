#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<long long>s;
    long long mn=1e18;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int val)
		{
			// Write your code here.
			if(s.empty()){
            s.push(val);
            mn=val;
			}else{
				if(val<mn){
					s.push(2LL*val-mn);
					mn=val;
				}else{
					s.push(val);
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop() {
			if(s.size()==0)return -1;
			int t = s.top();
			if(s.top()<mn){
				// 2*val-mn=x
				t = mn;
				mn=2*mn-s.top();
			}
			
			s.pop();
			return t;
		}
		
		int top() {
			if(s.size()==0)return -1;
			if(s.top()<mn){
				return mn;
			}
			return s.top();
		}
		
		int getMin() {
			if(s.size()==0)return -1;
			return mn;
    }
};
