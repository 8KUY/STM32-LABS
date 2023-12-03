#include "main.h"

int main(void)
{

  // GPIO_InitTypeDef GPIO_InitStruct = {0};

  // __HAL_RCC_GPIOC_CLK_ENABLE();
  uint32_t tmpreg; 
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);
  /* Delay after an RCC peripheral clock enabling */
  tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);

  // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
  CLEAR_BIT(GPIOC->ODR, GPIO_ODR_ODR13);
  SET_BIT(GPIOC->ODR, GPIO_ODR_ODR14);
  SET_BIT(GPIOC->ODR, GPIO_ODR_ODR15);

  // GPIO_InitStruct.Pin = GPIO_PIN_13;
  // GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  // GPIO_InitStruct.Pull = GPIO_NOPULL;
  // GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  // HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  MODIFY_REG(GPIOC->CRH, GPIO_CRH_CNF13 | GPIO_CRH_CNF14 | GPIO_CRH_CNF15, \
  GPIO_CRH_MODE13_0 | GPIO_CRH_MODE14_0 | GPIO_CRH_MODE15_0);

  
  SET_BIT(GPIOC->ODR, GPIO_ODR_ODR13);
  SET_BIT(GPIOC->ODR, GPIO_ODR_ODR14);
  CLEAR_BIT(GPIOC->ODR, GPIO_ODR_ODR15);

  
  while (1)
  {

  }

}
