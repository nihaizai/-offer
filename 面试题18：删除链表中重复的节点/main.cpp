#include <iostream>

using namespace std;

//struct ListNode{
//	int value;
//	ListNode* pNext;
//};


//===============面试题18 删除链表的节点==============
//void DeleteNode(ListNode** pHead,ListNode* pDelete){
//	
//	//要删除的节点不是尾结点
//	if (pDelete->pNext != NULL){
//	ListNode* pTmp = pDelete->pNext;
//	pDelete->pNext = pTmp->pNext;
//	pDelete->value = pTmp->value;
//	delete pTmp;
//	pTmp = NULL;
//	cout << "condition 1" << endl;
//	}
//	//链表只有一个节点，删除头节点（也是尾节点）
//	else if (pDelete == *pHead){
//		delete pDelete;
//		pDelete = NULL;
//		*pHead = NULL;
//		cout << "condition 2" << endl;
//	}
//	//链表有多个节点，删除尾节点
//	else{
//		ListNode* pTmp = *pHead;
//		while (pTmp->pNext != pDelete){
//			pTmp = pTmp->pNext;
//		}
//		pTmp->pNext = NULL;
//		delete pDelete;
//		pDelete = NULL;
//		cout << "condition 3" << endl;
//	}
//}


//================删除链表中重复的节点==========================
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:

	//代码出现段错误
	ListNode* deleteDuplication(ListNode* pHead)
	{
		
		ListNode* pPre = NULL;
		ListNode* pNode = pHead;
		while (pNode != NULL){
			if (pNode->next == NULL){
				pNode = pNode->next;
				break;
			}
			if (pNode->next != NULL && pNode->val != pNode->next->val){
				pPre = pNode;
				pNode = pNode->next;
			}
			else{
				if (pNode->next != NULL)
				{
					int value = pNode->val;
					ListNode* pDelete = pNode;
					while (pDelete != NULL && pDelete->val == value){
						if (pHead == pDelete){
							pHead = pDelete->next;
							pPre = pDelete->next;
						}
						else{
							pPre->next = pDelete->next;
						}

						ListNode* pNext = pDelete->next;
						/*delete pDelete;
						pDelete = NULL;*/
						pDelete = pNext;

					}
					pNode = pPre->next;
				}
				
			}
			
		}
		return pHead;
	}

//正确答案
	ListNode* deleteDuplicationF2(ListNode** pHead){
		if (pHead == NULL || *pHead == NULL){
			return NULL;
		}
		ListNode* pPre = NULL;
		ListNode* pNode = *pHead;
		while (pNode != NULL){
			ListNode* pNext = pNode->next;
			bool needToDel = false;
			if (pNext != NULL && pNode->val == pNext->val)
				needToDel = true;

			if (!needToDel){
				pPre = pNode;
				pNode = pNode->next;
			}
			else{
				ListNode* pToBeDel = pNode;
				int value = pNode->val;
				while (pToBeDel != NULL && pToBeDel->val == value){
					pNext = pToBeDel->next;
					/*delete pToBeDel;
					pToBeDel = NULL;*/

					pToBeDel = pNext;
				}

				if (pPre == NULL){
					*pHead = pNext;
				}
				else{
					pPre->next = pNext;
				}
				pNode = pNext;
			}
		}
		return *pHead;
	}
};








int main(){
	Solution s;
	ListNode* node1 = new ListNode(2);
	ListNode node2(2);
	ListNode node3(2);
	ListNode node4(3);
	ListNode node5(4);
	node1->next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	/*ListNode* node5 = new ListNode(1);
	delete node5;*/

	/*ListNode* pNode = &node3;
	ListNode* pNode2 = &node4;
	pNode->next = NULL;
	pNode2->val = 0;
	pNode2->next = NULL;

	delete pNode2;
	pNode2 = NULL;*/
	

	ListNode* result = s.deleteDuplication(node1);
	cout << result->val << endl;
	cout << result->next->val << endl;
	if (result->next == NULL){
		cout << "Passed." << endl;
	}
	else{
		cout << "Failed." << endl;
	}










	//ListNode* pHead = new ListNode();
	//pHead->value = 1;
	//ListNode* pNode1 = new ListNode();
	//pNode1->value = 2;
	//ListNode* pNode2 = new ListNode();
	//pNode2->value = 3;
	//ListNode* pNode3 = new ListNode();
	//pNode3->value = 4;
	//
	//pHead->pNext = NULL;
	//DeleteNode(&pHead,pHead);
	//if (pHead == NULL){
	//	cout << "Passed." << endl;
	//}
	//else{
	//	cout << "Failed." << endl;
	//}
	///*pHead->pNext = pNode1;*/
	////pNode1->pNext = pNode2;
	////pNode2->pNext = pNode3;
	////pNode3->pNext = NULL;
	////DeleteNode(pHead,pNode2);
	////if (pNode2->value == 4 && pNode2->pNext == NULL){
	////	cout << "Passed." << endl;
	////}
	////else{
	////	cout << "Failed." << endl;
	////}
	return 0;
}
