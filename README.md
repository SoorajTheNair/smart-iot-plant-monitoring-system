# Smart Plant Monitoring & Protection System 🌱🤖

A full-stack IoT-based system for **real-time soil moisture monitoring** and **motion detection near plants**, with automated alerts, data storage, dashboards, and system-wide automation.

This project demonstrates a complete **end-to-end IoT pipeline** integrating embedded systems, messaging, automation, databases, visualization, and alerting.

---

## 🔧 System Architecture

Soil Moisture Sensor + PIR Sensor → ESP32 → MQTT → n8n → MySQL → Grafana → Telegram Alerts

---

## ⚙️ System Behavior

The system automatically triggers alerts when:
- 🚨 Soil moisture level falls below a defined threshold  
- 🚨 Motion is detected near the plant  

This enables **plant monitoring + protection** in a single integrated system.

---

## 🚀 Features

- Real-time soil moisture monitoring  
- Motion detection near plant  
- Low-moisture threshold alerts  
- Motion-triggered alerts  
- MQTT-based messaging pipeline  
- Event-driven automation workflows  
- Database storage  
- Live visualization dashboards  
- Real-time Telegram notifications  
- Modular and scalable architecture   

---

## 🧠 Tech Stack

- ESP32 (Embedded C++)
- MQTT (Mosquitto)
- n8n (Automation Engine)
- MySQL (Database)
- Grafana (Visualization)
- Telegram Bot API (Alerts)

---

## 📁 Project Structure

```txt
smart-iot-monitoring-system/
│
├── esp32/
│   └── firmware.ino
│
├── mqtt/
│   └── mosquitto.conf
│
├── n8n/
│   └── workflow.json
│
├── database/
│   └── schema.sql
│
├── grafana/
│   └── dashboard.json
│
├── diagrams/
│   └── architecture.png
│
├── screenshots/
│   ├── grafana.png
│   ├── telegram.png
│   ├── esp32_setup.jpg
│   └── n8n.png
│
|
└── README.md
