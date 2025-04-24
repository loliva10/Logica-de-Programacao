//Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual
//Calcule e imprima
//A idade dessa pessoa
//Essa idade convertida em semana

//Variáveis
long anoNascimento = 0;
long anoAtual = 0;
long idade = 0; //indica a idade
long idadeSemana = 0;

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  
  //cabeçalho
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|        LOPAL - EX_02         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
  
  
  
  
  //entrada
  Serial.println("Digite o ano de seu nascimento");//pergunta o ano de nascimento do usuário
  while( !Serial.available() ){}//Aguarda o usuário digitar (para o loop)
  anoNascimento = Serial.parseInt();
  
  Serial.println("Digite o ano atual");//pergunta o ano atual
  while( !Serial.available() ){}//Aguarda o usuário digitar (para o loop)
  anoAtual = Serial.parseInt();
  
  //processamento
  idade = anoAtual - anoNascimento; 
  idadeSemana = idade * (365 / 7);
  
  //saída
  Serial.println("Ano de seu Nascimento: " + String(anoNascimento) );
  Serial.println("Ano Atual: " + String(anoAtual) );
  Serial.println("Sua idade: " + String(idade) );
  Serial.println("Sua idade em semanas: " + String(idadeSemana) );
}