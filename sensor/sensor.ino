//pines del sensor HC-SR04
const int trigPin = 9;
const int echoPin = 9;
long duracion;
int distancia;
void setup() {
  //incializamos un pin de salida y uno de entrada
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Apagamos el sensor para evitar errores
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Ensendemos el sensor por 10 milis y apagamos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  //calculo de la distancia en cm
  distancia = (duracion * 0.034) / 2;
  
}
