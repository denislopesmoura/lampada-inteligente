/**
 * 
 * Title: main.ino
 * Description: controlador de lâmpada utilizando sensor de Movimento de Presença PIR
 * Author: Denis Lopes
 * Data: 19/11/2019
 * 
 **/ 

#define pinRele 7
#define pinPIR 6
#define pinButton 5


void setup()
{
    Serial.begin(9600);
    Serial.println("Iniciando detecção...\n");

    //configura os pinos do rele, sensor de presença e PushButton
    pinMode(pinRele, OUTPUT);
    pinMode(pinPIR, INPUT);
    pinMode(pinButton, INPUT);

    //garante que a lâmpada iniciará apagada
    digitalWrite(pinRele, LOW);

}

void readPushButton()
    {
        
        //lê pino do Pushbutton
        int statusButton = digitalRead(pinButton);

        if(statusButton == HIGH)
        {   
            //Desliga a lâmpada
            digitalWrite(pinRele, LOW);
        }
        else
        {
            //Liga a lâmpada
            digitalWrite(pinRele, HIGH);
        }
        
    }

void loop()
{
    //lê o sensor PIR
    bool valuePIR = digitalRead(pinPIR);

    //lê PushButton
    readPushButton();

    if(valuePIR)
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
