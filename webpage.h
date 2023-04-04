// webpage.h
#ifndef _WEBPAGE_H
#define _WEBPAGE_H

#include <pgmspace.h>
#include "calculator.h"
#include "piano.h"
#include "temperature.h"
#include "animations.h"

const char html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <meta charset='UTF-8'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <title>Sanyo808D</title>
    <style>
      ... // Include the existing styles here
    </style>
  </head>
  <body>
    <div>
      <button onclick='showSection("calc")'>Calculator</button>
      <button onclick='showSection("animations")'>Animations</button>
      <button onclick='showSection("temp")'>Temperature</button>
      <button onclick='showSection("piano")'>Piano</button>
    </div>
    calculator.h
    animations_html
    temperature.h
    piano.h
    <script>