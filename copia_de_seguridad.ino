#define uno 1
#define dos 2
#define tres 4
#define cuatro 8
#define cinco 16
#define seis 32
#define siete 64
#define ocho 128

int latchPin = 10 ;        //Pin conectado a ST_CP of 74HC595 (Verde)
int clockPin = 12;        //Pin conectado a SH_CP of 74HC595 (Amarillo)
int dataPin = 11;          //Pin connected to DS of 74HC595  (Azul)

int boton1 = 0;
int boton2= 0;
int boton3 =0;
int boton4 = 0;
int boton5 = 0;

boolean paso1 = true;
boolean paso2 = true;
boolean paso3 = true;
boolean paso4 = true;
boolean paso5 = false;

boolean llave1 =true;
boolean llave2 =true;
boolean llave3 =true;

unsigned long antes = 0;
unsigned long ahora = 0;
int posicion = 0;
int fijo = 0;

boolean limiteY = false;
boolean limiteX = false;

boolean ArribaAbajo = true;
boolean DerechaIzquierda = true;

char AccionAnterior;
char direccion;
int led = 13;

int N=0;
int M=0;
int i=0;
int w;
int j = 0;
//Punto donde aparece el puntero (es decir, el centro del objeto que creamos)
int x = 4;
int  y = 1;

byte matrix[8][8]={    {0,0,0,0,0,0,0,0},
                       {0,1,1,1,1,1,1,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},                          
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},  

                  };



void setup()
   {      pinMode(latchPin, OUTPUT);
          pinMode(clockPin, OUTPUT);
          pinMode(dataPin, OUTPUT);

          pinMode(2, OUTPUT);
          pinMode(3, OUTPUT);
          pinMode(4, OUTPUT);
          pinMode(5, OUTPUT);
          pinMode(6, OUTPUT);
          pinMode(7, OUTPUT);
          pinMode(8, OUTPUT);
          pinMode(9, OUTPUT);

          pinMode(14, INPUT);
          pinMode(15, INPUT);
          pinMode(16, INPUT);
          pinMode(17, INPUT);

          pinMode(led,OUTPUT);
 Serial.begin(9600);
   }


   
void loop() 
   {
             
             lectura();
             boton1 = digitalRead(14); 
             if (boton1 == HIGH && paso1 == true){  
                    
                 FiguraUNO('U');
                 
                  paso1 = false; 
                                                                       
                      }
                      
            if (boton1 == LOW && paso1 == false){ paso1 = true;} 
            

           boton2 = digitalRead(15); 
             if (boton2 == HIGH && paso2 == true){                               

                 FiguraUNO('D');
                                
                  paso2 = false;                
                      }
                      
              if (boton2 == LOW && paso2 == false){ paso2 = true;} 
 

            boton3 = digitalRead(16); 
             if (boton3 == HIGH && paso3 == true){                 

                  FiguraUNO('L');
                  
                  paso3 = false;                 
                      }
              if (boton3 == LOW && paso3 == false){ paso3 = true;} 


           boton4 = digitalRead(17); 
             if (boton4 == HIGH && paso4 == true){                 

                  FiguraUNO('R');
                             
                  paso4 = false;                 
                      }
             if (boton4 == LOW && paso4 == false){ paso4 = true;} 


          boton5 = digitalRead(18);
          if(boton5==HIGH || paso5 == true){
            paso5=true;
            disparo(); 
                      
           
             }
          
   }


