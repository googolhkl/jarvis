
#define motor1_Pin1 2
#define motor1_Pin2 3
#define motor2_Pin1 4
#define motor2_Pin2 5
#define motor3_Pin1 6
#define motor3_Pin2 7
#define motor4_Pin1 8
#define motor4_Pin2 9
#define motor5_Pin1 10
#define motor5_Pin2 11
#define LED 12

#define motor1_f 48
#define motor1_r 49
#define motor2_f 50
#define motor2_r 51
#define motor3_f 52
#define motor3_r 53
#define motor4_f 54
#define motor4_r 55
#define motor5_f 56
#define motor5_r 57




class Motor
{
	private:
		int Pin1;
		int Pin2;
	public:
		Motor(int,int);
		int GetPin1() const;
		int GetPin2() const;
		void SetMotor(bool);
		void SetPin();
};



Motor shoulder_r(motor1_Pin1,motor1_Pin2);
Motor shoulder_c(motor2_Pin1,motor2_Pin2);
Motor elbow(motor3_Pin1,motor3_Pin2);
Motor wrist(motor4_Pin1,motor4_Pin2);
Motor finger(motor5_Pin1,motor5_Pin2);
// ex) 10= select motor1 and direction forward , 11= select motor1 and direction reverse
//     31= select motor3 and direction reverse , 30= select motor3 and direction forward
int motor_select;

// ***********************************************************************************
void setup()
{
  Serial.begin(9600);
  shoulder_r.SetPin();
  shoulder_c.SetPin();
  elbow.SetPin();
  wrist.SetPin();
  finger.SetPin();
}

void loop()
{
  if(Serial.available())
  {
      motor_select= Serial.read();
      Serial.println(motor_select);
  }
  

  if(motor1_f==motor_select)
  {
  shoulder_r.SetMotor(true);
  motor_select=0;
  }

  else if(motor1_r==motor_select)
  {
   shoulder_r.SetMotor(false);
   motor_select=0;
  }
  else if(motor2_f==motor_select)
  {
   shoulder_c.SetMotor(true);
   motor_select=0;
  }
  else if(motor2_r==motor_select)
  {
    shoulder_c.SetMotor(false);
    motor_select=0;
  }
  else if(motor3_f==motor_select)
  {
    elbow.SetMotor(true);
    motor_select=0;
  }
  else if(motor3_r==motor_select)
  {
    elbow.SetMotor(false);
    motor_select=0;
  }
  else if(motor4_f==motor_select)
  {
    wrist.SetMotor(true);
    motor_select=0;
  }
  else if(motor4_r==motor_select)
  {
    wrist.SetMotor(false);
    motor_select=0;
  }
  else if(motor5_f==motor_select)
  {
    finger.SetMotor(true);
    motor_select=0;
  }
  else if(motor5_r==motor_select)
  {
    finger.SetMotor(false);
    motor_select=0;
  }
  else
  {
  }


   
}

// ***********************************************************************************


Motor::Motor(int Pin1=0,int Pin2=0)
	:Pin1(Pin1), Pin2(Pin2)
{
	//empty
}

int Motor::GetPin1() const
{
	//printf("%d\n",Pin1);
	
}

int Motor::GetPin2() const
{
	//printf("%d\n",Pin2);
}

void Motor::SetPin(void)
{
	pinMode(Pin1,OUTPUT);
	pinMode(Pin2,OUTPUT);
}

void Motor::SetMotor(bool reverse)
{

	if(reverse)
	{
		digitalWrite(Pin1,0);
		digitalWrite(Pin2,1);
		delay(1000);
		digitalWrite(Pin1,0);
		digitalWrite(Pin2,0);
		
	}

	else
	{
		digitalWrite(Pin1,1);
		digitalWrite(Pin2,0);
		delay(1000);
		digitalWrite(Pin1,0);
		digitalWrite(Pin2,0);
		
	}
}
