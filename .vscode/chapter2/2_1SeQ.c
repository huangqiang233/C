#include <stdio.h>
#include <stdlib.h>

#define Max 100
typedef int Datatype;

typedef struct {
    Datatype data[Max];
    int length;
} SQList;

// 初始化线性表
void initList(SQList *list) {
    list->length = 0;
}

// 插入
int insertElement(SQList *list, int pos, Datatype value) {
    if (list->length >= Max) {
        printf("线性表已满，无法插入！\n");
        return 0;
    }
    if (pos < 1 || pos > list->length + 1) {
        printf("插入位置不合法！\n");
        return 0;
    }
    for (int i = list->length; i >= pos; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[pos - 1] = value;
    list->length++;
    return 1;
}

// 删除元素
int deleteElement(SQList *list, int pos) {
    if (list->length == 0) {
        printf("线性表为空，无法删除！\n");
        return 0;
    }
    if (pos < 1 || pos > list->length) {
        printf("删除位置不合法！\n");
        return 0;
    }
    for (int i = pos - 1; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return 1;
}

// 查找元素
int findElement(SQList *list, Datatype value) {
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == value) {
            return i + 1;
        }
    }
    return 0;
}

// 显示线性表
void displayList(SQList *list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    SQList list;
    initList(&list);

    // 插入元素
    insertElement(&list, 1, 10);
    insertElement(&list, 2, 20);
    insertElement(&list, 3, 30);

    // 显示线性表
    printf("插入元素后的线性表: ");
    displayList(&list);

    // 删除元素
    deleteElement(&list, 2);
    printf("删除元素后的线性表: ");
    displayList(&list);

    // 查找元素
    int pos = findElement(&list, 30);
    if (pos) {
        printf("元素 30 的位置是: %d\n", pos);
    } else {
        printf("未找到元素 30!\n");
    }

    return 0;
}    