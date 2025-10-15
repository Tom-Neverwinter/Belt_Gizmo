# Pager System - Quick Reference Guide

## 🎯 8-Character Display Optimization

Your physical 7-segment LED display has **exactly 8 digits**. The pager system is optimized for this limitation.

## ✅ Quick Messages (Pre-Configured)

These messages are designed to fit perfectly on your display:

| Button | Display | Meaning |
|--------|---------|---------|
| GHOST | `GHOST   ` | Ghost detected nearby |
| PKE SURG | `PKE SURG` | PKE energy surge detected |
| TRAP RDY | `TRAP RDY` | Trap is ready to deploy |
| RTN BASE | `RTN BASE` | Return to base |
| ALERT | `ALERT   ` | General alert |
| HELP | `HELP    ` | Emergency assistance |

## 📝 Custom Messages

### Character Limit
- **Maximum**: 8 characters
- **Automatic**: Converts to UPPERCASE
- **Automatic**: Truncates if longer than 8 chars

### Examples of Good Messages
```
READY    (5 chars)
GO NOW   (6 chars)
PKE 9999 (8 chars)
WAIT     (4 chars)
CLEAR    (5 chars)
DANGER   (6 chars)
CODE RED (8 chars)
```

### Tips for Abbreviations
- **RETURN** → **RTN**
- **DETECTED** → **DETECT** or **DET**
- **EMERGENCY** → **EMERG** or **ALERT**
- **LOCATION** → **LOC**
- **POSITION** → **POS**
- **STATUS** → **STAT**
- **CONFIRM** → **CONF**
- **NEGATIVE** → **NEG**
- **AFFIRMATIVE** → **YES** or **AFFIRM**

## 🔊 Notification Beep Control

### Checkbox Toggle
- ✅ **Checked** = Beep enabled (default)
- ☐ **Unchecked** = Silent mode

### When to Use Silent Mode
- Stealth operations
- Quiet environments
- Night operations
- When buzzer is annoying
- Testing without sound

### Beep Behavior
- **Enabled**: Plays 800Hz → 1000Hz dual-tone
- **Disabled**: Message still displays, no sound
- **Volume**: Respects global buzzer volume setting
- **Mute**: If buzzer volume is 0, no beep regardless of checkbox

## 🖥️ Display Behavior

### Physical LED Display
- Shows **exactly 8 characters**
- Uppercase letters and numbers only
- Limited special character support
- Characters appear left-to-right
- Blank spaces fill unused digits

### Virtual Nixie Display
- Shows same 8 characters as physical
- Orange glowing effect
- Updates in real-time
- Synchronized with hardware

### Web Message Log
- Unlimited length in history
- Shows full timestamp
- Scrollable list
- Stores up to 50 messages
- Not saved on device (web only)

## 📱 Usage Examples

### Emergency Alert
1. Type: `HELP`
2. Ensure beep is ✅ checked
3. Press Send
4. Result: Loud dual-tone alert + LED display

### Silent Status Update
1. Type: `ALL GOOD` (truncates to `ALL GOOD`)
2. Uncheck ☐ beep checkbox
3. Press Send
4. Result: Silent LED update

### Quick Alert
1. Click **GHOST** button
2. Beep plays if enabled
3. Instant transmission

### Numeric Code
1. Type: `12345678`
2. All 8 digits display
3. Perfect for codes/IDs

## 🔧 Technical Details

### API Call
```
GET /sendPagerMessage?message=GHOST&beep=1
```

### Parameters
- `message`: Text (max 8 chars, auto-truncated)
- `beep`: `1` (enabled) or `0` (disabled)

### Arduino Function
```cpp
displayMessage(String message)
// Displays up to 8 characters on LED
// Handles uppercase conversion
// Maps chars to 7-segment patterns
```

### JavaScript Function
```javascript
sendPagerMessage()
// Enforces 8-char limit
// Converts to uppercase
// Checks beep toggle
// Sends to device
```

## ⚠️ Limitations

### What Works Well
- ✅ Uppercase letters (A-Z)
- ✅ Numbers (0-9)
- ✅ Spaces
- ✅ Short words

### What May Not Display
- ❌ Lowercase (auto-converted)
- ❌ Special symbols (varies by display)
- ❌ Emojis
- ❌ Accented characters

### Character Mapping
Your 7-segment display can show:
- All numbers: 0-9
- Most letters: A, B, C, D, E, F, G, H, I, J, L, O, P, S, U, Y
- Limited: K, M, N, Q, R, T, V, W, X, Z (may look odd)

## 💡 Pro Tips

1. **Test First**: Try messages to see how they display
2. **Use Numbers**: Numbers always display perfectly
3. **Abbreviate**: Get creative with short forms
4. **Quick Buttons**: Fastest for common alerts
5. **Silent Mode**: Toggle beep for different situations
6. **Message Log**: Check web interface for full history
7. **Volume Control**: Set buzzer volume separately
8. **Uppercase**: System does it automatically

## 🎮 Keyboard Shortcuts

- **Enter Key**: Send message (when input is focused)
- **Tab**: Navigate between input and buttons
- **Space**: Toggle beep checkbox (when focused)

## 📊 Message Examples by Category

### Status Updates
```
READY
BUSY
WAITING
DONE
COMPLETE (truncates to COMPLETE)
```

### Locations
```
BASE
FIELD
SITE A
LOC 1234
```

### Actions
```
GO
STOP
HOLD
MOVE
DEPLOY
```

### Alerts
```
DANGER
CAUTION
WARNING (truncates to WARNING)
URGENT
```

### Confirmations
```
YES
NO
OK
CONFIRM (truncates to CONFIRM)
RECEIVED (truncates to RECEIVED)
```

## 🔄 Workflow Example

**Field Operation Scenario:**

1. Base sends: `GHOST` (beep ON) → Team alerted
2. Team responds: `MOVING` (beep OFF) → Silent confirmation
3. Base updates: `LOC 42` (beep ON) → Location alert
4. Team confirms: `ARRIVED` (beep OFF) → Status update
5. Emergency: `HELP` (beep ON) → Loud alert
6. Base responds: `BACKUP` (beep ON) → Confirmation

---

**Remember**: The 8-character limit isn't a bug, it's a feature! It forces clear, concise communication just like real pagers from the 1990s. 📟
