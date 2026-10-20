// Required libraries
#include <Arduino.h>

// LED Pins
int led1 = 2;
int led2 = 3;
int led3 = 5;
int led4 = 6;
int led5 = 9;
int led6 = 10;

// Button Pin
int btn = 8;
int btn_data, led_state, prev_btn_data;

int i = 0;

int i1 = 0;
int i2 = 0;
int i3 = 0;
int i4 = 0;
int i5 = 0;
int i6 = 0;

int direction = 1;
int start = 1;

// Main Function *************************************
void setup() {
  // Connect
  Serial.begin(9600);
  while (!Serial);    

  // Output
  Serial.println("MYCROMARS");
  Serial.println("LED Series");

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  pinMode(btn, INPUT_PULLUP);
}

void loop() {
  // assign: Button input (press: HIGH)
  btn_data = digitalRead(btn);

  // Statement: Button
  if(btn_data == LOW && btn_data != prev_btn_data)
  {
    // true/false
    led_state = !led_state;

    if (led_state == 1){
      Serial.println("ON");
     //Serial.println(led_state);
    }
    else if (led_state == 0){
      Serial.println("OFF");
      //Serial.println(led_state);
    }
    
  }

if (led_state == true)
{

  if (direction == 1){
     i++;
     if (i == 6){
      direction = 0;
      start = 0;
     }
  }
  else {
     i--;
      if (i == 1){
      direction = 1;
     }
  }

  switch (i)
  {
    case 1:
      i1 = 250;
      i2 = 0; 
      i3 = 0;
      break;

    case 2:
      if (direction == 1){i1 = 10;}
      i2 = 250;
      if (direction == 0){i3 = 10; i4 = 0;}
      break;

    case 3:
      i1 = 0;
      if (direction == 1){i2 = 10;}
      i3 = 250;
      if (direction == 0){i4 = 10; i5 = 0;}
      break;

    case 4:
      i2 = 0;
      if (direction == 1){i3 = 10;}
      i4 = 250;
      if (direction == 0){i5 = 10; i6 = 0;}
      break;

    case 5:
      i3 = 0;
      if (direction == 1){i4 = 10;}
      i5 = 250;
      if (direction == 0){i6 = 10;}
      break;

    case 6:
      i4 = 0;
      i5 = 0;
      i6 = 250;
      break;

      default: 
        i1 = 0;
        i2 = 0;
        i3 = 0;
        i4 = 0;
        i5 = 0;
        i6 = 0;
    }
  delay(200);
 }
 else{
    i1 = 0;
    i2 = 0;
    i3 = 0;
    i4 = 0;
    i5 = 0;
    i6 = 0;
 }

   // LED on/off
  analogWrite(led1, i1);
  analogWrite(led2, i2);
  analogWrite(led3, i3);
  analogWrite(led4, i4);
  analogWrite(led5, i5);
  analogWrite(led6, i6);
 
  // Assign: LOW/HIGH
  prev_btn_data = btn_data;

  if (i == 1 & start == 0){
    delay(100);
  }
  else if (i == 6 ){
    delay(100);
  }

  delay(10);
}