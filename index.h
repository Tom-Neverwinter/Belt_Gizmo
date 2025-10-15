// index.h
#ifndef _INDEX_H
#define _INDEX_H

#include <pgmspace.h>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset='UTF-8'>
  <meta name='viewport' content='width=device-width, initial-scale=1.0'>
  <title>Ghostbusters Belt Gizmo</title>
  <style>
    /* Theme Variables */
    :root {
      --primary-color: #ff6600;
      --primary-glow: rgba(255, 102, 0, 0.5);
      --secondary-color: #ff3300;
      --bg-dark: #0a0a0a;
      --bg-medium: #1a1a1a;
      --bg-light: #2a2a2a;
      --border-color: #442200;
      --text-color: #ff6600;
      --display-bg: linear-gradient(180deg, #1a0a00 0%, #0a0500 100%);
      --tube-border: #331100;
      --theme-name: 'Nixie Tube';
    }
    
    /* Military Surplus Theme */
    body.theme-military {
      --primary-color: #00ff00;
      --primary-glow: rgba(0, 255, 0, 0.5);
      --secondary-color: #00cc00;
      --bg-dark: #0a0a0a;
      --bg-medium: #1a1a1a;
      --bg-light: #2a2a2a;
      --border-color: #003300;
      --text-color: #00ff00;
      --display-bg: linear-gradient(180deg, #001a00 0%, #000a00 100%);
      --tube-border: #004400;
      --theme-name: 'Military Surplus';
    }
    
    /* Retro CRT Theme */
    body.theme-crt {
      --primary-color: #00ffff;
      --primary-glow: rgba(0, 255, 255, 0.5);
      --secondary-color: #00cccc;
      --bg-dark: #000000;
      --bg-medium: #0a0a0a;
      --bg-light: #1a1a1a;
      --border-color: #003333;
      --text-color: #00ffff;
      --display-bg: linear-gradient(180deg, #001a1a 0%, #000a0a 100%);
      --tube-border: #004444;
      --theme-name: 'CRT Monitor';
    }
    
    body {
      font-family: 'Courier New', monospace;
      background-color: var(--bg-dark);
      color: var(--text-color);
      margin: 0;
      padding: 0;
      background-image: 
        repeating-linear-gradient(0deg, transparent, transparent 2px, rgba(0,0,0,.3) 2px, rgba(0,0,0,.3) 4px);
      background-size: 100% 4px;
    }
    h1, h2 {
      text-align: center;
      color: var(--text-color);
      text-shadow: 0 0 15px var(--primary-color), 0 0 30px var(--secondary-color);
      font-family: 'Courier New', monospace;
      text-transform: uppercase;
      letter-spacing: 3px;
      font-weight: bold;
    }
    h1::before {
      content: '⚠ ';
      color: var(--secondary-color);
    }
    h1::after {
      content: ' ⚠';
      color: var(--secondary-color);
    }
    nav {
      background-color: #000;
      padding: 15px;
      text-align: center;
      border-bottom: 3px solid var(--primary-color);
      box-shadow: 0 0 30px var(--primary-glow);
      border-top: 1px solid var(--border-color);
    }
    nav button {
      background-color: var(--bg-medium);
      color: var(--text-color);
      border: 2px solid var(--primary-color);
      padding: 10px 20px;
      margin: 5px;
      cursor: pointer;
      font-size: 14px;
      font-family: 'Courier New', monospace;
      text-transform: uppercase;
      font-weight: bold;
      border-radius: 0;
      transition: all 0.3s;
      box-shadow: 0 0 10px var(--primary-glow), inset 0 0 5px rgba(0,0,0,0.5);
      position: relative;
    }
    nav button::before {
      content: '[ ';
    }
    nav button::after {
      content: ' ]';
    }
    nav button:hover, nav button.active {
      background-color: var(--primary-color);
      color: #000;
      box-shadow: 0 0 20px var(--primary-color);
      text-shadow: 0 0 5px #000;
    }
    
    /* Nixie Tube Display */
    .nixie-display {
      background: var(--display-bg);
      border: 4px solid var(--tube-border);
      border-radius: 3px;
      padding: 30px 20px;
      margin: 20px auto;
      max-width: 700px;
      box-shadow: inset 0 0 30px var(--primary-glow), 0 0 40px var(--primary-glow);
      position: relative;
    }
    .nixie-display::before {
      content: '';
      position: absolute;
      top: 0;
      left: 0;
      right: 0;
      height: 2px;
      background: var(--primary-color);
      opacity: 0.3;
    }
    .nixie-display::after {
      content: '⚡ CAUTION: HIGH VOLTAGE ⚡';
      position: absolute;
      bottom: 5px;
      left: 50%;
      transform: translateX(-50%);
      font-size: 9px;
      color: var(--secondary-color);
      letter-spacing: 1px;
      opacity: 0.7;
    }
    .nixie-tubes {
      display: flex;
      justify-content: center;
      gap: 8px;
      margin-bottom: 15px;
    }
    .nixie-tube {
      background: radial-gradient(circle, var(--bg-medium) 0%, #000 70%);
      border: 3px solid var(--border-color);
      border-radius: 3px;
      width: 70px;
      height: 100px;
      display: flex;
      align-items: center;
      justify-content: center;
      position: relative;
      box-shadow: inset 0 0 20px var(--primary-glow), 0 0 15px var(--primary-glow);
    }
    .nixie-tube::before {
      content: '';
      position: absolute;
      top: 5px;
      left: 10px;
      width: 15px;
      height: 15px;
      background: radial-gradient(circle, rgba(255, 255, 255, 0.3), transparent);
      border-radius: 50%;
      opacity: 0.6;
    }
    .nixie-tube::after {
      content: '';
      position: absolute;
      bottom: 3px;
      left: 3px;
      right: 3px;
      height: 1px;
      background: var(--primary-color);
      opacity: 0.2;
    }
    .nixie-digit {
      font-family: 'Courier New', monospace;
      font-size: 60px;
      font-weight: bold;
      color: var(--primary-color);
      text-shadow: 0 0 20px var(--primary-color), 0 0 40px var(--secondary-color), 0 0 60px var(--secondary-color);
      animation: nixieGlow 2s ease-in-out infinite;
    }
    @keyframes nixieGlow {
      0%, 100% { 
        text-shadow: 0 0 20px var(--primary-color), 0 0 40px var(--secondary-color), 0 0 60px var(--secondary-color);
        opacity: 1;
      }
      50% { 
        text-shadow: 0 0 30px var(--primary-color), 0 0 60px var(--secondary-color), 0 0 90px var(--secondary-color);
        opacity: 0.95;
      }
    }
    .display-label {
      text-align: center;
      color: var(--text-color);
      font-size: 11px;
      text-transform: uppercase;
      letter-spacing: 3px;
      margin-top: 10px;
      font-weight: bold;
    }
    .display-label::before {
      content: '▸ ';
    }
    .display-label::after {
      content: ' ◂';
    }
    .section {
      display: none;
      padding: 20px;
      max-width: 900px;
      margin: 20px auto;
      background-color: var(--bg-medium);
      border: 3px solid var(--primary-color);
      border-radius: 0;
      box-shadow: 0 0 30px var(--primary-glow), inset 0 0 20px rgba(0,0,0,0.5);
      position: relative;
    }
    .section::before {
      content: '█';
      position: absolute;
      top: 5px;
      left: 5px;
      color: var(--secondary-color);
      font-size: 8px;
    }
    .section.active {
      display: block;
    }
    .error {
      color: #ff0000;
      text-align: center;
      font-weight: bold;
      text-shadow: 0 0 10px #ff0000;
      text-transform: uppercase;
      letter-spacing: 2px;
    }
    .error::before {
      content: '⚠ ERROR: ';
    }
    input[type='text'], input[type='number'], textarea {
      width: 100%;
      padding: 10px;
      font-size: 16px;
      background-color: var(--bg-dark);
      color: var(--text-color);
      border: 2px solid var(--primary-color);
      border-radius: 0;
      text-align: right;
      font-family: 'Courier New', monospace;
      box-shadow: inset 0 0 10px var(--primary-glow);
      text-transform: uppercase;
    }
    input[type='text']::placeholder, input[type='number']::placeholder {
      color: var(--border-color);
      opacity: 0.7;
    }
    button, input[type='button'], input[type='submit'] {
      background-color: var(--bg-medium);
      color: var(--text-color);
      border: 2px solid var(--primary-color);
      padding: 12px 20px;
      margin: 5px;
      cursor: pointer;
      font-size: 13px;
      font-family: 'Courier New', monospace;
      text-transform: uppercase;
      font-weight: bold;
      border-radius: 0;
      transition: all 0.3s;
      min-width: 60px;
      box-shadow: 0 0 10px var(--primary-glow), inset 0 0 5px rgba(0,0,0,0.5);
      letter-spacing: 1px;
    }
    button:hover, input[type='button']:hover, input[type='submit']:hover {
      background-color: var(--primary-color);
      color: #000;
      box-shadow: 0 0 20px var(--primary-color);
      text-shadow: 0 0 3px #000;
    }
    button:active, input[type='button']:active, input[type='submit']:active {
      transform: translateY(2px);
      box-shadow: 0 0 5px var(--primary-color);
    }
    .calc-grid {
      display: grid;
      grid-template-columns: repeat(4, 1fr);
      gap: 10px;
      margin-top: 20px;
    }
    
    /* Pager System */
    .pager-container {
      background: linear-gradient(180deg, var(--bg-medium) 0%, var(--bg-dark) 100%);
      border: 3px solid var(--primary-color);
      border-radius: 0;
      padding: 20px;
      margin: 20px 0;
      box-shadow: 0 0 30px var(--primary-glow), inset 0 0 10px rgba(0,0,0,0.5);
      position: relative;
    }
    .pager-container::before {
      content: '▓▓';
      position: absolute;
      top: 5px;
      right: 5px;
      color: var(--border-color);
      font-size: 10px;
    }
    .pager-screen {
      background-color: #000;
      border: 2px solid var(--border-color);
      border-radius: 0;
      padding: 15px;
      min-height: 120px;
      max-height: 200px;
      overflow-y: auto;
      margin-bottom: 15px;
      font-family: 'Courier New', monospace;
      box-shadow: inset 0 0 20px var(--primary-glow);
    }
    .pager-message {
      color: var(--text-color);
      text-shadow: 0 0 5px var(--primary-color);
      margin: 5px 0;
      padding: 5px;
      border-bottom: 1px solid var(--border-color);
      animation: messageIn 0.3s ease-out;
    }
    .pager-message::before {
      content: '> ';
      color: var(--secondary-color);
    }
    @keyframes messageIn {
      from { opacity: 0; transform: translateX(-10px); }
      to { opacity: 1; transform: translateX(0); }
    }
    .pager-input-group {
      display: flex;
      gap: 10px;
    }
    .pager-input-group input {
      flex: 1;
    }
    .pager-input-group button {
      flex: 0 0 auto;
    }
    .message-timestamp {
      color: #884400;
      font-size: 11px;
      margin-right: 10px;
    }
    .key {
      width: 40px;
      height: 120px;
      border: 2px solid #ff6600;
      float: left;
      background-color: #fff;
      cursor: pointer;
      margin: 2px;
      transition: all 0.1s;
      box-shadow: 0 0 5px rgba(255, 102, 0, 0.3);
    }
    .key:hover {
      background-color: #ffcc99;
      box-shadow: 0 0 15px rgba(255, 102, 0, 0.6);
    }
    .key.black {
      height: 80px;
      background-color: #1a1a1a;
      width: 30px;
      margin-left: -16px;
      margin-right: -16px;
      z-index: 1;
      position: relative;
    }
    .key.black:hover {
      background-color: #442200;
      box-shadow: 0 0 15px rgba(255, 102, 0, 0.6);
    }
    #keys {
      overflow: hidden;
      padding: 20px;
      background-color: #1a1a1a;
      border-radius: 10px;
      border: 2px solid #442200;
    }
    input[type='range'] {
      width: 100%;
      margin: 10px 0;
      accent-color: #ff6600;
    }
    .temp-display {
      font-size: 24px;
      text-align: center;
      padding: 20px;
      margin: 10px 0;
      background-color: #0a0a0a;
      border: 2px solid #ff6600;
      border-radius: 5px;
      box-shadow: 0 0 20px rgba(255, 102, 0, 0.2);
    }
    #colorBox {
      width: 150px;
      height: 150px;
      background-color: #ff6600;
      margin: 20px auto;
      transition: all 1s;
      border: 2px solid #ff6600;
      box-shadow: 0 0 30px #ff6600;
    }
  </style>
</head>
<body>
  <h1>SANYO 808D PKE METER</h1>
  <div style='text-align: center; margin: -10px 0 10px 0; font-size: 11px; color: var(--border-color); letter-spacing: 2px;'>
    [ PARANORMAL KINETIC ENERGY DETECTION SYSTEM ]
  </div>
  
  <!-- Virtual 7-Segment Display -->
  <div class='nixie-display'>
    <div class='nixie-tubes' id='virtualDisplay'>
      <div class='nixie-tube'><span class='nixie-digit'>0</span></div>
      <div class='nixie-tube'><span class='nixie-digit'>0</span></div>
      <div class='nixie-tube'><span class='nixie-digit'>0</span></div>
      <div class='nixie-tube'><span class='nixie-digit'>0</span></div>
      <div class='nixie-tube'><span class='nixie-digit'>0</span></div>
      <div class='nixie-tube'><span class='nixie-digit'>0</span></div>
      <div class='nixie-tube'><span class='nixie-digit'>0</span></div>
      <div class='nixie-tube'><span class='nixie-digit'>0</span></div>
    </div>
    <div class='display-label'>PKE READING</div>
  </div>
  
  <nav>
    <button onclick='showSection("calc")' id='btn-calc'>Calculator</button>
    <button onclick='showSection("pager")' id='btn-pager'>Pager</button>
    <button onclick='showSection("display")' id='btn-display'>Display</button>
    <button onclick='showSection("piano")' id='btn-piano'>Piano</button>
    <button onclick='showSection("temp")' id='btn-temp'>Temperature</button>
    <button onclick='showSection("settings")' id='btn-settings'>Settings</button>
  </nav>

  <!-- Calculator Section -->
  <div id='calc' class='section active'>
    <h2>PKE Calculator</h2>
    <p id="error" class="error"></p>
    <div class='calc-grid'>
      <input type='button' value='7' onclick='handleButtonClick("7")'>
      <input type='button' value='8' onclick='handleButtonClick("8")'>
      <input type='button' value='9' onclick='handleButtonClick("9")'>
      <input type='button' value='/' onclick='handleButtonClick("/")'>
      <input type='button' value='4' onclick='handleButtonClick("4")'>
      <input type='button' value='5' onclick='handleButtonClick("5")'>
      <input type='button' value='6' onclick='handleButtonClick("6")'>
      <input type='button' value='*' onclick='handleButtonClick("*")'>
      <input type='button' value='1' onclick='handleButtonClick("1")'>
      <input type='button' value='2' onclick='handleButtonClick("2")'>
      <input type='button' value='3' onclick='handleButtonClick("3")'>
      <input type='button' value='-' onclick='handleButtonClick("-")'>
      <input type='button' value='0' onclick='handleButtonClick("0")'>
      <input type='button' value='.' onclick='handleButtonClick(".")'>
      <input type='button' value='=' onclick='handleButtonClick("=")'>
      <input type='button' value='+' onclick='handleButtonClick("+")'>
      <input type='button' value='C' onclick='handleButtonClick("C")' style='grid-column: span 2;'>
    </div>
    <label for='volume'>Buzzer Volume:</label>
    <input type='range' id='volume' name='volume' min='0' max='100' value='50'>
    <span id='volumeValue'>50%</span>
  </div>

  <!-- Pager Section -->
  <div id='pager' class='section'>
    <h2>PKE Pager System</h2>
    <div class='pager-container'>
      <div class='pager-screen' id='pagerScreen'>
        <div class='pager-message'>
          <span class='message-timestamp'>[SYSTEM]</span>
          Pager system online. Ready to receive messages.
        </div>
      </div>
      <div class='pager-input-group'>
        <input type='text' id='pagerInput' placeholder='Max 8 chars for LED display...' maxlength='8'>
        <button onclick='sendPagerMessage()'>Send</button>
        <button onclick='clearPagerMessages()'>Clear</button>
      </div>
      <div style='margin-top: 15px;'>
        <label>
          <input type='checkbox' id='pagerBeep' checked> Enable notification beep
        </label>
      </div>
      <div style='margin-top: 10px;'>
        <label>Quick Messages (8 chars max):</label><br>
        <button onclick='sendQuickMessage("GHOST")'>GHOST</button>
        <button onclick='sendQuickMessage("PKE SURG")'>PKE SURG</button>
        <button onclick='sendQuickMessage("TRAP RDY")'>TRAP RDY</button>
        <button onclick='sendQuickMessage("RTN BASE")'>RTN BASE</button>
        <button onclick='sendQuickMessage("ALERT")'>ALERT</button>
        <button onclick='sendQuickMessage("HELP")'>HELP</button>
      </div>
      <div style='margin-top: 10px; padding: 10px; background-color: #0a0a0a; border: 1px solid #442200; border-radius: 5px;'>
        <small>💡 Tip: Messages are limited to 8 characters to fit the physical LED display. Longer messages will be truncated.</small>
      </div>
    </div>
  </div>

  <!-- Display Section -->
  <div id='display' class='section'>
    <h2>Display Control</h2>
    
    <!-- Animations -->
    <div class='pager-container'>
      <h3>🎬 Display Animations</h3>
      <div style='margin: 15px 0;'>
        <button onclick='setDisplayAnimation("none")'>⏹️ Stop</button>
        <button onclick='setDisplayAnimation("loading")'>📊 Loading Bar</button>
        <button onclick='setDisplayAnimation("spinner")'>🔄 Spinner</button>
        <button onclick='setDisplayAnimation("pulse")'>💓 Pulse</button>
        <button onclick='setDisplayAnimation("sweep")'>⚡ Sweep</button>
        <button onclick='setDisplayAnimation("random")'>🎲 Random</button>
        <button onclick='setDisplayAnimation("surge")'>📈 PKE Surge</button>
      </div>
      <div style='margin: 15px 0;'>
        <label for='animSpeed'>Animation Speed:</label>
        <input type='range' id='animSpeed' min='10' max='500' value='100' oninput='updateAnimSpeed(this.value)'>
        <span id='animSpeedValue'>100ms</span>
      </div>
      <div style='margin-top: 10px; padding: 10px; background-color: var(--bg-dark); border: 1px solid var(--border-color);'>
        <small><strong>Loading Bar:</strong> Progress indicator<br>
        <strong>Spinner:</strong> Rotating character<br>
        <strong>Pulse:</strong> Breathing brightness effect<br>
        <strong>Sweep:</strong> Knight Rider style<br>
        <strong>Random:</strong> Random numbers<br>
        <strong>PKE Surge:</strong> Energy spike simulation</small>
      </div>
    </div>
    
    <!-- Clock -->
    <div class='pager-container' style='margin-top: 20px;'>
      <h3>🕐 NTP Clock</h3>
      <div style='margin: 15px 0;'>
        <button onclick='initNTPClock()'>🔄 Sync Time (NTP)</button>
        <button onclick='showClockDisplay()'>⏰ Show Clock</button>
        <button onclick='showDateDisplay()'>📅 Show Date</button>
        <button onclick='hideClockDisplay()'>⏹️ Hide Clock</button>
      </div>
      <div style='margin: 15px 0;'>
        <label for='timezone'>Timezone (UTC offset):</label>
        <select id='timezone' onchange='setTimezoneOffset(this.value)'>
          <option value='-12'>UTC-12 (Baker Island)</option>
          <option value='-11'>UTC-11 (American Samoa)</option>
          <option value='-10'>UTC-10 (Hawaii)</option>
          <option value='-9'>UTC-9 (Alaska)</option>
          <option value='-8'>UTC-8 (Pacific)</option>
          <option value='-7'>UTC-7 (Mountain)</option>
          <option value='-6'>UTC-6 (Central)</option>
          <option value='-5' selected>UTC-5 (Eastern)</option>
          <option value='-4'>UTC-4 (Atlantic)</option>
          <option value='-3'>UTC-3 (Argentina)</option>
          <option value='0'>UTC+0 (London)</option>
          <option value='1'>UTC+1 (Paris)</option>
          <option value='2'>UTC+2 (Cairo)</option>
          <option value='8'>UTC+8 (Beijing)</option>
          <option value='9'>UTC+9 (Tokyo)</option>
        </select>
      </div>
      <div style='margin-top: 10px; padding: 10px; background-color: var(--bg-dark); border: 1px solid var(--border-color);'>
        <small>💡 <strong>NTP Sync:</strong> Connects to internet time server<br>
        <strong>Clock Format:</strong> HHMMSS (24-hour)<br>
        <strong>Date Format:</strong> MMDDYYYY<br>
        <strong>Note:</strong> Requires WiFi connection to sync</small>
      </div>
    </div>
  </div>

  <!-- Piano Section -->
  <div id='piano' class='section'>
    <h2>Ghost Detector Piano</h2>
    <div id='keys'></div>
    <div style='clear: both; padding-top: 20px;'>
      <button onclick='playTheme(1)'>Play Ghostbusters Theme (1984)</button>
      <button onclick='playTheme(2)'>Play Ghostbusters Theme (2016)</button>
      <button onclick='playTheme(3)'>Play Afterlife Theme</button>
      <button onclick='playTheme(4)'>Play Creepy Music</button>
    </div>
  </div>

  <!-- Temperature Section -->
  <div id='temp' class='section'>
    <h2>PKE Meter Temperature</h2>
    <div class='temp-display'>
      <p>Device Temperature:</p>
      <p><span id='gizmo_temperature_value' style='font-size: 36px;'>--.-</span> °C</p>
    </div>
    <div class='temp-display'>
      <p>Ambient Temperature:</p>
      <p><span id='phone_temperature_value' style='font-size: 36px;'>--.-</span> °C</p>
    </div>
  </div>

  <!-- Settings Section -->
  <div id='settings' class='section'>
    <h2>⚙️ System Settings</h2>
    
    <!-- Theme Settings -->
    <div class='pager-container'>
      <h3>🎨 Interface Theme</h3>
      <div style='margin: 15px 0;'>
        <p style='margin-bottom: 10px;'><strong>Current Theme:</strong> <span id='currentTheme'>Nixie Tube</span></p>
        <button onclick='setTheme("nixie")' id='theme-nixie'>🟠 Nixie Tube (Orange)</button>
        <button onclick='setTheme("military")' id='theme-military'>🟢 Military Surplus (Green)</button>
        <button onclick='setTheme("crt")' id='theme-crt'>🔵 CRT Monitor (Cyan)</button>
      </div>
      <div style='margin-top: 10px; padding: 10px; background-color: var(--bg-dark); border: 1px solid var(--border-color);'>
        <small><strong>Nixie Tube:</strong> Warm orange glow, vintage 1980s aesthetic<br>
        <strong>Military Surplus:</strong> Green phosphor, rugged field equipment vibe<br>
        <strong>CRT Monitor:</strong> Cyan blue, retro computer terminal look</small>
      </div>
    </div>
    
    <!-- Sound Settings -->
    <div class='pager-container'>
      <h3>🔊 Sound Settings</h3>
      <div style='margin: 15px 0;'>
        <label for='masterVolume'>Master Volume:</label>
        <input type='range' id='masterVolume' min='0' max='100' value='50' oninput='updateMasterVolume(this.value)'>
        <span id='masterVolumeValue'>50%</span>
      </div>
      <div style='margin: 15px 0;'>
        <label>
          <input type='checkbox' id='soundEnabled' checked onchange='toggleSound(this.checked)'> Enable All Sounds
        </label>
      </div>
      <div style='margin: 15px 0;'>
        <label>
          <input type='checkbox' id='calculatorBeep' checked> Calculator Beep
        </label>
      </div>
      <div style='margin: 15px 0;'>
        <label>
          <input type='checkbox' id='pagerBeepSetting' checked> Pager Notifications
        </label>
      </div>
      <div style='margin: 15px 0;'>
        <label>
          <input type='checkbox' id='pianoEnabled' checked> Piano Sounds
        </label>
      </div>
      <div style='margin: 15px 0;'>
        <label>
          <input type='checkbox' id='themeAutoplay' checked> Auto-play Theme (every 15 min)
        </label>
      </div>
      <button onclick='testSound()'>Test Sound</button>
    </div>

    <!-- Display Settings -->
    <div class='pager-container' style='margin-top: 20px;'>
      <h3>💡 Display Settings</h3>
      <div style='margin: 15px 0;'>
        <label for='displayBrightness'>LED Brightness:</label>
        <input type='range' id='displayBrightness' min='0' max='15' value='8' oninput='updateBrightness(this.value)'>
        <span id='brightnessValue'>8</span>
      </div>
      <div style='margin: 15px 0;'>
        <label>
          <input type='checkbox' id='displayEnabled' checked onchange='toggleDisplay(this.checked)'> Enable LED Display
        </label>
      </div>
      <div style='margin: 15px 0;'>
        <label>
          <input type='checkbox' id='statusLED' checked onchange='toggleStatusLED(this.checked)'> Status LED
        </label>
      </div>
      <div style='margin: 15px 0;'>
        <label for='displayTimeout'>Display Timeout (seconds):</label>
        <input type='number' id='displayTimeout' min='0' max='300' value='0' style='width: 80px;'>
        <button onclick='setDisplayTimeout()'>Set</button>
        <br><small>0 = Always On</small>
      </div>
    </div>

    <!-- Message Settings -->
    <div class='pager-container' style='margin-top: 20px;'>
      <h3>📟 Default Messages</h3>
      <div style='margin: 15px 0;'>
        <label>Startup Message:</label>
        <input type='text' id='startupMessage' value='READY' maxlength='8' style='width: 200px;'>
        <button onclick='setStartupMessage()'>Set</button>
      </div>
      <div style='margin: 15px 0;'>
        <label>Idle Message:</label>
        <input type='text' id='idleMessage' value='PKE 808D' maxlength='8' style='width: 200px;'>
        <button onclick='setIdleMessage()'>Set</button>
      </div>
      <div style='margin: 15px 0;'>
        <button onclick='sendToDisplay("startupMessage")'>Preview Startup</button>
        <button onclick='sendToDisplay("idleMessage")'>Preview Idle</button>
      </div>
    </div>

    <!-- WiFi Settings -->
    <div class='pager-container' style='margin-top: 20px;'>
      <h3>📡 WiFi Information</h3>
      <div style='margin: 15px 0;'>
        <p><strong>SSID:</strong> sanyo808D</p>
        <p><strong>Password:</strong> ghostbuster</p>
        <p><strong>IP Address:</strong> 192.168.4.1</p>
        <p><strong>Status:</strong> <span id='wifiStatus' style='color: #00ff00;'>Connected</span></p>
      </div>
    </div>

    <!-- System Actions -->
    <div class='pager-container' style='margin-top: 20px;'>
      <h3>🔧 System Actions</h3>
      <div style='margin: 15px 0;'>
        <button onclick='saveSettings()'>💾 Save Settings</button>
        <button onclick='loadSettings()'>📂 Load Settings</button>
        <button onclick='resetSettings()'>🔄 Reset to Defaults</button>
      </div>
      <div style='margin: 15px 0;'>
        <button onclick='clearDisplay()'>🧹 Clear Display</button>
        <button onclick='testAllSystems()'>🧪 Test All Systems</button>
      </div>
      <div style='margin: 15px 0; padding: 10px; background-color: #0a0a0a; border: 1px solid #442200; border-radius: 5px;'>
        <small>💡 Settings are saved in browser localStorage and sent to device</small>
      </div>
    </div>

    <!-- Device Info -->
    <div class='pager-container' style='margin-top: 20px;'>
      <h3>ℹ️ Device Information</h3>
      <div style='margin: 15px 0;'>
        <p><strong>Device:</strong> Sanyo 808D PKE Meter</p>
        <p><strong>Firmware:</strong> v1.0 Enhanced</p>
        <p><strong>Display:</strong> 8-Digit 7-Segment LED</p>
        <p><strong>Controller:</strong> ESP32</p>
        <p><strong>Uptime:</strong> <span id='uptime'>--:--:--</span></p>
      </div>
    </div>
  </div>

  <script>
    // Global variables
    let result = '0';
    let volume = 50;
    let colorIndex = 0;
    let animationInterval;
    let pagerMessages = [];

    // Section switching
    function showSection(sectionId) {
      const sections = document.querySelectorAll('.section');
      sections.forEach(section => section.classList.remove('active'));
      document.getElementById(sectionId).classList.add('active');
      
      // Update button states
      const buttons = document.querySelectorAll('nav button');
      buttons.forEach(btn => btn.classList.remove('active'));
      document.getElementById('btn-' + sectionId).classList.add('active');
    }
    
    // Update virtual nixie tube display
    function updateVirtualDisplay(value) {
      const digits = String(value).padStart(8, '0').slice(-8).split('');
      const tubes = document.querySelectorAll('.nixie-digit');
      tubes.forEach((tube, index) => {
        tube.textContent = digits[index] || '0';
      });
    }

    // Calculator functions
    function updateResult() {
      updateVirtualDisplay(result);
    }
    
    function showError(message) {
      document.getElementById('error').innerText = message;
    }
    
    function handleButtonClick(buttonValue) {
      if (buttonValue == 'C') {
        result = '0';
        showError('');
      } else if (buttonValue == '=') {
        try {
          result = String(eval(result));
          updateLED(result);
          playBuzzer();
          showError('');
        } catch (e) {
          showError('Error: Invalid expression');
          result = '0';
        }
      } else {
        if (result === '0' && buttonValue !== '.') {
          result = buttonValue;
        } else {
          result += buttonValue;
        }
      }
      updateResult();
    }
    
    function updateLED(value) {
      // Update both physical and virtual displays
      updateVirtualDisplay(value);
      fetch('/updateLed?value=' + encodeURIComponent(value))
        .then(response => response.text())
        .then(data => console.log('LED updated:', data))
        .catch(err => console.error('LED update error:', err));
    }
    
    function playBuzzer() {
      fetch('/playBuzzer?volume=' + volume)
        .then(response => response.text())
        .then(data => console.log('Buzzer played:', data))
        .catch(err => console.error('Buzzer error:', err));
    }

    // Volume control
    const volumeSlider = document.getElementById('volume');
    volumeSlider.addEventListener('input', (event) => {
      volume = event.target.value;
      document.getElementById('volumeValue').innerText = volume + '%';
    });

    // Piano functions
    const notes = [
      {note: 262, color: 'white', name: 'C'},
      {note: 277, color: 'black', name: 'C#'},
      {note: 294, color: 'white', name: 'D'},
      {note: 311, color: 'black', name: 'D#'},
      {note: 330, color: 'white', name: 'E'},
      {note: 349, color: 'white', name: 'F'},
      {note: 370, color: 'black', name: 'F#'},
      {note: 392, color: 'white', name: 'G'},
      {note: 415, color: 'black', name: 'G#'},
      {note: 440, color: 'white', name: 'A'},
      {note: 466, color: 'black', name: 'A#'},
      {note: 494, color: 'white', name: 'B'},
      {note: 523, color: 'white', name: 'C2'}
    ];

    const keysElement = document.getElementById('keys');
    notes.forEach((key) => {
      const keyElement = document.createElement('div');
      keyElement.className = 'key ' + key.color;
      keyElement.title = key.name;
      keyElement.addEventListener('click', () => playNote(key.note));
      keysElement.appendChild(keyElement);
    });

    function playNote(note) {
      fetch('/playNote?note=' + note)
        .then(response => response.text())
        .then(data => console.log('Note played:', data))
        .catch(err => console.error('Note error:', err));
    }

    function playTheme(theme) {
      fetch('/playTheme?theme=' + theme)
        .then(response => response.text())
        .then(data => console.log('Theme played:', data))
        .catch(err => console.error('Theme error:', err));
    }

    // Temperature functions
    function updateTemperatureDisplay(id, value) {
      document.getElementById(id).innerHTML = value.toFixed(1);
    }

    function fetchGizmoTemperature() {
      fetch('/getTemperature')
        .then(response => response.json())
        .then(data => {
          if (data.temperature !== undefined) {
            updateTemperatureDisplay('gizmo_temperature_value', data.temperature);
          }
        })
        .catch(err => console.error('Temperature error:', err));
    }

    // Animation functions
    function changeColor() {
      const colors = ['#00ff00', '#00ff88', '#00ffff', '#0088ff', '#0000ff', '#8800ff', '#ff00ff', '#ff0088', '#ff0000'];
      colorIndex = (colorIndex + 1) % colors.length;
      const colorBox = document.getElementById('colorBox');
      colorBox.style.backgroundColor = colors[colorIndex];
      colorBox.style.transform = 'rotate(' + (colorIndex * 40) + 'deg) scale(' + (1 + colorIndex * 0.1) + ')';
      colorBox.style.boxShadow = '0 0 ' + (20 + colorIndex * 5) + 'px ' + colors[colorIndex];
    }

    function startAnimation() {
      if (!animationInterval) {
        const speed = document.getElementById('speed').value;
        animationInterval = setInterval(changeColor, 1000 / speed);
      }
    }

    function stopAnimation() {
      if (animationInterval) {
        clearInterval(animationInterval);
        animationInterval = null;
      }
    }

    // Speed control
    const speedSlider = document.getElementById('speed');
    speedSlider.addEventListener('input', (event) => {
      document.getElementById('speedValue').innerText = event.target.value;
      if (animationInterval) {
        stopAnimation();
        startAnimation();
      }
    });

    // Pager functions
    function sendPagerMessage() {
      const input = document.getElementById('pagerInput');
      let message = input.value.trim().toUpperCase();
      
      if (message) {
        // Enforce 8 character limit
        if (message.length > 8) {
          message = message.substring(0, 8);
        }
        
        addPagerMessage(message);
        input.value = '';
        
        // Check if beep is enabled
        const beepEnabled = document.getElementById('pagerBeep').checked;
        
        // Send to device with beep preference
        fetch('/sendPagerMessage?message=' + encodeURIComponent(message) + '&beep=' + (beepEnabled ? '1' : '0'))
          .then(response => response.text())
          .then(data => console.log('Pager message sent:', data))
          .catch(err => console.error('Pager error:', err));
      }
    }
    
    function sendQuickMessage(message) {
      // Quick messages are already 8 chars or less
      addPagerMessage(message);
      
      // Check if beep is enabled
      const beepEnabled = document.getElementById('pagerBeep').checked;
      
      fetch('/sendPagerMessage?message=' + encodeURIComponent(message) + '&beep=' + (beepEnabled ? '1' : '0'))
        .then(response => response.text())
        .then(data => console.log('Quick message sent:', data))
        .catch(err => console.error('Pager error:', err));
    }
    
    function addPagerMessage(message) {
      const screen = document.getElementById('pagerScreen');
      const timestamp = new Date().toLocaleTimeString();
      const messageDiv = document.createElement('div');
      messageDiv.className = 'pager-message';
      messageDiv.innerHTML = '<span class="message-timestamp">[' + timestamp + ']</span>' + message;
      screen.appendChild(messageDiv);
      screen.scrollTop = screen.scrollHeight;
      
      pagerMessages.push({time: timestamp, text: message});
      if (pagerMessages.length > 50) pagerMessages.shift();
    }
    
    function clearPagerMessages() {
      const screen = document.getElementById('pagerScreen');
      screen.innerHTML = '<div class="pager-message"><span class="message-timestamp">[SYSTEM]</span>Messages cleared.</div>';
      pagerMessages = [];
    }
    
    // Enter key support for pager
    document.addEventListener('DOMContentLoaded', function() {
      document.getElementById('pagerInput').addEventListener('keypress', function(e) {
        if (e.key === 'Enter') sendPagerMessage();
      });
      
      // Initialize display
      updateVirtualDisplay('00000000');
      document.getElementById('btn-calc').classList.add('active');
      
      // Load theme first
      loadTheme();
      
      // Load saved settings
      loadSettings();
      
      // Update uptime
      updateUptime();
      setInterval(updateUptime, 1000);
    });

    // Auto-update temperature
    setInterval(fetchGizmoTemperature, 2000);
    fetchGizmoTemperature();
    
    // Settings Functions
    let startTime = Date.now();
    
    function updateMasterVolume(value) {
      volume = parseInt(value);
      document.getElementById('masterVolumeValue').innerText = value + '%';
      document.getElementById('volume').value = value;
      document.getElementById('volumeValue').innerText = value + '%';
      
      // Send to device
      fetch('/setVolume?volume=' + value)
        .then(response => response.text())
        .then(data => console.log('Volume updated:', data))
        .catch(err => console.error('Volume error:', err));
    }
    
    function toggleSound(enabled) {
      if (!enabled) {
        updateMasterVolume(0);
      } else {
        const savedVolume = localStorage.getItem('savedVolume') || 50;
        updateMasterVolume(savedVolume);
      }
    }
    
    function updateBrightness(value) {
      document.getElementById('brightnessValue').innerText = value;
      
      // Send to device
      fetch('/setBrightness?value=' + value)
        .then(response => response.text())
        .then(data => console.log('Brightness updated:', data))
        .catch(err => console.error('Brightness error:', err));
    }
    
    function toggleDisplay(enabled) {
      fetch('/toggleDisplay?enabled=' + (enabled ? '1' : '0'))
        .then(response => response.text())
        .then(data => console.log('Display toggled:', data))
        .catch(err => console.error('Display error:', err));
    }
    
    function toggleStatusLED(enabled) {
      fetch('/toggleStatusLED?enabled=' + (enabled ? '1' : '0'))
        .then(response => response.text())
        .then(data => console.log('Status LED toggled:', data))
        .catch(err => console.error('Status LED error:', err));
    }
    
    function setDisplayTimeout() {
      const timeout = document.getElementById('displayTimeout').value;
      fetch('/setDisplayTimeout?seconds=' + timeout)
        .then(response => response.text())
        .then(data => {
          console.log('Timeout set:', data);
          alert('Display timeout set to ' + timeout + ' seconds');
        })
        .catch(err => console.error('Timeout error:', err));
    }
    
    function setStartupMessage() {
      const msg = document.getElementById('startupMessage').value.toUpperCase().substring(0, 8);
      fetch('/setStartupMessage?message=' + encodeURIComponent(msg))
        .then(response => response.text())
        .then(data => {
          console.log('Startup message set:', data);
          alert('Startup message set to: ' + msg);
        })
        .catch(err => console.error('Startup message error:', err));
    }
    
    function setIdleMessage() {
      const msg = document.getElementById('idleMessage').value.toUpperCase().substring(0, 8);
      fetch('/setIdleMessage?message=' + encodeURIComponent(msg))
        .then(response => response.text())
        .then(data => {
          console.log('Idle message set:', data);
          alert('Idle message set to: ' + msg);
        })
        .catch(err => console.error('Idle message error:', err));
    }
    
    function sendToDisplay(inputId) {
      const msg = document.getElementById(inputId).value.toUpperCase().substring(0, 8);
      updateVirtualDisplay(msg);
      fetch('/updateLed?value=' + encodeURIComponent(msg))
        .then(response => response.text())
        .then(data => console.log('Display updated:', data))
        .catch(err => console.error('Display error:', err));
    }
    
    function testSound() {
      playTone(1000, 200);
      setTimeout(() => playTone(1500, 200), 300);
    }
    
    function clearDisplay() {
      updateVirtualDisplay('00000000');
      fetch('/updateLed?value=0')
        .then(response => response.text())
        .then(data => console.log('Display cleared:', data))
        .catch(err => console.error('Clear error:', err));
    }
    
    function testAllSystems() {
      alert('Testing all systems...');
      
      // Test display
      updateVirtualDisplay('12345678');
      setTimeout(() => {
        // Test sound
        playTone(800, 100);
        setTimeout(() => playTone(1000, 100), 150);
      }, 1000);
      
      setTimeout(() => {
        updateVirtualDisplay('TEST OK');
        alert('System test complete!');
      }, 2000);
    }
    
    function saveSettings() {
      const settings = {
        masterVolume: document.getElementById('masterVolume').value,
        soundEnabled: document.getElementById('soundEnabled').checked,
        calculatorBeep: document.getElementById('calculatorBeep').checked,
        pagerBeepSetting: document.getElementById('pagerBeepSetting').checked,
        pianoEnabled: document.getElementById('pianoEnabled').checked,
        themeAutoplay: document.getElementById('themeAutoplay').checked,
        displayBrightness: document.getElementById('displayBrightness').value,
        displayEnabled: document.getElementById('displayEnabled').checked,
        statusLED: document.getElementById('statusLED').checked,
        displayTimeout: document.getElementById('displayTimeout').value,
        startupMessage: document.getElementById('startupMessage').value,
        idleMessage: document.getElementById('idleMessage').value
      };
      
      localStorage.setItem('pkeSettings', JSON.stringify(settings));
      alert('Settings saved to browser!');
    }
    
    function loadSettings() {
      const saved = localStorage.getItem('pkeSettings');
      if (saved) {
        const settings = JSON.parse(saved);
        
        document.getElementById('masterVolume').value = settings.masterVolume || 50;
        document.getElementById('masterVolumeValue').innerText = (settings.masterVolume || 50) + '%';
        document.getElementById('soundEnabled').checked = settings.soundEnabled !== false;
        document.getElementById('calculatorBeep').checked = settings.calculatorBeep !== false;
        document.getElementById('pagerBeepSetting').checked = settings.pagerBeepSetting !== false;
        document.getElementById('pianoEnabled').checked = settings.pianoEnabled !== false;
        document.getElementById('themeAutoplay').checked = settings.themeAutoplay !== false;
        document.getElementById('displayBrightness').value = settings.displayBrightness || 8;
        document.getElementById('brightnessValue').innerText = settings.displayBrightness || 8;
        document.getElementById('displayEnabled').checked = settings.displayEnabled !== false;
        document.getElementById('statusLED').checked = settings.statusLED !== false;
        document.getElementById('displayTimeout').value = settings.displayTimeout || 0;
        document.getElementById('startupMessage').value = settings.startupMessage || 'READY';
        document.getElementById('idleMessage').value = settings.idleMessage || 'PKE 808D';
        
        volume = parseInt(settings.masterVolume || 50);
      }
    }
    
    function resetSettings() {
      if (confirm('Reset all settings to defaults?')) {
        localStorage.removeItem('pkeSettings');
        location.reload();
      }
    }
    
    // Theme Functions
    function setTheme(themeName) {
      const body = document.body;
      
      // Remove all theme classes
      body.classList.remove('theme-military', 'theme-crt');
      
      // Add new theme class
      if (themeName === 'military') {
        body.classList.add('theme-military');
        document.getElementById('currentTheme').innerText = 'Military Surplus';
      } else if (themeName === 'crt') {
        body.classList.add('theme-crt');
        document.getElementById('currentTheme').innerText = 'CRT Monitor';
      } else {
        // Default nixie theme
        document.getElementById('currentTheme').innerText = 'Nixie Tube';
      }
      
      // Save theme preference
      localStorage.setItem('selectedTheme', themeName);
      
      // Update theme button states
      document.querySelectorAll('[id^="theme-"]').forEach(btn => {
        btn.style.opacity = '0.6';
      });
      document.getElementById('theme-' + themeName).style.opacity = '1';
    }
    
    function loadTheme() {
      const savedTheme = localStorage.getItem('selectedTheme') || 'nixie';
      setTheme(savedTheme);
    }
    
    // Display Animation Functions
    function setDisplayAnimation(type) {
      fetch('/setAnimation?type=' + type)
        .then(response => response.text())
        .then(data => console.log('Animation:', data))
        .catch(err => console.error('Animation error:', err));
    }
    
    function updateAnimSpeed(value) {
      document.getElementById('animSpeedValue').innerText = value + 'ms';
      fetch('/setAnimationSpeed?speed=' + value)
        .then(response => response.text())
        .then(data => console.log('Speed updated:', data))
        .catch(err => console.error('Speed error:', err));
    }
    
    // Clock Functions
    function initNTPClock() {
      fetch('/initClock')
        .then(response => response.text())
        .then(data => {
          console.log('Clock init:', data);
          alert('NTP time sync initiated. Wait a few seconds then show clock.');
        })
        .catch(err => console.error('Clock init error:', err));
    }
    
    function showClockDisplay() {
      fetch('/showClock')
        .then(response => response.text())
        .then(data => {
          console.log('Clock shown:', data);
          updateVirtualDisplay('CLOCK ON');
        })
        .catch(err => console.error('Clock error:', err));
    }
    
    function showDateDisplay() {
      fetch('/showDate')
        .then(response => response.text())
        .then(data => {
          console.log('Date shown:', data);
          updateVirtualDisplay('DATE');
        })
        .catch(err => console.error('Date error:', err));
    }
    
    function hideClockDisplay() {
      fetch('/hideClock')
        .then(response => response.text())
        .then(data => {
          console.log('Clock hidden:', data);
          updateVirtualDisplay('00000000');
        })
        .catch(err => console.error('Clock hide error:', err));
    }
    
    function setTimezoneOffset(offset) {
      fetch('/setTimezone?offset=' + offset)
        .then(response => response.text())
        .then(data => {
          console.log('Timezone set:', data);
          alert('Timezone updated to UTC' + (offset >= 0 ? '+' : '') + offset);
        })
        .catch(err => console.error('Timezone error:', err));
    }
    
    function updateUptime() {
      const elapsed = Date.now() - startTime;
      const hours = Math.floor(elapsed / 3600000);
      const minutes = Math.floor((elapsed % 3600000) / 60000);
      const seconds = Math.floor((elapsed % 60000) / 1000);
      document.getElementById('uptime').innerText = 
        String(hours).padStart(2, '0') + ':' + 
        String(minutes).padStart(2, '0') + ':' + 
        String(seconds).padStart(2, '0');
    }
  </script>
</body>
</html>
)rawliteral";

#endif // _INDEX_H
