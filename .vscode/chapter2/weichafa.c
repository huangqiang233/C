#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// 尾插法创建链表
ListNode* create_linked_list() {
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = NULL;
    ListNode* tail = dummy;

    for (int i = 1; i <= 5; i++) {
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node->val = i;
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }

    ListNode* head = dummy->next;
    free(dummy);
    return head;
}

// 打印链表
void print_linked_list(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// 释放链表内存
void free_linked_list(ListNode* head) {
    ListNode* current = head;
    ListNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    ListNode* head = create_linked_list();
    print_linked_list(head);
    free_linked_list(head);
    return 0;
}    