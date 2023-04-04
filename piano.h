#ifndef PIANO_H
#define PIANO_H

#include <toneAC.h>

// Define note frequencies for a 3-octave range
const int notes[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988, 1047};

// Define effect parameters
const int effectDelays[] = {0, 50, 100, 150, 200, 250};
const int effectIntensities[] = {0, 5, 10, 15, 20, 25};

void playNote(int note, int delayTime) {
  toneAC(note, effectDelays[delayTime]);
}

void setDelay(int delayTime) {
  toneACsetDelay(effectDelays[delayTime]);
}

void setIntensity(int intensity) {
  toneACsetVolume(effectIntensities[intensity]);
}

void playTheme(int theme) {
  switch (theme) {
    case 1: // Ghostbusters (1984)
      const int gbTheme[] = {392, 392, 392, 311, 466, 392, 311, 466, 392, 784, 659, 523, 466, 392, 784, 659, 523, 466, 392, 392, 523, 587, 659, 523, 587};
      for (int i = 0; i < 25; i++) {
        toneAC(gbTheme[i], 50);
        delay(300);
        noToneAC();
        delay(50);
      }
      break;

    case 2: // Ghostbusters (2016)
      const int gb2016Theme[] = {330, 330, 247, 262, 220, 196, 220, 262, 330, 262, 330, 392, 349, 294, 330, 330, 247, 262, 220, 196, 220, 262, 294, 294, 262, 330, 330, 247, 262, 220, 196, 220, 262, 294, 294, 262};
      for (int i = 0; i < 36; i++) {
        toneAC(gb2016Theme[i], 50);
        delay(200);
        noToneAC();
        delay(50);
      }
      break;

    case 3: // Ghostbusters: Afterlife
      const int gbAfterlifeTheme[] = {330, 330, 330, 294, 349, 294, 262, 220, 294, 349, 330, 294, 294, 262, 294, 330, 294, 262, 220};
      for (int i = 0; i < 19; i++) {
        toneAC(gbAfterlifeTheme[i], 50);
        delay(200);
        noToneAC();
        delay(50);
      }
      break;

    case 4: // Slow creepy music
      const int creepyTheme[] = {165, 175, 185, 195, 205, 215, 225, 235, 245, 255, 265, 275, 285, 295, 305, 315, 325, 335, 345, 355, 365, 375, 385, 395, 405};
      for (int i = 0; i < 25; i++) {
        toneAC(creepyTheme[i]);
        delay(1000);
        noToneAC();
        delay(100);
      }
      break;

    default:
      break;
  }
}

#endif


