// While - É uma estrutura de repetição que só executa repetição/laço enquanto 
// a condição for verdadeira
/**/
int numero1 = 0; //variavel global

void setup()
{
  Serial.begin(9600);
}

//função
void loop()
{
  //o 0 também conta
  //while
  int contadorWhile = 100; //variavel local
  
  while(contadorWhile >= 0){
   Serial.println(String(contadorWhile));
  //contadorWhile = contadorWhile - 1;
  contadorWhile--;
}
  
  Serial.println("---------------------------");
  delay(4000);
  
}