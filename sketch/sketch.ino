
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

#define __ADDR "clie2"

void setup(){
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)__ADDR);
  Mirf.payload = sizeof(unsigned long);
  Mirf.config();
  Serial.println(__ADDR); 
}

unsigned long time = 12345;

void loop()
{
    byte data[Mirf.payload];
    while(!Mirf.dataReady())
    {
      ;
    }
    Serial.println("Got Data");
    Mirf.getData(data);
    Serial.print((char *)data);
} 
  
  
  