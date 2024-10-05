# Proyecto Emisor Infrarrojos

Este proyecto consiste en un sistema que utiliza un microcontrolador (como el ESP32) para emitir señales infrarrojas controladas por WiFi. Está compuesto por un archivo principal para la lógica de emisión de infrarrojos y otro archivo que contiene definiciones de pines.

## Archivos

### 1. `emisor_infrarojos.ino`

Este archivo contiene el código principal para controlar el emisor de infrarrojos. Utiliza las bibliotecas necesarias para enviar señales IR y recibir comandos a través de la red WiFi. El ESP32 recibe peticiones HTTP desde un dispositivo (como una aplicación móvil), y en función de la ruta solicitada, emite una señal infrarroja para controlar diferentes dispositivos (televisores, sistemas de audio, etc.).

#### Funcionalidades Principales:
- Conexión a una red WiFi.
- Recepción de comandos mediante HTTP.
- Conversión de esos comandos en señales infrarrojas utilizando un LED emisor de infrarrojos.

#### Ejemplo de Rutas HTTP:
- `/Power`: Enciende o apaga el dispositivo.
- `/VolUp`: Sube el volumen.
- `/VolDown`: Baja el volumen.
- `/ChannelUp`: Cambia de canal.

Este archivo es el núcleo del proyecto y se encarga de la lógica de control de infrarrojos.

### 2. `PinDefinitionsAndMore.h`

Este archivo incluye las definiciones de los pines y otras configuraciones necesarias para el funcionamiento del proyecto. Aquí es donde se asignan los pines del microcontrolador para el emisor de infrarrojos, botones, sensores, etc.

#### Contenido:
- Definiciones de pines del ESP32.
- Parámetros adicionales para configurar el comportamiento del sistema.

Es importante mantener este archivo bien organizado para facilitar la modificación de los pines en caso de cambios en el hardware.

## Requisitos

- **ESP32**: Se utiliza como controlador principal.
- **Emisor de infrarrojos**: Un LED infrarrojo conectado a uno de los pines del ESP32.
- **Conexión WiFi**: Para recibir comandos desde una red local.
- **Bibliotecas Arduino**:
  - `IRremoteESP8266` o similar (dependiendo de la biblioteca IR que utilices).
  - `WiFi` para la conexión a la red.
  
## Cómo Ejecutarlo

1. **Clona este repositorio** o descarga los archivos.
2. Abre el archivo `emisor_infrarojos.ino` en el **Arduino IDE** o **PlatformIO**.
3. Asegúrate de tener instaladas las bibliotecas necesarias.
4. Configura los parámetros de la red WiFi (SSID y contraseña) en el archivo `emisor_infrarojos.ino`.
5. Sube el código al ESP32.
6. Conecta el ESP32 a un emisor infrarrojo en el pin definido en `PinDefinitionsAndMore.h`.
7. Utiliza una aplicación o un navegador para enviar peticiones HTTP al ESP32 (por ejemplo, `http://192.168.0.110/Power`).

## Futuras Mejoras

- Añadir más rutas HTTP para controlar funciones adicionales.
- Implementar una interfaz gráfica más avanzada en la aplicación móvil complementaria.
- Soporte para más dispositivos con diferentes códigos infrarrojos.

## Contribuciones

Si tienes sugerencias o mejoras para este proyecto, no dudes en crear un **pull request** o abrir un **issue**. ¡Las contribuciones son bienvenidas!

