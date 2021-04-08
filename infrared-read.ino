//Aluno: Eron Almeida Vieira da Silva
//Mat.:20142610326
//Biblioteca foi extraida do endereço: https://github.com/z3t0/Arduino-IRremote 
  
#include <IRremote.h>  
  
int codigo_IR = 11;          //Pino de Leitura
float leitura;  
int led1 = 5;  
int led2 = 7;
int led3 = 4;  
  
IRrecv irrecv(codigo_IR);  //Função da biblioteca
decode_results results;  
  
void setup()  
{  
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR  
}  
   
void loop()  
{  
  if (irrecv.decode(&results))  
  {  
    Serial.print("Leitura infravermelho : ");  
    Serial.println(results.value, HEX);  
    leitura = (results.value);  
    if (leitura == 0xC18E7) //Verifica se a tecla 1 foi acionada  
    {  
      digitalWrite(led1, HIGH);  //Acende o led vermelho  
    }  
    if (leitura == 0xCA05F) //Verifica se a tecla 2 foi acionada  
    {  
      digitalWrite(led1, LOW); //Apaga o led vermelho  
    }  
    if (leitura == 0xC28D7) //Verifica se a tecla 3 foi acionada  
    {  
      digitalWrite(led2, HIGH); //Acende o led verde  
    }  
    if (leitura == 0xC9867) //Verifica se a tecla 4 foi acionada  
    {  
      digitalWrite(led2, LOW); //Apaga o led verde  
    } 
    if (leitura == 0xCC03F) //Verifica se a tecla 5 foi acionada  
    {  
      digitalWrite(led3, HIGH); //Acende o led azul  
    }   
    if (leitura == 0xCA45B) //Verifica se a tecla 6 foi acionada  
    {  
      digitalWrite(led3, LOW); //Apaga o led verde  
    }  
    if (leitura == 0xC609F) //Verifica se a tecla 7 foi acionada  
    {  
      digitalWrite(led1, LOW); //Apaga todos os leds  
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);  
    }  
  irrecv.resume(); //Le o próximo valor  
  }  
}  
