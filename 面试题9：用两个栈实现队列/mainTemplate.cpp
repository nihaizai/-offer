#include <iostream>
#include <stack>
using namespace std;



template<typename T> class CQueue{
public:
	CQueue(){}
	~CQueue(){}

	void appendTail(const T& node);
	T deleteHeadF1();
	T deleteHeadF2();
private:
	stack<T> stack1;
	stack<T> stack2;
};


template <typename T> void CQueue<T>::appendTail(const T& node){
	stack1.push(node);

}
template <typename T> T CQueue<T>::deleteHeadF1(){
	if (stack1.empty() && stack2.empty()){
		return -1;
	}
	if (stack2.empty()){
	while (!stack1.empty()){
		stack2.push(stack1.top());
		stack1.pop();
	}
	}
	T result = stack2.top();
	stack2.pop();
	return result;
}


template <typename T> T CQueue<T>::deleteHeadF2(){
	if (stack1.empty()){
		return -1;
	}
	while (!stack1.empty()){
		stack2.push(stack1.top());
		stack1.pop();
	}
	T result = stack2.top();
	stack2.pop();
	while (!stack2.empty()){
		stack1.push(stack2.top());
		stack2.pop();
	}
	return result;
}
//往空的队列里添加、删除元素
//往非空的队列里添加、删除元素
//连续删除元素直至队列为空
void Test(int actual, int expected){
	if (actual == expected){
		cout << "passed." << endl;
	}
	else{
		cout << "Failed." << endl;
	}
}
int main(){
	CQueue<int> c;
	c.appendTail(1);
	c.appendTail(2);
	c.appendTail(3);
	int rs = c.deleteHeadF2();
	Test(rs, 1);
	c.appendTail(4);
	int rs2 = c.deleteHeadF2();
	Test(rs2, 2);
	c.appendTail(5);
	int rs3 = c.deleteHeadF2();
	Test(rs3, 3);
	int rs4 = c.deleteHeadF2();
	Test(rs4, 4);
	int rs5 = c.deleteHeadF2();
	Test(rs5, 5);
	int rs6 = c.deleteHeadF2();
	Test(rs6, -1);


	return 0;
}
