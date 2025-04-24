// Faça um programa que receba a medida em polegadas
// e exiba esse número em centimetros. 

// Variáveis
float polegadas = 0;
float centimetros = 0;

void setup()
{
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop()
{
  
  //cabeçalho
  Serial.println("|------------------------------|");
  Serial.println("|                              |");
  Serial.println("|        LOPAL - EX_06         |");
  Serial.println("|                              |");
  Serial.println("|------------------------------|");
  
  
  Serial.println();//pula uma linha
  Serial.println();//pula uma linha
  
  
  
  
  // Entrada
  Serial.println("Digite a medida em polegadas:");
  while (!Serial.available()) {}       // Aguarda o usuário digitar
  polegadas = Serial.parseFloat();     // Lê a medida em polegadas
  delay(500);                          // Pequeno delay para garantir leitura

  // Processamento
  centimetros = polegadas * 2.54;     // Converte polegadas para centímetros

  // Saída
  Serial.print(polegadas);
  Serial.print(" polegadas equivale a ");
  Serial.print(centimetros, 2);        // Exibe o resultado com 2 casas decimais
  Serial.println(" centimetros.");

  delay(5000); // Aguarda 5 segundos antes de permitir nova entrada
}
