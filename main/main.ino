const int stepPinx = 2;      // Step motor adım pini
const int dirPinx = 5;       // Step motor yön pini
const int stepPiny = 3;      // Step motor adım pini
const int dirPiny = 6;       // Step motor yön pini
const int stepPinz = 4;      // Step motor adım pini
const int dirPinz = 7;       // Step motor yön pini

const int Enable_A = 44;      // sol motorların hız kontrolü için pwm çıkışı
const int Enable_B = 46;      // sağ motorların hız kontrolü için pwm çıkışı
const int inputA1 = 22;       // Sol motorların Kontrolü
const int inputA2 = 23;       // Sol motorların Kontrolü
const int inputB1 = 24;       // Sağ motorların Kontrolü
const int inputB2 = 25;       // Sağ motorların Kontrolü

String inputString="";
char junk;

void setup() {
  pinMode(Enable_A, OUTPUT);    //Çıkış olarak ayarlama
  pinMode(Enable_B, OUTPUT);
  pinMode(inputA1, OUTPUT);
  pinMode(inputA2, OUTPUT);
  pinMode(inputB1, OUTPUT);
  pinMode(inputB2, OUTPUT);
  
  pinMode(stepPinx,OUTPUT);    // Step motorların pinlerinin çıkış olarak ayarlanması
  pinMode(dirPinx,OUTPUT);
  pinMode(stepPiny,OUTPUT);
  pinMode(dirPiny,OUTPUT);
  pinMode(stepPinz,OUTPUT);
  pinMode(dirPinz,OUTPUT);
  Serial.begin(9600);         //Seri iletişimin başlatılması
}
void loop() {
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read();     //Giriş değerlerini oku.
      inputString += inChar;                 //Seri monitörden gelen değerleri stringe çevir.
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // Seri arabelleğin temizlenmesi
    if(inputString == "xileri"){         //1'e basıldığında motor hareket eder
      Sstep(stepPinx, dirPinx, HIGH, 500, 200); 
    }else if(inputString == "xgeri"){  
      Sstep(stepPinx, dirPinx,LOW, 500, 200);
    }else if(inputString == "ileri"){
      Mmotor("ileri", 150);
    }else if(inputString == "geri"){
      Mmotor("geri", 150);
    }else if(inputString == "sol"){
      Mmotor("sol", 150);
    }else if(inputString == "sag"){
      Mmotor("sag", 150);
    }else if(inputString == "dur"){
      MotorDur();
    }
    inputString = "";
  }
}
void Sstep(char steP, char dir, char yon, int hiz, int adim_sayisi){
  digitalWrite(dir,yon);
  for(int x = 0; x < adim_sayisi; x++){
  digitalWrite(steP,HIGH);
  delayMicroseconds(hiz);
  digitalWrite(steP,LOW);
  delayMicroseconds(hiz);
  }
}
void Mmotor(char Motoryon, int hizi){
  if(Motoryon == "ileri"){
    analogWrite(Enable_A, hizi);
    analogWrite(Enable_B, hizi);
    digitalWrite(inputA1, HIGH);
    digitalWrite(inputA2, LOW);
    digitalWrite(inputB1 , HIGH);
    digitalWrite(inputB2, LOW);
    }
    else if(Motoryon == "geri"){
    analogWrite(Enable_A, hizi);
    analogWrite(Enable_B, hizi);
    digitalWrite(inputA1, LOW);
    digitalWrite(inputA2, HIGH);
    digitalWrite(inputB1 , LOW);
    digitalWrite(inputB2, HIGH);
    }
    else if(Motoryon == "sol"){
    analogWrite(Enable_A, hizi);
    analogWrite(Enable_B, hizi);
    digitalWrite(inputA1, HIGH);
    digitalWrite(inputA2, LOW);
    digitalWrite(inputB1 , LOW);
    digitalWrite(inputB2, HIGH);
    }
    else if(Motoryon == "sag"){
    analogWrite(Enable_A, hizi);
    analogWrite(Enable_B, hizi);
    digitalWrite(inputA1, LOW);
    digitalWrite(inputA2, HIGH);
    digitalWrite(inputB1 , HIGH);
    digitalWrite(inputB2, LOW);
    }
  }
void MotorDur(){
  digitalWrite(Enable_A, LOW);
  digitalWrite(Enable_B, LOW);
  }
