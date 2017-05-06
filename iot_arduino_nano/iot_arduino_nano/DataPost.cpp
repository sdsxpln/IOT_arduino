#include "DataPost.h"
byte buff[2];

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

float Get_MQ7(int MQ7_Pin) {
	int var;
	float Convert_Voltage;
	var = analogRead(MQ7_Pin);
	Convert_Voltage = (BaseVoltage*var) / 1024;
	return (10.0f + 100.0f * Convert_Voltage);
}


int BH1750_Read(int address) 
{
	int i = 0;
	Wire.beginTransmission(address);
	Wire.requestFrom(address, 2);
	while (Wire.available()) 
	{
		buff[i] = Wire.read();  // read one byte
		i++;
	}
	Wire.endTransmission();
	return i;
}




void BH1750_Init(int address)
{
	Wire.beginTransmission(address);
	Wire.write(0x10);
	Wire.endTransmission();
}

int Get_Lux() {
	int val;
	val = ((buff[0] << 8) | buff[1]) / 1.2;
	return val;
}






