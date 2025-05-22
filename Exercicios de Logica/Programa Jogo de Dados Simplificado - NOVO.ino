int ledVerde = 12;
int ledVermelho = 8;
int ledAzul1 = 7;
int ledAzul2 = 4;
int ledAzul3 = 2;
int palpites;


void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0)); // corrigido
}

void desenhaCabecalho()
{
  Serial.println("Bem vindo(a) ao programa Jogo de dados!!");
  Serial.println();
  delay(500);
}

void desenhaPontinho(int qtdPontos = 5, int tempo = 700)
{
  for(int i = 1; i <= qtdPontos; i++)
  {
    Serial.print(".");
    delay(tempo);
  }
  Serial.println();
}

void loop()
{
  desenhaCabecalho();

  Serial.println("Quantas vezes voce quer jogar?");
  while (!Serial.available());
  int qtdRodadas = Serial.parseInt();

  if (qtdRodadas <= 0 || qtdRodadas > 100) {
    Serial.println("Quantidade invalida. Tente novamente.");
    return;
  }

  int vetPalpites[qtdRodadas];
  int vetResultados[qtdRodadas];
  
  for(int r = 0; r < qtdRodadas; r++) // corrigido
  {
    Serial.println("Digite seu palpite de 1 a 6");
    while(!Serial.available());  
    palpites = Serial.parseInt();

    if (palpites < 1 || palpites > 6) {
      Serial.println("Palpite invalido. Use numeros de 1 a 6.");
      r--; // refaz a rodada
      continue;
    }

    int numeroSorteado = random(1, 7); // número entre 1 e 6

    vetPalpites[r] = palpites;
    vetResultados[r] = numeroSorteado;
    
    Serial.print("Jogando dado ");
    desenhaPontinho();
    Serial.println();

    Serial.println("Palpite do usuario: " + String(palpites));
    Serial.println("Numero do Dado: " + String(numeroSorteado));
    Serial.println();

    if(palpites == numeroSorteado)
    {
      Serial.println("Acertou, parabens!!");
      digitalWrite(ledVerde, HIGH);
      delay(3000);
      digitalWrite(ledVerde, LOW);
      delay(1000);
      for(int i = 0; i <= 3; i++){
      digitalWrite(ledAzul1, HIGH);
      }
    } else {
      Serial.println("Que pena! Tente outra vez");
      digitalWrite(ledVermelho, HIGH);
      delay(3000);
      digitalWrite(ledVermelho, LOW);
    }  
  }

  // Estatísticas
  Serial.println("ESTATÍSTICAS DO JOGO");
  Serial.println();

  for(int i = 0; i < qtdRodadas; i++)
  {
    Serial.println("Rodada " + String(i + 1) + ":"); 
    Serial.println("    Palpite: " + String(vetPalpites[i])); 
    Serial.println("    Numero Sorteado: " + String(vetResultados[i]));
    
    if (vetPalpites[i] == vetResultados[i]) {
      Serial.println("    Resultado: Acertou!");
    } else {
      Serial.println("    Resultado: Errou!");
    }

    Serial.println("________________________________");
    Serial.println();
  }

  Serial.println("Fim do jogo, reiniciando sistema!");
  desenhaPontinho(3, 500);
  delay(3000);
}
