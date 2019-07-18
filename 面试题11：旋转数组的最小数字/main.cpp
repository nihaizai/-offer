#include <iostream>
#include <vector>

using namespace std;

int Min(vector<int>& numbers){

	if (numbers.size() <= 0){
		throw new std::exception("Invalid parameters");
		//return -1;
	}


	int low = 0;
	int high = numbers.size() - 1;
	int mid = 0;

	while (numbers[low] >= numbers[high]){
		if (high - low == 1){
			mid = high;
			break;
		}
		mid = (low + high) / 2;

		//如果下标low、high和mid指向的三个数字相等，则只能顺序查找
		//如Test4所示
		if (numbers[low] == numbers[high] && numbers[low] == numbers[mid]){
			int temp = numbers[low];
			for (int j = low+1; j < high; j++){
				if (numbers[j] <= temp){
					temp = numbers[j];
				}
			}
			return temp;
		}

		//缩小查找范围
		if (numbers[low] <= numbers[mid]){
			low = mid;
		}
		else if (numbers[mid] <= numbers[high]){
			high = mid;
		}
	}
	return numbers[mid];
}


void Test(string s,vector<int>& v,int expected){
	cout << s.c_str() << "  ";
	try{
	int result = Min(v);

	if (result == expected){
		cout << "Passed." << endl;
	}
	else{
		cout << "Failed." << endl;
	}
	}
	catch (...){
		if (v.size() == 0){
			cout << "Passed." << endl;
		}
		else{
			cout << "Failed." << endl;
		}
	}

}



//数组按照升序排序，未进行旋转。
void Test1(){
	vector<int> v = { 1, 2, 3, 4, 5 };
	string s = "test1";
	Test(s, v, 1);
}

//典型输入，单调升序的数组的一个旋转
void Test2(){
	vector<int> v = { 6,7,8,1, 2, 3, 4, 5 };
	string s = "test2";
	Test(s, v, 1);
}

//有重复数字，但 数字并不是最小数字
void Test3(){
	vector<int> v = { 2,3,3,5,6,7,8,1 };
	string s = "test3";
	Test(s, v, 1);
}

//有重复数字，且数字是最小数字
void Test7(){
	vector<int> v = { 2,  5, 6, 7, 8, 1,1 };
	string s = "test7";
	Test(s, v, 1);
}




//有重复数字，并且重复的数字刚好是第一个和最后一个数字
void Test4(){
	vector<int> v = {1,1,1,0,1 };
	string s = "test4";
	Test(s, v, 0);
}

//只包含一个元素的数组
void Test5(){
	vector<int> v = { 1 };
	string s = "test5";
	Test(s, v, 1);
}

//数组为空
void Test6(){
	vector<int> v = {};
	string s = "test6";
	Test(s, v, -1);
}


int main(){
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}
