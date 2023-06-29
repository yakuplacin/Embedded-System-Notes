#ifndef DHT11_H
#define DHT11_H
 
#include "tim.h"
#include "stm32f1xx_hal.h"
 
#define DHT11_PORT		   GPIOC
#define DHT11_PIN		      GPIO_PIN_5
 
#define DHT11_OUT_1				HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET)
#define DHT11_OUT_0				HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET)
 
#define DHT11_IN					        HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)
 
typedef struct
{
	uint8_t humi_int;
	uint8_t humi_deci;
	uint8_t temp_int;
	uint8_t temp_deci;
	uint8_t check_sum;
		                 
} DHT11_Data_TypeDef;
 
uint8_t DHT11_ReadData(DHT11_Data_TypeDef* DHT11_Data);
 
#endif	/* DHT11_H */
