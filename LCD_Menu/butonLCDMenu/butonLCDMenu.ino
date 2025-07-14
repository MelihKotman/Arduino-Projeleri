#include <LiquidCrystal.h>
//#include <LiquidCrystal_I2C.h>

//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3 ,2);

/*
* LCD I2C ile (Adres[ya hexadecimal  ya da 0x27 gibi adres, satir sayisi, sutun sayisi])
*LiquidCrystal_I2C lcd(39, 16, 2);
*/

int upButton = 10; //menude yukari gitme
int downButton = 9; //menude asagi gitme
int selectButton = 8; //menudeki oldugu bolumdeki secenegi secme
const int menuCountItem = 4; //Ayarlar, Hakkinda, Saat, Cikis seklinde 4 tanedir

String menuItems[menuCountItem] = {
  "Settings",
  "About",
  "Time",
  "Off"
};
int menuIndex = 0; //Menudeki seceneklerin belirlendigi indextir.

bool buttonPressed = false; //Sure bitmeden tekrar cagrilmasini(debouncing) olayi icin

void setup() {
  lcd.begin(16, 2);
  /*
  *lcd.init();
  *lcd.backlight();
  */
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(selectButton, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Menu basliyor...");
  delay(1000);
  lcd.clear();

  showMenu();
}

void loop() {
  //Yukari butonu
  if(digitalRead(upButton) == HIGH && !buttonPressed){
    menuIndex = (menuIndex - 1 + menuCountItem) % menuCountItem; // 0-3-2-1 seklinde gider 
    showMenu(); 
    buttonPressed = true; //Basildigini goster
  }
  //Asagi butonu
  if(digitalRead(downButton) == HIGH && !buttonPressed){
    menuIndex = (menuIndex + 1) % menuCountItem; //0-1-2-3 seklinde gider 
    showMenu();
    buttonPressed = true; //Basildigini goster
  }
  //Secim butonu
  if(digitalRead(selectButton) == HIGH && !buttonPressed){
    lcd.clear(); //Temizle
    switch(menuIndex){ //Secime gore secimlerin icine gir.
      case 0:
        lcd.print("Settings...");
        break;
      case 1:
        lcd.print("About...");
        break;
      case 2:
        lcd.print("Time is ...");
        break;
      case 3:
        lcd.print("Exit...");
        break;
      default:
        lcd.print("Wrong Selection");
    }

    delay(1000); //Secim ekranini 1 s goster
    showMenu(); //Ana menuye don
    buttonPressed = true;

  }
  //Eger hicbirine basilmadiysa tekrardan secim yapabilir kullanici
  if(digitalRead(upButton) == LOW && digitalRead(downButton) == LOW && digitalRead(selectButton) == LOW){
    buttonPressed = false;
  }
}

void showMenu(){
  lcd.clear(); //Temizle
  lcd.setCursor(0, 0); //En bastan basla
  lcd.print("Menu : "); //"Menu : "yaz
  lcd.setCursor(0 ,1); //Alta gec
  lcd.print("> "); //Secenekleri goster
  lcd.print(menuItems[menuIndex]);
}