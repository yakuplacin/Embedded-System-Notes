#ifndef _RELAY_H
#define _RELAY_H
#include "main.h"
#include "gpio.h"

#define Relay_Port      GPIOC
#define HUM_UP_Pin      GPIO_PIN_6
#define HUM_DOWN_Pin    GPIO_PIN_7
#define TEMP_UP_Pin     GPIO_PIN_8
#define TEMP_DOWN_Pin   GPIO_PIN_9

#define HUM_UP_OFF		  HAL_GPIO_WritePin(Relay_Port, HUM_UP_Pin, GPIO_PIN_SET) 
#define HUM_UP_ON	      HAL_GPIO_WritePin(Relay_Port, HUM_UP_Pin, GPIO_PIN_RESET)

#define HUM_DOWN_OFF		HAL_GPIO_WritePin(Relay_Port, HUM_DOWN_Pin, GPIO_PIN_SET)
#define HUM_DOWN_ON   	HAL_GPIO_WritePin(Relay_Port, HUM_DOWN_Pin, GPIO_PIN_RESET)

#define TEMP_UP_OFF		  HAL_GPIO_WritePin(Relay_Port, TEMP_UP_Pin, GPIO_PIN_SET)
#define TEMP_UP_ON	    HAL_GPIO_WritePin(Relay_Port, TEMP_UP_Pin, GPIO_PIN_RESET)
 
#define TEMP_DOWN_OFF		HAL_GPIO_WritePin(Relay_Port, TEMP_DOWN_Pin, GPIO_PIN_SET)
#define TEMP_DOWN_ON  	HAL_GPIO_WritePin(Relay_Port, TEMP_DOWN_Pin, GPIO_PIN_RESET)





#endif