void disparo(){



  if(llave1==true){ antes = millis(); /*Serial.print ("El tiempo antes era: "); Serial.println(antes);*/ llave1=false;}
  
  if(llave2==true){ llave2=false; // //Solo se ejecuta la primera vez que se dispara
       if(direccion == 'U' || direccion == 'D'){posicion=y; fijo = x; ArribaAbajo = true;  DerechaIzquierda = false; }  else{ fijo=y; posicion = x; ArribaAbajo = false;  DerechaIzquierda = true;}
           if(direccion=='U'|| direccion == 'L'){llave3 = true; N=2; M=1;} else{llave3 = false; N=-2; M=-1;}
            } 
            
   if(posicion+N <=-1 || posicion+N >=8){llave1=true; paso5 = false; llave2=true;} //DEBE SER UNA FUNCION, EN ESTA CASO CUANDO EL DISPARO SE HACE EN EL LÍMITE, RESETEA TODO E IMPIDE EL DISPARO

  

  if(ArribaAbajo == true){
  //Serial.println(posicion+N); 
 switch(posicion+N){
  case 0: matrix[posicion+N][fijo] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[posicion+N][fijo]=0; if(llave3==true){ posicion++;} else{llave1=true; paso5 = false; llave2=true;} llave1=true;}   break; 
  case 1: matrix[posicion+N][fijo] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[posicion+N][fijo]=0; if(llave3==true){ posicion++;} else{posicion--;}  llave1=true;}   break; 
  case 2: matrix[posicion+N][fijo] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[posicion+N][fijo]=0; if(llave3==true){ posicion++;} else{posicion--;}  llave1=true;}   break; 
  case 3: matrix[posicion+N][fijo] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[posicion+N][fijo]=0; if(llave3==true){ posicion++;} else{posicion--;}  llave1=true;}   break;  
  case 4: matrix[posicion+N][fijo] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[posicion+N][fijo]=0; if(llave3==true){ posicion++;} else{posicion--;}  llave1=true;}   break; 
  case 5:  matrix[posicion+N][fijo] = 1;  ahora = millis(); if(ahora-antes>=250){ matrix[posicion+N][fijo]=0; if(llave3==true){ posicion++;} else{posicion--;}  llave1=true;}   break; 
  case 6: matrix[posicion+N][fijo] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[posicion+N][fijo]=0; if(llave3==true){ posicion++;} else{posicion--;}  llave1=true;}   break; 
  case 7: matrix[posicion+N][fijo] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[posicion+N][fijo]=0; if(llave3==true){ paso5 = false; llave2=true; llave1=true;} else{posicion--;} }  break;   
    }

     switch(w){
  case 0: if(matrix[posicion+N+M][fijo]==1){w++; } break; 
  case 1: if(llave1==true){ matrix[posicion+N][fijo]=0;  llave1=true; paso5 = false; llave2=true;  w=0;} break;
       }
      
  }




 if(DerechaIzquierda == true){

 switch(posicion+N){
  case 0: matrix[fijo][posicion+N] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[fijo][posicion+N]=0; if(llave3==true){posicion++;} else{paso5= false; llave2=true; llave1=true;} llave1=true;}   break; 
  case 1: matrix[fijo][posicion+N] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[fijo][posicion+N]=0; if(llave3==true){posicion++;} else{posicion--;} llave1=true;}   break; 
  case 2: matrix[fijo][posicion+N] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[fijo][posicion+N]=0; if(llave3==true){posicion++;} else{posicion--;} llave1=true;}   break; 
  case 3: matrix[fijo][posicion+N] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[fijo][posicion+N]=0; if(llave3==true){posicion++;} else{posicion--;} llave1=true;}   break;  
  case 4: matrix[fijo][posicion+N] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[fijo][posicion+N]=0; if(llave3==true){posicion++;} else{posicion--;} llave1=true;}   break; 
  case 5: matrix[fijo][posicion+N] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[fijo][posicion+N]=0; if(llave3==true){posicion++;} else{posicion--;} llave1=true;}   break; 
  case 6: matrix[fijo][posicion+N] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[fijo][posicion+N]=0; if(llave3==true){posicion++;} else{posicion--;} llave1=true;}   break; 
  case 7: matrix[fijo][posicion+N] = 1;  ahora = millis();  if(ahora-antes>=250){ matrix[fijo][posicion+N]=0; if(llave3==true){paso5= false; llave2=true; llave1=true;} else{posicion--;} }  break; 
                                 }

     switch(w){
  case 0: if(matrix[fijo][posicion+N+M]==1){w++; } break; 
  case 1: if(llave1==true){ matrix[fijo][posicion+N]=0;  llave1=true; paso5 = false; llave2=true;  w=0;} break;
       }
                   } 
           }
   
                           
