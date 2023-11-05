const int LDR = A0;
const int BUTTON = 4;
const int TOGGLE = 5;
const int FAN = 14;

const int RGB[] = {15,12,13};
const int RED = RGB[0];
const int GREEN = RGB[1];
const int BLUE = RGB[2];

int Mode[] = {1,0,0};
int normal = Mode[0];
int fast = Mode[1];
int full = Mode[2];

const int LDR_limit = 200;
const int LDR_limit_min = 150;

void setup() 
{
    Serial.begin(9600);
    pinMode(LDR, INPUT);
    pinMode(TOGGLE, INPUT);
    pinMode(BUTTON, INPUT);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(FAN,OUTPUT);

}

void loop()
{    
    int button_press;
    int LED_number;
    int LDR_value;
    int auto_manual;
    
    auto_manual = digitalRead(TOGGLE);
    delay(200);

     Serial.println(auto_manual);

    LDR_value = analogRead(LDR);
    delay(200);

if((LDR_value > LDR_limit) && auto_manual == 0)
{ 
    Serial.println("In Automatic");
    button_press = digitalRead(BUTTON);
    delay(500);
    if(button_press == 0)
      { 
      if(Mode[0]==1)
        {
          Mode[0] = 0;
          Mode[1] = 1;
          Mode[2] = 0; 
        }else if(Mode[1]==1)
        {
          Mode[0] = 0;
          Mode[1] = 0;
          Mode[2] = 1; 
        }else if(Mode[2]==1)
        {
          Mode[0] = 1;
          Mode[1] = 0;
          Mode[2] = 0; 
        }
        
      }
    analogWrite(RGB[0], 0);
    analogWrite(RGB[1], 0);
    analogWrite(RGB[2], 0);
    for(int i=0; i<3;++i)
        {
          if(Mode[i]==1)
            LED_number = i;
        }
    analogWrite(RGB[LED_number], 254);
  
    //Normal Mode
    if(Mode[0] == 1)
    {
        analogWrite(FAN, 50);
        delay(2000);
        analogWrite(FAN, 0); 
        delay(500); 
    }

     if(Mode[1] == 1)
    {
        analogWrite(FAN, 200);
        delay(2000);
        analogWrite(FAN, 0); 
        delay(500);  
    }

     if(Mode[2] == 1)
    {
        analogWrite(FAN, 255);
        delay(2500);
    }
}

if(auto_manual == 1)
{
    Serial.println("In Manual");
    button_press = digitalRead(BUTTON);
    delay(500);
    if(button_press == 0)
      { 
      if(Mode[0]==1)
        {
          Mode[0] = 0;
          Mode[1] = 1;
          Mode[2] = 0; 
        }else if(Mode[1]==1)
        {
          Mode[0] = 0;
          Mode[1] = 0;
          Mode[2] = 1; 
        }else if(Mode[2]==1)
        {
          Mode[0] = 1;
          Mode[1] = 0;
          Mode[2] = 0; 
        }
        
      }
    analogWrite(RGB[0], 0);
    analogWrite(RGB[1], 0);
    analogWrite(RGB[2], 0);
    for(int i=0; i<3;++i)
        {
          if(Mode[i]==1)
            LED_number = i;
        }
    analogWrite(RGB[LED_number], 254);
  
    //Normal Mode
    if(Mode[0] == 1)
    {
        analogWrite(FAN, 50);
        delay(2000);
        analogWrite(FAN, 0); 
        delay(500); 
    }

     if(Mode[1] == 1)
    {
        analogWrite(FAN, 200);
        delay(2000);
        analogWrite(FAN, 0); 
        delay(500);  
    }

     if(Mode[2] == 1)
    {
        analogWrite(FAN, 255);
        delay(2500);
    }
    
}


LDR_value = analogRead(LDR);
delay(200);

if((LDR_value < LDR_limit_min)&& auto_manual == 0)
    {
        analogWrite(FAN, 0);
        analogWrite(RGB[0], 0);
        analogWrite(RGB[1], 0);
        analogWrite(RGB[2], 0);
        ESP.deepSleep(5e6);
    }

}
