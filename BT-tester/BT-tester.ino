/*
  Programmer: Mohammad Afeef
  Code to test the working of an HC 05 module.
  Upload the code to the nano.
  connect Rx pin of the module to Tx pin of nano.
  connect Tx pin of the module to Rx pin of nano.
  connect the GND and VCC pins.
*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char info = Serial.read();
    Serial.println(info);
  }
}
