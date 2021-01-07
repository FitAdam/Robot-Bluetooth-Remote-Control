
class DCMotors{
  
  int _IN1;
  int _IN2;
  int _IN3;
  int _IN4;

  int tempo;
  
 public:
  DCMotors(int IN1, int IN2, int IN3, int IN4){
    _IN1 = IN1;
    _IN2 = IN2;
    _IN3 = IN3;
    _IN4 = IN4;
  // pin modes for dc motors
    pinMode(_IN1, OUTPUT);
    pinMode(_IN2, OUTPUT);
    pinMode(_IN3, OUTPUT);
    pinMode(_IN4, OUTPUT);
  }


// functions for dc motors
void Forward(int tempo)
{
  digitalWrite(_IN1, LOW);
  analogWrite(_IN2, tempo);
  digitalWrite(_IN3, LOW);
  analogWrite(_IN4, tempo);
}

void Reverse(int tempo)
{
  analogWrite(_IN1, tempo);
  digitalWrite(_IN2, LOW);

  analogWrite(_IN3, tempo);
  digitalWrite(_IN4, LOW);

}

void Stop()
{
  digitalWrite(_IN1, LOW);
  digitalWrite(_IN2, LOW);


  digitalWrite(_IN3, LOW);
  digitalWrite(_IN4, LOW);

}

void Left(int tempo)
{
  digitalWrite(_IN1, LOW);
  analogWrite(_IN2, tempo);

  analogWrite(_IN3, tempo);
  digitalWrite(_IN4, LOW);

}

void Right(int tempo)
{ 
  analogWrite(_IN1, tempo);
  digitalWrite(_IN2, LOW);
  
  digitalWrite(_IN3, LOW);
  analogWrite(_IN4, tempo);

}

};
