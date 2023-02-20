
int pines[5] = {8, 9, 10, 11, 12};
int valores[5] = {16, 8, 4, 2, 1};  
int salida[5] = {1, 0, 1, 0, 1};

void setup(){
  for(int i = 0; i < 5; i++){
    pinMode(pines[i], OUTPUT);
  }
}
 
void loop(){
  int a = 1;
  int b = 3;
  repeat(a);
  delay(20000);
  repeat(b);
}

void repeat(int valor){
  for(int i = 0; i < 32; i+=valor){
    validar(i);
    iluminar();
    delay(3000);
  }
}

void validar(int valor){
  for(int i = 0; i < 5; i++){
    if(valor == valores[i]){
      salida[i] = 1;
      valor = valor - valores[i];
    }else if(valor > valores[i]){
      salida[i] = 1;
      valor = valor - valores[i];
    }else if(valor < valores[i]){
      salida[i] = 0;
    }
  }
}

void iluminar(){
  for(int i = 0; i < 5; i++){
    if(salida[i] == 1){
      digitalWrite(pines[i], HIGH);
    }else{
      digitalWrite(pines[i], LOW);
    }
  }
}
