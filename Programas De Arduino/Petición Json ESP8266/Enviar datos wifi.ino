#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
 
void setup() {
  Serial.begin(115200);                    //Comunicación serial
  WiFi.begin("Nombre de la Red", "Passwprd de la red");   //Conexión WiFi
  while (WiFi.status() != WL_CONNECTED) {  //Espera la conexión
    delay(500);
  }
}
 
void loop() {
 if(WiFi.status()== WL_CONNECTED){   //Verifica el estado de la conexión del Wifi
  if(Serial.available()>0)    //Verifica si hay algún dato en el buffer de entrada del ESP8266
  {      
   HTTPClient http;    //Objeto de tipo HTTP
   http.begin("http://sensor-de-luz.azurewebsites.net/task");      //Ruta de inserción de datos (Web)
   http.addHeader("Content-Type", "application/json");  //Especificación del Content-Type
   int httpCode = http.POST("{\"name\" : \""+Serial.readString()+"\" }");   //Manda la petición HTTP y manda los datos de lectura que se reicibieron en el puerto serial.
   http.end();  //Cierra la petición
  }
 delay(1000); //Lee si hay datos en el Buffer a cada segundo, esto se hace para evitar una agloremacion de datos de lectura
 }
}
