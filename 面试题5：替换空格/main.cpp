#include <iostream>

using namespace std;


class Solution {
public:
	void replaceSpace(char str[], int length) {
		if (str == nullptr && length <= 0){
			return;
		}
		int str_size;
		int count = 0;
		for (str_size = 0; str[str_size] != '\0'; str_size++){
			if (str[str_size] == ' '){
				count++;
			}
		}
		int rst_size = str_size + 2 * count;
		if (rst_size > length){
			return;
		}
		int p1 = str_size;
		int p2 = rst_size;
		while (p1 >= 0 && p1 != p2){
			if (str[p1] == ' '){
				str[p2--] = '0';
				str[p2--] = '2';
				str[p2--] = '%';

			}
			else{
				str[p2--] = str[p1];
			}
			p1--;
		}
	}
};



class Solution_niuke {

public:

	void replaceSpace(char *str, int length) {

		int str_size; //原字符串的长度

		int blankNumber = 0; //空格的数量

		for (str_size = 0; str[str_size] != '\0'; str_size++){

			if (str[str_size] == ' '){

				blankNumber++;

			}

		}



		int newStr_size = blankNumber * 2 + str_size;

		if (newStr_size > length){

			return;

		}

		str[newStr_size] = '\0';  
		//这里并不能如此修改字符串数组中的值，但牛客网上通过了，还需进一步考虑分析。

		int p1 = str_size - 1;

		int p2 = newStr_size - 1;

		while (p1 >= 0 && p1 != p2){

			if (str[p1] == ' '){

				str[p2--] = '0';

				str[p2--] = '2';

				str[p2--] = '%';

			}

			else{

				str[p2--] = str[p1];

			}

			p1--;

		}

		for (int i = 0; i < newStr_size; i++){
			cout << str[i];
		}
		cout << endl;



	}

};

//====================测试代码==================
void Test(char* testName, char str[], int length, char expected[]){
	if (testName != nullptr){
		cout << testName << "   begins" << endl;
	}
	Solution st;
	st.replaceSpace(str,length);
	if (expected == nullptr && str == nullptr)
		cout << "passed" << endl;
	else if (expected == nullptr && str != nullptr)
		cout << "failed" << endl;
	else if (strcmp(str, expected) == 0)
		cout << "passed" << endl;
	else
		cout << "failed" << endl;


}

//空格在句子中间
void Test1(){
	const int length = 50;
	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

//空格在句子开头
void Test2(){
	const int length = 50;
	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}
//空格在句子结尾
void Test3(){
	const int length = 50;
	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}
//空格在句子中间、开头、结尾都有
void Test4(){
	const int length = 50;
	char str[length] = " hello  world ";
	Test("Test4", str, length, "%20hello%20%20world%20");
}

//无空格
void Test5(){
	const int length = 50;
	char str[length] = "helloworld";
	Test("Test5", str, length, "helloworld");
}
//str为nullptr
void Test6(){
	Test("Test6", nullptr, 0,nullptr);
}
//str内容为空
void Test7(){
	const int length = 50;
	char str[length] = "";
	Test("Test7", str, length,"");
}

//str内容为空格
void Test8(){
	const int length = 50;
	char str[length] = "  ";
	Test("Test8", str, length, "%20%20");
}

int main(){

	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();



	Solution_niuke st;
	int length = 30;
	char* str = (char*)malloc(sizeof(char) * length);
	str = "hello  world ";
	st.replaceSpace(str,length);
	for (int i = 0; str[i] != '\0'; i++){
	cout << str[i];
	}
	cout << endl;
	return 0;
}
