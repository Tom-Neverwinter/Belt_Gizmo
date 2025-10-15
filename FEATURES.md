# Sanyo 808D PKE Meter - Feature Guide

## 🔢 Virtual Nixie Tube Display

The web interface features an authentic **8-digit nixie tube display** that mirrors your physical 7-segment LED hardware in real-time.

### Design Features
- **Orange glow aesthetic** - Inspired by the original Sanyo 808D PKE meter
- **Animated glow effect** - Pulsing orange light mimics real nixie tubes
- **Glass tube appearance** - Realistic rendering with highlights and shadows
- **Real-time synchronization** - Updates instantly with physical display

### How It Works
When you perform calculations or receive pager messages, both displays update simultaneously:
- Physical: 7-segment LED display on your hardware
- Virtual: Nixie tube display in the web browser

## 🧮 Calculator Function

Full-featured calculator with hardware integration.

### Features
- Standard operations: +, -, *, /
- Decimal point support
- Clear function
- Error handling for invalid expressions

### Display Integration
- Results appear on both physical and virtual displays
- Buzzer confirmation beep on calculation
- Visual error messages for invalid input

### Usage
1. Click number and operator buttons
2. Press `=` to calculate
3. Result displays on both screens
4. Press `C` to clear

## 📟 Pager Messaging System

Optimized messaging system designed for 8-character 7-segment LED displays.

### Features
- **8 character limit** - Perfectly fits physical LED display
- **Quick messages** - Pre-configured 8-char alerts
- **Optional beep** - Toggle notification sound on/off
- **Message history** - Scrollable log with timestamps (web only)
- **Physical display** - Messages show on all 8 LED digits
- **Auto-uppercase** - Converts to uppercase for LED readability
- **Auto-truncate** - Longer messages trimmed automatically

### Quick Message Buttons
- **GHOST** - Alert team to paranormal activity
- **PKE SURG** - Report sudden PKE energy spike
- **TRAP RDY** - Signal trap is armed and ready
- **RTN BASE** - Call team back to headquarters
- **ALERT** - General alert signal
- **HELP** - Emergency assistance needed

### Notification Beep Control
- **Checkbox toggle** - Enable/disable beep per message
- **Dual-tone alert** - 800Hz → 1000Hz notification
- **Volume aware** - Respects global buzzer volume setting
- **Silent mode** - Send messages without sound

### Custom Messages
Type any message up to 8 characters and press Send. Messages:
1. Appear in web interface log with timestamp
2. Display on physical 7-segment LEDs (all 8 digits)
3. Play optional dual-tone beep if enabled
4. Auto-convert to uppercase
5. Auto-truncate if longer than 8 characters

### Message Log
- Stores up to 50 messages
- Auto-scrolls to newest message
- Timestamps in local time
- Clear button to reset log
- Web interface only (not stored on device)

### Best Practices
- Use abbreviations: "RTN" instead of "RETURN"
- Numbers display clearly: "PKE 1234"
- Avoid special characters (may not display well)
- Use quick messages for speed
- Toggle beep off for silent operations

## 🎹 Piano / Tone Generator

13-key virtual piano with Ghostbusters theme songs.

### Piano Keys
- Full octave from C to C2
- White and black keys with visual feedback
- Hover effects
- Click to play notes

### Theme Songs
1. **Ghostbusters (1984)** - Original movie theme
2. **Ghostbusters (2016)** - Reboot theme variation
3. **Afterlife Theme** - Modern atmospheric version
4. **Creepy Music** - Spooky ambient sounds

### Volume Control
Adjustable buzzer volume from 0-100% affects all sounds:
- Piano notes
- Theme music
- Calculator beeps
- Pager notifications

## 🌡️ Temperature Monitor

Real-time temperature monitoring with auto-refresh.

### Features
- **Device Temperature** - ESP32 internal sensor reading
- **Ambient Temperature** - Placeholder for external sensor
- **Auto-update** - Refreshes every 2 seconds
- **JSON API** - Easy integration with external sensors

### Display
- Large numeric display with decimal precision
- Celsius units
- Nixie-style visual theme

## 🎨 PKE Energy Animations

Visual effects for atmospheric display.

### Features
- **Color cycling** - 9 different colors
- **Rotation effect** - Animated spinning
- **Scale effect** - Growing/shrinking animation
- **Glow effect** - Pulsing shadows
- **Speed control** - Adjustable from 1-10

### Controls
- **Start Animation** - Begin color cycling
- **Stop Animation** - Freeze current state
- **Speed Slider** - Adjust animation rate

## 🎨 Visual Design

### Color Scheme
- **Primary**: Orange (#ff6600) - Nixie tube glow
- **Secondary**: Dark brown (#442200) - Tube glass
- **Background**: Black (#0a0a0a) - Deep space
- **Accents**: Red-orange gradients

### Typography
- **Courier New** - Monospace for technical feel
- **Glowing text shadows** - Authentic nixie effect
- **Uppercase labels** - Military/technical aesthetic

### Interactive Elements
- Hover effects on all buttons
- Active state highlighting
- Smooth transitions (0.3s)
- Responsive touch targets

## 🔧 Technical Details

### Display Synchronization
```javascript
function updateVirtualDisplay(value) {
  // Converts any value to 8-digit display
  // Pads with leading zeros
  // Updates all 8 nixie tubes simultaneously
}
```

### Pager System
```javascript
function sendPagerMessage() {
  // Adds message to web log
  // Sends to hardware via /sendPagerMessage endpoint
  // Triggers notification beep
  // Updates physical display
}
```

### Calculator Logic
```javascript
function handleButtonClick(buttonValue) {
  // Handles all calculator operations
  // Updates virtual display
  // Sends to hardware
  // Plays confirmation beep
}
```

## 📱 Mobile Optimization

- Responsive button sizing
- Touch-friendly controls
- Viewport meta tag for proper scaling
- Flexible grid layouts
- Auto-scrolling message log

## 🔊 Audio System

### Buzzer Control
- Volume: 0-100%
- Frequency range: 180-1000 Hz
- Duration control
- PWM-based volume adjustment

### Sound Types
- **Calculator beep**: 1000 Hz, 100ms
- **Pager notification**: 800 Hz → 1000 Hz dual tone
- **Piano notes**: 262-523 Hz (C to C2)
- **Theme music**: Multi-note sequences

## 🌐 Network Features

### WiFi Access Point
- SSID: sanyo808D
- Password: ghostbuster
- IP: 192.168.4.1
- Subnet: 255.255.255.0

### Web Server
- Async HTTP server
- Non-blocking operations
- Parameter validation
- Error handling
- CORS-friendly

## 💡 Usage Tips

1. **Calculator**: Use virtual display to see results before they appear on hardware
2. **Pager**: Quick messages are fastest for common alerts
3. **Piano**: Adjust volume before playing themes
4. **Temperature**: Useful for monitoring device heat during extended use
5. **Animations**: Great for attracting attention at events

## 🎯 Future Enhancements

- Scrolling text for long pager messages
- External temperature sensor support
- Message scheduling
- Custom theme song upload
- Display brightness control
- Battery level indicator
- WiFi signal strength display
