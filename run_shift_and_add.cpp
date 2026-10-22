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
    int a = 0x05; // x^2 + 1
    int b = 0x03; // x + 1
    int m = 0x13; 

    int result = shift_and_add(a, b, m);
    printf("Result: 0x%X\n", result);
}