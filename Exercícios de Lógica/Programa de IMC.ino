// Faça um programa que receba o nome, o peso e a altura de uma
// pessoa. Calcule e imprima o nome e o IMC dessa pessoa.

// Variáveis
String nome = "";
float peso = 0;
float altura = 0;
float imc = 0;

void setup()
{
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop()
{
  // Entrada
  Serial.println("Digite seu nome:");
  while (!Serial.available()) {}       // Aguarda entrada
  nome = Serial.readStringUntil('\n'); // Lê o nome até apertar Enter
  nome.trim();                         // Remove espaços extras
  delay(500);

  Serial.println("Digite seu peso em kg (ex: 70.5):");
  while (!Serial.available()) {}
  peso = Serial.parseFloat();          // Lê o peso
  delay(500);

  Serial.println("Digite sua altura em metros (ex: 1.75):");
  while (!Serial.available()) {}
  altura = Serial.parseFloat();        // Lê a altura
  delay(500);

  // Processamento
  imc = peso / (altura * altura);      // Fórmula do IMC

  // Saída
  
  Serial.print("Nome: ");
  Serial.println(nome);
  Serial.print("IMC: ");
  Serial.println(imc, 2);              // Mostra o IMC com 2 casas decimais

  delay(7000); // Aguarda 7 segundos antes de permitir nova entrada
}