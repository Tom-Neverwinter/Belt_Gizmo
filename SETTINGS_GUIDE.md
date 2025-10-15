# Settings Page - Complete Guide

## 📑 Overview

The Settings page provides centralized control over all device features, preferences, and system configuration. Access it via the **Settings** tab in the navigation bar.

## 🔊 Sound Settings

### Master Volume Control
- **Range**: 0-100%
- **Default**: 50%
- **Syncs with**: Calculator volume slider
- **Affects**: All sounds (calculator, pager, piano, themes)

### Enable All Sounds Toggle
- ✅ **Checked**: Sounds enabled at current volume
- ☐ **Unchecked**: Mutes all sounds (sets volume to 0)
- **Quick mute**: Faster than adjusting volume slider

### Per-Feature Sound Toggles

#### Calculator Beep
- Controls confirmation beep when pressing `=`
- Independent of master volume
- Useful for silent calculations

#### Pager Notifications
- Controls dual-tone alert (800Hz → 1000Hz)
- Separate from per-message beep toggle in Pager tab
- Master override for all pager sounds

#### Piano Sounds
- Enable/disable piano key sounds
- Affects both individual notes and theme songs
- Useful for testing without noise

#### Auto-play Theme
- Controls automatic theme playback every 15 minutes
- Default: Enabled
- Plays Ghostbusters 1984 theme
- Disable for quiet operation

### Test Sound Button
- Plays two tones: 1000Hz → 1500Hz
- Verifies buzzer is working
- Tests current volume setting

## 💡 Display Settings

### LED Brightness
- **Range**: 0-15 (MAX7219 hardware levels)
- **Default**: 8 (medium)
- **0**: Display off (but still functional)
- **15**: Maximum brightness
- **Real-time**: Updates immediately on device

### Enable LED Display
- ✅ **Checked**: Display active
- ☐ **Unchecked**: Display shutdown (power saving)
- **Note**: Virtual display still works when disabled

### Status LED
- Controls GPIO 23 status LED
- ✅ **On**: LED lit (device active)
- ☐ **Off**: LED dark (stealth mode)
- Useful for night operations

### Display Timeout
- **Range**: 0-300 seconds
- **Default**: 0 (always on)
- **0**: Display never turns off
- **>0**: Auto-off after inactivity
- **Example**: 60 = display turns off after 1 minute

## 📟 Default Messages

### Startup Message
- **Length**: Max 8 characters
- **Default**: "READY"
- **When shown**: Device boot/reset
- **Auto-uppercase**: Converts to caps
- **Preview**: Click "Preview Startup" to test

### Idle Message
- **Length**: Max 8 characters
- **Default**: "PKE 808D"
- **When shown**: No activity for timeout period
- **Auto-uppercase**: Converts to caps
- **Preview**: Click "Preview Idle" to test

### Message Examples
```
Startup Messages:
- READY
- ONLINE
- BOOT OK
- PKE ON
- HELLO

Idle Messages:
- PKE 808D
- STANDBY
- IDLE
- WAITING
- SANYO808
```

## 📡 WiFi Information

### Network Details (Read-Only)
- **SSID**: sanyo808D
- **Password**: ghostbuster
- **IP Address**: 192.168.4.1
- **Status**: Connected (green) / Disconnected (red)

### Connection Info
- Device creates its own WiFi access point
- No internet connection (local only)
- Connect any device to access web interface
- Range: ~30 feet typical

## 🔧 System Actions

### Save Settings
- **Function**: Saves all settings to browser localStorage
- **Includes**: All sound, display, and message preferences
- **Persistent**: Survives browser refresh
- **Per-device**: Settings saved per browser/device
- **Alert**: Confirms save successful

### Load Settings
- **Function**: Automatically loads on page load
- **Source**: Browser localStorage
- **Fallback**: Uses defaults if no saved settings
- **Syncs**: Applies settings to device immediately

### Reset to Defaults
- **Function**: Clears all saved settings
- **Confirmation**: Asks "Reset all settings to defaults?"
- **Action**: Deletes localStorage and reloads page
- **Defaults restored**:
  - Volume: 50%
  - Brightness: 8
  - All sounds: Enabled
  - Display: Enabled
  - Startup: "READY"
  - Idle: "PKE 808D"

### Clear Display
- **Function**: Clears LED to "00000000"
- **Immediate**: Updates both virtual and physical displays
- **Useful**: Reset display before new message

### Test All Systems
- **Function**: Comprehensive system test
- **Sequence**:
  1. Display shows "12345678" (1 second)
  2. Plays dual-tone beep (800Hz → 1000Hz)
  3. Display shows "TEST OK" (1 second)
  4. Alert confirms completion
- **Duration**: ~3 seconds total
- **Verifies**: Display, sound, communication

## ℹ️ Device Information

### Hardware Details (Read-Only)
- **Device**: Sanyo 808D PKE Meter
- **Firmware**: v1.0 Enhanced
- **Display**: 8-Digit 7-Segment LED
- **Controller**: ESP32
- **Uptime**: HH:MM:SS (live counter)

