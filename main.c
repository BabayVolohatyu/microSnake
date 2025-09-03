#include <stdint.h>
#include <stdio.h>

#define headX 0
#define headY 3
#define tailX 6
#define tailY 9
#define appleX 12
#define appleY 15
#define lenS 18
#define lenE 23

#define set(a, n)  ((uint8_t)((a)[(n)/8] |=  (1 << ((n)%8))))
#define clr(a, n)  ((uint8_t)((a)[(n)/8] &= ~(1 << ((n)%8))))
#define get(a, n)  ((uint8_t)(((a)[(n)/8] >> ((n)%8)) & 1))

uint8_t getB(const uint8_t data[], uint8_t start_bit, uint8_t n) {
    uint8_t value = 0;
    for(uint8_t i = 0; i < n; ++i)
        value |= get(data, start_bit + i) << i;
    return value;
}
void setB(uint8_t data[], uint8_t start_bit, uint8_t n, uint8_t value) {
    for(uint8_t i = 0; i < n; ++i)
        (value & (1 << i)) ? set(data, start_bit + i) : clr(data, start_bit + i);
}

int main(void) {
    uint8_t data[3] = {};
    uint8_t body[24] = {};
    setB(body, 0, 3, 0x5); // 101 bcs 1st bit for existence and 01 to move right
    setB(data, lenS, 6, 0x1); // set len to 1
    printf("%u\n", body[0]);
    while (1) {
        for (uint8_t i = 0; i < getB(data, 12, 6); ++i) {
        }
    }
    return 0;
}