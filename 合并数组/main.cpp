#include <iostream>
#include <vector>
using namespace std;

/*
题目描述1：有两个排序的数组A1和A2，
内存在A1的末尾有足够多的空余空间容纳A2。
请实现一个函数，把A2中的所有数字插入A1中，
并且所有的数字是排序的。
*/
//定义La时，其长度应为La中有效数字长度和Lb中有效数字长度之和。
void MergeList(int La[],int a_length,int Lb[],int b_length){
	cout << "MergeList" << endl;
	if (a_length <= 0 && b_length <= 0){
		cout << "there exists a null array" << endl;
		return;
	}
	for (int i = 0; i < a_length-1; i++){
		if (La[i] > La[i + 1]){
			cout << "La is not the right array" << endl;
			return;
		}
	}
	for (int i = 0; i < b_length - 1; i++){
		if (Lb[i] > Lb[i + 1]){
			cout << "Lb is not the right array" << endl;
			return;
		}
	}

	int m_length = a_length + b_length;
	int a_index = a_length - 1;
	int b_index = b_length - 1;
	int m_index = m_length - 1;
	while (a_index >= 0 &&b_index >= 0){
		if (La[a_index] <= Lb[b_index]){
			La[m_index] = Lb[b_index];
			b_index--;
		}
		else{
			La[m_index] = La[a_index];
			a_index--;
		}
		m_index--;
	}
	while (a_index >= 0){
		La[m_index--] = La[a_index--];
	}
	while (b_index >= 0){
		La[m_index--] = Lb[b_index--];
	}
	//return La;


}
/*
题目描述2：有两个排序的数组A1和A2，
请实现一个函数，把A1、A2中的所有数字插入新的数组A3中，
并且所有的数字是排序的。
*/
void MergeListNew(int La[],int a_length,int Lb[],int b_length,int Lc[],int c_length){
	cout << "MergeListNew Start" << endl;
	if (a_length <= 0 && b_length <= 0){
		cout << "there exists a null array" << endl;
		return;
	}
	for (int i = 0; i < a_length - 1; i++){
		if (La[i] > La[i + 1]){
			cout << "La is not the right array" << endl;
			return;
		}
	}
	for (int i = 0; i < b_length - 1; i++){
		if (Lb[i] > Lb[i + 1]){
			cout << "Lb is not the right array" << endl;
			return;
		}
	}
	int a_index = 0;
	int b_index = 0;
	int c_index = 0;
	while (a_index < a_length && b_index < b_length){
		if (La[a_index] <= Lb[b_index]){
			Lc[c_index] = La[a_index];
			a_index++;
		}
		else{
			Lc[c_index] = Lb[b_index];
			b_index++;
		}
		c_index++;
	}
	while (a_index < a_length){
		Lc[c_index] = La[a_index];
		a_index++;
		c_index++;
	}
	while (b_index < b_length){
		Lc[c_index] = Lb[b_index];
		b_index++;
		c_index++;
	}

}









//==============测试代码=================
bool Array_equal(int* a, int a_length, int* b,int b_length){
	if (a == nullptr && b == nullptr){
		cout << "all nullptr" << endl;
		return true;
	}
	if (a_length != b_length){
		return false;
	}
	for (int i = 0; i < a_length; i++){
		if (a[i] != b[i]){
			return false;
		}
	}
	return true;
}

void Test(char* test_num,int a[],int a_length,int b[],int b_length,int truth[],int t_length){
	MergeList(a,a_length,b,b_length);
	for (int i = 0; i < a_length + b_length; i++){
		cout << a[i] << "  ";
	}
	cout << endl;
	if (Array_equal(a, a_length + b_length, truth, t_length)){
		cout << test_num << "  passed. " << endl;
	}

}
void TestNew(char* test_num,int a[],int a_length,int b[],int b_length,int truth[],int t_length){
	int c_length = a_length + b_length;
	int *c = new int[c_length];
	MergeListNew(a,a_length,b,b_length,c,c_length);
	cout << "C  Start" << endl;
	for (int i = 0; i < c_length; i++){
		cout << c[i] << "  ";
	}
	cout << endl;
	if (Array_equal(c, c_length, truth, t_length)){
		cout << test_num << "  passed. " << endl;
	}

	delete[] c;
}
//一般情况下，a、b数组中的元素均按照次序排列
void Test1(){
	int a[10] = { 1, 2, 3, 4 };
	int b[6] = {0,0,5,6,7,8};
	int truth[10] = {0,0,1,2,3,4,5,6,7,8};
	//Test("test1", a, 4, b, 6, truth, 10);
	TestNew("test new1", a, 4, b, 6, truth, 10);
}
//a数组为空,b非空
void Test2(){
	int a[6] = {};
	int b[6] = { 1, 2, 3, 4, 5, 6 };
	int truth[6] = { 1, 2, 3, 4, 5, 6 };
	//Test("test2", a, 0, b, 6, truth, 6);
	TestNew("test new2", a, 0, b, 6, truth, 6);
}

//a数组非空，b为空
void Test3(){
	int a[4] = { 1, 2, 3, 4 };
	int* b = nullptr;
	int truth[4] = { 1, 2, 3, 4 };
	//Test("test3", a, 4, b, 0, truth, 4);
	TestNew("test new3", a, 4, b, 0, truth, 4);
}

//a中数组未按照升序排列
void Test4(){
	int a[10] = {1,4,3};
	int b[7] = { 5, 6 ,7,8,8,9,9};
	int truth[10] = {1,4,3};
	//Test("test4", a, 3, b, 7, truth, 10);
	TestNew("test new4", a, 3, b, 7, truth, 10);
}

//b中数组未按照升序排列
void Test5(){
	int a[10] = { 5, 6, 7, 8, 8, 9, 9 };
	int b[3] = {1,4,3};
	int truth[10] = { 5, 6, 7, 8, 8, 9, 9 };
	//Test("test5", a, 3, b, 7, truth, 10);
	TestNew("test new5", a, 3, b, 7, truth, 10);
}
//a，b数组均为空
void Test6(){
	int* a = nullptr;
	int* b = nullptr;
	int* truth = nullptr;
	//Test("test6", a, 0, b, 0, truth, 0);
	TestNew("test new6", a, 0, b, 0, truth, 0);
}




int main(){
	
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	return 0;
}
