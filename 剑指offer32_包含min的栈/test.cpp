#include<iostream>
#include<stack>
using namespace std;

//定义栈的数据结构，
//请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

class Solution {
public:
	void push(int value) {
		StackInt.push(value);
		if (StackMin.empty())
			StackMin.push(value);
		else if (StackMin.top()<value)
			StackMin.push(StackMin.top());
		else
			StackMin.push(value);
	}
	void pop() {
		if (!StackInt.empty())
		{
			StackInt.pop();
			StackMin.pop();
		}
	}
	int top() {
		return StackInt.top();
	}
	int min() {
		return StackMin.top();
	}
private:
	stack<int> StackInt;
	stack<int> StackMin;
};

void TestFunc(){
	Solution s;
	s.push(2);
	s.push(1);
	s.push(4);
	s.push(3);
	s.push(5);
	cout << s.min() << endl;
}

//思路：利用一个辅助栈来存放最小值
//
//栈  3，4，2，5，1
//辅助栈 3，3，2，2，1
//每入栈一次，就与辅助栈顶比较大小，如果小就入栈，如果大就入栈当前的辅助栈顶
//当出栈时，辅助栈也要出栈
//这种做法可以保证辅助栈顶一定都当前栈的最小值

class Solution2 {
public:

	stack<int> stack1, stack2;

	void push(int value) {
		stack1.push(value);
		if (stack2.empty())
			stack2.push(value);
		else if (value <= stack2.top())
		{
			stack2.push(value);
		}
	}

	void pop() {
		if (stack1.top() == stack2.top())
			stack2.pop();
		stack1.pop();

	}

	int top() {
		return stack1.top();
	}

	int min() {
		return stack2.top();
	}

};

void TestFunc2(){
	Solution s;
	s.push(2);
	s.push(1);
	s.push(4);
	s.push(3);
	s.push(5);
	cout << s.min() << endl;
}
int main(){
	TestFunc2();
	system("pause");
	return 0;
}

