const int inputA1 = 8;       // Sol motorların Kontrolü
const int inputA2 = 9;       // Sol motorların Kontrolü
const int inputB1 = 10;       // Sağ motorların Kontrolü
const int inputB2 = 11;       // Sağ motorların Kontrolü
const int Enable_A = 5;      
const int Enable_B = 6;

int speed = 250;

String inputString="";
char junk;

void setup() {
  pinMode(inputA1, OUTPUT);
  pinMode(inputA2, OUTPUT);
  pinMode(inputB1, OUTPUT);
  pinMode(inputB2, OUTPUT);
  pinMode(Enable_A, OUTPUT);
  pinMode(Enable_B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read();
      inputString += inChar;
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }
    if(inputString == "1"){
    analogWrite(Enable_A, speed);
    analogWrite(Enable_B, speed);
    digitalWrite(inputA1, HIGH);
    digitalWrite(inputA2, LOW);
    digitalWrite(inputB1 , HIGH);
    digitalWrite(inputB2, LOW);
    }else if(inputString == "2"){
    analogWrite(Enable_A, speed);
    analogWrite(Enable_B, speed);
    digitalWrite(inputA1, LOW);
    digitalWrite(inputA2, HIGH);
    digitalWrite(inputB1 , LOW);
    digitalWrite(inputB2, HIGH);
    }else if(inputString == "3"){
    analogWrite(Enable_A, speed);
    analogWrite(Enable_B, speed);
    digitalWrite(inputA1, HIGH);
    digitalWrite(inputA2, LOW);
    digitalWrite(inputB1 , LOW);
    digitalWrite(inputB2, HIGH);
    }else if(inputString == "4"){
    analogWrite(Enable_A, speed);
    analogWrite(Enable_B, speed);
    digitalWrite(inputA1, LOW);
    digitalWrite(inputA2, HIGH);
    digitalWrite(inputB1 , HIGH);
    digitalWrite(inputB2, LOW);
    }else if(inputString == "5"){
    digitalWrite(inputA1, LOW);
    digitalWrite(inputA2, LOW);
    digitalWrite(inputB1 , LOW);
    digitalWrite(inputB2, LOW);
    }
    inputString = "";
  }
}
