# Edge Demo Arduino
### Table of Contents
- [Overview](https://github.com/measurify/edge-demo-arduino#overview)
- [How to use](https://github.com/measurify/edge-demo-arduino#how-to-use)
- [Code](https://github.com/measurify/edge-demo-arduino#code)
## Overview
This demo is based on [edge](https://github.com/Measurify/edge), a generic runtime system capable of processing data flows collected by sensors attached to a device through scripts.
## How to use
This library requirements are listed on the [edge guide](https://github.com/Measurify/edge#arduino). After you ensured your system satisfies all the prerequisites you can start using this demo.
The board used for this example is ESP32, so you will need to select the ESP32 Wrover Module inside your IDE. If you don't know how to install it, have a look at the [source code](https://github.com/Measurify/edge#Arduino-example).
## Code
In this example the board is supposed to be attached to three sensors, so three features are provided:
- **Light**
- **Temperature**
- **Motion** 

The functions used to collect these data are _getLux()_, _getTemperature()_, _detectedMotion()_:
```
float getLux(){
  unsigned int data0, data1;
  if (lightSensor.getData(data0,data1))
  {
    double lux;// Resulting lux value
    if (!lightSensor.getLux(lightSensorGain,lightSensorms,data0,data1,lux)) 
    { 
      //sensor saturated
    }
    return lux;
  }
  else{
     //I2C error
  }
  
}
```
```
float getTemperature(){
  Wire.requestFrom(tmpSensorAddress,2); //size: 2 bytes 
  byte MSB = Wire.read();
  byte LSB = Wire.read();
  int TemperatureSum = ((MSB << 8) | LSB) >> 4; //12 bit int, two's complement for negative
  return TemperatureSum*0.0625;//quantization level is 0.0625 celsius
}
```
```
void detectedMotion(){
  detachInterrupt(digitalPinToInterrupt(pirPin)); //PIR sensor needs 2 seconds to take an image to compare to
  pirCounter=clock();
  motion = new sample("motion");
  //motion->startDate=Edge->Api->getActualDate();
  //motion->endDate=motion->startDate;
  motion->value=1;
  samples.push_back(motion);
}
```
Once all the four features are found, a Wi-Fi connection is established with the given SSID (_ssidWifi_) and password (_passWifi_), then, if it succeed, data are sent to Measurify: a cloud-based, measurement-oriented platform created by the Elios Lab of the University of Genoa to manage intelligent objects in IoT ecosystems.
