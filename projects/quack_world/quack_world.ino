/*
  Nome progetto: Quack, world
  Descrizione:   Quack, world su schermo seriale LCD 16x2
  Board:         Arduino Uno
  Autore:        PaperFra
  Data:          2 settembre 2026
*/

// Includere la libreria. Verificare di averla importata dal Library Manager.
#include <LiquidCrystal_I2C.h>

// Inizializzare lo schermo LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Accendere lo schermo
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Allineare il cursore per scrivere il testo.
  // Il primo argomento definisce la colonna e il secondo la riga
  lcd.setCursor(0, 0);
  lcd.print("quack,");
  lcd.setCursor(1, 1);
  lcd.print("world");

  // Disegnare la papera
  lcd.setCursor(8, 0);
  lcd.print("<(o )___");
  lcd.setCursor(9, 1);
  lcd.print("( ._> /");
}

void loop() {
  // Non serve inserire nulla qui in questo caso
}
