#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

	bool existNode(char* matrix, int rows, int cols, char* str, int pathIndex, int index, vector<char>& visit){
		
		//结束条件
		if (str[pathIndex] == '\0'){
			return true;
		}
	
		int rIndex = index / cols;
		int cIndex = index % cols;
		if (rIndex >= 0 && rIndex < rows && cIndex >=0 && cIndex < cols && visit[index] == 'F'&& matrix[rIndex*cols + cIndex] == str[pathIndex]){
			pathIndex++;
			visit[index] = 'T';

			bool leftPath = false;
			bool rightPath = false;
			bool topPath = false;
			bool buttonPath = false;
			//左右上下节点的判断条件，记住右侧小于等于这个条件，因为其可能存在只有一个字符的字符串
			//(cIndex - 1 >= 0) && (cIndex + 1 <= cols) && (rIndex - 1 >= 0) && (rIndex + 1 <rows) &&
			if (existNode(matrix, rows, cols, str, pathIndex, rIndex*cols + cIndex - 1, visit)) leftPath = true;
			if ( existNode(matrix, rows, cols, str, pathIndex, rIndex*cols + cIndex + 1, visit)) rightPath = true;
			if ( existNode(matrix, rows, cols, str, pathIndex, (rIndex - 1)*cols + cIndex, visit)) topPath = true;
			if (existNode(matrix, rows, cols, str, pathIndex, (rIndex + 1)*cols + cIndex, visit)) buttonPath = true;
			bool endPath = leftPath || rightPath || topPath || buttonPath;

			if (!endPath){
				--pathIndex;
				visit[index] = 'F';
			}
			else{
				return true;
			}
		}
		return false;
	}

	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		vector<int> firstIndex;
		for (int i = 0; i<rows; i++){
			for (int j = 0; j<cols; j++){
				if (matrix[i*cols + j] == str[0]){
					firstIndex.push_back(i*cols + j);
				}
			}
		}

		for (unsigned int i = 0; i<firstIndex.size(); i++){
			vector<char> visit;
			int pathIndex = 0;

			for (int i = 0; i<rows; i++){
				for (int j = 0; j<cols; j++){
					visit.push_back('F');
				}
			}
			if (existNode(matrix, rows, cols, str, pathIndex, firstIndex[i], visit)){
				return true;
			}
		}
		return false;


	}




};

void Test(char* testNum,char* matrix,int rows,int cols,char* str,int expected){
	Solution s;
	cout << testNum << "   ";
	if (s.hasPath(matrix,rows,cols,str) == expected){
		cout << "Passed." << endl;
	}
	else{
		cout << "Failed." << endl;
	}

}

//存在路径
void Test1(){
	char* matrix = "ABTGCFCSJDEH";
	char* str = "ABFDE";
	Test("test1",matrix,3,4,str,1);
}

//不存在路径
void Test2(){
	char* matrix = "ABTGCFCSJDEH";
	char* str = "ABDE";
	Test("test2", matrix, 3, 4, str, 0);
}

//只有一行，存在路径
void Test3(){
	char* matrix = "ABTGCFCSJDEH";
	char* str = "GCFCS";
	Test("test3", matrix, 1, 12, str, 1);
}

//只有一行，不存在路径
void Test4(){
	char* matrix = "ABTGCFCSJDEH";
	char* str = "GCFS";
	Test("test4", matrix, 1, 12, str, 0);
}

//只有一列，存在路径
void Test5(){
	char* matrix = "ABTGCFCSJDEH";
	char* str = "GCFCS";
	Test("test5", matrix, 12, 1, str, 1);
}

//只有一列，不存在路径
void Test6(){
	char* matrix = "ABTGCFCSJDEH";
	char* str = "GCFS";
	Test("test6", matrix, 12, 1, str, 0);
}

//只有一个数字
void Test7(){
	char* matrix = "A";
	char* str1 = "A";
	char* str2 = "B";
	Test("test7", matrix, 1, 1, str1, 1);
	//Test("test8", matrix, 1, 1, str2, 0);
}












int main(){
	/*Solution s;
	char* matrix = "A";
	bool result = s.hasPath(matrix,1,1,"A");
	cout << result << endl;*/
	/*Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();*/
	Test7();
	return 0;
}
