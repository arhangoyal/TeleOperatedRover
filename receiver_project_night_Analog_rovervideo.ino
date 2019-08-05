#include <VirtualWire.h>    //This library needs to be downloaded and added to the code using the sketch option

//for the receiver
struct package
{
  float code;
  float ax;
  float roll;
};

typedef struct package Package;
Package data;

const int receive_pin = 11;   //this is the receiving pin according to my circuit diagram

//motor driver pins with respective arduino pins
const int In1 = 8;
const int In2 = 9;
const int In3 = 4;
const int In4 = 5;
const int Out2 = 3;   // out2 = enB — this is the second motor
const int Out1 = 6;   // out1 = enA — this is the first motor
float speed1 = 0.5 * 0.9 * 100;   //the values before hundred ("0.5*0.9") can be changed to adjust the rover's balance
float speed2 = 0.5 * 1.1 * 100;   //the values before hundred ("0.5*1.1") can be changed to adjust the rover's balance

// ultrasonic sensor
const int trig = 12;
const int echo = 7;
float enb=0.85*1.5;
float ena=1.15*1.5;
long duration; // long can store large amount of data.
long distance;



void setup()
{ 
  Serial.begin(9600);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(Out2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(Out1, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode (echo, INPUT);


  vw_set_rx_pin(receive_pin);;;;;
  vw_setup(500);   // 500 Bits per sec
  vw_rx_start();   // Start the receiver PLL running
}


void loop()
{ 
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = duration * 0.034 / 2;
  
    if (distance > 40)
    {
      uint8_t buf[sizeof(data)];
      uint8_t buflen = sizeof(data);


      if (vw_have_message() == true)
      {
        Serial.println(data.code);
        vw_get_message(buf, &buflen);
        memcpy(&data, &buf, buflen);
        float right = data.ax + 0.5*data.roll;
        float left = data.ax - 0.5*data.roll;

        if (data.code == 56.0)
        {
//          Serial.println(data.ax);
//          Serial.println(data.roll);
//          data is received by the transmitter. 56 can be any random number.


            Serial.println(data.ax);
            if (data.ax > 20)
            {
//              Serial.print("forward");
              analogWrite(Out2, enb*fabs(data.ax));   //all these values before fabs(data.ax) [enb here] can be changed to adjust the rover's balance
              analogWrite(Out1, ena*fabs(data.ax));
              digitalWrite(In1, LOW);
              digitalWrite(In2, HIGH);
              digitalWrite(In3, HIGH);
              digitalWrite(In4, LOW);
              Serial.println("forward");
            }

            else if (data.ax < -20)
            {
//              Serial.print("backward");
              analogWrite(Out2, enb*fabs(data.ax));
              analogWrite(Out1, ena*fabs(data.ax));
              digitalWrite(In1, HIGH);
              digitalWrite(In2, LOW);
              digitalWrite(In3, LOW);
              digitalWrite(In4, HIGH);
              Serial.println("backward");
            }


            else if (data.roll > 20 && fabs(data.roll) > fabs(data.ax))
            {
//              Serial.println("right");
              analogWrite(Out2, enb*right);
              analogWrite(Out1, ena*left);
              digitalWrite(In1, LOW);
              digitalWrite(In2, HIGH);
              digitalWrite(In3, HIGH);
              digitalWrite(In4, LOW);
            }

            else if (data.roll < -20 && fabs(data.roll) > fabs(data.ax))
            {
//              Serial.println("left");
              analogWrite(Out2, enb*right);
              analogWrite(Out1, ena*left);
              digitalWrite(In1, LOW);
              digitalWrite(In2, HIGH);
              digitalWrite(In3, HIGH);
              digitalWrite(In4, LOW);
            }


            else
            {
//              Serial.println("STOP");
              analogWrite(Out2, 0);
              analogWrite(Out1, 0);
              digitalWrite(In1, LOW);
              digitalWrite(In2, LOW);
              digitalWrite(In4, LOW);
              digitalWrite(In3, LOW);
            }
        }
      }
    }
    
    else 
    {
//      Serial.println("what");
      analogWrite(Out2, speed1);
      analogWrite(Out1, speed2);
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);
    }
}
