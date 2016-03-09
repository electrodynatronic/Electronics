//
//    FILE: ArduinoWebserver.ino
//  AUTHOR: 
// VERSION: 0.1.01
// PURPOSE: Implements a basic temperature monitor and webserver with an Arduino, DHT11, and a W5100
//     URL:
//
// Released to the public domain
//

#include <dht.h>

dht DHT;

#define DHT11_PIN 5

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {  0x42, 0x42, 0x42, 0x42, 0x42, 0x42};
IPAddress ip(192, 168, 1, 42);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

unsigned long previousMillis = 0;        // will store last time was updated

// constants won't change :
const long interval = 2000;           // interval at which to check (milliseconds)

void setup()
{
  Serial.begin(115200);while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    readDHT();
    printDHTdata();
  }

// listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pin
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");
          }
          for (int dChannel = 2; dChannel < 6; dChannel++) {
            int dReading = digitalRead(dChannel);
            client.print("digital input ");
            client.print(dChannel);
            client.print(" is ");
            client.print(dReading);
            client.println("<br />");
          }
          client.print("Humidity ");
          client.print(DHT.humidity);
            client.println("<br />");
          client.print("Temperature ");
          client.print(DHT.temperature);
          
            client.println("<br />");
          
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
    Ethernet.maintain();
  }

}

void printDHTdata(){
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);
//delay(2000);
}

void readDHT(){
  // READ DATA
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
}
//
// END OF FILE
//
