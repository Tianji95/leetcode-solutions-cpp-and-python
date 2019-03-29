class Solution
{
public:
	Node* recur(Node* now)
	{
		Node* prev = nullptr;
		Node* tmp = nullptr;
		Node* next = nullptr;
		while (now)
		{
			if (now->child)
			{
				tmp = recur(now->child);

				next = now->next;

				now->next = now->child;
				now->child->prev = now;
				now->child = nullptr;

				tmp->next = next;
				if(next)
				    next->prev = tmp;

				prev = tmp;
				now = next;

			}
			else
			{
				prev = now;
				now = now->next;
			}

		}
		return prev;
	}
	Node* flatten(Node* head)
	{
		

		Node* now = head;
		Node* tmp;

		recur(now);
		return head;

	}
};
