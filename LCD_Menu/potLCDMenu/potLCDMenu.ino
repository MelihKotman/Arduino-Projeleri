#include <LiquidCrystal.h>
//#include <LiquidCrystal_I2C.h>

//RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3 ,2);

/*
* LCD I2C ile (Adres[ya hexadecimal  ya da 0x27 gibi adres, satir sayisi, sutun sayisi])
*LiquidCrystal_I2C lcd(39, 16, 2);
*/
int potSelect = A0; //Menude pot ile secmek icin
int selectButton = 8; //Menudeki ogeyi seçmek için buton
const int menuCountItem = 4; //Ayarlar, Hakkinda, Saat, Cikis seklinde 4 tanedir

String menuItems[menuCountItem] = {
  "Settings",
  "About",
  "Time",
  "Off"
};
int menuIndex = 0; //Menudeki seceneklerin belirlendigi indextir.
int lastMenuIndex = -1; //Ilk basta -1'den baslatirsak ilk secenegi gosterir ve cevirdikce degistirir
bool buttonPressed = false; //Debounce icin

void setup() {
  lcd.begin(16, 2);
  /*
  *lcd.init();
  *lcd.backlight();
  */
  pinMode(selectButton, INPUT);
  pinMode(potSelect, INPUT);  // Zorunlu degil

  lcd.setCursor(0, 0);
  lcd.print("Menu basliyor...");
  delay(1000);
  lcd.clear();

  showMenu();
}

void loop() {
  // Potansiyometre okuma ve menü index hesaplama
  int potVal = analogRead(potSelect);
  int currentMenu = map(potVal, 0, 1023, 0, menuCountItem - 1); 
  //Menude "exit" kismina gelince dalgalanma oluyorsa manuel pot degeri araligi atama yapabilirsin

    // Menu degistiyse ekranda goster
  if(currentMenu != lastMenuIndex){
      menuIndex = currentMenu;
      showMenu();
      lastMenuIndex = currentMenu;
   }
     // Select butonuna basıldıysa
  if(digitalRead(selectButton) == HIGH && !buttonPressed){
    lcd.clear();
    lcd.setCursor(0, 0);
    switch(menuIndex){ 
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

    delay(1000);
    showMenu();
    buttonPressed = true;
  }
   // Buton serbest bırakıldıysa yeniden basılabilir hale getir
  if(digitalRead(selectButton) == LOW){
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