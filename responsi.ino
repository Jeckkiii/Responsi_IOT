// --- HEADER FILE ---
#include <WiFi.h>           // Library wajib untuk koneksi WiFi

// --- KONFIGURASI WIFI (HARUS DIGANTI) ---
// Perhatikan bahwa SSID yang Anda masukkan memiliki spasi di akhir: "GEDUNG B - WPA "
// Pastikan ini benar atau hapus spasi jika tidak diperlukan.
const char* WIFI_SSID = "GEDUNG B - WPA";     
const char* WIFI_PASSWORD = "123123123"; 

// --- KONFIGURASI SENSOR (PIN GPIO HARUS DISESUAIKAN) ---
// Pin GPIO 4 dan 5 pada ESP32 umum digunakan, pastikan koneksi ADC/Analog pada pin ini benar.
const int LDR_PIN = 5;     // Pin untuk Sensor Cahaya (LDR)
const int RAIN_PIN = 4;    // Pin untuk Sensor Hujan

// Variabel untuk menampung data sensor
int light_intensity = 0; // Nilai mentah LDR (0 - 4095)
int rain_level = 0;      // Nilai mentah Sensor Hujan (0 - 4095)

// Interval waktu pembacaan data (ms) - Diatur menjadi 5 detik untuk pengujian yang cepat
const long readingInterval = 5000;
unsigned long lastReadingTime = 0;

// --- SETUP ---
void setup() {
    Serial.begin(115200);   // Inisialisasi Serial Monitor
    delay(100);

    // Konfigurasi pin input analog
    pinMode(LDR_PIN, INPUT);
    pinMode(RAIN_PIN, INPUT);

    // 1. Inisialisasi Koneksi WiFi
    Serial.println("=====================================");
    Serial.println("MEMULAI KONEKSI WIFI...");
    
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }
    
    Serial.println();
    
    // 2. Cek Status Koneksi dan Tampilkan Info Jaringan
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("=====================================");
        Serial.println("✅ KONEKSI WIFI BERHASIL!");
        
        // Menampilkan IP Address
        Serial.print("Alamat IP Perangkat: ");
        Serial.println(WiFi.localIP());
        
        // Menampilkan MAC Address
        Serial.print("MAC Address Perangkat: ");
        Serial.println(WiFi.macAddress());
        
        Serial.println("=====================================");
        Serial.println("Sistem IoT siap beroperasi (Pemantauan Lokal)");
    } else {
        Serial.println("=====================================");
        Serial.println("❌ KONEKSI WIFI GAGAL! Perangkat beroperasi dalam mode mandiri.");
        Serial.println("=====================================");
    }
    
    lastReadingTime = millis();
}

// --- LOOP UTAMA ---
void loop() {
    // Mengecek apakah sudah waktunya untuk membaca data
    if (millis() - lastReadingTime >= readingInterval) {

        // 1. BACA DATA SENSOR
        light_intensity = analogRead(LDR_PIN);
        rain_level = analogRead(RAIN_PIN);

        // 2. TAMPILKAN DATA DI SERIAL MONITOR (Penting untuk Pengujian & Validasi)
        Serial.println("--- Pembacaan Sensor ---");
        
        // Data LDR
        Serial.print("LDR (Cahaya) - Nilai: "); 
        Serial.print(light_intensity);
        Serial.println(" (0=Terang, 4095=Gelap)");

        // Data Rain Sensor
        Serial.print("Rain Sensor (Hujan) - Nilai: "); 
        Serial.print(rain_level);
        Serial.println(" (0=Basah, 4095=Kering)");
        
        // 3. UPDATE WAKTU TERAKHIR
        lastReadingTime = millis();
    }
}