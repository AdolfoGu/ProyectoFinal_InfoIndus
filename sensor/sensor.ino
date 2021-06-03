#include <LiquidCrystal.h> //libreria para la pantalla lcd


LiquidCrystal lcd(13,12,11,10,9,8); //definimos los pines de la pantalla que vamos a utilizar

//pines del sensor HC-SR04
int disparador = 7;   // triger
int entrada = 6;      // echo

//leds
int Ledrojo = 2;
int Ledamarillo = 3;
int Ledverde = 4;

//bocina
int bocina=5;

float distancia;
long tiempo;

void setup() {
  //inicializamos los pines de entrada y salida
  pinMode(disparador, OUTPUT);
  pinMode(entrada, INPUT);

  //inicializamos los leds
  pinMode(Ledrojo, OUTPUT);
  pinMode(Ledverde, OUTPUT);
  pinMode(Ledamarillo, OUTPUT);

  //inicilizamos la bocina
  pinMode(bocina,OUTPUT);

  //iniciamos la pantalla, ponemos un mensaje y limpiamos
  lcd.begin(16,2);
  lcd.print("Proyecto");
  lcd.clear();
}

void loop() {
  
  //Ensendemos el sensor por 10 milis y apagamos
  digitalWrite(disparador, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparador, LOW);

  //calculo de la distancia
  tiempo = (pulseIn(entrada, HIGH)/2); //utilizamos la funcion pulseIn 
  distancia = float(tiempo * 0.0343);

  //encendemos el led rojo si la distancia es menor a 30 y encendemos la bocina
  if(distancia < 30){
      digitalWrite(Ledrojo,HIGH);
      digitalWrite(Ledverde,LOW);
      digitalWrite(Ledamarillo,LOW);
      tone(5,210,50);
      tone(5,300,50);
    }

  //encendemos el led amarillo si la distancia es menor a 80
  if(distancia >= 30 && distancia < 80){
    digitalWrite(Ledrojo,LOW);
    digitalWrite(Ledamarillo,HIGH);
    digitalWrite(Ledverde,LOW);
  }

  //encendemos el led verde si la distancia es mayor o igual a 80
  if(distancia >= 80){
    digitalWrite(Ledrojo,LOW);
    digitalWrite(Ledamarillo,LOW);
    digitalWrite(Ledverde,HIGH);
   }

  lcd.setCursor(0,0);  //colocamos el cursor de la pantalla en el inicio
  lcd.print("CM:"); //ponemos CM en la pantalla
  lcd.setCursor(3,1);  //colocamos el cursor de la pantalla en 3,1
  lcd.print(distancia);  //ponemos la distancia calculada
  delay(50);
}
 
