<div align="center">

# 👻 Ghostbusters PKE Meter - Belt Gizmo
### Sanyo 808D Enhanced Edition

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-ESP32-blue.svg)](https://www.espressif.com/en/products/socs/esp32)
[![Arduino](https://img.shields.io/badge/Arduino-Compatible-green.svg)](https://www.arduino.cc/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)

*A fully functional, WiFi-enabled PKE meter with web interface, real-time clock, animations, and authentic Ghostbusters aesthetics*

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [API](#-api-reference) • [Contributing](#-contributing)

---

</div>

## 📖 About

Why pay $500+ for a belt gizmo when you can build your own? This project provides a complete software solution for a functional Ghostbusters PKE meter that works with popular 3D printable cases.

**Compatible with:**
- [Ghostbusters Belt Gizmo](https://cults3d.com/en/3d-model/gadget/ghostbusters-belt-gizmo) (Basic)
- [Ultimate Belt Gizmo with Daughter Board](https://cults3d.com/en/3d-model/gadget/ghostbusters-ultimate-belt-gizmo-with-daughter-bard) ⭐ **Recommended**

### What Makes This Special?

- 🎨 **3 Visual Themes** - Nixie Tube, Military Surplus, CRT Monitor
- 📱 **WiFi Web Interface** - Control everything from your phone
- 🕐 **Real-Time Clock** - NTP-synced time display
- 🎬 **6 Display Animations** - Loading bars, sweeps, PKE surges
- 📟 **Pager System** - Send 8-character messages
- 🎹 **Piano & Themes** - Play notes and Ghostbusters music
- 🌡️ **Temperature Monitor** - ESP32 internal sensor
- ⚙️ **Full Settings Control** - Brightness, volume, themes, timezones

---

## ✨ Recent Software Improvements

### 🎯 Key Improvements

<table>
<tr>
<td width="50%">

**✅ Core Fixes**
- Complete web interface
- All handlers functional
- Proper error handling
- AsyncWebServer fixed

</td>
<td width="50%">

**🎨 Visual Themes**
- 🟠 Nixie Tube (Orange)
- 🟢 Military Surplus (Green)
- 🔵 CRT Monitor (Cyan)

</td>
</tr>
<tr>
<td>

**🎬 Display Animations**
- Loading Bar
- Spinner
- Pulse (breathing)
- Sweep (Knight Rider)
- Random numbers
- PKE Surge

</td>
<td>

**🕐 NTP Clock**
- Real-time sync
- Timezone support
- Date display
- Auto-update

</td>
</tr>
</table>

---

## 🚀 Features

### 📱 Web Interface

<details>
<summary><b>6 Functional Tabs</b></summary>

1. **Calculator** - Working 4-function calculator with LED display
2. **Pager** - 8-character messaging system with quick alerts
3. **Display** - Animations and NTP clock control
4. **Piano** - 13-key virtual piano + 4 Ghostbusters themes
5. **Temperature** - Real-time temperature monitoring
6. **Settings** - Complete system configuration

</details>

<details>
<summary><b>3 Visual Themes</b></summary>

| Theme | Color | Aesthetic | Best For |
|-------|-------|-----------|----------|
| 🟠 **Nixie Tube** | Orange | Warm 1980s vintage | Indoor, classic feel |
| 🟢 **Military Surplus** | Green | Rugged tactical | Outdoor, high visibility |
| 🔵 **CRT Monitor** | Cyan | Retro terminal | Lab work, technical |

**Design Philosophy:** Gritty DIY blend of retro-futurism, military surplus, and garage-engineered mad science. Not sleek corporate tech—scrappy, analog, built from salvaged hardware.

</details>

### 🎬 Display Animations

| Animation | Effect | Use Case |
|-----------|--------|----------|
| 📊 Loading Bar | Progress fills left to right | Boot sequence, loading |
| 🔄 Spinner | Rotating character | Processing indicator |
| 💓 Pulse | Breathing brightness | Standby, ambient |
| ⚡ Sweep | Knight Rider style | Scanning, detection |
| 🎲 Random | Chaotic numbers | Energy fluctuation |
| 📈 PKE Surge | Intensity waves | Ghost detection |

**Speed Control:** 10ms - 1000ms per frame

### 🕐 Real-Time Clock

- **NTP Sync** - Connects to internet time server
- **Format** - HHMMSS (24-hour) or MMDDYYYY (date)
- **Timezones** - UTC-12 to UTC+12 with DST support
- **Auto-Update** - Refreshes every second

### 📟 Pager System

- **8-Character Limit** - Fits physical LED display perfectly
- **Quick Messages** - GHOST, PKE SURG, TRAP RDY, RTN BASE, ALERT, HELP
- **Optional Beep** - Toggle notification sound per message
- **Message Log** - Scrollable history with timestamps
- **Auto-Uppercase** - Optimized for LED readability

### 🎹 Audio Features

- **13-Key Piano** - Full octave (C to C2)
- **4 Theme Songs** - Ghostbusters 1984, 2016, Afterlife, Creepy
- **Volume Control** - 0-100% adjustable
- **Mute Toggle** - Quick silent mode

### ⚙️ Settings & Control

- **Theme Switcher** - Change visual style instantly
- **Brightness** - LED intensity 0-15
- **Volume** - Master and per-feature controls
- **Display Timeout** - Auto-off timer
- **Default Messages** - Startup and idle text
- **LocalStorage** - Settings persist across sessions

---

## 🔧 Hardware Requirements

### Components

| Component | Specification | GPIO Pin |
|-----------|---------------|----------|
| **Microcontroller** | ESP32 | - |
| **Display** | MAX7219 8-digit 7-segment (×8) | DATA:14, CLK:13, CS:27 |
| **Buzzer** | Passive buzzer | GPIO 2 |
| **Status LED** | Single LED | GPIO 23 |
| **Power** | 5V USB or battery | - |

### Wiring Diagram

```
ESP32                MAX7219 Display
GPIO 14  --------→  DIN (Data)
GPIO 13  --------→  CLK (Clock)
GPIO 27  --------→  CS  (Chip Select)
5V       --------→  VCC
GND      --------→  GND

GPIO 2   --------→  Buzzer (+)
GND      --------→  Buzzer (-)

GPIO 23  --------→  Status LED (+)
GND      --------→  Status LED (-) via resistor
```

### 3D Printable Cases

- **Basic:** [Ghostbusters Belt Gizmo](https://cults3d.com/en/3d-model/gadget/ghostbusters-belt-gizmo)
- **Recommended:** [Ultimate Belt Gizmo](https://cults3d.com/en/3d-model/gadget/ghostbusters-ultimate-belt-gizmo-with-daughter-bard) ⭐

---

## 📥 Installation

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) 1.8.x or newer
- [ESP32 Board Support](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)

### Required Libraries

Install via Arduino Library Manager:

```
MD_MAX72XX          - LED matrix control
ESPAsyncWebServer   - Async web server
AsyncTCP            - TCP library for ESP32
```

### Quick Start

1. **Clone Repository**
   ```bash
   git clone https://github.com/yourusername/Belt_Gizmo.git
   cd Belt_Gizmo
   ```

2. **Open in Arduino IDE**
   ```
   File → Open → beltgizmo.ino
   ```

3. **Configure Board**
   ```
   Tools → Board → ESP32 Dev Module
   Tools → Upload Speed → 115200
   Tools → Flash Size → 4MB
   ```

4. **Upload Code**
   ```
   Sketch → Upload (or Ctrl+U)
   ```

5. **Connect to WiFi**
   - SSID: `sanyo808D`
   - Password: `ghostbuster`
   - IP: `192.168.4.1`

6. **Open Web Interface**
   ```
   http://192.168.4.1
   ```

### WiFi Configuration

| Setting | Value |
|---------|-------|
| **Mode** | Access Point |
| **SSID** | sanyo808D |
| **Password** | ghostbuster |
| **IP Address** | 192.168.4.1 |
| **Subnet** | 255.255.255.0 |

**To change WiFi credentials**, edit `beltgizmo.ino`:
```cpp
const char* ssid = "your_ssid";
const char* password = "your_password";
```

---

## 📖 Usage

### First Boot

1. Power on device
2. Wait for WiFi AP to start (~5 seconds)
3. Connect phone/computer to `sanyo808D` network
4. Open browser to `http://192.168.4.1`
5. Explore the 6 tabs!

### Quick Actions

| Action | Steps |
|--------|-------|
| **Calculate** | Calculator tab → Enter numbers → Press = |
| **Send Message** | Pager tab → Type message → Send |
| **Show Clock** | Display tab → Sync Time → Show Clock |
| **Play Animation** | Display tab → Click animation button |
| **Change Theme** | Settings tab → Interface Theme → Select |
| **Adjust Volume** | Settings tab → Master Volume slider |

---

## 🔌 API Reference

### Base URL
```
http://192.168.4.1
```

### API Endpoints

<details>
<summary><b>Display Control</b></summary>

| Endpoint | Parameters | Description |
|----------|------------|-------------|
| `GET /updateLed` | `value=123` | Update LED display |
| `GET /setBrightness` | `value=0-15` | Set LED brightness |
| `GET /toggleDisplay` | `enabled=0\|1` | Enable/disable display |
| `GET /toggleStatusLED` | `enabled=0\|1` | Control status LED |
| `GET /setDisplayTimeout` | `seconds=60` | Set auto-off timer |

</details>

<details>
<summary><b>Display Animations</b></summary>

| Endpoint | Parameters | Description |
|----------|------------|-------------|
| `GET /setAnimation` | `type=loading\|spinner\|pulse\|sweep\|random\|surge\|none` | Set animation |
| `GET /setAnimationSpeed` | `speed=10-1000` | Animation speed (ms) |

**Animation Types:**
- `loading` - Progress bar
- `spinner` - Rotating character
- `pulse` - Breathing effect
- `sweep` - Knight Rider
- `random` - Random numbers
- `surge` - PKE surge
- `none` - Stop all

</details>

<details>
<summary><b>NTP Clock</b></summary>

| Endpoint | Parameters | Description |
|----------|------------|-------------|
| `GET /initClock` | - | Initialize NTP sync |
| `GET /showClock` | - | Display time (HHMMSS) |
| `GET /showDate` | - | Display date (MMDDYYYY) |
| `GET /hideClock` | - | Hide clock |
| `GET /setTimezone` | `offset=-5` | Set timezone (UTC offset) |

</details>

<details>
<summary><b>Sound Control</b></summary>

| Endpoint | Parameters | Description |
|----------|------------|-------------|
| `GET /playBuzzer` | `volume=50` | Play beep |
| `GET /playNote` | `note=440` | Play frequency (Hz) |
| `GET /playTheme` | `theme=1-4` | Play theme song |
| `GET /setVolume` | `volume=0-100` | Set master volume |
| `GET /mute` | - | Toggle mute |

</details>

<details>
<summary><b>Messaging</b></summary>

| Endpoint | Parameters | Description |
|----------|------------|-------------|
| `GET /sendPagerMessage` | `message=TEXT&beep=0\|1` | Send message (8 chars max) |
| `GET /setStartupMessage` | `message=READY` | Set boot message |
| `GET /setIdleMessage` | `message=PKE808D` | Set idle message |

</details>

<details>
<summary><b>Sensors</b></summary>

| Endpoint | Parameters | Description |
|----------|------------|-------------|
| `GET /getTemperature` | - | Get temperature (JSON) |

**Response Format:**
```json
{
  "temperature": 22.5
}
```

</details>

### Example API Calls

```bash
# Show clock
curl http://192.168.4.1/showClock

# Start sweep animation
curl http://192.168.4.1/setAnimation?type=sweep

# Send pager message
curl http://192.168.4.1/sendPagerMessage?message=GHOST&beep=1

# Set brightness
curl http://192.168.4.1/setBrightness?value=15

# Play theme
curl http://192.168.4.1/playTheme?theme=1
```

---

## 📚 Documentation

- **[FEATURES.md](FEATURES.md)** - Detailed feature guide
- **[THEMES_GUIDE.md](THEMES_GUIDE.md)** - Visual theme design philosophy
- **[SETTINGS_GUIDE.md](SETTINGS_GUIDE.md)** - Settings page documentation
- **[PAGER_GUIDE.md](PAGER_GUIDE.md)** - Pager system reference
- **[DISPLAY_FEATURES.md](DISPLAY_FEATURES.md)** - Animations & clock guide
- **[CHANGELOG.md](CHANGELOG.md)** - Version history

---

## 🤝 Contributing

Contributions are welcome! This project is free for all.

### How to Contribute

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`)
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. **Open** a Pull Request

### Ideas for Contributions

- 🎨 Additional visual themes
- 🎬 More display animations
- 🎵 Additional theme songs
- 📊 Data logging features
- 🔧 External sensor support
- 🌐 Multi-language support
- 📱 Mobile app integration
- 🔄 OTA firmware updates

---

## 🎯 Roadmap

- [ ] External temperature sensor (DS18B20)
- [ ] EEPROM settings storage
- [ ] OTA firmware updates
- [ ] Scrolling text for long messages
- [ ] Bluetooth connectivity
- [ ] Battery level indicator
- [ ] Custom animation sequences
- [ ] Alarm/timer functions
- [ ] Data logging to SD card
- [ ] MQTT integration

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 💖 Support

If you find this project useful, consider:

- ⭐ **Starring** this repository
- 🐛 **Reporting** bugs and issues
- 💡 **Suggesting** new features
- 🔀 **Contributing** code improvements
- 💵 **Donating** via PayPal: Tom_Neverwinter@yahoo.com

---

## 🙏 Acknowledgments

- **3D Models** - Thanks to the creators on Cults3D
- **Ghostbusters** - For the inspiration and iconic design
- **Community** - Everyone who contributes and provides feedback
- **Libraries** - MD_MAX72XX, ESPAsyncWebServer, AsyncTCP

---

## 📞 Contact

- **Issues** - [GitHub Issues](https://github.com/yourusername/Belt_Gizmo/issues)
- **Discussions** - [GitHub Discussions](https://github.com/yourusername/Belt_Gizmo/discussions)
- **Email** - Tom_Neverwinter@yahoo.com

---

<div align="center">

### 👻 "We're ready to believe you!" 👻

**Made with ❤️ for Ghostbusters fans everywhere**

[⬆ Back to Top](#-ghostbusters-pke-meter---belt-gizmo)

</div>
