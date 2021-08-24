//YouTube|Tech at Home

// motor right
int in1 = 2;
int in2 = 3;
int enable1 = 4;  // pin with ~ symbol

int channel_2 = 5;  // pin with ~ symbol

// motor left
int in3 = 6;
int in4 = 7;
int enable2 = 8;  // pin with ~ symbol

int channel_3 = 9;  // pin with ~ symbol
void setup()
{
// motor right  
  pinMode(channel_2, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enable1, OUTPUT);
// motor left
  pinMode(channel_3, INPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enable2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
  int pwm = 0;
  int pwm2 = 0;
  // motor right
  int value = pulseIn(channel_2, HIGH, 25000);
  // motor left
  int value2 = pulseIn(channel_3, HIGH, 25000);
  if((value==0)&&(value2==0))        
  {
// motor right  
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enable1, 0);      
// motor left
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enable2, 0);  
  }
 
  else if((value > 1530)&&(value2 > 1530))
  {
      pwm = map(value, 1530, 2000, 0, 255);      
      // motor right
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enable1, pwm);  
      pwm2 = map(value2, 1530, 2000, 0, 255);
      // motor left
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enable2, pwm2);        
  }  

  else if((value > 1530)&&(value2 < 1460))
  {
      pwm = map(value, 1530, 2000, 0, 255);      
      // motor right
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enable1, pwm);  
      pwm2 = map(value2, 1460, 1000, 0, 255);
      // motor left
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enable2, pwm2);  
  }

  else if((value < 1460)&&(value2 > 1530))
  {
      pwm = map(value, 1460, 1000, 0, 255);      
      // motor right
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enable1, pwm);  
      pwm2 = map(value2, 1530, 2000, 0, 255);
      // motor left
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enable2, pwm2);  
  }
 
  else if((value < 1460)&&(value2 < 1460))
  {
      pwm = map(value, 1460, 1000, 0, 255);
      // motor right      
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enable1, pwm);
      pwm2 = map(value2, 1460, 1000, 0, 255);
      // motor left
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enable2, pwm2);            
  }
 
  else
  {
// motor right    
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enable1, 0);
// motor left      
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enable2, 0);      
  }
 
  delay(10);
}
