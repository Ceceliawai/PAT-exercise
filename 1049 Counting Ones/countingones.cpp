#include <math.h>
#include <stdio.h>
long int base[11];
int main() {
    int N, temp, len, digits, remain, radix;
    long int count = 0;
    scanf("%d", &N);
    base[0] = 0;
    base[1] = 1;
    for (int i = 2; i <= 10; i++) {
        base[i] = pow(10, i - 1) + base[i - 1] * 10;
    }
    len = 0;
    temp = N / 10;
    while (temp != 0) {
        len++;
        temp /= 10;
    }
    if (len == 0) {
        // 只有一位数
        printf("1");
        return 0;
    }
    temp = N;
    while (len != 0) {
        radix = pow(10, len);
        digits = temp / radix;
        remain = temp % radix;
        if (digits == 1) {
            count += base[len] + remain + 1;
        } else {
            if (digits != 0) count += digits * base[len] + radix;
        }
        len--;
        temp = remain;
    }
    if (temp >= 1) count = count + 1;
    printf("%ld", count);
    return 0;
}