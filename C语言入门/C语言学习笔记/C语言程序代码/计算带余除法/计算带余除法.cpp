#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) { // ע�� while ������ case
        // 64 λ������� printf("%lld") to 
        printf("%d %d\n", a/b,a%b);
    }
    return 0;
}
