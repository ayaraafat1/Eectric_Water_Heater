/*
 * TIMER_prog.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Aya Raafat
 */
#include "../../Serv/std.h"
#include "../../Serv/bit_math.h"
#include "../../MCAL/TIMER/TIMER0_init.h"
#include "TIMER_int.h"

void TIMER_vid_int(void)//interface & initialization
{
	TIMER0_vid_int();
}

void TIMER_vid_Start(void)//start timer
{
	TIMER0_vid_Start();
}
void TIMER_vid_Stop(void)//Stop timer
{
	TIMER0_vid_Stop();
}
void TIMER_vid_Reset(void)//Reset timer
{
	TIMER0_vid_Reset();
}

void TIMER_vid_Write_COMP_OCR0(uint8 Copy_Start_Value)//comparing value to write the ocr
{
	TIMER0_vid_Write_COMP_OCR0(Copy_Start_Value);
}

//INT enable
void TIMER_vid_COMP_Interrupt_Enable(void)//comparing INT enable
{
	TIMER0_vid_COMP_Interrupt_Enable();
}

void timer_isr_fun(void (*fun)(void))
{
	TIMER0_CTC_INT=fun;
}


