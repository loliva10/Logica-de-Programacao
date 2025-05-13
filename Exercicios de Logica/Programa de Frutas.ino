/*
	1 - Melancia
    2 - Banana
    3 - Macã
    4 - Morango
    5 - Laranja
	
*/
int fruta = 4;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  switch(fruta) {
    case 1:
    	Serial.println("Voce escolheu a fruta MELANCIA");
    	break;
    case 2:
    	Serial.println("Voce escolheu a fruta BANANA");
    	break;
    case 3:
    	Serial.println("Voce escolheu a fruta MACA");
    	break;
	 case 4:
    	Serial.println("Voce escolheu a fruta MORANGO");
    	break;  
    case 5:
    	Serial.println("Voce escolheu a fruta LARANJA");
    	break; 
    default :
    	Serial.println("Nao temos a fruta escolhida");
  }
  
  
  delay(20000);
}