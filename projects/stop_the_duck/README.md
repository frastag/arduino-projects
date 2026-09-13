# Stop the duck

Se una papera (o qualsiasi altro oggetto) si avvicina troppo, digli di fermarsi.

## Componenti

- Board: Arduino Uno
- Sensori/attuatori: 
  - Schermo seriale LCD 16x2
  - Sensore ad ultrasuoni HC-SR04
- Altro:
  - Breadboard
  - Jumper

## Collegamenti (pinout)

| Componente (BME280) | Pin Arduino Uno |
|---------------------|-----------------|
| VCC                 | 3.3V            |
| GND                 | GND             |
| SCL                 | SCL             |
| SDA                 | SDA             |
| TRIG                | Pin 8           |
| ECHO                | Pin 9           |


## Librerie richieste

- LiquidCrystal_I2C 

## Come caricare

1. Apri `stop_the_duck.ino` con Arduino IDE (o `arduino-cli compile --upload ...`)
2. Seleziona board e porta corretta
3. Upload

## Note

Puoi trovare l'articolo integrale con spiegazione e schema nell'articolo dedicato: [Hello world? No, Quack, world](https://quackworld.substack.com/p/hello-world-no-quack-world)
