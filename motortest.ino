#include <Servo.h>

#define IN1 4
#define IN2 3
#define IN3 8
#define IN4 12
Servo servohand1;
Servo servohand2;
Servo servohead;
Servo servoclaw;
int r;
int h;


#define leftSpeed 100
#define rightSpeed 100

//电机初始化
void IniMotor()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //pinMode(ENA,OUTPUT);
  //pinMode(ENB,OUTPUT);
}

//舵机初始化
void iniServo()
{
  servoclaw.attach(3);
  servohand2.attach(5);
  servohead.attach(6);
  servohead.attach(9);
  servohand1.write(90);
  servohand2.write(90);
  servohead.write(90);
  servoclaw.write(90);
  
}
//直走
void line()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
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
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  //analogWrite(ENA,rightSpeed);
  //analogWrite(ENB,leftSpeed); 
}

//拾起
void pickup()
{
    int i = servohand1.read();
    for(i;i<=160;i++)
    {
        servohand1.write(i);
        delay(30);
    } 
    int j = servohand2.read();
    for(j;j>=78;j--)
    {
        servohand2.write(j);
        delay(30);
    }
    int k = servoclaw.read();
    for(k;k>=0;k--)
    {
        servoclaw.write(k);
        delay(30);
    }
}

//放下
void putdown()
{
    int i = servohand1.read();
    for(i;i<=160;i++)
    {
        servohand1.write(i);
        delay(30);
    } 
    int j = servohand2.read();
    for(j;j<=180;j++)
    {
        servohand2.write(j);
        delay(30);
    }
    int k = servoclaw.read();
    for(k;k>=150;k--)
    {
        servoclaw.write(k);
        delay(30);
    }
}

//机械臂转向左
void switchleft()
{
    int p = servohead.read();
    int q = p-15;
    for(p;p>=q;p--)
    {
        servohead.write(p);
        delay(30);
    }
}

//机械臂转向右
void switchright()
{
    int p = servohead.read();
    int q = p+15;
    for(p;p<=q;p++)
    {
        servohead.write(p);
        delay(30);
    }
}


void RunMotor() //run the motors
{
  unsigned  char x;
  if(Serial.available())
  {x=Serial.read();
  switch(x)
  {
    case 0:
          line();
          break;
    case 1:
          turnRight();
          break;

    case 2:
          turnLeft();
          break;
    case 3:
          stopp();
          break;
    case 4:
          pickup();
          break;
    case 5:
          putdown();
          break;
    case 6:
          switchleft();
          break;
    case 7:
          switchright();
          break;
  }
  }
}


void setup() {
  IniMotor();
  Serial.begin(9600);
  iniServo();
}

void loop() {
  if(Serial.available())
  {
    r = Serial.read();
    if(r!=-1){
      h=r;
    }
    switch(h)
    {
      
    }
  }

}
