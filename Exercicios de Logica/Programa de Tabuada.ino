int tabuadaEscolhida; 
int resultado;

void setup()
{
  Serial.begin(9600);
}
;
void loop()
{
 Serial.println("Bem-vindo(a)! :)");
 Serial.println("Escolha um numero para mostrar sua tabuada:");
 while(!Serial.available()){}//Espera o usuário
 tabuadaEscolhida = Serial.parseInt();
  
 for(int contador = 1; contador <= 10; contador++){
 resultado = tabuadaEscolhida * contador;
 
 //Exibir assim: 2 x 1 = 20
 Serial.println(String(tabuadaEscolhida) + " X " + String(contador) + " = " + String(resultado));
   
 Serial.println("|-----------------------------------|");
   
 }
  delay(4000);
}