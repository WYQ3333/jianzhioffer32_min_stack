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
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s.min() << endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}

