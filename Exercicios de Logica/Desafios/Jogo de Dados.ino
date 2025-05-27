#include <Servo.h>
Servo Porta;

int servoPin = 13;
int acertos = 0;
int ledVerde = 12;
int ledVermelho = 8;
int ledsAzuis[] = {7, 4, 2}; //3 leds da cor azul
int numeroDeSorte;

void setup()
{
  Serial.begin(9600);
  Porta.attach(servoPin);
  Porta.write(0); //porta fechada  
  
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  for (int i = 0; i < 3; i++) {
  pinMode(ledsAzuis[i], OUTPUT);
  digitalWrite(ledsAzuis[i], LOW);
  }
  desenhaCabecalho();
  delay(1500);
  
  randomSeed(analogRead(A0)); // Inicializa gerador de números aleatórios
  novoDesafio();
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

  if (Serial.available() > 0) {
    int tentativa = Serial.parseInt();

    if (tentativa < 1 || tentativa > 6) {
      Serial.println("Digite um numero de 1 a 6!");
      return;
    }

    if (tentativa == numeroDeSorte) {
      Serial.println("Correto! Voce ganhou sua joia azul!");
      Serial.println();
      piscarLed(ledVerde);
      digitalWrite(ledsAzuis[acertos], HIGH);
      acertos++;

      if (acertos == 3) {
        Serial.println("Voce conquistou as 3 joias! Espere a porta abrir...");
        Serial.println();
        abrirPorta();
      } else {
        novoDesafio();
      }

    } else {
      Serial.println("Errado! O guardiao negou a sua joia!");
      Serial.println();
      piscarLed(ledVermelho);
      novoDesafio();
    }
  }
}

void piscarLed(int led) {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
}

  void desenhaCabecalho() {
  Serial.println("Ola GURREIRO, seja bem vindo a nossa FORTALEZA, vamos comecar a jogar?");
  Serial.println();
  delay(500);
}

void novoDesafio() {
  numeroDeSorte = random(1, 7); // Gera número de 1 a 6
  Serial.println("Tente adivinhar o numero de sorte do dado (1 a 6):");
}

void abrirPorta() {
  for (int angulo = 0; angulo <= 90; angulo++) {
    Porta.write(angulo);
    delay(15);
  }
  Serial.println("A Porta da Fortaleza esta aberta! Aproveite Guerreiro, otimo jogo!");
}
