 /* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dwt_stm32_delay.h"
#include "string.h"
#include <stdio.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
uint8_t Rh_byte1, Rh_byte2;
uint8_t Temp_byte1, Temp_byte2;
float RH,TEMP;
uint16_t RH1,TEMP1;
uint8_t check=0;

  UART_HandleTypeDef huart1;
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  void set_gpio_output(void){
	  GPIO_InitStruct.Pin = GPIO_PIN_1;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  }

  /*Configure GPIO pin : PA2 */
  void set_gpio_input(void){
	   GPIO_InitStruct.Pin = GPIO_PIN_1;
  	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  	  GPIO_InitStruct.Pull = GPIO_NOPULL;
  	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  }


  void dht22_start(void){
	  set_gpio_output();
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	  DWT_Delay_us(500);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
	  DWT_Delay_us(30);

	  set_gpio_input();

  }

  void check_respose (void){
	  DWT_Delay_us(40);
	  if(!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1))){
		  DWT_Delay_us(40);
		  if((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1))) check=1;
	  }
	  while((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)));
  }


  uint8_t read_data(void){
	  uint8_t i,j;
	  for (j=0;j<8;j++){
		  while(!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)));
		  DWT_Delay_us(40);
		  if ((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1))==0){
			  i&= ~(1<<(7-j));
		  }
		  else i|= (1<<(7-j));
		  while ((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)));
	  }
	  return i;
  }


/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  DWT_Delay_Init ();
  /* USER CODE END 2 */
   uint8_t buffer[16];
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //HAL_UART_Transmit(&huart1, (uint8_t*)"HI\n", strlen("HI\n"), 200);
    /* USER CODE END WHILE */
	  dht22_start();
	 // HAL_UART_Transmit(&huart1, (uint8_t*)"HI01\n", strlen("HI01\n"), 200);
	  check_respose();

	  //HAL_UART_Transmit(&huart1, (uint8_t*)"HI02\n", strlen("HI02\n"), 200);
	  Rh_byte1 = read_data();
	  //HAL_UART_Transmit(&huart1, (uint8_t*)"HI03\n", strlen("HI03\n"), 200);
	  Rh_byte2 = read_data();
	 // HAL_UART_Transmit(&huart1, (uint8_t*)"HI04\n", strlen("HI04\n"), 200);
	  Temp_byte1 = read_data();
	 // HAL_UART_Transmit(&huart1, (uint8_t*)"HI05\n", strlen("HI05\n"), 200);
	  Temp_byte2 = read_data();
	 // HAL_UART_Transmit(&huart1, (uint8_t*)"HI06\n", strlen("HI06\n"), 200);
	  //sum = read_data();
	//  HAL_UART_Transmit(&huart1, (uint8_t*)"HI07\n", strlen("HI07\n"), 200);
	  TEMP1 = (Temp_byte1<<8)|Temp_byte2;
	 // HAL_UART_Transmit(&huart1, (uint8_t*)"HI08\n", strlen("HI08\n"), 200);
	  RH1 = (Rh_byte1<<8)|Rh_byte2;

	  TEMP1 = (TEMP1/10.0);
	  RH1 = (RH1/10.0);
	//  HAL_UART_Transmit(&huart1, (uint8_t*)"HI09\n", strlen("HI09\n"), 200);
	  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, sprintf(buffer, "Temperature is %d \n", TEMP1), 500); // @suppress("Float formatting support")
	  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, sprintf(buffer, "Humidity is %d \n", RH1), 500); // @suppress("Float formatting support")

    /* USER CODE BEGIN 3 */

	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{


  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA1 */


}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
