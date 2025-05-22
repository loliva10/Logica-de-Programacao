  // C++ code
  //Variaveis Globais
  //vetor tamanho 6: vai do 0 ate 5
  String frutas[6];//criar um vetor tamanho 6 (preenchendo as posições com string vazias)
  float precosFrutas[6];
  void setup()
  {
    Serial.begin(9600);

    Serial.println("*** SACOLAO DO FIOT ***");
    Serial.println();

    Serial.println("Oh FIOT, bora cadastrar as frutas!");

    Serial.println();

    for(int i = 0; i <= 5; i++)
    {
      Serial.println("Informe a "+ String(i + 1) +"a Fruta:");
      while(!Serial.available());
      String fruta = Serial.readString();

      Serial.println("Qual o preco de " + fruta + "?");
      while(!Serial.available());
      float precoDigitado = Serial.parseFloat();


     //poe a fruta na sacola / cadastra a fruta no array/vetor
      frutas[i] = fruta;
      precosFrutas[i] = precoDigitado;


    }//fim do for
    Serial.println("=FIM DE CADASTRO=");
    
    
    Serial.println("==AS FRUTAS CADASTRADAS FORAM:==");

    //crie um for paraexibir as frutas cadastradas
    for(int i = 0; i <= 5; i++)
    {
    Serial.println(String(i +1) + "a Fruta: " + frutas[i]);
    Serial.println("Preco da "+ frutas[i] + " Fruta: " + String(precosFrutas[0]));
    }
    Serial.println("=FIM DA LISTA DE FRUTAS=");
  } 

  void loop()
  {

  }