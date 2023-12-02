#include <SoftwareSerial.h>

// tx 10, rx 11
SoftwareSerial gps(10, 11);

char c;
int sayac = 0;


String lat1D = "";
String lat1F = "";
String lng1D = "";
String lng1F = "";
String header = "";

float latF;
float lngF;

float latD;
float lngD;

void setup() {
 Serial.begin(115200);
 gps.begin(9600);
 delay(1000);
}

void loop() {

    while(gps.available() > 0){

      sayac++;
      c = gps.read();

      if(c == '\n'){
        if(header == "$GNRMC"){
          
            latD = lat1D.toFloat();
            Serial.print("latD* = ");
            Serial.println(latD,6);             
            latF = lat1F.toFloat();
            Serial.print("latF/ = ");
            Serial.println(latF,6);             
            latF = ((latF / 100) / 60)*100;
            Serial.print("latF- = ");
            Serial.println(latF,6);
            Serial.println("");              
            latD = latD + latF;
     
            lngD = lng1D.toFloat();
            Serial.print("lngD* = ");
            Serial.println(lngD,6);             
            lngF = lng1F.toFloat();
            Serial.print("lngF/ = ");
            Serial.println(lngF,6);             
            lngF = ((lngF / 100) / 60)*100;
            Serial.print("lngF- = ");
            Serial.println(lngF,6);
            Serial.println("");              
            lngD = lngD + lngF;
            
            Serial.print("header = ");
            Serial.println(header);
            /*Serial.print("latD = ");
            Serial.println(latD,6); 
            Serial.print("lngD = ");
            Serial.println(lngD,6);
            Serial.println("");*/

            Serial.print("konum: ");
            Serial.print(latD, 6);
            Serial.print(",");
            Serial.println(lngD, 6);
          }
          
        sayac = 0;
        header = "";
        lat1D = "";
        lat1F = "";   
        lng1D = "";
        lng1F = "";
       }

      else if(sayac >= 1 && sayac <= 6){
        header = header + c;  
       }

      else if(header == "$GNRMC"){        
        if(sayac >= 21 && sayac <= 29){
            if(sayac == 21 || sayac == 22){
                lat1D = lat1D + c;
              }
            else{
                lat1F = lat1F + c;
              }
          }
  
        else if(sayac >= 34 && sayac <= 43){
            if(sayac == 34 || sayac == 35){
                lng1D = lng1D + c;
              }
            else{
                lng1F = lng1F + c;
              }               
          }   
       }
    }
}
