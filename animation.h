// animations.h
#ifndef _ANIMATIONS_H
#define _ANIMATIONS_H

#include <pgmspace.h>

const char animations_html[] PROGMEM = R"rawliteral(
<div id='animations'>
  <h1>Animations</h1>
  <div id='colorBox' style='width: 200px; height: 200px; background-color: red; margin: 0 auto;'></div>
  <button onclick='startAnimation()'>Start Animation</button>
  <button onclick='stopAnimation()'>Stop Animation</button>
</div>
<script>
  let colorIndex = 0;
  let animationInterval;

  function changeColor() {
    const colors = ['red', 'green', 'blue', 'yellow', 'purple'];
    colorIndex = (colorIndex + 1) % colors.length;
    document.getElementById('colorBox').style.backgroundColor = colors[colorIndex];
  }

  function startAnimation() {
    if (!animationInterval) {
      animationInterval = setInterval(changeColor, 1000);
    }
  }

  function stopAnimation() {
    if (animationInterval) {
      clearInterval(animationInterval);
      animationInterval = null;
    }
  }
    function startAnimation() {
    if (!animationInterval) {
      animationInterval = setInterval(changeColor, 1000);
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
