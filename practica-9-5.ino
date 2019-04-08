const int LED =  LED_BUILTIN; // Asignamos el pin por defecto al led 
int estadoLed = LOW;             // Iniciamos siempre el led en el estadoLed mas bajo.
unsigned long anteriorMillis = 0;

void setup() {
  // set the digital pin as output:
  pinMode(LED, OUTPUT);
  Serial.begin(9600); //Activamos el puerto a 9600 baudios para visualizarlo por consola
}

void loop() {

  float in, out;
  int out2;
  

  for (in = 0; in < 100.283; in = in + 0.01) //Recorremos desde 0 a 100.283 incrementando 0.01. Periodo completo de onda
  {
    out = sin(in) * 127.5 + 127.5; // Convertirmos la salida para que vaya de 0 a 255 la amplitud de nuestra onda
    out2 = out; // Lo pasamos de float a entero
    long intervalo = out2;
    
    unsigned long MillisActual = millis(); // me devuelve el número de milisegundos desde que Arduino se ha reseteado, dado que millis devuelve un unsigned long puede tener un valor de hasta 4.294.967.295 
    Serial.println(out2); 

  if (MillisActual - anteriorMillis >= intervalo) { //De esta manera hacemos que cuando la resta sea mayor al intervalo se realice el parpadeo. Al variar el intervalo con los valores de la onda senoidal, logramos que este intervalo varíe entre todos sus valores
    // Guardamos la ultima vez qe nuestro led ha parpadeado
    anteriorMillis = MillisActual;

    // Si el led está apagado lo encenderemos y viceversa
    if (estadoLed == LOW) {
      estadoLed = HIGH;
    } else {
      estadoLed = LOW;
    }

    // Mandamos al puerto digital nuestro estado del led
    digitalWrite(LED, estadoLed);  
  }
  }
}
