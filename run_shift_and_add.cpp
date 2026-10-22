#include <stdint.h>
#include <cstdio>

int shift_and_add(int a, int b, int m) {
    int result = 0;
    while (b > 0) {
        if (b & 1) {
            result = result ^ a;
        }
        a <<= 1;
        if(a & 0x100) {
            a ^= m;
        }
        b >>= 1;
        if (b == 0) {
            break;
        }
    }
    return result;
}

int main() {
    int a = 0x57; // 0101 0111: x^6 + x^4 + x^2 + x + 1
    int b = 0x83; // 1000 0011: x^7 + x + 1
    int m = 0x11B; // 1 0001 1011: x^8 + x^4 + x^3 + x + 1

    int result = shift_and_add(a, b, m);
    printf("Result: 0x%X\n", result);
}