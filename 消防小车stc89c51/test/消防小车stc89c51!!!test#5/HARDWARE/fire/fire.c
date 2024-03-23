#include <REGX52.H>
#include "run.h"
#include "fan.h"
#include "Delay.h"

sbit DO1 = P1^2;  	//front
sbit DO2 = P1^3;		//left
sbit DO3 = P1^4;		//right

void fire()
{
	if(DO1 == 0)      //sence fire front
	{
		car_stop();
		fan_on();
		Delay(5000);
		fan_off();
		car_leftstop();
		Delay(500);
		car_stop();
		Delay(100);
	}
	else if(DO2 == 0)			//sence fire left
	{
		car_stop();
		Delay(100);
		while(DO1 == 1)
			car_leftstop();
		while(DO1 == 0)
		{car_stop();
		Delay(80);
		fan_on();
		Delay(5000);}
		fan_off();
		car_leftstop();
		Delay(500);
		car_stop();
		Delay(100);
	}
	if(DO3 == 0)			//sence fire right
	{
		car_stop();
		Delay(100);
		while(DO1 == 1)
			car_rightstop();
		while(DO1 == 0)
		{car_stop();	
		Delay(80);
		fan_on();
		Delay(5000);}
		fan_off();
		car_rightstop();
		Delay(500);
		car_stop();
		Delay(100);
	}
}