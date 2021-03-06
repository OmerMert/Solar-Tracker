#include<Servo.h>

Servo servoT;
int angleservoT = 90;

Servo servoB;
int angleservoB = 90;

// LDR pin connections
int ldrTR = A0; // Top-right LDR
int ldrTL = A1; // Top-left LDR
int ldrBL = A2; // Bottom-right LDR
int ldrBR = A3; // Bottom-right LDR

void setup() 
{
  // servo connections
  servoT.attach(5);
  servoB.attach(6);
}

void loop() 
{
 
  int TR= analogRead(ldrTR);  // Top-right
  int TL= analogRead(ldrTL);  // Top-left
  int BL= analogRead(ldrBL);  // Bottom-right
  int BR= analogRead(ldrBR);  // Bottom-left

  int avTOP = (TL+TR)/2;  // average value top
  int avBOTTOM = (BL+BR)/2; // average value bottom
  int avLEFT = (BL+TL)/2; // average value left
  int avRIGHT = (BR+TR)/2;// average value right

  int dservoTOP = avTOP - avBOTTOM; // check the diffirence of top and bottom
  int dservoBOTTOM = avLEFT - avRIGHT;  // check the diffirence of left and rigt
  
   if (-100> dservoTOP  || dservoTOP > 100)
   {
   if( avTOP > avBOTTOM)
        {
        angleservoT--;
        if(angleservoT > 180)
           {
             angleservoT=180;
           }
        }
     else if(avBOTTOM > avTOP)
     {
        angleservoT++;
        if(angleservoT < 0)
        {
          angleservoT=0;
        }
     } 
     servoT.write(angleservoT); 
   }

   if(-100 > dservoBOTTOM || dservoBOTTOM > 100)
   {
    if(avRIGHT > avLEFT)
    {
      angleservoB++;
      if(angleservoB > 180)
        angleservoB=180;
    }
    else if(avLEFT>avRIGHT)
    {
      angleservoB--;
      if(angleservoB < 0)
        angleservoB=0;
    }
    servoB.write(angleservoB);
   }
  
  delay(20); 
}