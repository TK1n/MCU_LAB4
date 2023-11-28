/*
 * global.h
 *
 *  Created on: Nov 20, 2023
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "uart_communiation_fsm.h"
#include "command_parser_fsm.h"


#define MAX_BUFFER_SIZE  30

#define WAITING	 		 0
#define READING			 1

#define RECEIVE			 2
#define SENDING		 	 3

uint8_t temp;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer;
uint8_t buffer_flag;
long int ADC_value;

extern int command_flag;
uint8_t command_data;

ADC_HandleTypeDef hadc1;
TIM_HandleTypeDef htim2;
UART_HandleTypeDef huart2;

extern int state;
extern int uart_state;

void copy_string(uint8_t* data1, uint8_t* data2);

int compare_string(uint8_t* data1, uint8_t* data2);


















#endif /* INC_GLOBAL_H_ */
