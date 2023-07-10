// piano_html.h
#ifndef _PIANO_HTML_H
#define _PIANO_HTML_H

#include <pgmspace.h>

const char piano_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <style>
    /* Add your CSS styles here */
    .key {
      width: 23px;
      height: 80px;
      border: 1px solid #000;
      float: left;
      background-color: #fff;
    }
    .key.black {
      height: 50px;
      background-color: #000;
      width: 15px;
      margin-left: -8px;
      margin-right: -8px;
      z-index: 1;
    }
  </style>
</head>
<body>
  <div id='piano'>
    <h1>Piano</h1>
    <div id='keys'></div>
    <label for='volume'>Volume:</label>
    <input type='range' id='volume' name='volume' min='0' max='100' value='50'>
    <button onclick='playTheme(1)'>Play Ghostbusters (1984) Theme</button>
    <button onclick='playTheme(2)'>Play Ghostbusters (2016) Theme</button>
    <button onclick='playTheme(3)'>Play Ghostbusters: Afterlife Theme</button>
    <button onclick='playTheme(4)'>Play Slow Creepy Music</button>
  </div>
  <script>
    const keys = [
      {note: 262, color: 'white'},
      {note: 277, color: 'black'},
      /* Add the rest of your keys here */
    ];
    const keysElement = document.getElementById('keys');
    keys.forEach((key) => {
      const keyElement = document.createElement('div');
      keyElement.className = 'key ' + key.color;
      keyElement.addEventListener('click', () => playNote(key.note));
      keysElement.appendChild(keyElement);
    });
    function playNote(note) {
      fetch('/playNote?note=' + note).then((response) => response.text())
        .then((data) => console.log(data));
    }
    function playTheme(theme) {
      fetch('/playTheme?theme=' + theme).then((response) => response.text())
        .then((data) => console.log(data));
    }
    const volumeSlider = document.querySelector('input[type="range"]');
    volumeSlider.addEventListener('input', (event) => {
      fetch('/setVolume?volume=' + event.target.value).then((response) => response.text())
        .then((data) => console.log(data));
    });
  </script>
</body>
</html>
)rawliteral";

#endif // _PIANO_HTML_H
