/*
 * global.c
 *
 *  Created on: Nov 20, 2023
 *      Author: PC
 */

#include "global.h"

uint8_t temp = 0;
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

long int ADC_value = 0;
int state = 0;
int command_flag = WAITING;
int uart_state = RECEIVE;


void copy_string(uint8_t* data1, uint8_t* data2){
	for (int i=0 ; i < MAX_BUFFER_SIZE; i++) {
		data1[i] = data2[i];
	}
}

int compare_string(uint8_t* data1, uint8_t* data2){
	for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
		if (data1[i] != data2[i]) {
			return 0; // Arrays are different
		}
	}
	return 1;
}







