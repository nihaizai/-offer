#include <iostream>
#include <vector>
using namespace std;

//f(n) = 0,n=0
//       1,n=1
//	   f(n - 1) + f(n-2),n>1

//递归
int Fibonacci(unsigned int n){
	if (n == 0) return 0;
	if (n == 1) return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}


int tmpVal[50];
//自上到下计算，保存中间结果值
int FibonacciTwo(unsigned int n){
	if (n == 0) { tmpVal[0] = 0; return 0; }
	if (n == 1) { tmpVal[1] = 1; return 1; }
	if (tmpVal[n] != 0){
		return tmpVal[n];
	}
	else{
		tmpVal[n] = FibonacciTwo(n - 1) + FibonacciTwo(n - 2);
		return tmpVal[n];
	}

}


//自下到上计算
int FibonacciThree(unsigned int n){
	if (n == 0) return 0;
	if (n == 1) return 1;
	else{
		int f1 = 0;
		int f2 = 1;
		int fs = -1;
		for (int i = 2; i <= n; i++){
			fs = f1 + f2;
			f1 = f2;
			f2 = fs;
		}
		return fs;
	}
}


void Test(int n,int expected){
	
	if (Fibonacci(n) == expected){
		cout << "Test for  "<< n <<"in Fibonacci passed." << endl;
	}
	else{
		cout << "Test for  " << n << "in Fibonacci Failed." << endl;
	}

	if (FibonacciTwo(n) == expected){
		cout << "Test for  " << n << "in FibonacciTwo passed." << endl;
	}
	else{
		cout << "Test for  " << n << "in FibonacciTwo Failed." << endl;
	}

	if (FibonacciThree(n) == expected){
		cout << "Test for  " << n << "in FibonacciThree passed." << endl;
	}
	else{
		cout << "Test for  " << n << "in FibonacciThree Failed." << endl;
	}



}



int main(){
	Test(0,0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);

	Test(40, 102334155);



	return 0;
}
