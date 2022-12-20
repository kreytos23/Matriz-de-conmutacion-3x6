//Pines
int contadorBoton = 10;
int configBoton = A0;
int dip1 = 10;
int dip2 = 11;

int salida1 = 9;
int salida2 = 8;
int salida3 = 7;
int salida4 = 6;
int salida5 = 5;
int salida6 = 4;

int entrada1 = A1;
int entrada2 = A2;
int entrada3 = A3;

//Variables
volatile int contador = 0;
volatile int estadoConfig = 0;

int bandera1Control1 = -1;
int bandera2Control1 = -1;

int bandera1Control2 = -1;
int bandera2Control2 = -1;

int bandera1Control3 = -1;
int bandera2Control3 = -1;

int bandera1Control4 = -1;
int bandera2Control4 = -1;

int bandera1Control5 = -1;
int bandera2Control5 = -1;

int bandera1Control6 = -1;
int bandera2Control6 = -1;

void setup() {
  Serial.begin(9600);

  pinMode(salida1, OUTPUT);
  pinMode(salida2, OUTPUT);
  pinMode(salida3, OUTPUT);
  pinMode(salida4, OUTPUT);
  pinMode(salida5, OUTPUT);
  pinMode(salida6, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(2), cambiarEstadoConfig, RISING);
  attachInterrupt(digitalPinToInterrupt(3), contadorIncremento, RISING);

  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);
  pinMode(entrada3, INPUT);
  pinMode(dip1, INPUT);
  pinMode(dip2, INPUT);
}

void loop() {
  Serial.print("Contador: ");
  Serial.println(contador);
  Serial.print("Estado: " );
  Serial.println(estadoConfig);

  habilitarSalidaConEntrada(bandera1Control1, bandera2Control1, salida1);
  habilitarSalidaConEntrada(bandera1Control2, bandera2Control2, salida2);
  habilitarSalidaConEntrada(bandera1Control3, bandera2Control3, salida3);
  habilitarSalidaConEntrada(bandera1Control4, bandera2Control4, salida4);
  habilitarSalidaConEntrada(bandera1Control5, bandera2Control5, salida5);
  habilitarSalidaConEntrada(bandera1Control6, bandera2Control6, salida6);
}

int configurarSalida(int &bandera1, int &bandera2){
  bandera1 = digitalRead(dip1);
  bandera2 = digitalRead(dip2);
}

void contadorIncremento(){
  delayMicroMili();
  contador++;
  if(contador >= 7){
    contador = 1;
  }
}

void habilitarSalidaConEntrada(int bandera1, int bandera2, int salida){
  if(bandera1 == 0 && bandera2 == 0){
    for(int i = 0; i <= 255; i++){
      digitalWrite(salida, digitalRead(entrada1));
    }
  }else if(bandera1 == 0 && bandera2 == 1){
    for(int i = 0; i <= 255; i++){
      digitalWrite(salida, digitalRead(entrada2));
    }
  }else if(bandera1 == 1 && bandera2 == 0){
    for(int i = 0; i <= 255; i++){
      digitalWrite(salida, digitalRead(entrada3));
    } 
  }else{
    digitalWrite(salida, LOW);
  }
}

void cambiarEstadoConfig(){
  delayMicroMili();
  if(estadoConfig == 0){
    estadoConfig = 1;
  }else{
    estadoConfig = 0;
  }
  
  if(estadoConfig == 1){
    switch(contador){
      case 1:
        Serial.println("Configurando 1");
        configurarSalida(bandera1Control1, bandera2Control1);
      break;
      case 2:
        Serial.println("Configurando 2");
        configurarSalida(bandera1Control2, bandera2Control2);
      break;
      case 3:
        Serial.println("Configurando 3");
        configurarSalida(bandera1Control3, bandera2Control3);
      break;
      case 4:
        Serial.println("Configurando 4");
        configurarSalida(bandera1Control4, bandera2Control4);
      break;
      case 5:
        Serial.println("Configurando 5");
        configurarSalida(bandera1Control5, bandera2Control5);
      break;
      case 6:
        Serial.println("Configurando 6");
        configurarSalida(bandera1Control6, bandera2Control6);
      break;
    }
  }
}
void delayMicroMili(){
  for(int i = 0; i<3; i++){
    delayMicroseconds(16383);
  }  
}
