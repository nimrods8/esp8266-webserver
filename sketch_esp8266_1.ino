// from: https://create.arduino.cc/projecthub/ROBINTHOMAS/esp8266-esp-01-webserver-7248ca

// ===============================================================
// to activate upload with WaveShare configuration:
// press A (RST=up) and Center(FLASH) at the same time
// release the A (RST) but keep Center pressed
// release Center and the device should start uploading code
// ===============================================================

#include <ESP8266WiFi.h>
 
const char* ssid = "LipmanDrayTek";               //type your ssid
const char* password = "0544205450";              //type your password

const char *css1= "body {\n\r"  
                  "font: 23px/30px 'Lucida Grande', Tahoma, Verdana, sans-serif;\n\r"  
                  "color: white;\n\r" 
                  "background: #3b3f46; }\n\r" 
                  ".container {\n\r" 
                  "margin: 0 auto;\n\r" 
                  "padding: 90px 0;\n\r" 
                  "width: 400px;\n\r" 
                  "background-image: -webkit-radial-gradient(center, farthest-side, rgba(255, 255, 255, 0.1), rgba(255, 255, 255, 0));\n\r" 
                  "background-image: -moz-radial-gradient(center, farthest-side, rgba(255, 255, 255, 0.1), rgba(255, 255, 255, 0));\n\r" 
                  "background-image: -o-radial-gradient(center, farthest-side, rgba(255, 255, 255, 0.1), rgba(255, 255, 255, 0));\n\r" 
                  "background-image: radial-gradient(center, farthest-side, rgba(255, 255, 255, 0.1), rgba(255, 255, 255, 0));\n\r" 
                  "}\n\r" 
                  
                  ".switch {\n\r" 
                  "  position: relative;\n\r" 
                  "  margin: 20px auto;\n\r" 
                  "  height: 46px;\n\r" 
                  "  width: 240px;\n\r" 
                  "  background: rgba(0, 0, 0, 0.25);\n\r" 
                  "  border-radius: 3px;\n\r" 
                  "  -webkit-box-shadow: inset 0 1px 3px rgba(0, 0, 0, 0.3), 0 1px rgba(255, 255, 255, 0.1);\n\r" 
                  "  box-shadow: inset 0 1px 3px rgba(0, 0, 0, 0.3), 0 1px rgba(255, 255, 255, 0.1);\n\r" 
                  "}\n\r" 

                  ".switch-label {\n\r" 
                  "  position: relative;\n\r" 
                  "  z-index: 2;\n\r" 
                  "  float: left;\n\r" 
                  "  width: 118px;\n\r" 
                  "  line-height: 45px;\n\r" 
                  "  font-size: 26px;\n\r" 
                  "  color: rgba(255, 255, 255, 0.35);\n\r" 
                  "  text-align: center;\n\r" 
                  "  text-shadow: 0 1px 1px rgba(0, 0, 0, 0.45);\n\r" 
                  "  cursor: pointer;\n\r" 
                  "}\n\r" 
                  ".switch-label:active {\n\r" 
                  "  font-weight: bold;\n\r" 
                  "}\n\r" 
                  
                  ".switch-label-off {\n\r" 
                  "  padding-left: 2px;\n\r" 
                  "}\n\r" 
                   
                  ".switch-label-on {\n\r" 
                  "  padding-right: 2px;\n\r" 
                  "}\n\r" 
                  
                  ".switch-input {\n\r" 
                  "  display: none;\n\r" 
                  "}\n\r" 
                  ".switch-input:checked + .switch-label {\n\r" 
                  "  font-weight: bold;\n\r" 
                  "  color: rgba(0, 0, 0, 0.65);\n\r" 
                  "  text-shadow: 0 1px rgba(255, 255, 255, 0.25);\n\r" 
                  "  -webkit-transition: 0.15s ease-out;\n\r" 
                  "  -moz-transition: 0.15s ease-out;\n\r" 
                  "  -o-transition: 0.15s ease-out;\n\r" 
                  "  transition: 0.15s ease-out;\n\r" 
                  "}\n\r" 
                  ".switch-input:checked + .switch-label-on ~ .switch-selection {\n\r" 
                  "  left: 120px;\n\r" 
                  "  /* Note: left: 50% doesn't transition in WebKit */\n\r" 
                  "}\n\r";


