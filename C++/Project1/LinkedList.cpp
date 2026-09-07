#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct Node{
	int val;
	Node* next;
	Node* random;
	Node() : val(0), next(nullptr), random(nullptr) {}
	Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
	Node(int _val, Node* _next, Node* _random) : val(_val), next(_next), random(_random) {}
};


class LinkedList {
public:
	ListNode* reverseLinkedList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr != nullptr) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}
		return prev;
	}
	void printCommonPart(ListNode* headA, ListNode* headB) {
		ListNode* p1 = headA;
		ListNode* p2 = headB;
		while (p1 != nullptr && p2 != nullptr) {
			if(p1->val > p2->val)
				p2 = p2->next;
			else if(p1->val < p2->val)
				p1 = p1->next;
			else {
				cout << p1->val << " ";
				p1 = p1->next;
				p2 = p2->next;
			}
		}
	}
	bool isPalindrome(ListNode* head) {
		stack<int> st;
		ListNode* p = head;
		while (p) {
			st.push(p->val);
			p->next;
		}
		p = head;
		while (p) {
			if (p->val != st.top()) {
				return false;
			}
			st.pop();
			p->next;
		}
		return true;
	}
	bool isPallindromev2(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode* p1 = head;
		ListNode* p2 = reverseLinkedList(slow);

		while (p2) {
			if(p1->val != p2->val) {
				return false;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		return true;
	}
	ListNode* LinkDutchFlagProblem(ListNode* head,int pivot) {
		if(!head || !head->next) {
			return head;
		}
		
		ListNode* SH = nullptr;
		ListNode* ST = nullptr;
		ListNode* EH = nullptr;
		ListNode* ET = nullptr;
		ListNode* BH = nullptr;
		ListNode* BT = nullptr;

		ListNode* next = nullptr;

		while (head) {
			next = head->next;
			head->next = nullptr;

			if (head->val < pivot) {
				if(!SH) {
					SH = head;
					ST = head;
				} else {
					ST->next = head;
					ST = head;
				}
			}
			else if (head->val > pivot)
			{
				if (!BH) {
					BH = head;
					BT = head;
				}
				else {
					BT->next = head;
					BT = head;
				}
			}
			else {
				if (!EH) {
					EH = head;
					ET = head;
				}
				else {
					ET->next = head;
					ET = head;
				}
			}
			head = next;
		}
		if (ST) {
			ST->next = EH;
			ET = ET ? ET : ST;
		}
		ListNode* newHead = SH ? SH : (EH ? EH : BH);
		if(ET) {
			ET->next = BH;
		}
		return newHead;
	}
	Node* copyRandomListV1(Node* head) { 
		std::unordered_map<Node*, Node*> map;
		Node* cur = head;

		while (cur != nullptr) {
			Node* nodecopy = new Node(cur->val);
			map[cur] = nodecopy;
			cur = cur->next;
		}
		cur = head;
		while (cur != nullptr) {
			Node* curcopy = map[cur];

			if(cur -> next != nullptr) {
				curcopy->next = map[cur->next];
			}
			else {
				curcopy->next = nullptr;
			}

			if(cur ->random != nullptr) {
				curcopy->random = map[cur->random];
			}
			else {
				curcopy->random = nullptr;
			}
		}
		return map[head];
	}
	Node* copyRandomListV2(Node* head) {
		if(head == nullptr) {
			return nullptr;
		}

		Node* cur = head;

		while (cur) {
			Node* copyNode = new Node(cur->val);
			Node* tempNext = cur->next;

			cur->next = copyNode;
			copyNode->next = tempNext;
			
			cur = tempNext;
		}

		cur = head;

		while (cur) {
			if (cur->random) {
				cur->next->random = cur->random->next;
			} else {
				cur->next->random = nullptr;
			}
			cur = cur->next->next;
		}

		Node* newHead = head->next;
		cur = head;
		while (cur) {
			Node* copyNode = cur->next;
			Node* OriginalNext = copyNode->next;

			cur->next = OriginalNext;
			if(OriginalNext) {
				copyNode->next = OriginalNext->next;
			} else {
				copyNode->next = nullptr;
			}
			cur = OriginalNext;
		}
		return newHead;
	}
	ListNode* getIntersectionNodeV1(ListNode* headA, ListNode* headB) {
		std::unordered_set<ListNode*> visit;

		ListNode* temp = headA;

		while(temp != nullptr) {
			visit.insert(temp);
			temp = temp->next;
		}

		temp = headB;

		while (temp) {
			if(visit.find(temp) != visit.end()) {
				return temp;
			}
			temp = temp->next;
		}
		return nullptr;
	}
	ListNode* getIntersectionNodeV2(ListNode* headA, ListNode* headB) {
		//判断有无环
		ListNode* meetA = detectCycle(headA);
		ListNode* meetB = detectCycle(headB);

		//同时无环判断
		if (!meetA && !meetB) {
			return getIntersectionNoCycle(headA, headB);
		}
		//一个有环一个无环，不相交
		else if ((meetA && !meetB) || (!meetA && meetB)) {
			return nullptr;
		}
		//两个都有环,两种情况1.在环外相交，2.在环内相交

		ListNode* entryA = findCycleEntry(headA, meetA);
		ListNode* entryB = findCycleEntry(headB, meetB);

		//入环点相同，说明在环外相交
		if (entryA == entryB) {
			ListNode* temp = entryA -> next;
			entryA->next = nullptr;
			ListNode* res = getIntersectionNoCycle(headA, headB);
			entryA->next = temp;
			return res;
		}
		ListNode* cur = entryA->next;
		while(cur != entryA) {
			if(cur == entryB) {
				return entryA;
			}
			cur = cur->next;
		}
		return nullptr;
	}
	ListNode* detectCycle(ListNode* head) {
		if(!head || !head->next) {
			return nullptr;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return slow;
			}
		}
		return nullptr;
	}
	ListNode* getIntersectionNoCycle(ListNode* headA, ListNode* headB) {
		int lenA = 0;
		int lenB = 0;
		ListNode* tempA = headA;
		ListNode* tempB = headB;
		while (tempA) { lenA++; tempA = tempA->next; }
		while (tempB) { lenB++; tempB = tempB->next; }

		tempA = headA;
		tempB = headB;
		int diff = abs(lenA - lenB);
		if(lenA > lenB) {
			while (diff--) {
				tempA = tempA->next;
			}
		} else {
			while (diff--) {
				tempB = tempB->next;
			}
		}
		while (tempA && tempB) {
			if (tempA == tempB) {
				return tempA;
			}
			tempA = tempA->next;
			tempB = tempB->next;
		}
		return nullptr;
	}
	ListNode* findCycleEntry(ListNode* head, ListNode* meetNode) {
		ListNode* ptr = head;
		while(ptr != meetNode) {
			ptr = ptr->next;
			meetNode = meetNode->next;
		}
		return ptr;
	}
};