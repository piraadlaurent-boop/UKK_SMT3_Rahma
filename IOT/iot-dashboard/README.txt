# IoT Dashboard

Dashboard dibuat mengikuti tampilan referensi: dark UI, sidebar, Live Data, Settings, History, status ESP32, grafik, dan mode demo.

## Cara menjalankan
1. Buka `index.html` di browser.
2. Dashboard langsung menjalankan Demo Mode sehingga kartu sensor dan grafik bergerak.
3. Untuk ESP32 asli, gunakan Chrome/Edge desktop lalu klik **Connect ESP32**.
4. ESP32 harus mengirim satu JSON per baris melalui Serial @115200, contoh:
   {"temperature":25.4,"humidity":61,"device":"ESP32","firmware":"v2.1.8"}

## Fitur
- Live temperature & humidity
- Grafik realtime
- Demo Mode
- Web Serial untuk ESP32
- Connect / Disconnect
- History tersimpan di localStorage
- Export CSV
- Settings tersimpan di localStorage
- Responsive mobile