const char *css2= ".switch-selection {\n\r" 
                  "  display: block;\n\r" 
                  "  position: absolute;\n\r" 
                  "  z-index: 1;\n\r" 
                  "  top: 2px;\n\r" 
                  "  left: 2px;\n\r" 
                  "  width: 118px;\n\r" 
                  "  height: 42px;\n\r" 
                  "  background: #65bd63;\n\r" 
                  "  border-radius: 3px;\n\r" 
                  "  background-image: -webkit-linear-gradient(top, #9dd993, #65bd63);\n\r" 
                  "  background-image: -moz-linear-gradient(top, #9dd993, #65bd63);\n\r" 
                  "  background-image: -o-linear-gradient(top, #9dd993, #65bd63);\n\r" 
                  "  background-image: linear-gradient(to bottom, #9dd993, #65bd63);\n\r" 
                  "  -webkit-box-shadow: inset 0 1px rgba(255, 255, 255, 0.5), 0 0 2px rgba(0, 0, 0, 0.2);\n\r" 
                  "  box-shadow: inset 0 1px rgba(255, 255, 255, 0.5), 0 0 2px rgba(0, 0, 0, 0.2);\n\r" 
                  "  -webkit-transition: left 0.15s ease-out;\n\r" 
                  "  -moz-transition: left 0.15s ease-out;\n\r" 
                  "  -o-transition: left 0.15s ease-out;\n\r" 
                  "  transition: left 0.15s ease-out;\n\r" 
                  "}\n\r" 
                  ".switch-blue .switch-selection {\n\r" 
                  "  background: #3aa2d0;\n\r" 
                  "  background-image: -webkit-linear-gradient(top, #4fc9ee, #3aa2d0);\n\r" 
                  "  background-image: -moz-linear-gradient(top, #4fc9ee, #3aa2d0);\n\r" 
                  "  background-image: -o-linear-gradient(top, #4fc9ee, #3aa2d0);\n\r" 
                  "  background-image: linear-gradient(to bottom, #4fc9ee, #3aa2d0);\n\r" 
                  "}" 
                  ".switch-yellow .switch-selection {\n\r" 
                  "  background: #c4bb61;\n\r" 
                  "  background-image: -webkit-linear-gradient(top, #e0dd94, #c4bb61);\n\r" 
                  "  background-image: -moz-linear-gradient(top, #e0dd94, #c4bb61);\n\r" 
                  "  background-image: -o-linear-gradient(top, #e0dd94, #c4bb61);\n\r" 
                  "  background-image: linear-gradient(to bottom, #e0dd94, #c4bb61);\n\r" 
                  "}\n\r" 
                  
                  ".mainDiv {\n\r" 
                  " text-align: center;\n\r" 
                  "  width: 100%;\n\r" 
                  "}";

 
int ledPin = 2; // GPIO2 of ESP8266
int led2Pin = 0; // GPIO0 for LED #2

const char *webPassword = "water";
bool goodPassword = true;
int ledValue = LOW, led2Value = LOW;


WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode( ledPin, OUTPUT);
  pinMode( led2Pin, OUTPUT);
  digitalWrite( ledPin, ledValue);
  digitalWrite( led2Pin, led2Value);
   
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin( ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
   
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/"); 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  client.setNoDelay(1);

  if (!client) {
    return;
  }
   
  // Wait until the client sends some data
  int timeout = 100;
  Serial.println("new client");
  while(!client.available()){
    delay(10);
    if( !(--timeout))
       return;
  }
  Serial.println("now available...");
  
  // Read the first line of the request
  String request = client.readStringUntil('\n\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
  if (request.indexOf("/LED=ON") != -1) 
  {
    
    Serial.println( "have led on");
    goodPassword = false;
    int f1;
    if( (f1=request.indexOf( "P=")) != -1)
    {
      f1 += 2;
      int f2 = request.indexOf( " ", f1);
      //Serial.println( f1);
      //Serial.println( f2);
      //Serial.println( request.substring( f1, f2));
      
      if( request.substring( f1, f2) == webPassword)
      {
         digitalWrite(ledPin, HIGH);
         ledValue = HIGH;
         goodPassword = true;
      } // endif
    } // endif
  } // endif
  else if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, LOW);
    ledValue = LOW;
    goodPassword = true;
  }


  // Match the request for LED 2
  if (request.indexOf("/LED2=ON") != -1) 
  {
    
    Serial.println( "have led 2 on");
    goodPassword = false;
    int f1;
    if( (f1=request.indexOf( "P=")) != -1)
    {
      f1 += 2;
      int f2 = request.indexOf( " ", f1);
      //Serial.println( f1);
      //Serial.println( f2);
      //Serial.println( request.substring( f1, f2));
      
      if( request.substring( f1, f2) == webPassword)
      {
         digitalWrite(led2Pin, HIGH);
         led2Value = HIGH;
         goodPassword = true;
      } // endif
    } // endif
  } // endif
  else if (request.indexOf("/LED2=OFF") != -1){
    digitalWrite(led2Pin, LOW);
    led2Value = LOW;
    goodPassword = true;
  }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
   
 
  // Return the response
  /*
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>\r<head>");
  client.println( "<title>Switch</title>");
  */
  /* this is the embedded css file taken from https://github.com/pawelka/esp8266 */
   
  client.println( "HTTP/1.1 200 OK\r"
                  "Content-Type: text/html\n\r"
                  "\n\r"
                  "<!DOCTYPE HTML>"
                  "<html>\n\r<head>"
                  "<title>Switch</title>"
                  "<style media=\"screen\" type=\"text/css\">\n\r");

  client.println( css1);
  client.println( css2);
  client.println( "</style>\n\r"
                  "<meta name=\"viewport\" content=\"width=device-width; initial-scale=1.0; maximum-scale=2.0;\"/>"
                  "</head>\n\r<body>\n\r"
                  "<div id=\"main\">\n\r"
                  "<div class=\"mainDiv\">\n\r"
                  "<h1>Switch</h1>");

  if( !goodPassword)
     client.print("<div class=\"switch\">BAD PASSWORD</div><br>");

  if( ledValue == HIGH)
  {
      client.println( "<div style=\"min-height:5px\"></div>"
                      "<div class=\"switch switch-blue\">"
                      "<input type=\"radio\" class=\"switch-input\" name=\"led1\" value=\"1\" id=\"led1a\" onchange=\"location.href='/LED=OFF&P='+document.getElementById('qta_field').value\">\n\r"
                      "<label for=\"led1a\" class=\"switch-label switch-label-off\">Off</label>"
                      "<input type=\"radio\" class=\"switch-input\" name=\"led1\" value=\"0\" id=\"led1b\" onchange=\"location.href='/LED=ON&P='+document.getElementById('qta_field').value\" checked>\n\r"
                      "<label for=\"led1b\" class=\"switch-label switch-label-on\">On</label>"
                      "<span class=\"switch-selection\"></span>"
                      "</div>");
  }
  else 
  {
      client.println( "<div style=\"min-height:5px\"></div>"
                      "<div class=\"switch switch-blue\">"
                      "<input type=\"radio\" class=\"switch-input\" name=\"led1\" value=\"1\" id=\"led1a\" onchange=\"location.href='/LED=OFF&P='+document.getElementById('qta_field').value\" checked>\n\r"
                      "<label for=\"led1a\" class=\"switch-label switch-label-off\">Off</label>"
                      "<input type=\"radio\" class=\"switch-input\" name=\"led1\" value=\"0\" id=\"led1b\" onchange=\"location.href='/LED=ON&P='+document.getElementById('qta_field').value\">\n\r"
                      "<label for=\"led1b\" class=\"switch-label switch-label-on\">On</label>"
                      "<span class=\"switch-selection\"></span>"
                      "</div>");
  
  }

  if( led2Value == HIGH)
  {
      client.println( "<div style=\"min-height:5px\"></div>"
                      "<div class=\"switch switch-blue\">"
                        "<input type=\"radio\" class=\"switch-input\" name=\"led2\" value=\"1\" id=\"led2a\" onchange=\"location.href='/LED2=OFF&P='+document.getElementById('qta_field').value\">"
                        "<label for=\"led2a\" class=\"switch-label switch-label-off\">Off</label>"
                        "<input type=\"radio\" class=\"switch-input\" name=\"led2\" value=\"0\" id=\"led2b\" onchange=\"location.href='/LED2=ON&P='+document.getElementById('qta_field').value\" checked>\n\r"
                        "<label for=\"led2b\" class=\"switch-label switch-label-on\">On</label>"
                        "<span class=\"switch-selection\"></span>"
                      "</div>");
  }
  else
  {
      client.println( "<div style=\"min-height:5px\"></div>"
                      "<div class=\"switch switch-blue\">"
                        "<input type=\"radio\" class=\"switch-input\" name=\"led2\" value=\"1\" id=\"led2a\" onchange=\"location.href='/LED2=OFF&P='+document.getElementById('qta_field').value\" checked>"
                        "<label for=\"led2a\" class=\"switch-label switch-label-off\">Off</label>"
                        "<input type=\"radio\" class=\"switch-input\" name=\"led2\" value=\"0\" id=\"led2b\" onchange=\"location.href='/LED2=ON&P='+document.getElementById('qta_field').value\">\n\r"
                        "<label for=\"led2b\" class=\"switch-label switch-label-on\">On</label>"
                        "<span class=\"switch-selection\"></span>"
                      "</div>");
  }
     
  client.print("Led pin is now: ");
   
  if(ledValue == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.print(", Led #2 pin is now: ");
   
  if(led2Value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  
  client.println("<br><br>\n\r"
                 "Your Password: <input type=\"password\" id=\"qta_field\" autofocus />\n\r"
                 "<br><br>\n\r"
                 "Click <a href='' onclick=\"this.href='/LED=ON&P='+document.getElementById('qta_field').value\">here</a> turn the LED on pin 2 <i>ON</i><br>\n\r"
                 "Click <a href='' onclick=\"this.href='/LED=OFF&P='+document.getElementById('qta_field').value\">here</a> turn the LED on pin 2 <i>OFF</i><br>\n\r"
                 "</div></div></html>\n\r");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}

