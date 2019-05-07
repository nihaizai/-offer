#include <iostream>

using namespace std;


class CMyString{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator = (const CMyString& str);

	void Print();



private:
	char* m_pData;

};

CMyString::CMyString(char *pData){
	if (pData == nullptr){
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData,pData);
	}
}

CMyString::CMyString(const CMyString & str){
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData,str.m_pData);
}

CMyString::~CMyString(){
	delete[] m_pData;
}



//===============方案1======================
//考查注意点：
//1.将返回值的类型声明为该函数的引用，并在函数结束前返回实例自身的引用即*this
//  只有返回一个引用，才可以允许连续赋值。
//2.将传入的参数的类型声明为常量引用，并且因为在赋值运算符函数内部不会改变传入的实例
//  的状态，因此应加上const关键字。
//3.在分配新内存之前要释放自身已有的空间，防止内存泄漏。
//4.判断传入的参数和当前的实例是否是同一个实例。
CMyString& CMyString::operator = (const CMyString& str){
	if (this == &str){
		return *this;
	}
	delete[]m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData,str.m_pData);

	return *this;

}

//========================方案2===============================
//方案1中在分配内存之前先delete释放了实例m_pData的内存，
//如果此时内存不足导致new char抛出异常,则m_pData将是一个空指针，
//这样非常容易导致程序崩溃。
//考虑到上述情况，因此设计方案2，创建一个临时实例，再交换临时实例和原来的实例。
//临时实例strTemp是一个局部变量，程序运行到if外面时就会自动调用strTemp的析构函数，
//strTemp.m_pData指向的内存也就是实例之前m_pData的内存就会被释放掉。

//CMyString& CMyString::operator =(const CMyString& str){
//	if (this != &str){
//		CMyString strTemp(str);
//
//		char* pTemp = strTemp.m_pData;
//		strTemp.m_pData = m_pData;
//		m_pData = pTemp;
//
//	}
//	return *this;
//}


//=============测试代码====================
void CMyString::Print(){
	cout << m_pData << endl;
}

//赋值给另一个实例
void Test1(){
	cout << "Test1:" << endl;
	char* text = "Hello World";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	cout << "The expected result is: " << text << endl;

	cout << "The actual result is: ";
	str2.Print();
	cout<< endl;
}

//连续赋值
void Test2(){
	cout << "Test2:" << endl;
	char* text = "this is test2";
	CMyString str1(text);
	CMyString str2, str3;
	str2 = str3 = str1;
	cout << "The expected result is: " << text << endl;
	cout << "The actual result is :";
	cout << "str2:  ";
	str2.Print();
	cout << endl;
	cout << "str3:  ";
	str3.Print();
	cout << endl;


}
//赋值给自己
void Test3(){
	cout << "Test3:" << endl;
	char* text = "this is test2";
	CMyString str1(text);
	str1 = str1;
	cout << "The expected result is: " << text << endl;

	cout << "The actual result is: ";
	str1.Print();
	cout << endl;
}

int main(){

	Test1();
	Test2();
	Test3();
	return 0;
}
