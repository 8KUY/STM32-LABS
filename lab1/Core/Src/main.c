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


  // После этого перейдем в бесконечное ожидание.
  while (1)
  {

  }

}
