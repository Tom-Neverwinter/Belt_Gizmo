// calculator.h
#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <pgmspace.h>

const char calculator_html[] PROGMEM = R"rawliteral(
<div>
  <button onclick='showSection("calc")'>Calculator</button>
  <button onclick='showSection("animations")'>Animations</button>
  <button onclick='showSection("temp")'>Temperature</button>
  <button onclick='showSection("piano")'>Piano</button>
</div>
<div id='calc'>
  <form method='get' action='/calc'>
    <h1>Sanyo808D Calculator</h1>
    <p id="error" class="error"></p>
    <table>
      <!-- Rest of your HTML code -->
    </table>
    <input type='text' id='result' readonly>
    <input type='submit' value='='>
    <label for='volume'>Volume:</label>
    <input type='range' id='volume' name='volume' min='0' max='100' value='25'>
  </form>
  <script>
    let result = '';
    let volume = 25;
    function updateResult() {
      document.querySelector('#result').value = result;
    }
    function showError(message) {
      document.querySelector('#error').innerText = message;
    }
    function handleButtonClick(buttonValue) {
      if (buttonValue == 'C') {
        result = '';
      } else if (buttonValue == '=') {
        try {
          result = eval(result);
          updateLED(result);
          playBuzzer();
          showError('');
        } catch (e) {
          result = '';
          showError('Error: Invalid expression');
        }
      } else {
        result += buttonValue;
      }
      updateResult();
    }
    function updateLED(value) {
      fetch('/updateLed?value=' + value).then((response) => response.text())
        .then((data) => console.log(data));
    }
    function playBuzzer() {
      fetch('/playBuzzer?volume=' + volume).then((response) => response.text())
        .then((data) => console.log(data));
    }
    function setVolume(value) {
      volume = value;
    }
    const buttons = document.querySelectorAll('input[type="button"]');
    buttons.forEach((button) => {
      button.addEventListener('click', (event) => {
        event.preventDefault();
        handleButtonClick(button.value);
      });
    });
    const volumeSlider = document.querySelector('input[type="range"]');
    volumeSlider.addEventListener('input', (event) => {
      setVolume(event.target.value);
    });
  </script>
</div>
)rawliteral";

#endif // _CALCULATOR_H
