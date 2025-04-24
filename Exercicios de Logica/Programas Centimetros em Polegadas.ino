// Faça um programa que receba a medida em centímetros
// e exiba esse número em polegadas. 

// Variáveis
float centimetros = 0;
float polegadas = 0;

void setup()
{
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop()
{
  
  //cabeçalho
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|        LOPAL - EX_05         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
  
  
  
  
  // Entrada
  Serial.println("Digite a medida em centimetros:");
  while (!Serial.available()) {}       // Aguarda o usuário digitar
  centimetros = Serial.parseFloat();   // Lê a medida em centímetros
  delay(500);                          // Pequeno delay para garantir leitura

  // Processamento
  polegadas = centimetros / 2.54;     // Converte centímetros para polegadas

  // Saída
  Serial.print(centimetros);
  Serial.print(" centimetros equivale a ");
  Serial.print(polegadas, 2);          // Exibe o resultado com 2 casas decimais
  Serial.println(" polegadas.");

  delay(5000); // Aguarda 5 segundos antes de permitir nova entrada
}
