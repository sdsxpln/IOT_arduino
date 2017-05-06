#include "stdio.h"
#include "stdlib.h"
#include "Arduino.h"
#include "Wire.h"
#define BaseVoltage 5.00f
#define BH1750address 0x23
class DT
{
private:
	float Sensor_Temp, Sensor_Bar, Sensor_Hum, Sensor_Lux,Sensor_Rain,Sensor_Co2,Sensor_Formal,Sensor_Air;

public:
	void Send_to_esp();
	void DataUpdate(float DataArray[]);

private:

};

float Get_MQ7(int MQ7_Pin);
int BH1750_Read(int address);
void BH1750_Init(int address);
int Get_Lux();

