#include "DataPost.h"



void DT::Send_to_esp()
{
	//char tempstr[64]="";
	//sprintf(tempstr, "%.2f %.2f %.2f", Sensor_Temp, Sensor_Hum, Sensor_Bar);
	//Serial.println(tempstr);
	Serial.print(Sensor_Temp);
	Serial.print('t');
	Serial.print(Sensor_Hum);
	Serial.print('h');
	Serial.print(Sensor_Bar);
	Serial.print('b');
	Serial.print(Sensor_Lux);
	Serial.print('l');
	Serial.print(Sensor_Rain);
	Serial.print('r');
	Serial.print(Sensor_Co2);
	Serial.print('c');
	Serial.print(Sensor_Formal);
	Serial.print('j');
	Serial.print(Sensor_Air);
	Serial.print('q');
	Serial.println("");
}

void DT::DataUpdate(float DataArray[])
{
	Sensor_Temp = DataArray[0];
	Sensor_Hum = DataArray[1];
	Sensor_Bar = DataArray[2];
	Sensor_Lux = DataArray[3];
	Sensor_Rain = DataArray[4];
	Sensor_Co2 = DataArray[5];
	Sensor_Formal = DataArray[6];
	Sensor_Air = DataArray[7];
}

