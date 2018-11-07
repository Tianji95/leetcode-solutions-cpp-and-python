
虽然都是一次遍历，但是别人有更快的方法：
**哦不好意思，后来看起来可能只是评判系统不够稳定**


    /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */



    // 注意，这是有序的链表
    // 基本思路，把l2的值都加到l1上，最后返回l1 
    // 注意，head 可能会变，因为ls2可能会插在ls1最前面，所以要更新 l1
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if(!l1)
                return l2;
            if(!l2)
                return l1;
            
            ListNode* ls1 =l1;
            ListNode* ls2 = l2;
            ListNode* prev = ls1;
            ListNode* head = l1;
            
            // 有1个到了尾部就可以退出循环
            
            int i =0;
            while(ls1 && ls2)
            {

                if(ls1->val<=ls2->val) 
                {
                    prev =ls1;
                    ls1= ls1->next;              
                }
                else  // ls2 > ls1, 把ls2连接到 ls1之前的位置，然后ls1不往下移动，ls2指向原来的ls2->next
                {
                    ListNode* tmp1 = ls1->next;
                    ListNode* tmp2 = ls2->next;
                    if(ls1 ==head)//说明ls1第一个值就比ls2大。这不能用prev,因为prev=头部有可能是，第一个ls1小，ls1移到
                    {            // 第二个位置，prev 当时指在第一个位置
                        ls2->next = ls1;
                        if(ls2 == l2) // 这个时候ls2的第一个值，小于ls1的第一个值，所以ls2的第一个值肯定是头
                        {
                        head=ls2;
                        }
                        prev = ls2;
                        
                    //  cout<<ls1->val<<";"<<ls2->val<<";"<<prev->val<<"\n";
                    }   
                    else
                    {
                        prev->next = ls2;
                        ls2->next =ls1;
                        prev = prev->next;  // 注意，prev 也要往下移动
                        
                    }
                    ls2 = tmp2;     
                }
            }
            
            if(ls2) // 如果ls2还有剩余的，这时候ls1应该到了null, 就把ls2 连在ls1最后
            {
                prev->next = ls2;
            }
            return  head;
        }
            
    };