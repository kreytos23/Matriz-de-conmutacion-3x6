//Pines
int contadorBoton = 10;
int configBoton = A0;
int dip1 = 8;
int dip2 = 9;

int salida1 = 7;
int salida2 = 6;
int salida3 = 5;
int salida4 = 4;
int salida5 = 3;
int salida6 = 2;

int entrada1 = A1;
int entrada2 = A2;
int entrada3 = A3;


//Variables

int contador = 0;
int estadoConfig = 0;

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
  
  pinMode(contadorBoton, INPUT);
  pinMode(configBoton, INPUT);
  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);
  pinMode(entrada3, INPUT);
  pinMode(dip1, INPUT);
  pinMode(dip2, INPUT);
  
}

void loop() {

  if(digitalRead(contadorBoton) == HIGH){
    contador++;
    delay(300);
  }
  if(contador >= 7){
    contador = 0;
    delay(300);
  }

  Serial.println(contador);

  if(digitalRead(configBoton) == HIGH){
     delay(300);
    if(estadoConfig == 0){
      estadoConfig = 1;
    }else{
      estadoConfig = 0;
    }
  }

  if(estadoConfig == 1){
    switch(contador){
      case 1:
        Serial.println("Configurando 1");
        bandera1Control1 = configurarSalida(1);
        bandera2Control1 = configurarSalida(2);
        
      break;
      case 2:
        Serial.println("Configurando 2");
        bandera1Control2 = configurarSalida(1);
        bandera2Control2 = configurarSalida(2);
      break;
      case 3:
        Serial.println("Configurando 3");
        bandera1Control3 = configurarSalida(1);
        bandera2Control3 = configurarSalida(2);
      break;
      case 4:
        Serial.println("Configurando 4");
        bandera1Control4 = configurarSalida(1);
        bandera2Control4 = configurarSalida(2);
      break;
      case 5:
        Serial.println("Configurando 5");
        bandera1Control5 = configurarSalida(1);
        bandera2Control5 = configurarSalida(2);
      break;
      case 6:
        Serial.println("Configurando 6");
        bandera1Control6 = configurarSalida(1);
        bandera2Control6 = configurarSalida(2);
      break;
    }
  }

  if(contador == 0){
    habilitarSalidaConEntrada(bandera1Control1, bandera2Control1, salida1);
    habilitarSalidaConEntrada(bandera1Control2, bandera2Control2, salida2);
    habilitarSalidaConEntrada(bandera1Control3, bandera2Control3, salida3);
    habilitarSalidaConEntrada(bandera1Control4, bandera2Control4, salida4);
    habilitarSalidaConEntrada(bandera1Control5, bandera2Control5, salida5);
    habilitarSalidaConEntrada(bandera1Control6, bandera2Control6, salida6);
  }
}

int configurarSalida(int dip){
    if(dip == 1){
      return digitalRead(dip1);
    }else{
      return digitalRead(dip2);
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


