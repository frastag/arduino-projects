/*
  Nome progetto: Stop the duck
  Descrizione:   Comunica alla papera di fermarsi quando è più vicina di 10 cm
  Board:         Arduino Uno
  Autore:        PaperFra
  Data:          13 settembre 2026
*/

// Includere la libreria. Verificare di averla importata dal Library Manager.
#include <LiquidCrystal_I2C.h>

// Inizializzare lo schermo LCD (indirizzo I2C 0x27, 16 colonne, 2 righe)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definire i PIN usati da HC-SR04
const int TRIG_PIN = 9;
const int ECHO_PIN = 8;

// Soglia di distanza (in cm) sotto la quale la papera è considerata "vicina"
const int THRESHOLD_CM = 10;

// Memorizza lo stato precedente, per aggiornare lo schermo
// solo quando lo stato cambia davvero (evita flicker dell'LCD)
bool wasStopped = false;

// Disegna la papera nella parte destra dello schermo (colonne 8-15)
void printDuck() {
  lcd.setCursor(8, 0);
  lcd.print("<(o )___");
  lcd.setCursor(9, 1);
  lcd.print("( ._> /");
}

// Stato "via libera": nessun ostacolo entro la soglia
void duckGo() {
  // Pulire lo schermo prima di ogni scrittura, così ogni ciclo
  // genera una transazione I2C pulita e uguale alla precedente
  lcd.clear();

  // Allineare il cursore per scrivere il testo.
  // Il primo argomento definisce la colonna e il secondo la riga
  lcd.setCursor(0, 0);
  lcd.print("Duck");
  lcd.setCursor(0, 0);
  lcd.print("come");

  printDuck();
}

// Stato "stop": la papera è entro la soglia
void duckStop() {
  // Pulire lo schermo prima di ogni scrittura, così ogni ciclo
  // genera una transazione I2C pulita e uguale alla precedente
  lcd.clear();

  // Allineare il cursore per scrivere il testo.
  // Il primo argomento definisce la colonna e il secondo la riga
  lcd.setCursor(0, 0);
  lcd.print("Duck");
  lcd.setCursor(1, 1);
  lcd.print("stop!");

  printDuck();
}

void setup() {
  // Accendere lo schermo
  lcd.init();
  lcd.backlight();

  // Assegnare la tipologia di PIN
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECO_PIN, INPUT);
}

void loop() {
  // Invia un impulso di trigger di 10 microsecondi
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Legge il tempo (in microsecondi) che l'eco impiega a tornare
  long duration = pulseIn(ECO_PIN, HIGH);

  // Calcola la distanza in cm (velocità del suono ≈ 343 m/s)
  float distance = duration * 0.0343 / 2;

  // Aggiorna lo schermo solo se lo stato è cambiato rispetto al ciclo precedente
  bool isStopped = (distance <= THRESHOLD_CM);
  if (isStopped != wasStopped) {
    isStopped ? duckStop() : duckGo();
    wasStopped = isStopped;
  }

  delay(300); // piccola pausa tra una lettura e l'altra
}