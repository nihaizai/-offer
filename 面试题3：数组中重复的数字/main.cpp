#include <iostream>
#include <vector>
#include <hash_map>

using namespace std;


int duplication(vector<int>& numbers){
	cout << numbers.size() << endl;
	if (numbers.size() != 0){
		for (int i = 0; i < numbers.size(); i++){
			while (numbers[i] != i){
				if (numbers[i] != numbers[numbers[i]]){
					int temp = numbers[numbers[i]];
					numbers[numbers[i]] = numbers[i];
					numbers[i] = temp;
				}
				else{
					return numbers[i];
				}
			}
		}
	}
	return -1;
}

//使用方案1哈希思想解决
class Solution_hash {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == nullptr || length <= 0){
			return false;
		}
		for (int i = 0; i<length; i++){
			if (numbers[i] <0 || numbers[i] >= length){
				return false;
			}
		}
		vector<bool> flag;
		for (int i = 0; i < length; i++){
			flag.push_back(false);
		}
		for (int i = 0; i < length; i++){
			if (flag[numbers[i]] == true){  //表示含有该元素
				*duplication = numbers[i];
				return true;
			}
			//如果没有该元素
			flag[numbers[i]] = true;
		}
		return false;
		
	}
};



//使用方案2解决
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == nullptr || length <= 0){
			return false;
		}
		for (int i = 0; i<length; i++){
			if (numbers[i] <0 || numbers[i] >= length){
				return false;
			}
		}
		for (int i = 0; i<length; i++){
			while (numbers[i] != i){
				if (numbers[i] != numbers[numbers[i]]){
					int temp = numbers[numbers[i]];
					numbers[numbers[i]] = numbers[i];
					numbers[i] = temp;

				}
				else{
					*duplication = numbers[i];
					return true;
				}
			}
		}
		return false;
	}
};






int main(){
	////测试duplication
	//vector<int> numbers = {2,3,1,0,2,5,3};
	//for (int i = 0; i < numbers.size(); i++){
	//	cout << numbers[i];
	//}
	//cout << endl;
	//int result = duplication(numbers);
	//cout << result << endl;
	//for (int i = 0; i < numbers.size(); i++){
	//	cout << numbers[i];
	//}
	//cout << endl;

	//测试方案1
	/*int numbers[10] = { 2, 3, 1, 0, 2, 5, 3 };
	int length = 7;
	int result;
	Solution_hash sh;
	bool sh_dt = sh.duplicate(numbers,length,&result);
	if (sh_dt){
		cout << result << endl;
	}*/


	////测试方案2
	//int numbers[10] = {1,2,3,0};
	//int numbers[10]={1,2,3,4,4,0,2,5};
	int numbers[] = { 2,3,5,4,3,2,6,7 };
	int length = 8;
	int result = 0;
	Solution st;
	for (int i = 0; i < length; i++){
		cout << numbers[i];
	}
	cout << endl;
	bool dt = st.duplicate(numbers,length,&result);
	for (int i = 0; i < length; i++){
		cout << numbers[i];
	}
	cout << endl;
	if (dt){
		cout << result << endl;
	}

	



	return 0;
}
