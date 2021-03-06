float TC[7];// regustro de las temperaturas en el momento
float TCAUX[7];// vvector auxiliar para ordenar las temperaturas
int aux[7];// auxiliar para registrar valores
int valor[100];//vector para registrar todas llas temperaturas del ciclo for
int Pin=A2;//pin en el que esta conectado el sensor
float value= analogRead(Pin);//registro del valor
float aux1;//auxiliar para hacer la media
void setup() {//seteo de variables
  //analogReference(INTERNAL);

  Serial.begin(9600);
}

void loop() {
  int n=100;//el valor de mediciones que hara el for
  
  aux[0]=analogRead(Pin);
  TC[0]=(aux[0]*50)/1023;
  Serial.print(TC[0]);
    Serial.print("\n");
  aux[1]=analogRead(Pin);
  TC[1]=(aux[1]*50)/1023;
  Serial.print(TC[1]);
    Serial.print("\n");
  aux[2]=analogRead(Pin);
  TC[2]=(aux[2]*50)/1023;
  Serial.print(TC[2]);
    Serial.print("\n");
  aux[3]=analogRead(Pin);
  TC[3]=(aux[3]*50)/1023;
  Serial.print(TC[3]);
    Serial.print("\n");
  aux[4]=analogRead(Pin);
  TC[4]=(aux[4]*50)/1023;
  Serial.print(TC[4]);
    Serial.print("\n");
  aux[5]=analogRead(Pin);
  TC[5]=(aux[5]*50)/1023;
  Serial.print(TC[5]);
    Serial.print("\n");
  TC[6]=0;
         
  
  for(int i = 0 ; i < n ; i++)
  {
    if(TC[6]==0)//si el valor de TC[6] es cero hace una primera medicion vacia
    {
      aux[6]=analogRead(Pin);
      Serial.print(aux[6]);
      TC[6]=(aux[6]*50)/1023;
    }
    
    else//si ya realizo una primer medicion solo registra valores de TC[6] y los recorre
    {
      TC[0]=TC[1];
      TC[1]=TC[2];
      TC[2]=TC[3];
      TC[3]=TC[4];
      TC[4]=TC[5];
      TC[5]=TC[6];
      valor[i]=analogRead(Pin);// guarda el valor de medicion
      TC[6]=(valor[i]*50)/1023;
    }
    TCAUX[0]=TC[0];
    TCAUX[1]=TC[1];
    TCAUX[2]=TC[2];
    TCAUX[3]=TC[3];
    TCAUX[4]=TC[4];
    TCAUX[5]=TC[5];
    TCAUX[6]=TC[6];
    
    
   for(int j = 0 ;j<7;j++)//arregla los datos de menor a mayor
      {
        if(TCAUX[j+1]>TCAUX[j]){
          aux1=TCAUX[j];
          TCAUX[j]=TCAUX[j+1];
          TCAUX[j+1]=aux1;
          }
      }
    Serial.print("\n\nLa temperatura actual es ");
    Serial.print(TC[6]);
    Serial.print("\n");
    Serial.print("La temperatura Promedio  es ");
    Serial.print(TCAUX[2]);
    Serial.print("\n\n");
    
    delay(1000);
    }
    
   delay(10000);
  
  }
