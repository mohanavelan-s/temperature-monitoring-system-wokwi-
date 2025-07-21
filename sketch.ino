/************************************************ 
TITLE: Temperature Monitoring System using ESP32 Microcontroller
SUBMITTED BY: PENTUAN, ALVIN
SUBMITTED TO: PROF. MICHAEL SAMONTE 
*************************************************/

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT22

#define LED1 2
#define LED2 5
#define LED3 18
#define LED4 19
#define BUZZER 15

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup() {
  lcd.init();         // initialize the LCD
  lcd.backlight();     // turn on backlight
  dht.begin();         // initialize DHT22 sensor
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature(); // read temperature data from DHT22
  float hum = dht.readHumidity();     // read humidity data from DHT22

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  if (temp < 28.0) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    tone(BUZZER, 1000); // Start the buzzer at 1 kHz
  } 
  else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    noTone(BUZZER); // Stop the buzzer
  }

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print(" %");
  lcd.setCursor(0, 2);
  lcd.print("Created By:");
  lcd.setCursor(0, 3);
  lcd.print("Vaishanvi and her team");
}
