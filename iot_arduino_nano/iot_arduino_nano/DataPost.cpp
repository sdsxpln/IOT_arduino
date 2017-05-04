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
	Serial.println("");


}

void DT::DataUpdate(float DataArray[])
{
	Sensor_Temp = DataArray[0];
	Sensor_Hum = DataArray[1];
	Sensor_Bar = DataArray[2];
	Sensor_Lux = DataArray[3];
}

