/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        
        auto it = head;
        int size = 0;
        while(it!=NULL){
            size++;
            it = it->next;
        }
        int times = size/2;//要做的次數
        
        auto prev= head , cur = head->next;
        auto last = head;//紀錄結束後 換到前面的prev

        for(int i=0;i<times;i++){
            
            auto cur_next = cur->next;//紀錄cur的下一個node
            //cout << "i:" << i << " " << prev->val << " " << cur->val << endl;
            if(i==0){//第一次把head換成cur
                head = cur;
            }        
            prev->next = NULL;//原來的prev 的next先為null
            cur->next = prev;//cur要換到prev前面 所以cur的next = prev
            prev->next = cur_next;//prev要換到前面 所以prev的next = 原本next的next
            
            if(i!=0){//第一次換不用考慮last的問題
                last-> next= cur;
                last = prev;
            }
            
            if(prev->next!=NULL){//如果換完的prev(在前) 的next != NULL
                prev = prev->next; //prev = prev的next
                 if(prev->next!=NULL) //如果換完的prev(在前) 的next->next != NULL
                     cur = prev->next;//cur = prev->next->next
            }
        }
        return head;
    }
};
