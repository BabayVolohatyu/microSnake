#include <stdint.h>
#include <stdio.h>

#define set(a, n)  ((uint8_t)((a)[(n)/8] |=  (1 << ((n)%8))))
#define clr(a, n)  ((uint8_t)((a)[(n)/8] &= ~(1 << ((n)%8))))
#define tgl(a, n)  ((uint8_t)((a)[(n)/8] ^=  (1 << ((n)%8))))
#define get(a, n)  ((uint8_t)(((a)[(n)/8] >> ((n)%8)) & 1))

uint8_t getC(const uint8_t data[], uint8_t start_bit, uint8_t n) {
    uint8_t value = 0;
    for(uint8_t i = 0; i < n; ++i)
        value |= get(data, start_bit + i) << i;
    return value;
}
void setC(uint8_t data[], uint8_t start_bit, uint8_t n, uint8_t value) {
    for(uint8_t i = 0; i < n; ++i)
        (value & (1 << i)) ? set(data, start_bit + i) : clr(data, start_bit + i);
}
int main(void) {
    uint8_t data[3];
    uint8_t body[16];
    return 0;
}