/* 

Faça um programa que receba 4 notas de um aluno, calcule e imprima a média
aritmética das notas e a mensagem de APROVADO para média superior ou igual a
7,0 RECUPERAÇÃO para notas entre 5.0 e 7,0 ou a mensagem de REPROVADO
para média inferior a 5,0

*/

float nf, n, n2, n3, n4;// cria as 5 váriaveis de uma só vez e inicializa com o valor já sendo 0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Qual a primeira nota?");
  while(!Serial.available());
  n = Serial.parseFloat();

  Serial.println("Qual a segunda nota?");
  while(!Serial.available());
  n2 = Serial.parseFloat();
  
  Serial.println("Qual a terceira nota?");
  while(!Serial.available());
  n3 = Serial.parseFloat();
  
  Serial.println("Qual a quarta nota?");
  while(!Serial.available());
  n4 = Serial.parseFloat();
  
  
  nf = (float(n) + float(n2) + float(n3) + float(n4)) / 4;
  
  Serial.println("A media aritimetrica e: " + String(nf));
  
  if(nf >= 7){
  Serial.println("Aprovado");
  } else if(7 > nf >= 5 ){
  Serial.println("Recuperação");
  } else {
  Serial.println("Reprovado");
  }
  
  
  delay(4000);
  
  Serial.println();
  Serial.println();
  Serial.println();
  
}