#include <iostream>

using namespace std;


class Solution {
public:
	bool isNumeric(const char* string)
	{
		if (string == NULL){
			return false;
		}
		bool num = scanInt(&string);
		if (*string == '.'){
			string++;
			num = scanUnsignedInt(&string) || num;
		}
		if (*string == 'e' || *string == 'E'){
			string++;
			num = num && scanInt(&string);
		}

		return num && *string == '\0';

	}
	bool scanUnsignedInt(const char** ptr){
		const char* before = *ptr;
		while (**ptr != '\0' && **ptr >= '0' && **ptr <= '9'){
			(*ptr)++;
		}
		return *ptr > before;
	}
	bool scanInt(const char** ptr){
		if (**ptr == '+' || **ptr == '-'){
			(*ptr)++;
		}
		return scanUnsignedInt(ptr);
	}

};


void Test(char* testNum, const char* str, bool expected){
	cout << testNum << "   ";
	Solution s;
	if (expected == s.isNumeric(str)){
		cout << "passed." << endl;
	}
	else{
		cout << "failed." << endl;
	}
}


int main(){
	/*Test("test1","100", true);
	Test("test2", ".100", true);
	Test("test3", "100.", true);
	Test("test4", "100.34", true);
	Test("test5", "100.E12", true);
	Test("test6", "100.E+12", true);
	Test("test7", "100.E-12", true);
	Test("test8", "100.23E12", true);
	Test("test9", "100.23E+12", true);
	Test("test10", "100.23E-12", true);
	Test("test11", "+1.E23", true);
	Test("test12", "-1.E23", true);


	Test("test13", "ab.", false);
	Test("test14", "100.+12", false);
	Test("test15", "E23", false);
	Test("test16", "100E12.32", false);*/
	Test("test17", "", false);

	return 0;
}

