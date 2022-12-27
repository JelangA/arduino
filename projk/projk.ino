#include <Servo.h>
#include <SoftwareSerial.h>

//Inialisasi pin lampu
const int pin1 = 4;
const int pin2 = 5;
const int pin3 = 6;
const int pin4 = 7;
const int pin5 = 8;
const int pin6 = 9;
const int pin7 = 10;
const int pin8 = 11;

//inisialsasi servo
const int servo = 12;
Servo myservo;

//posisi servo
const int buka = 100;
const int tutup = 27;

String data;

// =============== PROGRAM SEETING AWAL ============== //
void setup()
{
//Inialisasi baud rate serial monitor dan bluetooth
Serial.begin(9600);
Serial.println("Power Ready");
myservo.write(tutup);

myservo.attach(servo);
myservo.write(tutup);
delay(100);

//Inialisasi status pin I/O lampu
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
pinMode(pin5, OUTPUT);
pinMode(pin6, OUTPUT);
pinMode(pin7, OUTPUT);
pinMode(pin8, OUTPUT);

//Mengaktifkan pull up resisitor pin lampu
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(pin4, HIGH);
digitalWrite(pin5, HIGH);
digitalWrite(pin6, HIGH);
digitalWrite(pin7, HIGH);
digitalWrite(pin8, HIGH);
}

// ================== PROGRAM UTAMA ================= //
void loop()
{
  data = "";
  
  if(Serial.available() > 0){
    char data = Serial.read();
    int pos = 0;
    Serial.println(data);
    
    switch(data){
      //==============NYALA=========//
      case '1':
        digitalWrite(pin1, LOW);
        break;
      case '2':
        digitalWrite(pin2, LOW);
        break;
      case '3':
        digitalWrite(pin3, LOW);
        break;
      case '4':
        digitalWrite(pin4, LOW);
        break;
      case '5':
        digitalWrite(pin5, LOW);
        break;
      case '6':
        digitalWrite(pin6, LOW);
        break;
      case '7':
        digitalWrite(pin7, LOW);
        break;
      case '8':
        digitalWrite(pin8, LOW);
        break;
      //================MATI===========//
      case 'Q':
        digitalWrite(pin1, HIGH);
        break;
      case 'w':
        digitalWrite(pin2, HIGH);
        break;
      case 'E':
        digitalWrite(pin3, HIGH);
        break;
      case 'R':
        digitalWrite(pin4, HIGH);
        break;
      case 'T':
        digitalWrite(pin5, HIGH);
        break;
      case 'Y':
        digitalWrite(pin6, HIGH);
        break;
      case 'U':
        digitalWrite(pin7, HIGH);
        break;
      case 'I':
        digitalWrite(pin8, HIGH);
        break;
      //============SERVO=======//
      case 'X':
        myservo.write(27);
        delay(50);
        break;
      case 'Z':
        myservo.write(100);
        delay(50);
        break;
      default:
        break;
    }

    myservo.write(buka);
  delay(1000);
  myservo.write(pos);
  delay(1000);
    
  }

//  while (BT.available())
//  {
//
//    if(data.length() > 0)
//    {
//      //relay 1
//      if(data == "1"){
//        digitalWrite(pin1, LOW);
//        data = "";
//      }else if(data == "Q"){
//        digitalWrite(pin1, HIGH);
//        data = "";
//      }
//      
//      //relay 2
//      else if(data == "2"){
//        digitalWrite(pin2, LOW);
//        data = "";
//      }
//      else if(data == "W"){
//        digitalWrite(pin2, HIGH);
//        data = "";
//      }
//      
//      //relay 3
//      else if(data == "3"){
//        digitalWrite(pin3, LOW);
//        data = "";
//      }
//      else if(data == "E"){
//        digitalWrite(pin3, HIGH);
//        data = "";
//      }
//  
//      //relay 4
//      else if(data == "4"){
//        digitalWrite(pin4, LOW);
//        data = "";
//      }else if(data == "R"){
//        digitalWrite(pin4, HIGH);
//        data = "";
//      }
//  
//      //relay 5
//      else if(data == "5"){
//        digitalWrite(pin5, LOW);
//        data = "";
//      }else if(data == "T"){
//        digitalWrite(pin5, HIGH);
//        data = "";
//      }
//  
//      //relay 6
//      else if(data == "6"){
//        digitalWrite(pin6, LOW);
//        data = "";
//      }else if(data == "Y"){
//        digitalWrite(pin6, HIGH);
//        data = "";
//      }
//  
//      //relay 7
//      else if(data == "7"){
//        digitalWrite(pin7, LOW);
//        data = "";
//      }else if(data == "U"){
//        digitalWrite(pin7, HIGH);
//        data = "";
//      }
//  
//      //relay 8
//      else if(data == "8"){
//        digitalWrite(pin8, LOW);
//        data = "";
//      }else if(data == "I"){
//        digitalWrite(pin8, HIGH);
//        data = "";
//      }
//
//    // servo pintu
//      else if(data == "X"){
//
//          myservo.write(0);              // tell servo to go to position in variable 'pos'
//          delay(15);                       // waits 15ms for the servo to reach the position
//
//        data = "";
//      }
//      else if(data == "Z"){
//          myservo.write(170);              // tell servo to go to position in variable 'pos'
//          delay(20);                       // waits 15ms for the servo to reach the position
//        
//        data = "";
//      }
//    }
//      
//  }
  
}
