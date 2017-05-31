#include <My_DHT_Using_Opp.h>

#include <SPI.h>
#include <Ethernet.h>
#include "My_DHT_Using_Opp.h"
#define MOIST A0    // moisture sensor analog read pin
#define DHT11_TEMP 5   // temperature sensor digital read pin
#define SOUND A1       // small sound sensor analog read pin
int m1=0,m2=0,pm=0; //moisture varuables
int d1=0,d2=0,pd=0; //temperature variables
int s1=0,s2=0,ps=0; //sound variables
dht d;
// assign a MAC address for the ethernet controller.
// fill in your address here:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
// fill in an available IP address on your network here,
// for manual configuration:
IPAddress ip(192, 168, 137, 120);//ip address of the arduino

// fill in your Domain Name Server address here:
IPAddress myDns(8, 8, 8, 8);
byte getway[] = {192, 168, 137, 1};////ip address of the port through which ardrino has connected
// initialize the library instance:
EthernetClient client;
char server[] = "192.168.137.1";//ip address of the port through which ardrino has connected
//char server[] = "128.199.170.225";//ip address of the server (wampp or dogital ocen)
//IPAddress server(64,131,82,241);

unsigned long lastConnectionTime = 0;             // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 2L * 1000L; // delay between updates, in milliseconds
// the "L" is needed to use long type numbers

void setup() {
  // start serial port:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // give the ethernet module time to boot up:
  delay(1000);
  // start the Ethernet connection using a fixed IP address and DNS server:
  Ethernet.begin(mac, ip, myDns, getway);
  pinMode(MOIST,INPUT);
  pinMode(SOUND,INPUT);
  pinMode(DHT11_TEMP,INPUT);
  
  ////// captive portal login
  /*client.connect("10.10.10.1",80);
  client.println("GET /cgi-bin/user_session.ggi?user=macrologic&passwd=macrologic123 HTTP/1.1");
  client.println("Host: 10.10.10.1");*/
  //client.println("Accept: */*");
  /*client.println("User-Agent: Mozilla/5.0");
  //client.println("Connection: close");
  client.println()*/
  // print the Ethernet board/shield's IP address:
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // if there's incoming data from the net connection.
  // send it out the serial port.  This is for debugging
  // purposes only:
  // if (client.available()) {
  // char c = client.read();
  //Serial.write(c);
  //}
  //receiving temperature details
  d.read11(DHT11_TEMP);
  d1=d.temperature;
  m1=analogRead(MOIST);
  s1=analogRead(SOUND);
  if((d1>37) || (m1<350) || (s1<1000))
  {
   // String s1;
     delay(10000);
    d2=d.temperature;
    m2=analogRead(MOIST);
    s2=analogRead(SOUND);
    if((d1+d2)>=75)
    {
     // s1="FEVER" ;//+ "(" + (int)d.temperature + ")";
    Serial.println("BABY HAS FEVER");
    Serial.print(d2);
    pd=1;
    }
  else
  {
    Serial.println(d2);
    pd=0;
  }
  //receiving moisture details
 
    if((m1+m2)<800)
    {
    Serial.println("DIAPER IS WET,NEEDS ATTENTON");
    pm=1;
    }
  else
  {
  Serial.println("NOT WET");
  pm=0;
  }
//receiving voice details
    if((s1+s2)<2000)
    {
    Serial.println("CRYING OUT LOUD");
    ps=1;
    }
    else
    {
    Serial.println("NOT CRYING");
    ps=0;
    }
  }
  // if two seconds have passed since your last connection,
  // then connect again and send data:
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }
  }






// this method makes a HTTP connection to the server:
void httpRequest() {
  // close any connection before sending a new request.
  // This will free the socket on the WiFi shield
  client.stop();
  // if there's a successful connection:
  if (client.connect(server, 80)) {
    Serial.println("connecting...");
    // send the HTTP GET request:
      if(pd==1 && pm==1 && ps==1)
      {
      client.print("GET /put3.php?d1=FEVER&d2=WET&d3=CRYING");
      }
      if(pd==1 && pm==0 && ps==0)
      {
      client.print("GET /put3.php?d1=FEVER&d2=NO_WET&d3=NOT_CRYING");
      }
      
      if(pd==0 && pm==1 && ps==0)
      {
      client.print("GET /put3.php?d1=NO_FEVER&d2=WET&d3=NOT_CRYING");
      }
      
      if(pd==0 && pm==0 && ps==1)
      {
      client.print("GET /put3.php?d1='NO_FEVER'&d2='NOT_WET'&d3='CRYING'");
      }
       if(pd==1 && pm==1 && ps==0)
      {
      client.print("GET /put3.php?d1='FEVER'&d2='WET'&d3='NOT_CRYING'");
      }
       if(pd==0 && pm==1 && ps==1)
      {
      client.print("GET /put3.php?d1=NO_FEVER&d2=WET&d3=CRYING");
      }
       if(pd==1 && pm==0 && ps==1)
      {
      client.print("GET /put3.php?d1='FEVER'&d2='NOT_WET'&d3='CRYING'");
      }
    client.println(" HTTP/1.1");
    client.println("Host: 128.199.170.225");
    client.println("User-Agent: arduino-ethernet");
    client.println("Accept-Encoding: gzip");
    client.println("Accept-Charset: ISO-8859-1,UTF-8;q=0.7,*;q=0.7");
    client.println("Cache-Control: no-cache");
    client.println("Accept-Language: de,en;q=0.7,en-us;q=0.3");
    client.println("Connection: close");
    client.println();
    Serial.write("request sent\n");
    // note the time that the connection was made:
    lastConnectionTime = millis();
   // char ch=client.read();
   while(client.connected())
   {
    while(client.available())
    {
     // Serial.write(client.read());
    }
   }
    /*if(client.read())
    Serial.println("reply from server confirmed");
    if(!client.read())
    Serial.println("couldn't receive reply from server");
    */
    }
    
  else 
  {
    // if you couldn't make a connection:
    Serial.println("connection failed\n");
    delay(500);
  }
}

