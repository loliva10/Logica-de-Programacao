/*

Faça um programa receba dois valores e imprima qual é o maior número
digitado.

*/
// C++ code
//Variáveis
float numero1 = 0;
float numero2 = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Digite o primeiro numero");
  while (! Serial.available());
  numero1 = Serial.parseFloat();
  
  Serial.println("Digite o segundo numero");
  while (! Serial.available());
  numero2 = Serial.parseFloat();
  
  Serial.println("O maior numero eh: ");
  
  if (numero1 > numero2)
  {
   Serial.println(numero1);
  }
  else 
  {
  Serial.println(numero2);
  }
  Serial.println();
  delay(3000)
}