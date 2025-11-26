# 🛠️ Responsi 1 - Sistem Pemantauan Lingkungan Lokal IoT

Proyek ini adalah tugas Responsi 1 untuk Mata Kuliah Internet of Things (IoT). Sistem ini dirancang untuk memantau dua kondisi lingkungan (**Cahaya** dan **Hujan**) dan memvalidasi koneksi jaringan pada mikrokontroler sesuai dengan kriteria ujian.

## 🧑‍🎓 Identitas Proyek

| Detail | Keterangan |
| :--- | :--- |
| **Nama Mahasiswa** | Miqdad Dzaki Nashiruddien |
| **NIM** | 2311501005 |
| **Mata Kuliah** | Internet of Things |
| **Semester** | 5 |
| **Dosen Penguji** | Danur Wijayanto, S.Kom., M.Cs |
| **Mikrokontroler** | ESP32 / WeMos D1 Mini (Pilih salah satu yang digunakan) |

---

## ⚙️ Komponen Hardware

| Komponen | Fungsi dalam Proyek | Pin Koneksi (Contoh) |
| :--- | :--- | :--- |
| **Mikrokontroler** | Memproses data, menjalankan logika, dan koneksi WiFi. | - |
| **Sensor Cahaya (LDR)** | Mendeteksi intensitas cahaya. (Memenuhi syarat minimal 2 sensor) | GPIO 5 (ADC) |
| **Sensor Hujan (Rain Sensor)** | Mendeteksi keberadaan air/tingkat kebasahan. (Memenuhi syarat minimal 2 sensor) | GPIO 4 (ADC) |

---

## 💡 Deskripsi Sistem dan Alur Kerja

Sistem ini beroperasi dengan memprioritaskan validasi koneksi jaringan (syarat IoT) dan pemantauan data sensor secara lokal melalui Serial Monitor (syarat pengujian).

### 1. Koneksi Jaringan (Validasi IoT)

* Perangkat mencoba terhubung ke jaringan WiFi yang dikonfigurasi (`"GEDUNG B - WPA"`).
* Setelah koneksi berhasil, sistem menampilkan **IP Address** dan **MAC Address** di Serial Monitor sebagai bukti bahwa perangkat telah teridentifikasi dan berhasil terhubung ke Internet/Jaringan Lokal.

### 2. Akuisisi dan Interpretasi Data

* Setiap **5 detik**, mikrokontroler membaca nilai analog dari LDR dan Sensor Hujan.
* Data diinterpretasikan menggunakan *threshold* (ambang batas) sederhana, menghasilkan status:
    * **Cahaya:** Menghasilkan status **TERANG** atau **GELAP**.
    * **Rain Sensor:** Menghasilkan status **HUJAN** atau **TIDAK HUJAN**.

### 3. Pemantauan

* Semua *output* status jaringan dan data sensor ditampilkan secara *real-time* di **Serial Monitor** Arduino IDE.

---

## 💻 Penggunaan dan Pengujian

### A. Persiapan

1. Unduh file kode (`.ino`) dan pastikan *wiring* pin sensor sudah sesuai (GPIO 4 dan GPIO 5).
2. Ganti `WIFI_SSID` dan `WIFI_PASSWORD` dalam kode dengan kredensial jaringan yang benar.
3. Sesuaikan nilai *threshold* (ambang batas) interpretasi sensor jika pembacaan **TERANG/GELAP** atau **HUJAN/TIDAK HUJAN** tidak akurat di lingkungan pengujian Anda.

### B. Hasil Pengujian (Serial Monitor)

Berikut adalah contoh *output* kunci yang harus divalidasi oleh penguji:

1.  **Validasi Koneksi (Setup):**

    ```text
    =====================================
    ✅ KONEKSI WIFI BERHASIL!
    Alamat IP Perangkat: 192.168.1.xxx 
    MAC Address Perangkat: XX:XX:XX:XX:XX:XX 
    =====================================
    ```

2.  **Validasi Data Sensor (Loop):**

    ```text
    --- Status Lingkungan ---
    STATUS CAHAYA: GELAP 
    STATUS HUJAN: TIDAK HUJAN
    -------------------------
    ```

**Validasi:** Keberhasilan menampilkan **IP Address** dan **MAC Address** memenuhi kriteria **Terhubung ke Internet**. Pembacaan status Cahaya dan Hujan memenuhi kriteria **Menggunakan Minimal 2 Sensor** dan **Validasi Proyek**.

---
