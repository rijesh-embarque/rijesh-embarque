#include <stdint.h>

#define RCC_BASE 0x40021000
#define RCC_APB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x18))
#define RCC_APB2ENR_IOPCEN (1<<4)
#define GPIO_PORTC_BASE 0x40011000
#define GPIO_PORTC_CRH (*(volatile uint32_t *)(GPIO_PORTC_BASE + 0x04))
#define GPIO_PORTC_CNF (3<<22)
#define GPIO_PORTC_MODE (3<<20)
#define GPIO_PORTC_ODR (*(volatile uint32_t *)(GPIO_PORTC_BASE + 0x0C))
#define GPIO_LED (1<<13)

int main(void) {
    RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIO_PORTC_CRH &= ~(GPIO_PORTC_CNF);
    GPIO_PORTC_CRH |= GPIO_PORTC_MODE;
    while(1) {
        GPIO_PORTC_ODR |= GPIO_LED;
        for (uint32_t i = 0; i < 5000; ++i) {
            __asm__ volatile("nop");
        }
        GPIO_PORTC_ODR &= ~(GPIO_LED);
        for (uint32_t i = 0; i < 5000; ++i) {
            __asm__ volatile("nop");
        }
    }
    return 0;
}