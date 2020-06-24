int motorA_en = 16; //D0
int motorA1 = 5;    //D1
int motorA2 = 4;    //D2
int motorB_en = 14; //D5
int motorB1 = 12;   //D6
int motorB2 = 13;   //D7
int speed_A = 600;  //Speed of motor A, 0-1023
int speed_B = 600;  //Speed of motor B, 0-1023
bool motorA1_state;
bool motorA2_state;
bool motorB1_state;
bool motorB2_state;
int serial_input = 5;

void setup()
{
  pinMode(motorA_en, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB_en, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    serial_input = Serial.parseInt();
    if (serial_input != 0)
    {
      Serial.println(serial_input);
    }
  }
  switch (serial_input)
  {
    case 1:  //Forward
      Serial.println("Forward");
      motorA1_state = HIGH;
      motorA2_state = LOW;
      motorB1_state = HIGH;
      motorB2_state = LOW;
      break;

    case 2:  //Backward
      Serial.println("Backward");
      motorA1_state = LOW;
      motorA2_state = HIGH;
      motorB1_state = LOW;
      motorB2_state = HIGH;
      break;

    case 3:  //CW
      Serial.println("CW");
      motorA1_state = LOW;
      motorA2_state = HIGH;
      motorB1_state = HIGH;
      motorB2_state = LOW;
      break;
      
    case 4:  //CCW
      Serial.println("CCW");
      motorA1_state = HIGH;
      motorA2_state = LOW;
      motorB1_state = LOW;
      motorB2_state = HIGH;
      break;

    case 5:  //Full Stop
      Serial.println("Full Stop");
      motorA1_state = LOW;
      motorA2_state = LOW;
      motorB1_state = LOW;
      motorB2_state = LOW;
      break;

  }
  analogWrite(motorA_en, speed_A);
  digitalWrite(motorA1, motorA1_state);
  digitalWrite(motorA2, motorA2_state);
  analogWrite(motorB_en, speed_B);
  digitalWrite(motorB1, motorB1_state);
  digitalWrite(motorB2, motorB2_state);

  delay(1000);

}
