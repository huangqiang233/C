#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode, *LinkList;

// 创建循环单链表
LinkList createCyclicLink(LinkList head) {
    int x;
    LinkList tail, p;
    // 建立头结点
    head = (ListNode *)malloc(sizeof(ListNode));
    if (!head) {
        printf("内存分配失败！\n");
        exit(1);
    }
    head->next = NULL;
    // 输入第一个结点数据
    printf("请输入第一个结点的值（输入 0 结束）：");
    scanf("%d", &x);
    // 建立尾结点
    tail = (ListNode *)malloc(sizeof(ListNode));
    if (!tail) {
        printf("内存分配失败！\n");
        exit(1);
    }
    tail->data = x;        // 第一个结点赋值
    tail->next = tail;     // 尾结点指向自己，形成循环
    head->next = tail;     // 头指针指向第一个结点
    // 输入后续结点数据
    printf("请输入后续结点的值（输入 0 结束）：");
    scanf("%d", &x);
    while (x != 0) {
        // 建立新结点
        p = (ListNode *)malloc(sizeof(ListNode));
        if (!p) {
            printf("内存分配失败！\n");
            exit(1);
        }
        p->data = x;
        p->next = tail->next; // 新结点指向第一个结点
        tail->next = p;       // 尾结点指向新结点
        tail = p;             // 尾指针指向新结点
        // 输入下一个结点数据
        scanf("%d", &x);
    }
    return head;
}

// 打印循环单链表
void printCyclicLink(LinkList head) {
    if (head == NULL || head->next == NULL) {
        printf("链表为空！\n");
        return;
    }

    LinkList current = head->next; // 从第一个结点开始
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head->next); // 遍历到第一个结点时停止
    printf("(循环)\n");
}

// 释放循环单链表
void freeCyclicLink(LinkList head) {
    if (head == NULL || head->next == NULL) return;

    LinkList current = head->next;
    LinkList temp;
    while (current != head) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    LinkList head = NULL;

    // 创建循环单链表
    head = createCyclicLink(head);

    // 打印循环单链表
    printf("循环单链表内容：\n");
    printCyclicLink(head);

    // 释放循环单链表
    freeCyclicLink(head);

    return 0;
}