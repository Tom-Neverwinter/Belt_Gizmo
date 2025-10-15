# Changelog

## [Enhanced Edition] - 2025-10-15

### Added
- **Complete `index.h` file** with unified web interface
  - Ghostbusters-themed UI with green phosphor aesthetic
  - Responsive design for mobile and desktop
  - Section-based navigation (Calculator, Piano, Temperature, Animations)
  - Real-time updates and visual feedback

- **Full web handler implementations**
  - `/updateLed` - Display numbers on 7-segment LED
  - `/playBuzzer` - Play buzzer with volume control
  - `/playNote` - Play individual piano notes
  - `/playTheme` - Play 4 different Ghostbusters themes
  - `/getTemperature` - Get temperature readings (JSON)
  - `/setVolume` - Adjust buzzer volume
  - `/mute` - Toggle mute on/off

- **Audio system improvements**
  - Volume control (0-100%)
  - 4 theme songs (1984, 2016, Afterlife, Creepy)
  - 13-key piano with proper note frequencies (C to C2)
  - Tone generation with PWM-based volume control

- **Display enhancements**
  - `displayFloat()` function for decimal numbers
  - Improved `displayNumber()` with better digit handling
  - Support for negative numbers
  - Zero handling

- **Temperature monitoring**
  - ESP32 internal temperature sensor support
  - Simulated temperature for non-ESP32 boards
  - Auto-refresh every 2 seconds
  - JSON API for easy integration

- **Error handling**
  - Parameter validation on all endpoints
  - Meaningful error messages
  - HTTP status codes (200, 400)

### Fixed
- **Removed incorrect `server.handleClient()` call** in `loop()`
  - AsyncWebServer handles requests automatically
  - Prevents compilation errors

- **Fixed AsyncWebServer usage**
  - Changed from `String(index_html)` to `send_P()` for PROGMEM
  - Proper parameter handling with `hasParam()` and `getParam()`

- **Improved loop() function**
  - Added 10ms delay to prevent watchdog issues
  - Removed blocking operations
  - Better non-blocking theme playback

### Changed
- **Enhanced calculator**
  - Better error handling with try-catch
  - Visual error messages
  - Improved button layout
  - Volume slider with percentage display

- **Improved piano interface**
  - Visual key representation (white/black keys)
  - Hover effects
  - Key labels with note names
  - Better layout and styling

- **Better animations**
  - Smooth color transitions
  - Rotation and scaling effects
  - Adjustable speed (1-10)
  - Glowing effects matching Ghostbusters theme

- **Code organization**
  - Added ESP32-specific includes
  - Better function documentation
  - Consistent naming conventions
  - Modular function design

### Technical Improvements
- **Memory optimization**
  - Using PROGMEM for HTML storage
  - Efficient string handling
  - Reduced RAM usage

- **Performance**
  - Non-blocking operations
  - Efficient event handling
  - Optimized display updates

- **Compatibility**
  - ESP32 temperature sensor support
  - Fallback for other boards
  - Cross-platform compatibility

### Documentation
- Updated README.md with comprehensive documentation
- Added API endpoint reference
- Included pin configuration details
- Installation instructions
- Future enhancement roadmap

## [Original] - Previous Version

### Features
- Basic WiFi access point
- MAX7219 LED display support
- Buzzer support
- Web server framework
- Basic HTML structure (incomplete)

### Known Issues (Fixed in Enhanced Edition)
- Missing index.h file
- Commented-out web handlers
- Incorrect AsyncWebServer usage
- No temperature sensor implementation
- Incomplete piano functionality
- No theme music implementation
