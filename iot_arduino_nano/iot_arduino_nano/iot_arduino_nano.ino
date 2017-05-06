/*
 Name:		iot_arduino_nano.ino
 Created:	2017/5/4 13:30:21
 Author:	yewei
*/

// the setup function runs once when you press reset or power the board
#include "SPI.h"
#include <Wire.h>
#include "Adafruit_Si7021.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <math.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DataPost.h"

Adafruit_Si7021 sensor_T_H = Adafruit_Si7021(); //用构造函数生成温湿度传感器对象
Adafruit_BMP280 bme; // 定义气压计
Adafruit_SSD1306 display;
DT IotDT;
float DT_get_array[8];

int serial_putc(char c, struct __file *)
{
	Serial.write(c);
	return c;
}
void printf_begin(void)
{
	fdevopen(&serial_putc, 0);
}

void simple_display(int x, int y, char* str) {
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(x, y);
	display.println(str);
	display.display();
}

void Sensor_Get() {
	DT_get_array[0] = sensor_T_H.readTemperature(); //温度  t
	DT_get_array[1] = sensor_T_H.readHumidity(); //湿度  h
	DT_get_array[2] = bme.readPressure(); //气压  b
	DT_get_array[3] = Get_Lux();//光照  l
	DT_get_array[4] = 0; //雨水  r
	DT_get_array[5] = Get_MQ7(A1); //CO2   c
	DT_get_array[6] = 0; //甲醛  j
	DT_get_array[7] = 0; //空气质量  q
}

void setup() {
	Serial.begin(115200);
	Serial.println("ok");
	sensor_T_H.begin();
	bme.begin();
	BH1750_Init(BH1750address);
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
	display.display();
	display.clearDisplay();
	simple_display(0, 0, "hello world");
	simple_display(0, 20, "IG TEAM");
}

// the loop function runs over and over again until power down or reset
void loop() {
	//Serial.print("Humidity:    "); Serial.print(sensor_T_H.readHumidity());
	//Serial.print("\tTemperature: "); Serial.println(sensor_T_H.readTemperature());
	//Serial.print("Pressure = ");Serial.print(bme.readPressure());Serial.println(" Pa");
	Sensor_Get();
	IotDT.DataUpdate(DT_get_array);
	IotDT.Send_to_esp();
	delay(500);
}
