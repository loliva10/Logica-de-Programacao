// Calcule o salário acrescido de 10% e exiba o nome, cargo e novo salário.

// Variáveis
String nome = "";
String cargo = "";
float salario = 0;
float novoSalario = 0;

void setup()
{
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop()
{
    //cabeçalho - 2 pipes + 30 tracinhos
  
  Serial.println("|-----------------------------|");
  Serial.println("|                             |");
  Serial.println("|         LOPAL - EX07        |");
  Serial.println("|                             |");
  Serial.println("|-----------------------------|");
  Serial.println();//pula uma linha
  
  // Entrada
  Serial.println("Digite o nome do funcionario:");
  while (!Serial.available()) {}       // Aguarda o usuário digitar
  nome = Serial.readStringUntil('\n'); // Lê o nome até o Enter
  nome.trim();                         // Remove espaços extras
  delay(500);

  Serial.println("Digite o cargo do funcionario:");
  while (!Serial.available()) {}       // Aguarda o usuário digitar
  cargo = Serial.readStringUntil('\n'); // Lê o cargo até o Enter
  cargo.trim();                         // Remove espaços extras
  delay(500);

  Serial.println("Digite o salario do funcionario:");
  while (!Serial.available()) {}       // Aguarda o usuário digitar
  salario = Serial.parseFloat();       // Lê o salário
  delay(500);

  // Processamento
  novoSalario = salario * 1.10;        // Calcula o salário com 10% de aumento

  // Saída-formatada
  Serial.println();
  Serial.println();
  
  Serial.println("Relatorio:");
  Serial.println();
  Serial.println("-------------------------------");
  Serial.println();
  
  Serial.println("Nome: " + nome);
  Serial.println("Cargo: " + cargo);
  Serial.println("Salario Antigo: R$ " + String(salario));
  Serial.println("Salario Atualizado: R$ " + String(novoSalario));
  Serial.println();
  
  Serial.println("-------------------------------");
  
  Serial.print("Digite uma letra + <Enter> para continuar ...");//gambi para fazer o programa parar
  while(! Serial.available());
  
  Serial.println();
  Serial.println();
  
  Serial.read();//limpa o cache do \n - o <Enter>
}