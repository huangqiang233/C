#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool is_prime(int n) {
    if (n <= 1) return false;    // 1和负数不是质数
    if (n == 2) return true;     // 2是唯一的偶质数
    if (n % 2 == 0) return false;// 排除其他偶数

    int sqrt_n = (int)sqrt(n) + 1; // 计算√n并向上取整
    for (int i = 3; i <= sqrt_n; i += 2) { // 只检查奇数
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int test_numbers[] = {2, 17, 15, 1000000007};
    for (int i = 0; i < 4; i++) {
        printf("%d is prime? %s\n",
               test_numbers[i],
               is_prime(test_numbers[i]) ? "Yes" : "No");
    }
    return 0;
}
