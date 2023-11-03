// 4 way traffic lights 
//The mapping matches the thinkercad diagram

// intersection A
#define AG1A 8
#define AG1B 13
#define AY1A 9
#define AY1B 12
#define AR1A 10
#define AR1B 11

// intersection B
#define BG1A 2
#define BG1B 7
#define BY1A 3
#define BY1B 6
#define BR1A 4
#define BR1B 5
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(0, OUTPUT);
}


void loop()
{
  //stage1
  digitalWrite(AR1A, LOW);
  digitalWrite(AR1B, LOW);
  digitalWrite(AG1A, HIGH);
  digitalWrite(AG1B, HIGH);
  digitalWrite(BR1A, HIGH);
  digitalWrite(BR1B, HIGH);
  delay(5000);
  //stage2
  digitalWrite(AG1A, LOW);
  digitalWrite(AG1B, LOW);
  digitalWrite(AY1A, HIGH);
  digitalWrite(AY1B, HIGH);
  delay(2000);
  //stage3
  digitalWrite(AY1A, LOW);
  digitalWrite(AY1B, LOW);
  digitalWrite(AR1A, HIGH);
  digitalWrite(AR1B, HIGH);
  delay(1000);
  //stage4
  digitalWrite(BR1A, LOW);
  digitalWrite(BR1B, LOW);
  digitalWrite(BG1A, HIGH);
  digitalWrite(BG1B, HIGH);
  delay(5000);
  //stage5
  digitalWrite(BG1A, LOW);
  digitalWrite(BG1B, LOW);
  digitalWrite(BY1A, HIGH);
  digitalWrite(BY1B, HIGH);
  delay(2000);
  //stage6
  digitalWrite(BY1A, LOW);
  digitalWrite(BY1B, LOW);
  digitalWrite(BR1A, HIGH);
  digitalWrite(BR1B, HIGH);
  delay(1000);
  

}