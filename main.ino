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
#define pinButton 5

int statusButton = 0;


void setup()
{
    Serial.println(9600);
    Serial.println("Iniciando detecção...\n");

    //configura os pinos do rele, sensor de presença e Push Button
    pinMode(pinRele, OUTPUT);
    pinMode(pinPIR, INPUT);
    pinMode(pinButton, INPUT);

    //garante que a lampada iniciará apagada
    digitalWrite(pinRele, LOW);
    digitalWrite(pinButton, LOW);

}

void pushButton()
    {
        
        //lê pino do botão
        statusButton = digitalRead(pinButton);

        if(statusButton == HIGH)
        {   
            //Desliga a lâmpada
            digitalWrite(pinRele, LOW);
        }
        else
        {
            //Liga a lãmpada
            digitalWrite(pinRele, HIGH);
        }
        
    }
    
void loop()
{
    //lê o sensor PIR e o PushButton
    bool valorPIR = digitalRead(pinPIR);
    int statusButton = digitalRead(pinButton);

    //controla botão de teste para ligar/desligar lâmpada
    pushButton(statusButton);

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