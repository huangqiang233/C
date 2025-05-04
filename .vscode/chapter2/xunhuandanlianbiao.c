#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// 尾插法创建循环单链表
ListNode* create_circular_linked_list() {
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

    // 将尾节点的 next 指针指向头节点，形成循环
    if (tail != NULL) {
        tail->next = head;
    }

    return head;
}

// 打印循环单链表
void print_circular_linked_list(ListNode* head) {
    if (head == NULL) return;

    ListNode* current = head;
    do {
        printf("%d", current->val);
        if (current->next != head) {
            printf(" -> ");
        }
        current = current->next;
    } while (current != head);
    printf("\n");
}

// 释放循环单链表内存
void free_circular_linked_list(ListNode* head) {
    if (head == NULL) return;

    ListNode* current = head->next;
    while (current != head) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    ListNode* head = create_circular_linked_list();
    print_circular_linked_list(head);
    free_circular_linked_list(head);
    return 0;
}

