const int buttonPin = 2;     
const int ledPin =  13;      
volatile int buttonState = 0;     
void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(0, pin_ISR, CHANGE);
//3 vectors: 1st denotes vector corresponding to pins of arduino which can perform interrupt function ,0 for pin 2 and 1 for pin 3;
//2nd is interrupt service routine name;
//3rd is based on what its performing interrupt
}

void loop() 
{

}
void pin_ISR() //interrupt service routine
{
  buttonState = digitalRead(buttonPin);
  digitalWrite(ledPin, buttonState);
}
