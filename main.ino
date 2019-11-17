/**
 * 
 * Title: main.ino
 * Description: controlador de lâmpada utilizando sensor de Movimento de Presença PIR
 * Author: Denis Lopes
 * Data: 17/11/2019
 * 
 **/ 

#define pinRele 7
#define pinPIR 6


void setup()
{
    Serial.println(9600);
    Serial.println("Iniciando Detecção")

    pinMode(pinRele, OUTPUT);
    pinMode(pinPIR, INPUT);

    //garante que a lampada iniciará apagada
    digitalWrite(pinRele, LOW);

}

void loop()
{
    //lê o sensor PIR
    bool valorPIR = digitalRead(pinPIR);

    if(valorPIR)
    {
        Serial.println("Detectado! \n");
       
        //liga a lâmpada
        digitalWrite(pinRele, HIGH);
    }
    else
    {
        //desliga a lampada
        digitalWrite(pinRele, LOW);

        Serial.println("Procurando...");
        
    }
}