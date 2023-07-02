#include <LiquidCrystal.h>


// Создаем константы контактов для подключения к ардуино. 
const int RS = 4, EN = 5, D4 = 10, D5 = 11, D6 = 12, D7 = 13;

// Инициализируем объект-экран. 
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Веселый смайлик
byte smiley_funny[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

// Строгий смайлик
byte smiley_strict[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b00000
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(1, smiley_funny);
  lcd.createChar(2, smiley_strict);
}
 
void loop() {
  // Устанавливаем курсор в позицию (0, 0)
  lcd.setCursor(5, 0);
  lcd.print("Soil");

  // Считываем показания(0 - 1023) с аналогового пина к которому подключен датчи влажности почвы. 
  // Чем выше значение тем сопротивление больше, а значит почва сухая. 
  int sensorReading = analogRead(0);
  // Преобразуем значение из 0 - 1023 в 1 - 100; => 0 = 100; 1023 = 1. 
  int humidity_percentage = map(sensorReading, 0, 1023, 100, 1);
  if (humidity_percentage > 60){
    lcd.setCursor(11, 0);
    lcd.write(byte(1));
  } else {
    lcd.setCursor(11, 0);
    lcd.write(byte(2));
  }
  
  lcd.setCursor(2, 1);
  lcd.print("moisture: ");
  
  lcd.print(int(humidity_percentage));
  lcd.print("%");
  delay(1500);
  lcd.clear();

}


