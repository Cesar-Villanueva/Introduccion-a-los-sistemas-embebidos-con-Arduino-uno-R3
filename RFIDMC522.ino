/*
Autor : Cesar Villanueva
Date : 06/06/2026
Copyright : None
Contac : cedeci . cvillanueva@ieca . edu . mx
Changes by : None
Fixes : None
*/

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 5

MFRC522 rfid(SS_PIN, RST_PIN);

void setup()
{
    Serial.begin(9600);

    SPI.begin();

    rfid.PCD_Init();

    Serial.println();
    Serial.println("==============================");
    Serial.println(" PRUEBA DEL MODULO RFID RC522 ");
    Serial.println("==============================");
    Serial.println("Acerque una tarjeta...");
}

void loop()
{

    // Espera una tarjeta nueva
    if (!rfid.PICC_IsNewCardPresent())
    {
        return;
    }

    // Lee la tarjeta
    if (!rfid.PICC_ReadCardSerial())
    {
        return;
    }

    Serial.println();
    Serial.println("Tarjeta detectada");

    Serial.print("UID (HEX): ");

    for (byte i = 0; i < rfid.uid.size; i++)
    {

        if (rfid.uid.uidByte[i] < 0x10)
        {
            Serial.print("0");
        }

        Serial.print(rfid.uid.uidByte[i], HEX);
        Serial.print(" ");

    }

    Serial.println();

    Serial.print("UID (DEC): ");

    for (byte i = 0; i < rfid.uid.size; i++)
    {

        Serial.print(rfid.uid.uidByte[i], DEC);

        if (i < rfid.uid.size - 1)
        {
            Serial.print(" ");
        }

    }

    Serial.println();

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    delay(1000);

    Serial.println();
    Serial.println("Acerque otra tarjeta...");

}