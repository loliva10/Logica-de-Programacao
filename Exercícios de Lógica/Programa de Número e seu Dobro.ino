// Faça um programa que receba um número e exiba o seu dobro

//Váriaveis
int numero1 = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
 //entrada
  Serial.println("Digite o numero");//Pergunte o número que o usuário deseja ver  o dobro
  while(! Serial.available() ){};//Aguarde o usuario digitar(para o loop)
  numero1 = Serial.parseInt();
  
 //processamento 
  numero1 = numero1 * 2; 
  
 //saída
  Serial.println( "Seu numero e : " + String(numero1));
}