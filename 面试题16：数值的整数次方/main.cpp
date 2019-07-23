#include <iostream>

using namespace std;

bool g_InvalidInput = false;
double powerCoreF1(double base, int exponent);
double powerCoreF2(double base, int exponent);
double myPower(double base, int exponent){

	//base 为0，exponent >0,结果输出为0；
	if (abs(base-0.0)<0.0000001 && exponent >0){
		g_InvalidInput = false;
		return 0.0;
	}
	//0的0次方和负数次方，结果无意义,将g_InvalidInput赋值为true.
	if (abs(base - 0.0)<0.0000001 && exponent <=0){
		g_InvalidInput = true;
		return 0.0;
	}
	if (exponent == 0){
		g_InvalidInput = false;
		return 1.0;
	}

	int tmpEx = exponent;
	if (exponent<0){
		exponent = -exponent;
	}
	double result = powerCoreF2(base, exponent);

	if (tmpEx < 0){
		g_InvalidInput = false;
		return 1.0 / result;
	}

	return result;
}

double powerCoreF1(double base,int exponent){
	double result=1.00000000;
	while (exponent){
		result *= base;
		exponent--;
	}
	return result;
}


double powerCoreF2(double base,int exponent){
	if (exponent == 0) return 1.000000;
	if (exponent == 1) return base;
	//double result = 1.0000000;
	//if (exponent % 2 == 0){
	double	result =  powerCoreF2(base,exponent>>1);
	//}
	//else{
	//	result = powerCoreF2(base,(exponent-1)/2);
	//}
	result *= result;
	if (exponent & 0x1 == 1){
		result *= base;
	}
	return result;
}



void Test(string testNum,double base,int exponent,double expected){
	//cout <<testNum.c_str() << "   ";
	printf("%s  \n",testNum.c_str());
	double result = myPower(base, exponent);
	printf("%.3f ",result);
	/*cout << g_InvalidInput << endl;
	cout << invalid << endl;*/
	if ( !g_InvalidInput && abs(result - expected) <= 1e-15 ){
		//cout << "Passed." << endl;
		printf("Passed. \n");
	}
	else if (!g_InvalidInput && abs(result - expected) <= 1e-15){
		//cout << "Failed." << endl;
		printf("Failed. \n");
	}
	else if (g_InvalidInput){
		printf("true. \n");
	}
}


int main(){
	Test("test1",2,3,8.000);
	Test("test2", 2, -3, 0.125);
	Test("test3", -2, 3, -8.000);
	Test("test4", -2, -3, -0.125);
	Test("test5", 2, 0, 1.000);
	Test("test6", 2, 1, 2.000);
	Test("test7", 125, 1, 125.000);
	Test("test8", 0, -4, 0.000);  //true
	Test("test9", 1, 0, 1.000);
	Test("test10", 0, 0, 0.000); //true
	/*double result = powerCoreF2(2,5);
	cout << result << endl;*/
	return 0;
}
