# Quack World

Il primo programma che ogni sviluppatore scrive dice "Hello, world", il mio dice "Quack, world".

## Componenti

- Board: Arduino Uno
- Sensori/attuatori: 
  - Schermo seriale LCD 16x2
- Altro:
  - Breadboard
  - Jumper

## Collegamenti (pinout)

| Componente (BME280) | Pin Arduino Uno |
|---|-----------------|
| VCC | 3.3V            |
| GND | GND             |
| SCL | SCL             |
| SDA | SDA             |

## Librerie richieste

- nome-libreria (versione, da Library Manager)

## Come caricare

1. Apri `quack_world.ino` con Arduino IDE (o `arduino-cli compile --upload ...`)
2. Seleziona board e porta corretta
3. Upload

## Note

Puoi trovare l'articolo integrale con spiegazione e schema nell'articolo dedicato: [Hello world? No, Quack, world](https://quackworld.substack.com/p/hello-world-no-quack-world)
