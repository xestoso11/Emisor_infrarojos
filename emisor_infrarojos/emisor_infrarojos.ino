#include <Arduino.h>
#include "PinDefinitionsAndMore.h"//Configuración y definición de pines
#include <IRremote.hpp>
#include <WiFi.h>
const char* ssid     = "router_name";
const char* password = "router_pass";
//configuración ip estática para esp32
IPAddress ip(192,168,0,110); //ip esp32
IPAddress gateway(192,168,0,100); //ip router
IPAddress subnet(255,255,0,0); // mascarasubred
WiFiServer server(80);//puesto 80
void setup() {
    Serial.begin(115200);
    IrSender.begin(); // Inicializamos el emisor infrarrojo
    Serial.print(F("Listo para enviar señales IR en el pin"));
    Serial.println(IR_SEND_PIN);//Muestra el número del pin configurado en PinDefinitionsAndMore.h
     // Comenzamos conectándonos a una red WiFi
    Serial.println();
    Serial.println();
    Serial.print("Conectando a ");
    Serial.println(ssid);
//    Serial.print("Contraseña: ");
//    Serial.println(password);

     WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);//Configuración ip estática
    WiFi.begin(ssid, password);//Inicilizamos con los datos de nuestra red wifi
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Conectado a red Wifi.");
    Serial.println("Dirección IP ");
    Serial.println(WiFi.localIP());   
    server.begin();//Inicializamos el servidor web en el puerto 80
}
void loop() {
WiFiClient client = server.available();   // Escuchando a los clientes entrantes

  if (client) {                             // Si hay un cliente,
    Serial.println("Nuevo cliente");        // Imprime un mensaje en el puerto serie
    String currentLine = "";                // String para contener datos entrantes del cliente
    while (client.connected()) {            // Bucle mientras el cliente está conectado
      if (client.available()) {             // Si hay bytes para leer del cliente,
        char c = client.read();             // Lee un caracter
        Serial.write(c);                    // Lo imprimimos en el monitor serial
        if (c == '\n') {                    // Si el byte es un carácter de nueva línea

          
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // Contenido HTML
            client.print("Click <a href=\"/Apagar\">Apagar</a> Tecla Apagar.<br>");

            client.print("Click <a href=\"/Piloto\">Piloto</a> Tecla Piloto.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/Grabar\">Grabar</a> Tecla Grabar.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/VOL+\">VOLT+</a> Tecla subir volumen.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/VOLT-\">VOL-</a> Tecla bajar el volumen.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/P-\">P+</a> Tecla cambiar canal +.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/P-\">P-</a> Tecla cambiar canal -.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/MENU\">MENU</a> Tecla MENU.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/micanal\">micanal</a> Tecla micanal.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/EXIT\">EXIT</a> Tecla Salir.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/Volver\">Volver</a> Tecla Volver.<br>");      
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/ARRIBA\">ARRIBA</a> Tecla ARRIBA.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/DERECHA\">DERECHA</a> Tecla DERECHA.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/ABAJO\">ABAJO</a> Tecla ABAJO.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/IZQUIERDA\">IZQUIERDA</a> Tecla IZQUIERDA.<br>");

//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/1\">1</a> Tecla 1.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/2\">2</a> Tecla 2.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/3\">3</a> Tecla 3.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/4\">4</a> Tecla 4.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/5\">5</a> Tecla 5.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/6\">6</a> Tecla 6.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/7\">7</a> Tecla 7.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/8\">8</a> Tecla 8.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/9\">9</a> Tecla 9.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/0\">0</a> Tecla 0.<br>");
//-------------------------------------------------------------------------------------------

            client.print("Click <a href=\"/M\">M</a> Tecla m.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/tv\">tv</a> Tecla tv.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/+\">m+</a> Tecla m+.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/Serv\">Serv</a> Tecla Serv.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/Perso\">Perso</a> Tecla Perso.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/atras\">atras</a> Tecla <<.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/adelante\">adelante</a> Tecla >>.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/pausa\">pausa</a> Tecla ||.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/play\">play</a> Tecla |>.<br>");
//-------------------------------------------------------------------------------------------
            client.print("Click <a href=\"/live\">live</a> Tecla [].<br>");
//-------------------------------------------------------------------------------------------

            client.print("Click <a href=\"/OK\">OK</a> Tecla OK confirmar.<br>");
//-------------------------------------------------------------------------------------------                   
            client.println();
            // Salir del ciclo while:
            break;
          } else {    // si tienes una nueva línea, borra currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
//----------------------------------
        if (currentLine.endsWith("GET /Apagar")) {
          IrSender.sendRC5ext(0xA, 0xC, true);
        }
        if (currentLine.endsWith("GET /Piloto")) {
          IrSender.sendRC5ext(0xA, 0xF, true);
        }
        //-----------------------
        if (currentLine.endsWith("GET /Grabar")) {
          IrSender.sendRC5ext(0xA, 0x37, true);
        }
        //-----------------------
        if (currentLine.endsWith("GET /VOL+")) {       
          IrSender.sendRC5ext(0xA, 0x10, true);   //Volumen +      
        }
        //-----------------------
        if (currentLine.endsWith("GET /VOL-")) { 
          IrSender.sendRC5ext(0xA, 0x11, true); //volumen -          
        }
        if (currentLine.endsWith("GET /P+")) {       
          IrSender.sendRC5ext(0xA, 0x20, true);   //Volumen +      
        }
        //-----------------------
        if (currentLine.endsWith("GET /P-")) { 
          IrSender.sendRC5ext(0xA, 0x21, true); //volumen -          
        }
        //-----------------------
        if (currentLine.endsWith("GET /MENU")) {
          IrSender.sendRC5ext(0xA, 0xF, true); //menu              
        }
        //-----------------------
        if (currentLine.endsWith("GET /micanal")) {
          IrSender.sendRC5ext(0xA, 0x72, true); //menu              
        }
        //-----------------------
        if (currentLine.endsWith("GET /EXIT")) {
          IrSender.sendRC5ext(0xA, 0x53, true);   //Exit/salir
        }
        //-----------------------
        if (currentLine.endsWith("GET /Volver")) {
          IrSender.sendRC5ext(0xA, 0x22, true);   //Volver        
        }
        //-----------------------
        if (currentLine.endsWith("GET /ARRIBA")) {
          IrSender.sendRC5ext(0xA, 0x50, true);//ARRIBA          
        }      
        //-----------------------
        if (currentLine.endsWith("GET /DERECHA")) {
          IrSender.sendRC5ext(0xA, 0x56, true);//DERECHA        
        }
        //-----------------------
        if (currentLine.endsWith("GET /ABAJO")) {
          IrSender.sendRC5ext(0xA, 0x51, true);//ABAJO          
        }
        //-----------------------
        if (currentLine.endsWith("GET /IZQUIERDA")) {
          IrSender.sendRC5ext(0xA, 0x55, true);//IZQUIERDA        
        }
        //-----------------------
        if (currentLine.endsWith("GET /1")) {
          IrSender.sendRC5ext(0xA, 0x1, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /2")) {
          IrSender.sendRC5ext(0xA, 0x2, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /3")) {
          IrSender.sendRC5ext(0xA, 0x3, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /4")) {
          IrSender.sendRC5ext(0xA, 0x4, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /5")) {
          IrSender.sendRC5ext(0xA, 0x5, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /6")) {
          IrSender.sendRC5ext(0xA, 0x6, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /7")) {
          IrSender.sendRC5ext(0xA, 0x7, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /8")) {
          IrSender.sendRC5ext(0xA, 0x8, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /9")) {
          IrSender.sendRC5ext(0xA, 0x9, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /0")) {
          IrSender.sendRC5ext(0xA, 0x0, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /tv")) {
          IrSender.sendRC5ext(0xA, 0x28, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /Serv")) {
          IrSender.sendRC5ext(0xA, 0x52, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /Perso")) {
          IrSender.sendRC5ext(0xA, 0x6A, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /M")) {
          IrSender.sendRC5ext(0xA, 0x48, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /+")) {
          IrSender.sendRC5ext(0xA, 0x2F, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /atras")) {
          IrSender.sendRC5ext(0xA, 0xA, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /adelante")) {
          IrSender.sendRC5ext(0xA, 0x34, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /pausa")) {
          IrSender.sendRC5ext(0xA, 0x30, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /play")) {
          IrSender.sendRC5ext(0xA, 0x35, true);    
        }
        //-----------------------
        if (currentLine.endsWith("GET /live")) {
          IrSender.sendRC5ext(0xA, 0x36, true);    
        }
        //-----------------------

        if (currentLine.endsWith("GET /OK")) {
          IrSender.sendRC5ext(0xA, 0x57, true);//Ok
        }      
      }
    }
    // Cierra la conexión
    client.stop();
    Serial.println("Cliente desconectado");
    
  }
}
