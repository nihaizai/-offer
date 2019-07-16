#include <iostream>
#include <queue>

using namespace std;

template<typename T>class CStack{
public:
	CStack(){}
	~CStack(){}
	void append(const T& node);
	T deleteHead();
private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T> void CStack<T>::append(const T& node){
	if (queue1.empty() && queue2.empty()){
		queue1.push(node);
	}
	else if (!queue1.empty()){
		queue1.push(node);
	}
	else if (!queue2.empty()){
		queue2.push(node);
	}
}
template<typename T> T CStack<T>::deleteHead(){
	if (queue1.empty() && queue2.empty()){
		return -1;
	}
	if (!queue1.empty()){

		while (queue1.size()>1){
			queue2.push(queue1.front());
			queue1.pop();
		}
		T result = queue1.front();
		queue1.pop();
		return result;
	}
	if (!queue2.empty()){
		while ( queue2.size()>1){
			queue1.push(queue2.front());
			queue2.pop();
		}
		T result = queue2.front();
		queue2.pop();
		return result;
	}
	
}

void Test(){
	CStack<int> s;
	s.append(1);
	s.append(2);
	s.append(3);
	int rs = s.deleteHead();
	cout << rs << "   3"<<endl;
	s.append(4);
	s.append(5);
	int rs2 = s.deleteHead();
	cout << rs2 << "  5" << endl;
	int rs3 = s.deleteHead();
	int rs4 = s.deleteHead();
	int rs5 = s.deleteHead();
	int rs6 = s.deleteHead();
	cout << rs6 << "    -1" << endl;



}

int main(){
	Test();
	return 0;
}
