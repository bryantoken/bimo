#include <WiFi.h>

void wificonnect(){
  Serial.print("Conectando-se ao WiFi\n");
  displayPrint("Conectando-se ao WiFi");
  //Bloco responsável pela conexão com o wifi
  WiFi.begin("Wokwi-GUEST", "", 6); // conexão com o a rede wifi simulada do wokwi (SSID, senha, 6) o '6' é um canal, usado para pular fase de varredura e economizar tempo de execução
  while (WiFi.status() != WL_CONNECTED) { 
    digitalWrite(LED_VERMELHO, HIGH);
    delay(100);
    digitalWrite(LED_VERMELHO, LOW);
    delay(100);
  }
  String ip = WiFi.localIP().toString();
  //########################################
  Serial.println("Conectado!\n");
  displayPrint("Conectando");

  Serial.print("Endereço IP: ");
  displayPrint("Endereço IP: ");

  Serial.print(ip);
  displayPrint(ip);

  delay(2000);
  display.clearDisplay();
  
  digitalWrite(LED_VERDE, HIGH);
}
