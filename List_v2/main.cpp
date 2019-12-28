#include <iostream>

//链表逆序1
//方法：依次遍历链表节点，每遍历一个节点就逆置一个节点
//方案：1备份head->next, 2修改head->next,3移动head和new_head
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode * new_head = NULL;
    while(head) {
        ListNode *next=head->next;//备份head->next
        head->next=new_head;//更新head->next
        new_head=head;//移动new_head
        head=next;
    }
    return new_head;
}

//链表逆序2：反转从位置 m 到 n 的链表。
ListNode* reverseBetween(ListNode* head, int m, int n) {
    int change_len = n-m+1;//计算逆序节点个数
    ListNode *pre_head=NULL;//逆置节点前驱
    ListNode *result=head;//最终转换后的链表头节点，一般为head
    while (head && --m){//head向前移动m-1个位置
        pre_head=head;//记录head前驱
        head=head->next;
    }
    ListNode *modify_list_tail = head;//modify_list_tail指向当前head，即逆置后的链表尾

    ListNode *new_head=NULL;
    while (head && change_len) {
        ListNode *next=head->next;//备份head->next
        head->next=new_head;//更新head->next
        new_head=head;//移动new_head
        head=next;
        change_len--;
    }

    modify_list_tail->next=head;//连接逆置后的链表尾和逆置段的后一个节点
    if(pre_head){//如果pre_head不空，说明不是从第一个节点开始逆置，m>1
        pre_head->next=new_head;//将逆置链表开始的节点前驱与逆置后的头节点连接
    }
    else{
        result=new_head;//pr_head为空，则记录头节点
    }
    return result;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}