//Crea una figura parecida a una nave
void FiguraUNO(char eleccion){
  
 // if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez al inicio del disparo
//  Serial.println(direccion);  //Hay que leer constantemente, pero para el disparo solo lo lee unna vez al principio
  direccion = eleccion;

  
switch(eleccion){

  case 'U':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                                               
                  
                  if(y>=6){limiteY = true; } else {limiteY=false;} //Si el limite es verdadero impide el incremento //LIMITE, HAY QUE TENER EN CUENTA EL PUNTERO
                  if(AccionAnterior == 'U' && limiteY==false){ y++; }
                   Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);                  
                    
                  matrix[y+1][x] = 1;       
                  matrix[y][x+1]=1;
                  matrix[y][x-1]=1;   //Se dibuja el objeto
                  matrix[y][x] = 1;   
                  AccionAnterior = 'U';  
                              
                  break;

  case 'D':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                                 
                  
                  if(y<=1){limiteY = true;} else {limiteY=false;}
                  if(AccionAnterior=='D' && limiteY==false){ y--; }
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  matrix[y-1][x] = 1;
                  matrix[y][x+1]=1;  //Se dibuja el objeto
                  matrix[y][x-1]=1;
                  matrix[y][x] = 1; 
                  AccionAnterior = 'D';
                  break;

  case 'L':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                              
                 
                   if(x>=6){limiteX = true;} else {limiteX=false;} //Si el limite es verdadero impide el incremento //LIMITE, HAY QUE TENER EN CUENTA EL PUNTERO
                   if(AccionAnterior == 'L' && limiteX==false){ x++; }
                    Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  matrix[y][x] = 1;
                  matrix[y+1][x]=1;  //Se dibuja el objeto
                  matrix[y-1][x]=1;                
                  matrix[y][x+1] = 1;  //Este es el puntero
                  AccionAnterior='L';
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;               
                  
                   if(x<=1){limiteX = true;} else {limiteX=false;}
                   if(AccionAnterior=='R' && limiteX==false){ x--; }
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                   
                  matrix[y][x] = 1;
                  matrix[y+1][x]=1;  //Se dibuja el objeto
                  matrix[y-1][x]=1;                
                  matrix[y][x-1] = 1;  //Este es el puntero  
                  AccionAnterior='R';
                  break;
}
  
}

//Crea un cuadrado
void FiguraDOS(char eleccion){
  
  if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez al inicio del disparo

  
switch(eleccion){

  case 'U':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;     
                    
                             
                 y++;
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  matrix[y][x] = 1;                                     
                  matrix[y+1][x] = 1;
                  matrix[y+1][x-1]=1;
                  matrix[y][x-1]=1;   //Se dibuja el objeto                   
                    
                  break;

  case 'D':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                  y--;
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  matrix[y+1][x] = 1;
                  matrix[y+1][x-1]=1;
                  matrix[y][x-1]=1;   //Se dibuja el objeto
                  matrix[y][x] = 1;    
                  break;


  case 'L':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;              
                  x++;
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  matrix[y+1][x] = 1;
                  matrix[y+1][x-1]=1;
                  matrix[y][x-1]=1;   //Se dibuja el objeto
                  matrix[y][x] = 1;    
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                  x--;
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  matrix[y+1][x] = 1;
                  matrix[y+1][x-1]=1;
                  matrix[y][x-1]=1;   //Se dibuja el objeto
                  matrix[y][x] = 1;    
                  break;
}
  
}


//Crea un un punto 
void FiguraTRES(char eleccion){
  
  if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez al inicio del disparo
  
switch(eleccion){

  case 'U':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                 
                  y++;
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto
                  
                  break;

  case 'D':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                  y--;
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  
                   matrix[y][x] = 1;     //Se dibuja el objeto
                   
                  break;


  case 'L':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;              
                  x++;
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto
                  
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                  x--;
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto 
                  
                  break;
}
  
}

