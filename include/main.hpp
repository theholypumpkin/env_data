#ifndef Arduino_h
#include <Arduino.h>
#endif
#ifndef _MAIN_HPP
#define _MAIN_HPP

// A union so we can easily cast a uint16_t into a array of bytes.
union uint16_tByte{
    byte b[sizeof(uint16_t)];
    uint16_t i;
};

void setup();
void loop();
void alarmISRCallback();
void setupEEPROM();
void readCCSSensor(uint16_t &eco2Value, uint16_t &tvocValue);
void readCCSSensor(uint16_t &eco2Value, uint16_t &tvocValue,
                   float temperatureValue, float humidityValue);

bool readDHTSensor(float &temperatureValue, float &humidityValue, float &heatIndexValue);
void publishMQTT(uint16_t eco2Value, uint16_t tvocValue, long rssiValue,
                 float temperatureValue, float humidityValue, float heatIndexValue, 
                 float voltage, float percentage);

void publishMQTT(uint16_t eco2Value, uint16_t tvocValue, long rssiValue, 
                 float voltage, float percentage);
float calcBatteryPercentageLiPo(float voltage);

bool updateNetworkTime();
#endif