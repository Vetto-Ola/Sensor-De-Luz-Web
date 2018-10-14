const int LDRPin = A0;
int V;
 
void setup() 
{
   Serial.begin(115200);          //    Set up de la velocidad del puerto serial.
}
 
void loop()
{
   V = analogRead(LDRPin);         //   Lee la el dato análogo del sensor de luz (LDR).
   Serial.print(V);                //   Manda los datos por el TX de la placa del Arduino, la comunicación serial.
   delay(10000);                   //   Espera 10 segundo para volver a hacer la lectura y el envío.
}
