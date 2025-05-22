// C++ code
//Variáveis Globais
/*
      Cria cada vetor tamanho 4, de zero a 3
      fazendo parte do mesmo cadastro
  */
String convidados[4];
int idadeConvidados[4]; //Camel Case
String emailConvidados[4];

//Funções
void desenhaCabecalho()
{
  Serial.println("*** CHURRASCAO DO ZEH ***");
  Serial.println();
  Serial.println();
}


void setup()
{
  Serial.begin(9600);//inicia a comunicação serial  
}


void loop()
{

  //fazer um cabeçalho bonitinho para o programa
  desenhaCabecalho();//chama a função pra desenhar o cabeçalho

  //cadastrar os dados
  for(int i = 0; i < 3; i++)
  {
    //solicitar o nome do usuário
    Serial.println("Informe " +String(i + 1)+ "o nome para cadastro");
    while(!Serial.available());
    convidados[i] = Serial.readString();

    //solicitar a idade
    Serial.println("Informe o idade de " + convidados[i]);
    while(!Serial.available());
    idadeConvidados[i] = Serial.parseInt();

    //solicitar o email
    Serial.println("Informe o email de " + convidados[i]);
    while(!Serial.available());
    emailConvidados[i] = Serial.readString();

    Serial.println();

  }//fim do for


  //Exibir a lista de convidados - obs: só vai na festa quem for maior de idade >= 18

  Serial.println("** Exibindo convidados eleitos pra a festa **");
  Serial.println();
  Serial.println();

  for(int i = 0; i < 3; i++)
  {
    Serial.println("Nome: " + convidados[i]);
    Serial.println("Idade: " + String(idadeConvidados[i]));
    Serial.println("Email: " + emailConvidados[i]);
    Serial.println("Permissao para a festa: " +  String(idadeConvidados[i] >= 18 ? "OK" : "Menor de Idade"));

    Serial.println("----------");
    Serial.println();

  }//fim do for

  Serial.println();

  delay(2000);//pausa de 2 segundos
}//fim do loop