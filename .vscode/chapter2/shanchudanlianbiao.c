#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// 创建新节点
ListNode* create_node(int val) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

// 删除指定元素
ListNode* delete_element(ListNode* head, int target) {
    // 创建虚拟头节点
    ListNode* dummy = create_node(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* current = head;

    while (current) {
        if (current->val == target) {
            // 找到目标节点，跳过该节点
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            // 未找到目标节点，移动 prev 和 current 指针
            prev = current;
            current = current->next;
        }
    }

    ListNode* new_head = dummy->next;
    free(dummy);
    return new_head;
}

// 打印链表
void print_linked_list(ListNode* head) {
    ListNode* current = head;
    while (current) {
        printf("%d", current->val);
        if (current->next) {
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
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // 创建示例链表 1 -> 2 -> 3 -> 2 -> 4
    ListNode* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(2);
    head->next->next->next->next = create_node(4);

    printf("原始链表:\n");
    print_linked_list(head);

    // 删除值为 2 的元素
    ListNode* new_head = delete_element(head, 2);

    printf("删除元素后的链表:\n");
    print_linked_list(new_head);

    // 释放链表内存
    free_linked_list(new_head);

    return 0;
}
    