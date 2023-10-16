#include <Adafruit_Sensor.h>// undefined sensor library
#include <U8glib.h>   // u8glib  fron library mannager
#include <DHT.h>      // DHT11 sensor library
#define DHTTYPE    DHT11 //the DHT library where to expect a DHT sensor and which type

char temperature [5];
char humidity [5];

DHT dht(2, DHTTYPE); // connected to pin 8 of the Arduino
// display constructor for u8g library - this one depends on your type of display
U8GLIB_KS0108_128 u8g(8, 9, 10, 11, 4, 5, 6, 7, A4, A0, A1, A3, A2);     // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, cs1=14, cs2=15,di=17,rw=16

void setup() {  

  dht.begin();
  Serial.begin(9600); 
  u8g.begin();
  
     u8g.setFont(u8g_font_courB10);
  u8g.setColorIndex(1);


}

void loop() {  
  u8g.firstPage();
  do {   
    draw();
  } while( u8g.nextPage());
 
}
  
void draw(){

  readTemperature();
  readHumidity();
  
 
    u8g.drawFrame(0,0,128,31);            // upper frame
    u8g.drawFrame(0,33,128,31);  
    // lower frame    
  u8g.drawStr(15,13,"Temperature"); // text print on lcd screen  
  u8g.drawStr(33,27, temperature);   //value print on LCD screen
  u8g.drawStr(76,28, "C");//print symbol

  u8g.drawStr(30,46,"Humidity  ");   // text print on lcd screen        
  u8g.drawStr( 37,61, humidity);  //value print on LCD screen
  u8g.drawStr(75,61, "%");//print symbol
   
}

void readTemperature()
{
  float t = dht.readTemperature();// Read temperature value from sensor
  dtostrf(t, 3, 1, temperature);
  
}

void readHumidity()
{
  float h = dht.readHumidity();//Read humidity from senssor
  dtostrf(h, 3, 1, humidity);
}
