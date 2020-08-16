思想和没有反转的高精度加法一模一样，只是要处理末尾0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode,*head,*tail;
        head=l3;
        while(l1&&l2){
            l3->val+=l1->val+l2->val;
            tail=new ListNode(0);
            if(l3->val>=10){
                tail->val+=1;
                l3->val-=10;
            }
            l3->next=tail;
            l3=tail;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            l3->val+=l1->val;
            tail=new ListNode(0);
            if(l3->val>=10){
                tail->val+=1;
                l3->val-=10;
            }
            l3->next=tail;
            l3=tail;
            l1=l1->next;
        }
        l1=l2;
        while(l1){
            l3->val+=l1->val;
            tail=new ListNode(0);
            if(l3->val>=10){
                tail->val+=1;
                l3->val-=10;
            }
            l3->next=tail;
            l3=tail;
            l1=l1->next;
        }
        
        ListNode *pre=head,*p=head->next; //处理末尾的0，有点麻烦。。。
        while(p){
            if(p->next==NULL){
                if(p->val==0){
                    pre->next=NULL;
                }
                break;
            }
            pre=p;
            p=p->next;

        }
        return head;
    }
};
