int palpites;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0)); // corrigido
}

void desenhaCabecalho()
{
  Serial.println("Bem vindo ao programa 'Jogo de dados'");
  Serial.println("");
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

  Serial.println("Quantas vezes você quer jogar?");
  while (!Serial.available());
  int qtdRodadas = Serial.parseInt();

  if (qtdRodadas <= 0 || qtdRodadas > 100) {
    Serial.println("Quantidade inválida. Tente novamente.");
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
      Serial.println("Palpite inválido. Use números de 1 a 6.");
      r--; // refaz a rodada
      continue;
    }

    int numeroSorteado = random(1, 7); // número entre 1 e 6

    vetPalpites[r] = palpites;
    vetResultados[r] = numeroSorteado;
    
    Serial.print("Jogando dado ");
    desenhaPontinho();
    Serial.println();

    Serial.println("Palpite do usuário: " + String(palpites));
    Serial.println("Número do Dado: " + String(numeroSorteado));
    Serial.println();

    if(palpites == numeroSorteado)
    {
      Serial.println("Acertou, parabéns!!");
    } else {
      Serial.println("Que pena! Tente outra vez");
    }  
  }

  // Estatísticas
  Serial.println("ESTATÍSTICAS DO JOGO");
  Serial.println();

  for(int i = 0; i < qtdRodadas; i++)
  {
    Serial.println("Rodada " + String(i + 1) + ":"); 
    Serial.println("    Palpite: " + String(vetPalpites[i])); 
    Serial.println("    Número Sorteado: " + String(vetResultados[i]));
    
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
