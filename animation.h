// animations.h
#ifndef _ANIMATIONS_H
#define _ANIMATIONS_H

#include <pgmspace.h>

const char animations_html[] PROGMEM = R"rawliteral(
<div id='animations'>
  <h1>Animations</h1>
  <div id='colorBox' style='width: 100px; height: 100px; background-color: red; margin: 0 auto; transition: all 1s;'></div>
  <button onclick='startAnimation()'>Start Animation</button>
  <button onclick='stopAnimation()'>Stop Animation</button>
  <label for='speed'>Animation Speed:</label>
  <input type='range' id='speed' name='speed' min='1' max='5' value='1'>
</div>
<script>
  let colorIndex = 0;
  let animationInterval;

  function changeColor() {
    const colors = ['red', 'green', 'blue', 'yellow', 'purple', 'orange', 'pink', 'brown', 'gray'];
    colorIndex = (colorIndex + 1) % colors.length;
    const colorBox = document.getElementById('colorBox');
    colorBox.style.backgroundColor = colors[colorIndex];
    colorBox.style.transform = 'rotate(' + colorIndex * 36 + 'deg)';
    colorBox.style.width = (100 + colorIndex * 10) + 'px';
    colorBox.style.height = (100 + colorIndex * 10) + 'px';
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
</script>
)rawliteral";

#endif // _ANIMATIONS_H
