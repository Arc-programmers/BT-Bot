/*Programmer: Mohammad Afeef
Contains all the functions to
controll the bot in different 
dirctions using bluetooth with
mobile phone.
*/

//MOTOR_A PINS
int ena = 5;
int in1 = 6;
int in2 = 7;

//MOTOR_B PINS
int in3 = 8;
int in4 = 9;
int enb = 10;

//controll unit
int maxSpeed = 255;//The maximum PWM value to run the motor
int duration = 250;//The function will execute for more time after the signal is stoped.

//Directional functions

void front(){
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, maxSpeed);

  //MOTOR_B COUNTERCLOCKWISE MAX SPEED
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enb, maxSpeed);

  delay(duration);
}

void back(){
  //MOTOR_A COUNTERCLOCKWISE MAX SPEED
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena, maxSpeed);

  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, maxSpeed);

  delay(duration);
}

void left(){
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, maxSpeed);
  
  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, maxSpeed);

  delay(duration);
}

void right(){
  //MOTOR_A COUNTERCLOCKWISE MAX SPEED
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena, maxSpeed);

  //MOTOR_B COUNTERCLOCKWISE MAX SPEED
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enb, maxSpeed);

  delay(duration);
}

void stop(){
  //STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(duration);
}

void setup() {

  //Pin setup of all the motors
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Serial begin to recive from BT module 
  Serial.begin(9600);

}

void loop() {

  if(Serial.available()>0){
    char info = Serial.read();
    switch(info){
      case '1': front();
                break;
      case '2': back();
                break;
      case '3': right();
                break;
      case '4': left();
                break; 
      default : stop();                                       
    }
  }
  else
    stop();
}
