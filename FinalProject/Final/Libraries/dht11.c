#include "tim.h"
#include "dht11.h"
 
/**
	* @brief DHT11
	*/
static void DHT11_Mode_OUT_PP(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.Pin = DHT11_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	
  HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}
 
/**
	* @brief DHT11
	*/
static void DHT11_Mode_IN_NP(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.Pin = DHT11_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
 
  HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}
 
/**
	* @brief DHT11
	*/
uint8_t DHT11_ReadByte(void)
{
	uint8_t i, temp = 0;
 
	for (i = 0; i < 8; i++)
	{
		while (DHT11_IN == 0);
		
		delay_us(40);
		
		if (DHT11_IN == 1)
		{
			while (DHT11_IN == 1);
			
			temp |= (uint8_t)(0X01 << (7 - i));
		}
		else
		{
			temp &= (uint8_t)~(0X01 << (7 - i));
		}
	}
	return temp;
}
 
/**
	* @brief DHT11
	*/
uint8_t DHT11_ReadData(DHT11_Data_TypeDef *DHT11_Data)
{
	DHT11_Mode_OUT_PP();
	DHT11_OUT_0;	
	HAL_Delay(18);
	
	DHT11_OUT_1;
	delay_us(30);	
 
	DHT11_Mode_IN_NP();
	
	if (DHT11_IN == 0)
	{
		while (DHT11_IN == 0);
		
		while (DHT11_IN == 1);
		
		DHT11_Data->humi_int  = DHT11_ReadByte();
		DHT11_Data->humi_deci = DHT11_ReadByte();
		DHT11_Data->temp_int  = DHT11_ReadByte();
		DHT11_Data->temp_deci = DHT11_ReadByte();
		DHT11_Data->check_sum = DHT11_ReadByte();
		
		DHT11_Mode_OUT_PP();
		DHT11_OUT_1;	
		
		if (DHT11_Data->check_sum == DHT11_Data->humi_int + DHT11_Data->humi_deci + DHT11_Data->temp_int + DHT11_Data->temp_deci)	
		{
			return 1;
		}		
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


