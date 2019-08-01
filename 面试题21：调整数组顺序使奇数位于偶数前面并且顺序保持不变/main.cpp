#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	//时间复杂度O（n) 空间复杂度O(n);
	void reOrderArrayF1(vector<int> &array) {
		vector<int> odd;
		vector<int> even;
		for (int i = 0; i<(int)array.size(); i++){
			if (array[i] & 1 != 0){
				odd.push_back(array[i]);
			}
			else{
				even.push_back(array[i]);
			}
		}
		int i = 0;
		while (i < (int)odd.size()){
			array[i] = odd[i];
			i++;
		}
		while (i < (int)array.size()){
			array[i] = even[i - (int)odd.size()];
			i++;
		}

	}

	//时间复杂度 O(n) 空间复杂度O(1)
	void reOrderArrayF2(vector<int> &array){

		//======= 若无这个可能出现段错误====
		if (array.size() <= 0){
			return;
		}
     //==============


		int begin = 0;
		while (array[begin] & 1 != 0){
			begin++;
		}
		int end = begin + 1;
		//int end = 0;

		while ( end <array.size()){
			if (array[end]  % 2 == 0){
				end++;
			}
			else{
				int tmp = array[end];
				for (int i = end; i>begin; i--){
					array[i] = array[i - 1];
				}
				array[begin] = tmp;

				begin++;
				end++;
			}
		}
	}

//时间复杂度O（n^2) 空间复杂度 O(1)
	void reOrderArrayF3(vector<int> &array){
		for (int i = 0; i < array.size(); i++){
			for (int j = 0; j < array.size() - 1; j++){
				if (array[j] % 2 == 0 && array[j + 1] % 2 != 0){
					int tmp = array[j + 1];
					array[j + 1] = array[j];
					array[j] = tmp;
				}
			}
		}
	}
};

int main(){
	Solution s;
	vector<int> test = {2}; 
	s.reOrderArrayF3(test);
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << "   ";
	}
	cout << endl;

	//vector<int> tmp = {1,2,3,4,5};
	//int end = 1;
	//while (tmp[end] % 2 == 0){
	//	end++;
	//}
	//cout <<end << endl;
	return 0;
}
