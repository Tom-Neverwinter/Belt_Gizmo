// temperature_html.h
#ifndef _TEMPERATURE_HTML_H
#define _TEMPERATURE_HTML_H

#include <pgmspace.h>

const char temperature_html[] PROGMEM = R"rawliteral(
<div id='temp'>
  <h1>Temperature</h1>
  <p id='temperature_value'>--.- °C</p>
</div>
<script>
  function updateTemperatureDisplay(value) {
    document.getElementById('temperature_value').innerHTML = value + ' °C';
  }
  function fetchTemperature() {
    fetch('/getTemperature').then((response) => response.json())
      .then((data) => {
        updateTemperatureDisplay(data.temperature);
      });
  }
  setInterval(fetchTemperature, 1000); // Update temperature every 1 second (1000 ms)
</script>
)rawliteral";

#endif // _TEMPERATURE_HTML_H