#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);// adressage carte.
int led1 = 6;
int led2 = 7;
int horaire3 = 0;
int horaire4 = 0;

int unsigned Menu = 0; 
int unsigned SousMenu = 0 ;

double DelaiON; 
double DelaiOFF; 
double Tempo = millis();

double DelaiON2;
double DelaiOFF2;
double Tempo2 = millis();

int Clignote1 = 0; 
int Clignote2 = 0;

int SELECT = A0;
int UP = A1;
int DOWN = A2;
int LEFT = A3;
int RIGHT = 10;
typedef struct {
  String Menu;
}

TypeMenu;
TypeMenu NumMenu[100];

void Initialisation() {
  NumMenu[10] = (TypeMenu) {
    "8H - 10H"
  };
    NumMenu[11] = (TypeMenu) {
      "EPSI - B1"
    };
    NumMenu[12] = (TypeMenu) {
      "EPSI - B2"
    };
    NumMenu[13] = (TypeMenu) {
      "EPSI - B3"
    };
  NumMenu[20] = (TypeMenu) {
    "10H - 12H"
  };
    NumMenu[21] = (TypeMenu) {
      "EPSI - B1"
    };
    NumMenu[22] = (TypeMenu) {
      "EPSI - B2"
    };
    NumMenu[23] = (TypeMenu) {
      "EPSI - B3"
    };
  NumMenu[30] = (TypeMenu) {
    "13H - 15H"
  };
    NumMenu[31] = (TypeMenu) {
      "EPSI - B1"
    };
    NumMenu[32] = (TypeMenu) {
      "EPSI - B2"
    };
    NumMenu[33] = (TypeMenu) {
      "EPSI - B3"
    };

    NumMenu[40] = (TypeMenu) {
    "15H - 17H"
  };
    NumMenu[41] = (TypeMenu) {
      "EPSI - B1"
    };
    NumMenu[42] = (TypeMenu) {
      "EPSI - B2"
    };
    NumMenu[43] = (TypeMenu) {
      "EPSI - B3"
    };
}
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  Initialisation();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("* RESERVATION * ");
  lcd.setCursor(0, 1);
  lcd.print("   * SALLES *   ");
  delay(2000);
  pinMode(SELECT, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
}
void loop() {
  Boutons();
}
void Boutons() {
  if ( millis() > Tempo ) {
    if (digitalRead(LEFT) == LOW) {
      Serial.print("LEFT");
      SousMenu--;
      Tempo = millis() + 250;
      AfficheMenu();
    } else if (digitalRead(DOWN) == LOW) {
      Serial.print("DOWN");
      Menu = Menu - 10;
      Tempo = millis() + 250;
      SousMenu = 0 ;
      AfficheMenu();
    } else if (digitalRead(UP) == LOW) { 
      Serial.print("UP");
      Menu = Menu + 10;
      Tempo = millis() + 250;
      SousMenu = 0;
      AfficheMenu();
    } else if (digitalRead(RIGHT) == LOW) {
      Serial.print("RIGHT");
      SousMenu++;
      Tempo = millis() + 250;
      AfficheMenu();
    } else if (digitalRead(SELECT) == LOW) {
      Serial.print("SELECT");
      Tempo = millis() + 750;
      if(SousMenu > 0 && digitalRead(led1) == HIGH) {//réservable
        digitalWrite(led2 , HIGH);
        digitalWrite(led1 , LOW);
        if(Menu == 30)
        {
          horaire3 = 1;  
        }
        if(Menu == 40)
        {
          horaire4 = 1;  
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("   * SALLE *   ");
        lcd.setCursor(0, 1);
        lcd.print(" * RESERVEE * ");
      } else if (SousMenu == 0) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(" * CHOISISSEZ * ");
          lcd.setCursor(0, 1);
          lcd.print(" * UNE CLASSE *");
        } else {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("   * SALLE *   ");
          lcd.setCursor(0, 1);
          lcd.print("* INDISPONIBLE *");
        }
        delay(2000);
        lcd.clear();
        Menu = 10;
        AfficheMenu();
    }
  }
}
void AfficheMenu() {
  if (Menu == 0 ) {
    Menu = 40;
  }
  if (Menu == 50 || Menu == 65526) {
    Menu = 10;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(NumMenu[Menu].Menu);
  lcd.setCursor(0, 1);
  if ( SousMenu < 0 ) {
    SousMenu = 3;
  }
  if (NumMenu[Menu + SousMenu].Menu == "") {
    SousMenu = 3;
  }
  if (Menu + SousMenu > Menu) {
    lcd.print(NumMenu[Menu + SousMenu].Menu);
  }
  if (Menu == 10 || Menu == 20 || (Menu == 30 && horaire3 == 1) || (Menu == 40 && horaire4 == 1)) {
    digitalWrite(led2 , HIGH);
    digitalWrite(led1 , LOW);
  }
  else{
    digitalWrite(led1 , HIGH);
    digitalWrite(led2 , LOW);
  }
  Serial.print(Menu);
  Serial.print(SousMenu);
}
