// temperature_html.h
#ifndef _TEMPERATURE_HTML_H
#define _TEMPERATURE_HTML_H

#include <pgmspace.h>

const char temperature_html[] PROGMEM = R"rawliteral(
<div id='temp'>
  <h1>Temperature</h1>
  <p>Gizmo Temperature: <span id='gizmo_temperature_value'>--.- °C</span></p>
  <p>Phone Temperature: <span id='phone_temperature_value'>--.- °C</span></p>
</div>
<script>
  function updateTemperatureDisplay(id, value) {
    document.getElementById(id).innerHTML = value + ' °C';
  }
  function fetchGizmoTemperature() {
    fetch('/getTemperature').then((response) => response.json())
      .then((data) => {
        updateTemperatureDisplay('gizmo_temperature_value', data.temperature);
      });
  }
  function fetchPhoneTemperature() {
    // Here you would fetch the phone's temperature and call updateTemperatureDisplay
    // updateTemperatureDisplay('phone_temperature_value', phoneTemperature);
  }
  setInterval(fetchGizmoTemperature, 1000); // Update gizmo temperature every 1 second (1000 ms)
  setInterval(fetchPhoneTemperature, 1000); // Update phone temperature every 1 second (1000 ms)
</script>
)rawliteral";

#endif // _TEMPERATURE_HTML_H
