#include<LiquidCrystal.h>
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define sw1 10
#define sw2 9
#define sw3 8
#define sw4 7
#define sw5 6
#define swclose 13
 int vote1=0;
 int vote2=0;
 int vote3=0;
 //int vote4=0;
 int totvote=0;
 void CalcResult(int vote1,int vote2,int vote3){
  int vote=vote1+vote2+vote3;
      if(vote)
      {
       if((vote1 > vote2 && vote1 > vote3 ))
       {
        lcd.clear();
        lcd.print("BJP Wins");
        delay(2000);
        lcd.clear();
       }
       else if((vote2 > vote1 && vote2 > vote3 ))
       {
        lcd.clear();
        lcd.print("INC Wins");
        delay(2000);
        lcd.clear();
       }
       else if((vote3 > vote1 && vote3 > vote2 ))
       {
        lcd.clear();
        lcd.print("AAP Wins");
        delay(2000);
        lcd.clear();
       }
     
      
      else
      {
        lcd.clear();
        lcd.print("   Tie Up    ");
        lcd.setCursor(0,1);
        //lcd.print("   No Result   ");
        delay(1000);
        lcd.clear();
      }
      
     }      
      else 
      {
        lcd.clear();
        lcd.print("No Voting....");
        delay(1000);
        lcd.clear();
      }
      vote1=0;vote2=0;vote3=0;vote=0;
 }
 void setup()
 {
  
   pinMode(sw1, INPUT);
   pinMode(sw2,INPUT);
   pinMode(sw3,INPUT);
   pinMode(sw4,INPUT);
   pinMode(sw5,INPUT);
   pinMode(swclose,INPUT);  
   lcd.begin(16, 2);
   lcd.print("Voting Machine");
   lcd.setCursor(0,1);
   lcd.print("Mudit Maheshwari");
   delay(3000);
   digitalWrite(sw1, HIGH);
   digitalWrite(sw2, HIGH);
   digitalWrite(sw3, HIGH);
   digitalWrite(sw4, HIGH);
   digitalWrite(sw5, HIGH);
   digitalWrite(swclose,HIGH);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("BJP");
   lcd.setCursor(4,0);
   lcd.print("INC");
   lcd.setCursor(8,0);
   lcd.print("AAP");
  
 }
 void loop()
 {
   lcd.setCursor(0,0);
   lcd.print("BJP");
   lcd.setCursor(1,1);
   lcd.print(vote1);
   lcd.setCursor(4,0);
   lcd.print("INC");
   lcd.setCursor(5,1);
   lcd.print(vote2);
   lcd.setCursor(8,0);
   lcd.print("AAP");
    lcd.setCursor(9,1);
   lcd.print(vote3);
 
   if(digitalRead(sw1)==0)
     vote1++;
    // totvote++;
     while(digitalRead(sw1)==0);
   if(digitalRead(sw2)==0)
     vote2++;
    while(digitalRead(sw2)==0);
   if(digitalRead(sw3)==0)
     vote3++;
    while(digitalRead(sw3)==0);
   /*computing result*/
    if(digitalRead(sw4)==0)
    {
      CalcResult(vote1,vote2,vote3);
      lcd.clear();
    }
 if(digitalRead(sw5)==0)
{
      totvote=vote1+vote2+vote3;
      if(totvote){
      lcd.clear();
      lcd.print("Total votes");
     lcd.setCursor(0,1);
      lcd.print(totvote);
      delay(1000);
      lcd.clear();    
}}
 if(digitalRead(swclose)==0)
{
      lcd.clear();
      CalcResult(vote1,vote2,vote3);
      lcd.print("Voting Closed");
      delay(200000);
      lcd.clear();    
}
}   
   

