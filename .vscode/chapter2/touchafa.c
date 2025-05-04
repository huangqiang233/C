#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// 头插法创建链表
ListNode* create_linked_list_by_head_insertion() {
    ListNode* head = NULL;
    srand(time(NULL));  // 初始化随机数种子

    for (int i = 0; i < 5; i++) {
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node->val = rand() % 100;  // 生成 0 - 99 的随机数
        new_node->next = head;
        head = new_node;
    }
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
    ListNode* head = create_linked_list_by_head_insertion();
    print_linked_list(head);
    free_linked_list(head);
    return 0;
}
    