#include <WiFiManager.h> // Fork da biblitoeca original por https://github.com/lucsoliveira/WifiManager-PT-BR-ESP8266-

void setup() {
    WiFi.mode(WIFI_STA); // definir explicitamente o modo, o padrão esp é STA + AP

    // coloque seu código de configuração aqui, para ser executado uma vez:
    Serial.begin(115200);
    
    // WiFi.mode (WiFi_STA); // é uma boa prática certificar-se de que seu código define o modo wi-fi como você deseja.
    // WiFiManager, inicialização local. Assim que seu negócio estiver concluído, não há necessidade de mantê-lo por perto
    WiFiManager wm;

    //redefinir configurações - limpe as credenciais para teste
    //wm.resetSettings();

     // Conecte-se automaticamente usando credenciais salvas,
     // se a conexão falhar, ele inicia um ponto de acesso com o nome especificado ("AutoConnectAP"),
     // se vazio, irá gerar SSID automaticamente, se a senha estiver em branco, será AP anônimo (wm.autoConnect ())
     // então entra em um loop de bloqueio aguardando configuração e retornará o resultado de sucesso

    bool res;
    // res = wm.autoConnect(); // nome do AP gerado automaticamente a partir do chipid
    // res = wm.autoConnect("AutoConnectAP"); //ap anônimo
    res = wm.autoConnect("AutoConnectAPESP","senha123");

    if(!res) {
        Serial.println("Falhou ao conectar");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("conectado!");
    }

}

void loop() {
    // coloque seu código principal aqui, para executar repetidamente:
    
}
