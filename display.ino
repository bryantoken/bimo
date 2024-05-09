//Exibe texto estático
void displayPrint(String text){
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println(text);
  display.display(); 
}

//Exibe imagem bitmap
void displayDraw(const unsigned char img[] PROGMEM){
  display.clearDisplay();
  display.drawBitmap(0, 0, img , 128,64,1);
  display.display();
}