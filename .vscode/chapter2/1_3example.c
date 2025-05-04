#include <stdio.h>

// 递归算法计算斐波那契数列第n项
int fibonacci_recursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

// 迭代算法计算斐波那契数列第n项
int fibonacci_iterative(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int main() {
    int n = 5;
    int result_recursive = fibonacci_recursive(n);
    int result_iterative = fibonacci_iterative(n);

    printf("递归算法计算斐波那契数列第 %d 项的结果: %d\n", n, result_recursive);
    printf("迭代算法计算斐波那契数列第 %d 项的结果: %d\n", n, result_iterative);

    return 0;
}    