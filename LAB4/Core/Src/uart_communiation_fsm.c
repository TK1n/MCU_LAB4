/*
 * uart_communiation_fsm.c
 *
 *  Created on: Nov 20, 2023
 *      Author: PC
 */

#include "uart_communiation_fsm.h"

int flag_sent = 0;

void uart_communiation_fsm(){
	char str[50];
	switch(uart_state){
		case RECEIVE:
			if (command_flag) {
				uint8_t temp[MAX_BUFFER_SIZE]="!RST#";
				if (compare_string(command_data, temp)) {
					uart_state = SENDING;
					HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "\r\n"), 100);
					HAL_ADC_Start(&hadc1);
					ADC_value = HAL_ADC_GetValue(&hadc1);
					HAL_ADC_Stop(&hadc1);
					setTimer1(10);
					flag_send = 1;
				}
				else{
					uint8_t temp1[MAX_BUFFER_SIZE]="!OK#";
					if (compare_string(command_data, temp1)) {
						HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "\r\n"), 100);
						flag_send = 0;
						command_flag=0;
					}
				}

			}
			if(flag_send){
				if(timer1_flag == 1)
					uart_state = SENDING;
			}

			break;
		case SENDING:
				HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "!ADC=%ld#\r\n", ADC_value), 1000);
				uart_state = RECEIVE;
				setTimer1(3000);
			break;
		default:
			break;
	}
}















