int delayTime = 900;
int digit1 = 2;
int digit2 = 3;
int digit3 = 4;
int digit4 = 5;

//Segment pins
int segA = 6;
int segB = 7;
int segC = 9;
int segD = 10;
int segE = 11;
int segF = 12;
int segG = 8;

int buttonPin = 14; //it's A0 but we are using it as a digital input, 13+1
int powerPin = 15; //it's A1 but we are using it as a digital input, 14+1

unsigned long StartTime;

int buttonState = 0; //current state of the button
int lastButtonState = 0; //last state
int buttonCounter = 0; //push counter
unsigned long ElapsedTime;

void setup()
{
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  delay(1000);
  StartTime = millis();
  Serial.begin(9600);
  Serial.println("Start");
  pinMode(powerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  ElapsedTime = millis() - StartTime;
}

void loop()
{
  digitalWrite(powerPin, HIGH);
  if(buttonCounter != 1)
  {
    ElapsedTime = millis() - StartTime;
  }
  DisplayNumber(ElapsedTime);
  
  buttonState = digitalRead(buttonPin);
  if(buttonState != lastButtonState)
  {
    if(buttonState == HIGH)
     {
       buttonCounter++;
       lastButtonState = buttonState;
       //Serial.println(buttonCounter);
       delay(50);
     } 
     
  }
  Serial.println(buttonState);
}

void DisplayNumber(int n)
{
  int dividers[4] = {
    1000, 100, 10, 1      };
  int results[4] = {
    0, 0, 0, 0      };
  for(int i = 0; i < 4; i++) //there are 4 digits
  {
    results[i] = n / dividers[i];
    n %= dividers[i];
  }

  digitalWrite(digit1, LOW);
  sendDigit(results[0]);
  delayMicroseconds(delayTime);

  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, LOW);
  sendDigit(results[1]);
  delayMicroseconds(delayTime);

  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, LOW);
  sendDigit(results[2]);
  delayMicroseconds(delayTime);

  digitalWrite(digit3, HIGH);
  digitalWrite(digit4, LOW);
  sendDigit(results[3]);
  delayMicroseconds(delayTime);
  digitalWrite(digit4, HIGH);
}

void sendDigit(int x)
{
  switch (x) {
  case 1:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;
  case 2:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, LOW);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;
  case 3:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;
  case 4:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  case 5:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  case 6:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  case 7:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;
  case 8:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  case 9:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  case 0:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, LOW);
    break;
  default:
    break;
  }
}



