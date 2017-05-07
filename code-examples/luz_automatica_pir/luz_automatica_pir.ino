const int rele = 10;
const int led = 13;
const int pir = 2;
const char *author = "Rudy Rafael Ramirez Caero";
int state;
void setup() {
  // put your setup code here, to run once:
  pinMode(rele,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(pir,INPUT);
  state = digitalRead(pir);
  digitalWrite(rele,LOW);
  digitalWrite(led,LOW);
  attachInterrupt(0,action,CHANGE);
  Serial.begin(9600);
  Serial.println("Inicializacion de puerto serial realizada correctamente");

}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(pir);
  if(Serial.available() > 0){
    char cmd = Serial.read();
    switch(cmd){
      case 'a': encenderLuz();
                break; 
      case 'b': apagarLuz();
                break;
    }
  }
  Serial.println("PIR VALUE:");
  Serial.println(value);
  Serial.println("ESTADO PIR");
  Serial.println(state);
  delay(1000);
  
}

void encenderLuz(){
  Serial.println("encender");
  digitalWrite(led,HIGH);
  digitalWrite(rele,HIGH);                 
}

void apagarLuz(){
  Serial.println("apagar");
  digitalWrite(led,LOW);
  digitalWrite(rele,LOW);  
}

void realizarAccion(){
  if(state){
    encenderLuz();
  }else{
    apagarLuz();
  }
}

void action(){
  Serial.println("Interrupcion activada:cambio de estado");
  state = digitalRead(pir);
  Serial.println("interrupt state:");
  Serial.println(state);
  realizarAccion();
}
