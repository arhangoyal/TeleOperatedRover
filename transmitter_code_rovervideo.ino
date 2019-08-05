#include <VirtualWire.h>    //This library needs to be downloaded and added to the code using the sketch option
#include <Wire.h>



//for accelerometer
const int MPU = 0x68;
int16_t AcX, AcY, AcZ;

float pitchin;
float rollin;


//for transmitter
struct package
{
  float code;
  float ax;
  float roll;
};

typedef struct package Package;
Package data;

const int transmiting_pin = 12;





void setup() {
  Serial.begin(9600);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);        //end the transmission


  vw_set_tx_pin(transmiting_pin);
  vw_setup(500);   // 500 Bits per sec
}


void loop() {
  //take readings
  Wire.beginTransmission(MPU),
  Wire.write(0x3B),
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);
  AcX = Wire.read() << 8| Wire.read();
  AcY = Wire.read() << 8| Wire.read();
  AcZ = Wire.read() << 8| Wire.read();
  
  
  pitchin = atan2(AcY, AcZ);
  rollin = atan2(AcX, AcZ);
  
  data.code = 56.0;
  data.ax = pitchin*(180/3.14);
  data.roll = rollin*(180/3.14);

//  Serial.println(data.ax);
  Serial.println(data.roll);

  digitalWrite(13, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)&data, sizeof(data)); // uint8 is signifying the type of data and size of is signifying the size of the data.
  vw_wait_tx(); // Wait until the whole message is gone.
  digitalWrite(13, LOW);
}