### Uptime Counter
- Starts when page loads
- Format: Hours:Minutes:Seconds
- Updates every second
- Resets on page refresh
- Useful for monitoring session length

## 💾 Settings Storage

### Browser localStorage
- **Location**: Client-side (browser)
- **Capacity**: ~5-10MB typical
- **Persistence**: Survives browser close/reopen
- **Per-domain**: Separate for each website
- **Privacy**: Never sent to server automatically

### What's Saved
```javascript
{
  masterVolume: 50,
  soundEnabled: true,
  calculatorBeep: true,
  pagerBeepSetting: true,
  pianoEnabled: true,
  themeAutoplay: true,
  displayBrightness: 8,
  displayEnabled: true,
  statusLED: true,
  displayTimeout: 0,
  startupMessage: "READY",
  idleMessage: "PKE 808D"
}
```

### What's NOT Saved
- Pager message history
- Temperature readings
- Current display value
- Uptime counter
- WiFi status

## 🎯 Common Use Cases

### Silent Operation
1. Uncheck "Enable All Sounds"
2. Or set Master Volume to 0
3. Display still works normally

### Power Saving Mode
1. Set Display Brightness to 0-3
2. Set Display Timeout to 60 seconds
3. Uncheck Status LED
4. Uncheck Auto-play Theme

### Maximum Brightness
1. Set Display Brightness to 15
2. Good for bright environments
3. Uses more power

### Stealth Mode
1. Set Master Volume to 0
2. Uncheck Status LED
3. Set Display Brightness to 3
4. Uncheck Auto-play Theme

### Demo Mode
1. Set Display Brightness to 15
2. Set Master Volume to 75%
3. Check Auto-play Theme
4. Set Startup Message to "DEMO"

### Field Operation
1. Set Display Brightness to 10
2. Set Master Volume to 30%
3. Uncheck Auto-play Theme
4. Set Display Timeout to 120

## 🔄 Settings Sync

### How It Works
1. **Change setting** in web interface
2. **JavaScript** updates UI immediately
3. **API call** sent to ESP32 device
4. **Device** applies setting to hardware
5. **localStorage** saves for next session

### Sync Behavior
- **Volume**: Instant sync to buzzer
- **Brightness**: Instant sync to LED
- **Display toggle**: Instant hardware control
- **Messages**: Stored for later use
- **Timeout**: Applied on next idle period

## ⚠️ Important Notes

### Brightness Levels
- Level 0 = Display off (but still functional)
- Levels 1-5 = Dim (good for night)
- Levels 6-10 = Medium (normal use)
- Levels 11-15 = Bright (daylight)

### Volume Behavior
- Volume 0 = Muted (no sounds)
- Calculator beep toggle overrides volume
- Pager beep has two toggles (Settings + Pager tab)
- Piano toggle affects all musical sounds

### Display Timeout
- 0 = Never turns off
- Setting applies after next activity
- Display wakes on any interaction
- Timeout resets with each message/calculation

### Message Limits
- Startup/Idle messages: 8 characters max
- Auto-converted to uppercase
- Special characters may not display well
- Test with Preview buttons before setting

## 🐛 Troubleshooting

### Settings Not Saving
- Check browser allows localStorage
- Try different browser
- Clear browser cache and retry
- Check browser console for errors

### Volume Not Working
- Check "Enable All Sounds" is checked
- Verify Master Volume > 0
- Test with "Test Sound" button
- Check physical buzzer connection

### Display Not Updating
- Check "Enable LED Display" is checked
- Verify Brightness > 0
- Try "Test All Systems"
- Check physical LED connection

### Settings Reset on Refresh
- localStorage may be disabled
- Browser in private/incognito mode
- Try "Save Settings" button manually
- Check browser settings

## 💡 Pro Tips

1. **Save Often**: Click "Save Settings" after major changes
2. **Test First**: Use Preview buttons before setting messages
3. **Backup**: Take screenshot of settings for reference
4. **Volume Sync**: Master Volume syncs with Calculator volume
5. **Quick Mute**: Use "Enable All Sounds" toggle for fast mute
6. **Brightness**: Adjust based on ambient light
7. **Timeout**: Set to 0 for demos, 60+ for battery saving
8. **Messages**: Keep them short and clear (8 chars max)
9. **Test Systems**: Run "Test All Systems" after changes
10. **Reset**: Use "Reset to Defaults" if things get weird

## 📊 Settings Priority

When multiple settings conflict:

1. **Enable All Sounds** overrides Master Volume
2. **Display Enabled** overrides Brightness
3. **Per-feature toggles** override master settings
4. **Pager beep** (Pager tab) overrides Pager Notifications (Settings)
5. **Volume 0** mutes regardless of toggles

## 🔐 Security Notes

- Settings stored locally (not on device)
- No password protection on settings
- WiFi password is hardcoded (change in Arduino code)
- Settings visible to anyone with browser access
- No remote access (local WiFi only)

---

**Remember**: Settings are powerful! Start with defaults and adjust as needed. Use "Test All Systems" to verify changes work correctly.
