//Mux control pins
int s0 = 8;
int s1 = 9;
int s2 = 10;
int s3 = 11;

//Mux in “SIG” pin
int SIG_pin = 0;

void setup(){
pinMode(s0, OUTPUT);
pinMode(s1, OUTPUT);
pinMode(s2, OUTPUT);
pinMode(s3, OUTPUT);

digitalWrite(s0, LOW);
digitalWrite(s1, LOW);
digitalWrite(s2, LOW);
digitalWrite(s3, LOW);

Serial.begin(9600);
}

void loop(){

//Loop through and read all 16 values
//Reports back Value at channel 6 is: 346

// ar## : #-# 
int ar24 = analogRead(A1);
int ar25 = analogRead(A2);
int ar34 = analogRead(A3);
int ar35 = analogRead(A4);
int ar33 = analogRead(A5);
int ar45 = analogRead(A6);
int ar44 = analogRead(A7);
int ar55 = analogRead(A8);
int ar54 = analogRead(A9);
int ar43 = analogRead(A10);
int ar53 = analogRead(A11);
int ar52 = analogRead(A12);
int ar51 = analogRead(A13);
int ar42 = analogRead(A14);
int ar41 = analogRead(A15);
int ar32 = readMux(0);
int ar31 = readMux(1);
int ar21 = readMux(2);
int ar22 = readMux(3);
int ar11 = readMux(4);
int ar12 = readMux(5);
int ar13 = readMux(6);
int ar23 = readMux(7);
int ar14 = readMux(8);
int ar15 = readMux(9);



Serial.println("============================");
Serial.print(ar11); Serial.print("    ");
Serial.print(ar12); Serial.print("    ");
Serial.print(ar13); Serial.print("    ");
Serial.print(ar14); Serial.print("    ");
Serial.print(ar15); Serial.println("    ");
Serial.print(ar21); Serial.print("    ");
Serial.print(ar22); Serial.print("    ");
Serial.print(ar23); Serial.print("    ");
Serial.print(ar24); Serial.print("    ");
Serial.print(ar25); Serial.println("    ");
Serial.print(ar31); Serial.print("    ");
Serial.print(ar32); Serial.print("    ");
Serial.print(ar33); Serial.print("    ");
Serial.print(ar34); Serial.print("    ");
Serial.print(ar35); Serial.println("    ");
Serial.print(ar41); Serial.print("    ");
Serial.print(ar42); Serial.print("    ");
Serial.print(ar43); Serial.print("    ");
Serial.print(ar44); Serial.print("    ");
Serial.print(ar45); Serial.println("    ");
Serial.print(ar51); Serial.print("    ");
Serial.print(ar52); Serial.print("    ");
Serial.print(ar53); Serial.print("    ");
Serial.print(ar54); Serial.print("    ");
Serial.print(ar55); Serial.println("    ");
Serial.println("============================");
delay(1000);
 
  }
  
  int readMux(int channel)  { 
  int controlPin[] = {s0, s1, s2, s3}; 
  int muxChannel[16][4]={ {0,0,0,0},  
  {1,0,0,0}, //channel 1 
  {0,1,0,0}, //channel 2 
  {1,1,0,0}, //channel 3 
  {0,0,1,0}, //channel 4 
  {1,0,1,0}, //channel 5 
  {0,1,1,0}, //channel 6 
  {1,1,1,0}, //channel 7 
  {0,0,0,1}, //channel 8 
  {1,0,0,1}, //channel 9 
  {0,1,0,1}, //channel 10 
  {1,1,0,1}, //channel 11 
  {0,0,1,1}, //channel 12 
  {1,0,1,1}, //channel 13 
  {0,1,1,1}, //channel 14 
  {1,1,1,1} //channel 15 
  }; 
  //loop through the 4 sig 
  for(int i = 0; i < 4; i ++){ 
    digitalWrite(controlPin[i], muxChannel[channel][i]); 
    } 
    //read the value at the SIG pin 
    int val = analogRead(SIG_pin); //return the value 
    return val; 
    } 
