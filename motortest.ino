
#define IN1 4
#define IN2  3
#define IN3 8
#define IN4 12

#define leftSpeed 100
#define rightSpeed 100


//直走
void line()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void back()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  delay(100);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  //analogWrite(ENA,rightSpeed);
  //analogWrite(ENB,leftSpeed);
}
//右转
void turnRight()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  delay(100);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}
//左转
void turnLeft()
{
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(100);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
//制动
void stopp()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);
  //analogWrite(ENA,rightSpeed);
  //analogWrite(ENB,leftSpeed); 
}


void IniMotor()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //pinMode(ENA,OUTPUT);
  //pinMode(ENB,OUTPUT);
}

void RunMotor() //run the motors
{
  int x;
  x=Serial.read();
  if(x=='1')
  {
    line();
    delay(100);
  }
  if(x=='2')
  {
    turnRight();
    delay(100);
  }
  if(x=='3')
  {
    turnLeft();
    delay(100);
  }
  if(x=='4')
  {
    stopp();
    delay(100);
  if(x=='5')
  {
    back();
    delay(100);
  }
  }
}


void setup() {
  IniMotor();
  Serial.begin(9600);

}

void loop() {
  RunMotor();

}
