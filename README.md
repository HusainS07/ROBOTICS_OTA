# ROBOTICS_OTA

**ROBOTICS_OTA** is a collection of fundamental ESP32 projects demonstrating basic robotics control, Wi-Fi interaction, and Over-The-Air (OTA) firmware updates. This repository is ideal for beginners exploring ESP32-based robotic systems and remote firmware management.

---

## Projects Included

### 1. LED Blink (`LED_BLINK.ino`)
- Blinks the onboard LED (pin 2 for ESP32).  
- LED stays **ON for 4 seconds** and **OFF for 4 seconds** repeatedly.  
- Useful for testing ESP32 functionality and verifying hardware connections.

### 2. MAC Address Printer (`MAC_ADDRESS.ino`)
- Connects ESP32 to Wi-Fi in **station mode**.  
- Prints the **MAC address** and **IP address** to the Serial Monitor.  
- Helps identify and authorize devices for OTA updates.

### 3. OTA Firmware Update (`OTA_update.ino`)
- Enables **Over-The-Air updates** for ESP32 devices.  
- Allows secure remote firmware upgrades using a password-protected system.  
- OTA is enabled only if the ESP32 MAC address matches the allowed device.  
- Provides **progress feedback** and **error handling** during updates.  

---

## Step-by-Step Instructions

1. **Run LED Blink First**
   - Open `LED_BLINK/LED_BLINK.ino` in Arduino IDE.  
   - Upload it via USB to ESP32 to verify hardware functionality.  

2. **Check Device MAC Address**
   - Open `MAC_ADDRESS/MAC_ADDRESS.ino`.  
   - Replace `SSID` and `password` with your Wi-Fi credentials.  
   - Upload to ESP32 via USB.  
   - Open Serial Monitor to note your ESP32 **MAC address**.  

3. **Setup OTA Updates**
   - Open `OTA_update/OTA_update.ino`.  
   - Replace `ssid` and `password` with your Wi-Fi credentials.  
   - Replace `allowedMAC` with the MAC address obtained from step 2.  
   - Set `otaPassword` to your desired password.  
   - Upload via USB once. After this, future firmware updates can be done **wirelessly** via OTA.

4. **Perform OTA Updates**
   - Make changes in `OTA_update.ino` or other projects.  
   - Use Arduino IDE or OTA-enabled tool to upload **without USB**.  
   - Monitor progress and errors in Serial Monitor.

---

## Features
- Stepwise approach for beginners.  
- Secure OTA updates for ESP32-based robots.  
- Demonstrates digital output, Wi-Fi connectivity, and OTA handling.

---

## Requirements
- ESP32 Development Board  
- Arduino IDE with ESP32 board support  
- Wi-Fi network for OTA updates  

---

## License
This project is in the **public domain**, free to use and modify.

---

## Author
Husain Sakarwala
