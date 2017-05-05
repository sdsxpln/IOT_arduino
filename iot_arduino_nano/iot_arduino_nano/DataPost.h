#include "stdio.h"
#include "stdlib.h"
#include "Arduino.h"

class DT
{
private:
	float Sensor_Temp, Sensor_Bar, Sensor_Hum, Sensor_Lux,Sensor_Rain,Sensor_Co2,Sensor_Formal,Sensor_Air;

public:
	void Send_to_esp();
	void DataUpdate(float DataArray[]);

private:

};


