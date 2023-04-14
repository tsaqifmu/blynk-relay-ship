#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define MotorKanan D5
#define MotorKiri D6

int flag=0;
boolean isButtonPressed=LOW;
int x=0;
int y=0;

BLYNK_WRITE(V0) {
   x = param[0].asInt();
   y = param[1].asInt();
 Serial.print("X = ");
 Serial.print(x);
 Serial.print("; Y = ");
 Serial.println(y);
 if ( x<800 && x>300 && y>900){
  digitalWrite(MotorKiri,HIGH);
  digitalWrite(MotorKanan,HIGH);
 }else  if( x>900 && y<800 && y>300)
  digitalWrite(MotorKanan,HIGH);
 else  if( x<100 && y<800 && y>300)
  digitalWrite(MotorKiri,HIGH);
 else 
 {
  digitalWrite(MotorKiri,LOW);
  // ==ini bawah== digitalWrite(Light2,LOW);
  digitalWrite(MotorKanan,LOW);
  //digitalWrite(Light4,LOW);
   }
}

// ==== Dapetin token =====
char auth[] = "t8HHT8tly0K3CSaFgIcqQdO9UCkXvG6I";
// ===== id dan password internet =======
char ssid[] = "antique";
char pass[] = "bismillah";

void setup(){
  Serial.begin(9600);
  
  //kalo pake serangkota jangan lupa ganti jadi
  Blynk.begin(auth, ssid, pass, "iot.serangkota.go.id", 8080);
  //Blynk.begin(auth, ssid, pass);
  //Blynk.begin(auth, ssid, pass);
  pinMode(MotorKanan,OUTPUT);
  pinMode(MotorKiri,OUTPUT);
  digitalWrite(MotorKanan,LOW);
  digitalWrite(MotorKiri,LOW);

  delay(2000);
}

void loop(){

  Blynk.run();

}
