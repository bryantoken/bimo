//INCLUDES
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "emotions.h"

//DEFINES
#define LED_VERMELHO          2
#define LED_VERDE             0
#define ECHO_PIN             12
#define TRIG_PIN             14
#define SCREEN_WIDTH        128
#define SCREEN_HEIGHT        64
#define OLED_RESET           -1

//INSTANCIAR METODOS
void wificonnect();

//DEFINIÇÃO DE HARDWARE
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//VARIAVEIS GLOBAIS
unsigned long uptime = millis(); //tempo que o sistema está rodando
float distance = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000); 

  display.display();
  delay(2000);
  wificonnect();
  Serial.println("\nBimo: Puta que pariu...\nBimo: Nasci");
}

void loop() {
  distance = readDistanceCM();

  if(distance > 10 & detectMotion()){
    displayDraw(noreaction);
    uptime = millis();
  }
  else if((millis() - uptime) > 20000){         //verifica se o tempo passou em milissegundos, se sim, condição verdadeira                    
    displayDraw(iddle);                         //ao alterar o tempo também deve alterar no método detectMotion() abaixo
    uptime = millis();
  }
  else if(distance < 10){
    displayDraw(angry);
    uptime = millis();
  }

  delay(10); 
}

//usa a distancia e o tempo sem movimento
//para detectar se houve interação
//se não houver interação no tempo determinado
//entra a emoção de estado "iddle"
bool detectMotion(){    //+5 para uma margem de erro  
  if (readDistanceCM() > (distance + 5) | readDistanceCM() < (distance - 5) & (millis() - uptime) < 20000){
    Serial.println("true");   
    return true;                                                          
  }
  Serial.println("False");                                                                      
  return false;                                                           
}