//Crea una linea de 3 puntos (tetris)
void FiguraCUATRO(char eleccion){
  
  if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez

  
switch(eleccion){

  case 'U':            
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                 
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);                  
                 if(AccionAnterior == 'D' || AccionAnterior=='U'){ y++; }
                   
                  matrix[y][x] = 1;                                 
                  matrix[y+1][x]=1;    //Se dibuja el objeto
                  matrix[y-1][x] = 1; 
                                   
                  AccionAnterior = 'U';                  
                  break;

  case 'D':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                  
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                 if(AccionAnterior == 'D' || AccionAnterior == 'U'){ y--; }
                 
                  matrix[y][x] = 1;     //Se dibuja el objeto                
                  matrix[y+1][x]=1;
                  matrix[y-1][x] = 1;

                  AccionAnterior = 'D';  
                  break;


  case 'L':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;              
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  if(AccionAnterior == 'L' || AccionAnterior=='R'){ x++; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                 
                  matrix[y][x-1] = 1;
                  matrix[y][x+1] = 1;
                 
                  AccionAnterior = 'L';  
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                   if(AccionAnterior == 'L' || AccionAnterior=='R'){ x--; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                  
                  matrix[y][x-1] = 1;
                  matrix[y][x+1] = 1;
                  
                  AccionAnterior = 'R';  
                  break;
}
  
}


//Crea una linea de 3 puntos (tetris)
void FiguraCINCO(char eleccion){
  
  if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez

  
switch(eleccion){

  case 'U':            
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                 
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);                  
                 if(AccionAnterior == 'D' || AccionAnterior=='U'){ y++; }
                   
                  matrix[y][x] = 1;                                 
                  matrix[y-1][x]=1;    //Se dibuja el objeto
                  matrix[y+1][x-1] = 1;
                  matrix[y][x-1]= 1; 
                                   
                  AccionAnterior = 'U';                  
                  break;

  case 'D':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                  
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                 if(AccionAnterior == 'D' || AccionAnterior == 'U'){ y--; }
                 
                  matrix[y][x] = 1;                                 
                  matrix[y-1][x]=1;    //Se dibuja el objeto
                  matrix[y+1][x-1] = 1;
                  matrix[y][x-1]= 1; 
                  
                  AccionAnterior = 'D';  
                  break;


  case 'L':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;              
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  if(AccionAnterior == 'L' || AccionAnterior=='R'){ x++; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto      
                  matrix[y+1][x]=1;           
                  matrix[y+1][x-1] = 1;
                  matrix[y][x+1] = 1;
                 
                  AccionAnterior = 'L';  
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                   if(AccionAnterior == 'L' || AccionAnterior=='R'){ x--; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto      
                  matrix[y+1][x]=1;           
                  matrix[y+1][x-1] = 1;
                  matrix[y][x+1] = 1;
                  
                  AccionAnterior = 'R';  
                  break;
}
  
}

void FiguraSEIS(char eleccion){
  
  if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez

  
switch(eleccion){

  case 'U':            
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                 
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);                  
                 if(AccionAnterior == 'D' || AccionAnterior=='U'){ y++; }
                   
                  matrix[y][x] = 1; 
                  matrix[y][x+1] = 1;
                  matrix[y+1][x+1] = 1;
                  matrix[y-1][x] = 1;                                
                  

                                   
                  AccionAnterior = 'U';                  
                  break;

  case 'D':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                  
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                 if(AccionAnterior == 'D' || AccionAnterior == 'U'){ y--; }
                 
                  matrix[y][x] = 1; 
                  matrix[y][x+1] = 1;
                  matrix[y+1][x+1] = 1;
                  matrix[y-1][x] = 1;  

                  AccionAnterior = 'D';  
                  break;


  case 'L':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;              
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  if(AccionAnterior == 'L' || AccionAnterior=='R'){ x++; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                 
                  matrix[y][x+1] = 1;
                  matrix[y+1][x] = 1;
                  matrix[y+1][x-1] = 1;
                 
                  AccionAnterior = 'L';  
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                   if(AccionAnterior == 'L' || AccionAnterior=='R'){ x--; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                 
                  matrix[y][x+1] = 1;
                  matrix[y+1][x] = 1;
                  matrix[y+1][x-1] = 1;
                  
                  AccionAnterior = 'R';  
                  break;
}
  
}




void FiguraSIETE(char eleccion){
  
  if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez

  
switch(eleccion){

  case 'U':            
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                 
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);                  
                 if(AccionAnterior == 'D' || AccionAnterior=='U'){ y++; }
                   
                  matrix[y][x] = 1;                                 
                  matrix[y+1][x]=1;    //Se dibuja el objeto
                  matrix[y-1][x] = 1; 
                  matrix[y-1][x-1] = 1;
                                   
                  AccionAnterior = 'U';                  
                  break;

  case 'D':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                  
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                 if(AccionAnterior == 'D' || AccionAnterior == 'U'){ y--; }
                 
                  matrix[y][x] = 1;     //Se dibuja el objeto                
                  matrix[y+1][x]=1;
                  matrix[y+1][x-1] = 1;
                  matrix[y-1][x]=1;

                  AccionAnterior = 'D';  
                  break;


  case 'L':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;              
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  if(AccionAnterior == 'L' || AccionAnterior=='R'){ x++; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                 
                  matrix[y][x-1] = 1;
                  matrix[y+1][x-1] = 1;
                  matrix[y][x+1] = 1;
                 
                  AccionAnterior = 'L';  
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                   if(AccionAnterior == 'L' || AccionAnterior=='R'){ x--; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                  
                  matrix[y][x-1] = 1;
                  matrix[y][x+1] = 1;
                  matrix[y-1][x+1] = 1;
                  
                  AccionAnterior = 'R';  
                  break;
}
  
}

void FiguraOCHO(char eleccion){
  
  if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez

  
switch(eleccion){

  case 'U':            
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                 
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);                  
                 if(AccionAnterior == 'D' || AccionAnterior=='U'){ y++; }
                   
                  matrix[y][x] = 1;                                 
                  matrix[y+1][x]=1;    //Se dibuja el objeto
                  matrix[y-1][x] = 1; 
                  matrix[y-1][x+1] = 1;
                                   
                  AccionAnterior = 'U';                  
                  break;

  case 'D':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                  
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                 if(AccionAnterior == 'D' || AccionAnterior == 'U'){ y--; }
                 
                  matrix[y][x] = 1;     //Se dibuja el objeto                
                  matrix[y+1][x]=1;
                  matrix[y+1][x-1] = 1;
                  matrix[y-1][x]=1;

                  AccionAnterior = 'D';  
                  break;


  case 'L':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;              
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  if(AccionAnterior == 'L' || AccionAnterior=='R'){ x++; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                 
                  matrix[y][x-1] = 1;
                  matrix[y-1][x-1] = 1;
                  matrix[y][x+1] = 1;
                 
                  AccionAnterior = 'L';  
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                   if(AccionAnterior == 'L' || AccionAnterior=='R'){ x--; }
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                  
                  matrix[y][x-1] = 1;
                  matrix[y][x+1] = 1;
                  matrix[y+1][x+1] = 1;
                  
                  AccionAnterior = 'R';  
                  break;
}
  
}

//Crea una linea de 3 puntos con borrado especial(pong)
void FiguraNUEVE(char eleccion){
  
  if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez

  
switch(eleccion){

//Solo se usan las teclas L y R, hay que colocar márgen de límites y una salida de poscion en el punto (0,4)

  case 'L':            
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
             
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  x++; 
                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                 
                  matrix[y][x-1] = 1;
                  matrix[y][x+1] = 1;
                 
                  AccionAnterior = 'L';  
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  x--;                  
                  matrix[y][x] = 1;     //Se dibuja el objeto                  
                  matrix[y][x-1] = 1;
                  matrix[y][x+1] = 1;
                  
                  AccionAnterior = 'R';  
                  break;
}
  
}

//Crea una nave

void FiguraDIEZ(char eleccion){
  
  if(llave2==true) {direccion = eleccion; } //Se ejecuta una sola vez al inicio del disparo
  
switch(eleccion){

  case 'U':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                               
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                  if(AccionAnterior == 'U'){ y++; }
                  
                  matrix[y+1][x] = 1;
                  matrix[y][x+1]=1;
                  matrix[y][x-1]=1;   //Se dibuja el objeto
                  matrix[y][x] = 1;
                  matrix[y-1][x+1]= 1;
                  matrix[y-1][x-1] = 1;   
                  AccionAnterior = 'U'; 
                  break;

  case 'D':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;                
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                   if(AccionAnterior=='D'){ y--; }
                  matrix[y-1][x] = 1;
                  matrix[y][x+1]=1;  //Se dibuja el objeto
                  matrix[y][x-1]=1;
                  matrix[y][x] = 1; 
                  matrix[y+1][x+1]=1;
                  matrix[y+1][x-1]=1;
                  AccionAnterior = 'D';
                  break;

  case 'L':       matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;              
                  
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                   if(AccionAnterior == 'L'){ x++; }
                   
                  matrix[y][x] = 1;
                  matrix[y+1][x]=1;  //Se dibuja el objeto
                  matrix[y-1][x]=1;                
                  matrix[y][x+1] = 1;  //Este es el puntero
                  matrix[y+1][x-1] = 1;
                  matrix[y-1][x-1] = 1;
                  AccionAnterior='L';
                  break;

  case 'R':
                  matrix[y-1][x] = 0;
                  matrix[y-1][x+1]=0;
                  matrix[y-1][x-1]=0;        
                  matrix[y][x] = 0;
                  matrix[y][x-1] = 0;
                  matrix[y][x+1] = 0;
                  matrix[y+1][x] = 0;
                  matrix[y+1][x+1]= 0;
                  matrix[y+1][x-1] = 0;
                 
                  Serial.print ("Valor X: "); Serial.print(x);  Serial.print ("   Valor Y: "); Serial.println(y);
                   if(AccionAnterior=='R'){ x--; }
                   
                  matrix[y][x] = 1;
                  matrix[y+1][x]=1;  //Se dibuja el objeto
                  matrix[y-1][x]=1;                
                  matrix[y][x-1] = 1;  //Este es el puntero  
                  matrix[y+1][x+1]=1;
                  matrix[y-1][x+1]=1;
                  AccionAnterior='R';                
                  break;
}
  
}


void lectura(){

  for(j=0; j<=7; j++){

     digitalWrite(2,HIGH);
     digitalWrite(3,HIGH);
     digitalWrite(4,HIGH);
     digitalWrite(5,HIGH);
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
     digitalWrite(8,HIGH);
     digitalWrite(9,HIGH);

   switch(j){
    case 0:  digitalWrite(latchPin, LOW);  shiftOut(dataPin, clockPin, MSBFIRST,uno );  digitalWrite(latchPin, HIGH);   break;
    case 1:  digitalWrite(latchPin, LOW);  shiftOut(dataPin, clockPin, MSBFIRST,dos );  digitalWrite(latchPin, HIGH);   break;   
    case 2:  digitalWrite(latchPin, LOW);  shiftOut(dataPin, clockPin, MSBFIRST,tres );  digitalWrite(latchPin, HIGH);  ;break;
    case 3:  digitalWrite(latchPin, LOW);  shiftOut(dataPin, clockPin, MSBFIRST,cuatro );  digitalWrite(latchPin, HIGH);  break;
    case 4:  digitalWrite(latchPin, LOW);  shiftOut(dataPin, clockPin, MSBFIRST,cinco );  digitalWrite(latchPin, HIGH);  break;
    case 5:  digitalWrite(latchPin, LOW);  shiftOut(dataPin, clockPin, MSBFIRST,seis );  digitalWrite(latchPin, HIGH);  break;   
    case 6:  digitalWrite(latchPin, LOW);  shiftOut(dataPin, clockPin, MSBFIRST,siete );  digitalWrite(latchPin, HIGH);  break;
    case 7:  digitalWrite(latchPin, LOW);  shiftOut(dataPin, clockPin, MSBFIRST,ocho );  digitalWrite(latchPin, HIGH);  break;


   }

    for(i =0; i<=7; i++){

   
      switch(i){
        case 0: if(matrix[i][j]== 1){ digitalWrite(2,LOW);} else { digitalWrite(2,HIGH);} break;
        case 1: if(matrix[i][j]== 1){ digitalWrite(3,LOW);} else { digitalWrite(3,HIGH);} break;
        case 2: if(matrix[i][j]== 1){ digitalWrite(4,LOW);} else { digitalWrite(4,HIGH);} break;
        case 3: if(matrix[i][j]== 1){ digitalWrite(5,LOW);} else { digitalWrite(5,HIGH);} break;
        case 4: if(matrix[i][j]== 1){ digitalWrite(6,LOW);} else { digitalWrite(6,HIGH);} break;
        case 5: if(matrix[i][j]== 1){ digitalWrite(7,LOW);} else { digitalWrite(7,HIGH);} break;
        case 6: if(matrix[i][j]== 1){ digitalWrite(8,LOW);} else { digitalWrite(8,HIGH);} break;
        case 7: if(matrix[i][j]== 1){ digitalWrite(9,LOW);} else { digitalWrite(9,HIGH);} break;
      }        
     
  }




    
   }
}


/* Cosas a hacer:
  IMPORTANTE: armar un nuevo HARDWARE con las conexiones que se harán en la GameMaker y ADAPTAR el código a él. Cambiar los LOW por HIGH y recontruir el eje X e Y.
  Corregir 3 bugs: al disparar y girar al mismo tiempo, el siguiente disparo se realiza en la posicion anterior;  Borrar unicamente la posción que ocupa un objeto y no un radio de un cuadrado del puntero; Quitar el disparo a la linea de tres puntos del pong
  Comprimir los matrix[y][x] de todos los objeto;
  Añadir un milis() a los pulsadores para que cuando se mantenga presiona el objeto o puntero vaya avanzando poco a poco.
  Añadir una funcion de disparo múltiple
  Al disparar eliminar un punto que esté encendido (dejarlo en LOW , o destruirlo) Se añadira una funcion dentro del propio pisparo para tal propósito
  Al disparar eliminar un OBJETO, se empleara una funcion
  Al disparar se va eliminando progresivamente la columna o fila por donde pasa (lo que ocurro ahora). No hay que añadir nada.
  Interacción: hacer un punto que simule la pelota del PONG. 
  
  
 */
 
