#include<iostream>
#include<stack>
using namespace std;

//����ջ�����ݽṹ��
//���ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������

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

//˼·������һ������ջ�������Сֵ
//
//ջ  3��4��2��5��1
//����ջ 3��3��2��2��1
//ÿ��ջһ�Σ����븨��ջ���Ƚϴ�С�����С����ջ����������ջ��ǰ�ĸ���ջ��
//����ջʱ������ջҲҪ��ջ
//�����������Ա�֤����ջ��һ������ǰջ����Сֵ

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

