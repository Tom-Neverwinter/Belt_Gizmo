// calculator.h
#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <pgmspace.h>

const char calculator_html[] PROGMEM = R"rawliteral(
<div id='calc'>
  <form method='get' action='/calc'>
    <h1>Sanyo808D Calculator</h1>
    <style>
      body {
        font-family: Arial, sans-serif;
        background-color: #333;
        color: #FFA500;
      }
      h1 {
        text-align: center;
          }\
          table {\
            margin: 0 auto;\
          }\
          td {\
            padding: 10px;\
            border-radius: 5px;\
            background-color: #222;\
            color: #FFA500;\
            font-weight: bold;\
            text-align: center;\
          }\
          input[type=submit] {\
            background-color: #FFA500;\
            color: black;\
            padding: 10px 20px;\
            border: none;\
            border-radius: 5px;\
            cursor: pointer;\
            font-size: 16px;\
            margin-top: 10px;\
          }\
          input[type=text] {\
            padding: 10px;\
            border-radius: 5px;\
            border: none;\
            font-size: 16px;\
          margin-top: 10px;\
          width: 100%;\
          box-sizing: border-box;\
          background-color: #333;\
          color: #FFA500;\
          text-align: right;\
        }\
        input[type=range] {\
          width: 100%;\
          margin: 10px 0;\
        }\
      </style>\\
    </head>\
    <body>\
    <div>\
    <button onclick='showSection(\"calc\")'>Calculator</button>\
    <button onclick='showSection(\"animations\")'>Animations</button>\
    <button onclick='showSection(\"temp\")'>Temperature</button>\
    <button onclick='showSection(\"piano\")'>Piano</button>\
    </div>\
    <div id='calc'>\
      <form method='get' action='/calc'>\
        <h1>Sanyo808D Calculator</h1>\
        <table>\
          <tr>\
            <td><input type='button' name='num7' value='7'></td>\
            <td><input type='button' name='num8' value='8'></td>\
            <td><input type='button' name='num9' value='9'></td>\
            <td><input type='button' name='op' value='-'></td>\
          </tr>\
          <tr>\
            <td><input type='button' name='num4' value='4'></td>\
            <td><input type='button' name='num5' value='5'></td>\
            <td><input type='button' name='num6' value='6'></td>\
            <td><input type='button' name='op' value='*'></td>\
          </tr>\
          <tr>\
            <td><input type='button' name='num1' value='1'></td>\
            <td><input type='button' name='num2' value='2'></td>\
            <td><input type='button' name='num3' value='3'></td>\
            <td><input type='button' name='op' value='/'></td>\
          </tr>\
          <tr>\
            <td><input type='button' name='op' value='C'></td>\
            <td><input type='button' name='op' value='' disabled></td>\
            <td><input type='button' name='num0' value='0'></td>\
            <td><input type='button' name='op' value='+'></td>\
          </tr>\
        </table>\
        <input type='text' name='result' readonly>\
        <input type='submit' value='='>\
        <label for='volume'>Volume:</label>\
        <input type='range' id='volume' name='volume' min='0' max='100' value='25'>\
      </form>\
      <script>\
        let result = '';\
        let volume = 25;\
        function updateResult() {\
          document.querySelector('[name=\"result\"]').value = result;\
        }\
        function handleButtonClick(buttonValue) {\
          if (buttonValue == 'C') {\
            result = '';\
          } else if (buttonValue == '=') {\
            try {\
              result = eval(result);\
              updateLED(result);\
              playBuzzer();\
            } catch (e) {\
              result = 'Error';\
            }\
          } else {\
            result += buttonValue;\
          }\
          updateResult();\
        }\
        function updateLED(value) {\
          fetch('/updateLed?value=' + value).then((response) => response.text())\
            .then((data) => console.log(data));\
        }\
        function playBuzzer() {\
          fetch('/playBuzzer?volume=' + volume).then((response) => response.text())\
            .then((data) => console.log(data));\
        }\
        function setVolume(value) {\
          volume = value;\
        }\
        const buttons = document.querySelectorAll('input[type=\"button\"]');\
        buttons.forEach((button) => {\
          button.addEventListener('click', (event) => {\
            event.preventDefault();\
            handleButtonClick(button.value);\
          });\
        });\
        const volumeSlider = document.querySelector('input[type=\"range\"]');\
        volumeSlider.addEventListener('input', (event) => {
          setVolume(event.target.value);
        });
      </script>
    </body>
  </html>
</script>
)rawliteral";

#endif // _CALCULATOR_H