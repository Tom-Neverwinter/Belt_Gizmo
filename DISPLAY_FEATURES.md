# Display Features - Animations & Clock

## 🎬 Display Animations

### Available Animations

#### 1. **Loading Bar** 📊
- **Effect**: Progress bar fills left to right
- **Pattern**: `████░░░░` → `████████`
- **Use Case**: Boot sequence, data loading, progress indication
- **Visual**: Fills one digit at a time with '8' character

#### 2. **Spinner** 🔄
- **Effect**: Rotating character moves across display
- **Pattern**: `|` → `/` → `-` → `\` (repeating)
- **Use Case**: Processing indicator, "thinking" animation
- **Visual**: Single rotating character travels left to right

#### 3. **Pulse** 💓
- **Effect**: Breathing brightness effect
- **Pattern**: Brightness fades in/out (0-15)
- **Use Case**: Standby mode, ambient effect, heartbeat
- **Visual**: "PKE 808D" text pulses with changing brightness

#### 4. **Sweep** ⚡
- **Effect**: Knight Rider / Cylon eye style
- **Pattern**: Single bright digit sweeps back and forth
- **Use Case**: Scanning mode, PKE detection sweep
- **Visual**: Bright center with trailing dimmer segments

#### 5. **Random** 🎲
- **Effect**: Random numbers flashing
- **Pattern**: Random 0-9 digits on all positions
- **Use Case**: Data corruption effect, energy fluctuation
- **Visual**: Chaotic number display

#### 6. **PKE Surge** 📈
- **Effect**: Simulates paranormal energy spike
- **Pattern**: Increasing/decreasing intensity wave
- **Use Case**: Ghost detection, energy readings
- **Visual**: Random segments light up based on intensity level

### Animation Control

**Speed Range**: 10ms - 1000ms per frame
- **Fast** (10-50ms): Rapid, energetic
- **Medium** (100-200ms): Standard speed
- **Slow** (300-1000ms): Deliberate, dramatic

**API Endpoints**:
```
GET /setAnimation?type=loading     - Start loading bar
GET /setAnimation?type=spinner     - Start spinner
GET /setAnimation?type=pulse       - Start pulse
GET /setAnimation?type=sweep       - Start sweep
GET /setAnimation?type=random      - Start random
GET /setAnimation?type=surge       - Start PKE surge
GET /setAnimation?type=none        - Stop all animations
GET /setAnimationSpeed?speed=100   - Set speed (ms)
```

---

## 🕐 NTP Clock

### Features

#### Real-Time Clock Display
- **Format**: HHMMSS (24-hour)
- **Example**: `14:32:05` displays as `143205`
- **Update**: Every 1 second
- **Sync**: NTP internet time server

#### Date Display
- **Format**: MMDDYYYY
- **Example**: October 15, 2025 → `10152025`
- **Fallback**: MMDDYY if year too long

#### Timezone Support
- **Range**: UTC-12 to UTC+12
- **Default**: UTC-5 (Eastern Time)
- **Adjustable**: Via dropdown or API
- **DST**: Daylight saving offset supported

### NTP Sync Process

1. **Initialize**: Click "Sync Time (NTP)"
2. **Connect**: Device contacts `pool.ntp.org`
3. **Wait**: 2-5 seconds for sync
4. **Display**: Click "Show Clock" to see time

**Requirements**:
- WiFi connection active
- Internet access
- NTP port 123 not blocked

### Clock Control

**Web Interface**:
- 🔄 **Sync Time** - Initialize NTP connection
- ⏰ **Show Clock** - Display current time (HHMMSS)
- 📅 **Show Date** - Display current date (MMDDYYYY)
- ⏹️ **Hide Clock** - Stop clock display

**API Endpoints**:
```
GET /initClock              - Initialize NTP sync
GET /showClock              - Enable clock display
GET /showDate               - Show date once
GET /hideClock              - Disable clock display
GET /setTimezone?offset=-5  - Set timezone (UTC offset)
```

### Timezone Reference

| Zone | Offset | Example Cities |
|------|--------|----------------|
| HST | UTC-10 | Honolulu |
| AKST | UTC-9 | Anchorage |
| PST | UTC-8 | Los Angeles, Seattle |
| MST | UTC-7 | Denver, Phoenix |
| CST | UTC-6 | Chicago, Dallas |
| EST | UTC-5 | New York, Miami |
| GMT | UTC+0 | London |
| CET | UTC+1 | Paris, Berlin |
| EET | UTC+2 | Cairo, Athens |
| JST | UTC+9 | Tokyo |
| AEST | UTC+10 | Sydney |

---

## 🎯 Use Cases

### Animations

**Boot Sequence**:
1. Loading bar (5 seconds)
2. Sweep animation (3 seconds)
3. Display "READY"

**PKE Detection**:
1. Random animation (building tension)
2. PKE Surge (energy spike detected)
3. Display reading number

**Standby Mode**:
- Pulse animation with "PKE 808D"
- Low brightness, slow speed
- Ambient presence indicator

**Processing**:
- Spinner animation
- Indicates device is working
- User feedback

### Clock

**Field Operations**:
- Show clock during missions
- Track operation duration
- Coordinate team timing

**Laboratory**:
- Timestamp experiments
- Log event times
- Sync with other equipment

**Display**:
- Show date at startup
- Clock during idle periods
- Time-based events

---

## 🔧 Technical Details

### Animation Implementation

**Frame-Based System**:
```cpp
int animationFrame = 0;        // Current frame counter
int animationSpeed = 100;      // Milliseconds per frame
unsigned long lastUpdate = 0;  // Last update timestamp

