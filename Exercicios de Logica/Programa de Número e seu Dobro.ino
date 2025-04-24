// Faça um programa que receba um número e exiba o seu dobro

//Váriaveis
int numero1 = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  
  //cabeçalho
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|        LOPAL - EX_03         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
  
  
  
  
 //entrada
  Serial.println("Digite o numero");//Pergunte o número que o usuário deseja ver  o dobro
  while(! Serial.available() ){};//Aguarde o usuario digitar(para o loop)
  numero1 = Serial.parseInt();
  
 //processamento 
  numero1 = numero1 * 2; 
  
 //saída
  Serial.println( "Seu numero e : " + String(numero1));
}