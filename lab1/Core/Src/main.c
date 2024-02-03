#include "main.h"

int main(void)
{
  uint32_t * register_adr;
  uint32_t temp_val; 


  // Выставляем бит IOPCEN в регистре RCC_APB2ENR в логическую 1
  register_adr = (uint32_t *) 0x40021018U;   // 0x40021018 = 0x40021000 + 0x18
  *register_adr |= 0x10;                     // 0x10 = 0x0001 0000


  // Считываем значение регистра RCC_APB2ENR
  temp_val = *register_adr;


  // Одновременно установим биты MODE13[0], MODE14[0] и MODE15[0] в логическую 1.
  GPIOC->CRH |= (GPIO_CRH_MODE13_0 | GPIO_CRH_MODE14_0 | GPIO_CRH_MODE15_0);

  /* 
  Одновременно установим биты CNF13[0], CNF14[0] и CNF15[0] в логический 0,
  для этого сначала инвертируем битовые маски, а потом производим операцию логического И.
  */
  GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_CNF14 | GPIO_CRH_CNF15);


  // Одновременно установим биты ODR13 и ODR15 в логическую 1.
  GPIOC->ODR |= (GPIO_ODR_ODR13 | GPIO_ODR_ODR15);


  // Выставляем бит IOPBEN в регистре RCC_APB2ENR в логическую 1
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

  // Считываем значение регистра RCC_APB2ENR
	temp_val = *register_adr;

  // Биты MODE по умолчанию равны 00

  // Одновременно установим биты CNF12 = 10 и CNF13 = 10
  GPIOB->CRH |= (GPIO_CRH_CNF12_1 | GPIO_CRH_CNF13_1);
  GPIOB->CRH &= ~(GPIO_CRH_CNF12_0 | GPIO_CRH_CNF13_0);

  // Устанавливаем бит ODR13 в логическую 1
  GPIOB->ODR |= GPIO_ODR_ODR13;

  // Бесконечный цикл
  while (1)
  {
    // Проверям бит 12 в регистре GPIOC_IDR
    if ((GPIOB->IDR) & GPIO_IDR_IDR12) {
      GPIOC->ODR |= GPIO_ODR_ODR13;
    };

    // Проверям бит 13 в регистре GPIOC_IDR
    if ((GPIOB->IDR) & GPIO_IDR_IDR13) {
      GPIOC->ODR |= GPIO_ODR_ODR15;
    };

    // Выключаем оба светодиода
    GPIOC->ODR &= ~(GPIO_ODR_ODR13 | GPIO_ODR_ODR15);
  }

}
