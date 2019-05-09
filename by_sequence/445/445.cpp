class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		string outstr("");
		vector<int> list1;
		vector<int> list2;
		ListNode* now1 = l1;
		ListNode* now2 = l2;

		while (now1) {
			list1.push_back(now1->val);
			now1 = now1->next;
		}
		while (now2) {
			list2.push_back(now2->val);
			now2 = now2->next;
		}

		int i = list1.size() - 1;
		int j = list2.size() - 1;
		int isextra = 0;
		int now = 0;
		for (; i >= 0 && j >= 0; i--, j--) {
			now = list1[i] + list2[j] + isextra;
            isextra = 0;
			if (now >= 10) {
				isextra = 1;
				now = now % 10;
			}
			outstr.push_back('0' + now);
		}
		while (i >= 0) {
			now = list1[i] + isextra;
            isextra = 0;
			if (now >= 10) {
				isextra = 1;
				now = now % 10;
			}
			outstr.push_back('0' + now);
			i--;
		}

		while (j >= 0) {
			now = list2[j] + isextra;
            isextra = 0;
			if (now >= 10) {
				isextra = 1;
				now = now % 10;
			}
			outstr.push_back('0' + now);
			j--;
		}
        if(isextra){
            outstr.push_back('1');
        }

		ListNode* prev = nullptr;
		for (int i = 0; i < outstr.size(); i++) {
			ListNode* newNode = new ListNode(outstr[i] - '0');
			newNode->next = prev;
			prev = newNode;
		}
		return prev;



	}
};