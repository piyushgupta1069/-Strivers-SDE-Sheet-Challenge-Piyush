#include <bits/stdc++.h> 
void help(stack<int>&stack, int x)
{
	if(stack.size()==0){
		stack.push(x);
		return;
	}
	if(stack.top()<=x){
		stack.push(x);
		return;
	}
	int y = stack.top();
	stack.pop();
	help(stack,x);
	stack.push(y);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.size()==0)return;
	int x = stack.top();
	stack.pop();
	sortStack(stack);
	help(stack,x);
}
