enum display0 {a0 = 2, b0, c0, d0, e0, f0, g0};
enum display1 {a1 = 9, b1, c1, d1, e1, f1, g1};
int display0Pos = 0;
int display1Pos = 1;
int timeCounter = 0;
int co0 = 0;
int co1 = 0;
//HELLO AT328P
void int0()//backwards
{
  co0++;
  Serial.println(co0);
  disableTimer();
  updatePosBackwards();
  setDisplay0(-1);
  setDisplay1(-1);
  setDisplay0(display0Pos);
  setDisplay1(display1Pos);
  enableTimer();
  timeCounter = 0;
}
void int1()//forward
{
  co1++;
  Serial.println(co1);
  disableTimer();
  updatePosForward();
  setDisplay0(-1);
  setDisplay1(-1);
  setDisplay0(display0Pos);
  setDisplay1(display1Pos);
  enableTimer();
  timeCounter = 0;
}
void setup()
{
  Serial.begin(9600);
  for (int i = 2; i <= 15; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  attachInterrupt(digitalPinToInterrupt(21), int0, RISING);
  attachInterrupt(digitalPinToInterrupt(20), int1, RISING);
  enableTimer();
  setDisplay0(-1);
  setDisplay1(-1);
}

ISR(TIMER1_OVF_vect)
{
  TCNT1 = 3036;
  timeCounter++;
  if(timeCounter == 2)
  {
  //Serial.println(display0Pos);
  //Serial.println(display1Pos);
    timeCounter = 0;
    updatePosForward();
    setDisplay0(-1);
    setDisplay1(-1);
    setDisplay0(display0Pos);
    setDisplay1(display1Pos);
  }
}

void loop()
{
}

void enableTimer()
{
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 3036;// inicia o contador com 3036
  TCCR1B |= (1<<CS12); //ativa prescaler de x256
  TIMSK1 |= (1<<TOIE1); //ativa o overflow counter do TCCR1
}

void disableTimer()
{
  TIMSK1 |= (1<<TOIE1);
}

void updatePosForward()
{
  display0Pos++;
  display1Pos++;
  if(display1Pos == 11)
  {
    display1Pos = 0;
  }
  if(display0Pos == 11)
  {
    display0Pos = 0;
  }
}

void updatePosBackwards()
{
  display0Pos--;
  display1Pos--;
  if(display1Pos == -1)
  {
    display1Pos = 10;
  }
  if(display0Pos == -1)
  {
    display0Pos = 10;
  }
}

void setDisplay0(int option)
{
  switch(option)
  {
    case 0 : //H
    {
      digitalWrite(f0, 0);
      digitalWrite(b0, 0);
      digitalWrite(g0, 0);
      digitalWrite(e0, 0);
      digitalWrite(c0, 0);
      break;
    }
    case 1 : //E
    {
      digitalWrite(a0, 0);
      digitalWrite(f0, 0);
      digitalWrite(g0, 0);
      digitalWrite(e0, 0);
      digitalWrite(d0, 0);
      break;
    }
    case 2 : //L
    {
      digitalWrite(f0, 0);
      digitalWrite(e0, 0);
      digitalWrite(d0, 0);
      break;
    }
    case 3 : //L
    {
      digitalWrite(f0, 0);
      digitalWrite(e0, 0);
      digitalWrite(d0, 0);
      break;
    }
    case 4 : //O
    {
      digitalWrite(f0, 0);
      digitalWrite(e0, 0);
      digitalWrite(d0, 0);
      digitalWrite(c0, 0);
      digitalWrite(b0, 0);
      digitalWrite(a0, 0);
      break;
    }
    case 5 : //A
    {
      digitalWrite(f0, 0);
      digitalWrite(e0, 0);
      digitalWrite(c0, 0);
      digitalWrite(b0, 0);
      digitalWrite(a0, 0);
      digitalWrite(g0, 0);
      break;
    }
    case 6 : //t
    {
      digitalWrite(f0, 0);
      digitalWrite(g0, 0);
      digitalWrite(e0, 0);
      digitalWrite(d0, 0);
      break;
    }
    case 7 : //3
    {
      digitalWrite(a0, 0);
      digitalWrite(b0, 0);
      digitalWrite(g0, 0);
      digitalWrite(c0, 0);
      digitalWrite(d0, 0);
      break;
    }
    case 8 : //2
    {
      digitalWrite(a0, 0);
      digitalWrite(b0, 0);
      digitalWrite(g0, 0);
      digitalWrite(e0, 0);
      digitalWrite(d0, 0);
      break;
    }
    case 9 : //8
    {
      for(int i = 2 ; i <= 8 ; i++)
        digitalWrite(i, 0);
      break;
    }
    case 10 : //P
    {
      digitalWrite(a0, 0);
      digitalWrite(b0, 0);
      digitalWrite(f0, 0);
      digitalWrite(g0, 0);
      digitalWrite(e0, 0);
      break;
    }
    default :
    case -1 : //reset
    {
      digitalWrite(a0, 1);
      digitalWrite(b0, 1);
      digitalWrite(c0, 1);
      digitalWrite(d0, 1);
      digitalWrite(e0, 1);
      digitalWrite(f0, 1);
      digitalWrite(g0, 1);
      break;
    }
  }
}

void setDisplay1(int option)
{
  switch(option)
  {
    case 0 : //H
    {
      digitalWrite(f1, 0);
      digitalWrite(b1, 0);
      digitalWrite(g1, 0);
      digitalWrite(e1, 0);
      digitalWrite(c1, 0);
      break;
    }
    case 1 : //E
    {
      digitalWrite(a1, 0);
      digitalWrite(f1, 0);
      digitalWrite(g1, 0);
      digitalWrite(e1, 0);
      digitalWrite(d1, 0);
      break;
    }
    case 2 : //L
    {
      digitalWrite(f1, 0);
      digitalWrite(e1, 0);
      digitalWrite(d1, 0);
      break;
    }
    case 3 : //L
    {
      digitalWrite(f1, 0);
      digitalWrite(e1, 0);
      digitalWrite(d1, 0);
      break;
    }
    case 4 : //O
    {
      digitalWrite(f1, 0);
      digitalWrite(e1, 0);
      digitalWrite(d1, 0);
      digitalWrite(c1, 0);
      digitalWrite(b1, 0);
      digitalWrite(a1, 0);
      break;
    }
    case 5 : //A
    {
      digitalWrite(f1, 0);
      digitalWrite(e1, 0);
      digitalWrite(c1, 0);
      digitalWrite(b1, 0);
      digitalWrite(a1, 0);
      digitalWrite(g1, 0);
      break;
    }
    case 6 : //t
    {
      digitalWrite(f1, 0);
      digitalWrite(g1, 0);
      digitalWrite(e1, 0);
      digitalWrite(d1, 0);
      break;
    }
    case 7 : //3
    {
      digitalWrite(a1, 0);
      digitalWrite(b1, 0);
      digitalWrite(g1, 0);
      digitalWrite(c1, 0);
      digitalWrite(d1, 0);
      break;
    }
    case 8 : //2
    {
      digitalWrite(a1, 0);
      digitalWrite(b1, 0);
      digitalWrite(g1, 0);
      digitalWrite(e1, 0);
      digitalWrite(d1, 0);
      break;
    }
    case 9 : //8
    {
      digitalWrite(g1, 0);
      for(int i = 9 ; i <= 15 ; i++)
        digitalWrite(i, 0);
      break;
    }
    case 10 : //P
    {
      digitalWrite(a1, 0);
      digitalWrite(b1, 0);
      digitalWrite(f1, 0);
      digitalWrite(g1, 0);
      digitalWrite(e1, 0);
      break;
    }
    default :
    case -1 : //reset
    {
      digitalWrite(a1, 1);
      digitalWrite(b1, 1);
      digitalWrite(c1, 1);
      digitalWrite(d1, 1);
      digitalWrite(e1, 1);
      digitalWrite(f1, 1);
      digitalWrite(g1, 1);
      break;
    }
  }
}