void updateAnimation() {
  if (millis() - lastUpdate >= animationSpeed) {
    lastUpdate = millis();
    animationFrame++;
    // Draw current frame
  }
}
```

**Non-Blocking**:
- Runs in main loop()
- Doesn't block other operations
- Smooth, continuous animation

### Clock Implementation

**NTP Sync**:
```cpp
#include <time.h>
configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

struct tm timeinfo;
getLocalTime(&timeinfo);
sprintf(timeStr, "%02d%02d%02d", 
  timeinfo.tm_hour, 
  timeinfo.tm_min, 
  timeinfo.tm_sec);
```

**Update Rate**:
- Clock: 1 second intervals
- Date: On-demand display
- NTP Sync: Once at startup, then as needed

### Display Priority

**Hierarchy** (highest to lowest):
1. Pager messages (user input)
2. Calculator results (user input)
3. Clock display (if enabled)
4. Animations (if active)
5. Idle message (default)

**Conflicts**:
- Animations stop when clock enabled
- Clock stops when animation starts
- User input overrides both

---

## 💡 Tips & Tricks

### Animation Tips

1. **Combine with Sound**: Play theme music with sweep animation
2. **Speed Variation**: Slow for dramatic, fast for urgent
3. **Loop Sequences**: Chain animations for complex effects
4. **Brightness**: Use pulse for subtle ambient effect

### Clock Tips

1. **Sync First**: Always sync time before showing clock
2. **Timezone**: Set correct timezone for accurate time
3. **24-Hour**: Display uses 24-hour format (military time)
4. **Date Format**: US format (MM/DD/YYYY)

### Best Practices

**Animations**:
- ✅ Use loading bar for actual progress
- ✅ Use spinner for indefinite wait
- ✅ Use sweep for scanning/detection
- ✅ Stop animations when not needed (saves power)

**Clock**:
- ✅ Sync time once at startup
- ✅ Use clock for field operations
- ✅ Hide clock when using other features
- ✅ Set correct timezone for your location

---

## 🎨 Creative Uses

### Animation Sequences

**Ghost Hunt Start**:
```
1. Sweep (3 sec) - Scanning area
2. Random (2 sec) - Energy fluctuation
3. PKE Surge (5 sec) - Detection!
4. Display reading
```

**System Boot**:
```
1. Loading bar (full cycle)
2. Pulse "PKE 808D" (3 sec)
3. Display "READY"
```

**Idle Attract Mode**:
```
1. Pulse (10 sec)
2. Sweep (5 sec)
3. Random (3 sec)
4. Repeat
```

### Clock Integration

**Mission Timer**:
- Show clock at mission start
- Track elapsed time
- Coordinate with team

**Lab Experiments**:
- Display time during tests
- Log timestamps
- Sync with data collection

**Event Timing**:
- Show countdown to event
- Display current time
- Alert at specific times

---

## 📊 Performance

### Animation Performance
- **CPU Usage**: Minimal (~1-2%)
- **Update Rate**: Configurable (10-1000ms)
- **Power**: Negligible impact
- **Smoothness**: Depends on speed setting

### Clock Performance
- **CPU Usage**: Very low (~0.5%)
- **Update Rate**: 1 second
- **Network**: Only during NTP sync
- **Accuracy**: ±1 second (NTP dependent)

---

## 🚀 Future Enhancements

### Potential Additions

**More Animations**:
- Scrolling text (long messages)
- Countdown timer
- Binary counter
- Morse code display
- Waveform patterns

**Clock Features**:
- Alarm function
- Stopwatch mode
- Countdown timer
- Multiple timezone display
- 12-hour format option

**Advanced**:
- Custom animation sequences
- Animation scripting
- Scheduled displays
- Event-triggered animations

---

## 📝 API Reference

### Animation Endpoints

| Endpoint | Parameters | Description |
|----------|------------|-------------|
| `/setAnimation` | `type=loading\|spinner\|pulse\|sweep\|random\|surge\|none` | Set animation |
| `/setAnimationSpeed` | `speed=10-1000` | Set speed (ms) |

### Clock Endpoints

| Endpoint | Parameters | Description |
|----------|------------|-------------|
| `/initClock` | None | Initialize NTP sync |
| `/showClock` | None | Enable clock display |
| `/showDate` | None | Show date once |
| `/hideClock` | None | Disable clock |
| `/setTimezone` | `offset=-12 to +12` | Set timezone |

---

**Remember**: Animations and clock are powerful visual tools. Use them to enhance the PKE meter experience, provide feedback, and create atmosphere! 👻⚡🕐
