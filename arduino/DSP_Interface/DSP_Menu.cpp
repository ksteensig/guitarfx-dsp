#include "DSP_Menu.hpp"


// BEGIN IMPLEMENTATION of Menu
Menu::Menu(LiquidCrystal_I2C *lcdisplay) {
  // Save LCD object as part of this object
  this->lcd = lcdisplay;
  this->lcd->begin(16, 4);

  // ECHO
  this->rows[idx_echo_delay] = new char[16];
  sprintf(this->rows[idx_echo_delay], "%i", echo_delay_milliseconds);

  this->rows[idx_echo_gain] = new char[16];
  sprintf(this->rows[idx_echo_gain], "%1.3f", echo_gain_times);

  this->rows[idx_echo_feedback_gain] = new char[16];
  sprintf(this->rows[idx_echo_feedback_gain], "%1.3f", echo_feedback_gain_times);
  // ECHO END

  // FLANGER
  this->rows[idx_flanger_direct_gain] = new char[16];
  sprintf(this->rows[idx_flanger_direct_gain], "%1.3f", flanger_direct_gain);

  this->rows[idx_flanger_feedback_gain] = new char[16];
  sprintf(this->rows[idx_flanger_feedback_gain], "%1.3f", flanger_feedback_gain);

  this->rows[idx_flanger_base_delay] = new char[16];
  sprintf(this->rows[idx_flanger_base_delay], "%i", flanger_base_delay);

  this->rows[idx_flanger_amplitude] = new char[16];
  sprintf(this->rows[idx_flanger_amplitude], "%i", flanger_amplitude);

  this->rows[idx_flanger_frequency] = new char[16];
  sprintf(this->rows[idx_flanger_frequency], "%1.2f", flanger_frequency);
  // FLANGER END

  // CHORUS
  // Voice 0
  this->rows[idx_chorus_direct_gain0] = new char[16];
  sprintf(this->rows[idx_chorus_direct_gain0], "%1.3f", chorus_direct_gain0);

  this->rows[idx_chorus_feedback_gain0] = new char[16];
  sprintf(this->rows[idx_chorus_feedback_gain0], "%1.3f", chorus_feedback_gain0);

  this->rows[idx_chorus_base_delay0] = new char[16];
  sprintf(this->rows[idx_chorus_base_delay0], "%i", chorus_base_delay0);

  this->rows[idx_chorus_amplitude0] = new char[16];
  sprintf(this->rows[idx_chorus_amplitude0], "%i", chorus_amplitude0);

  this->rows[idx_chorus_frequency0] = new char[16];
  sprintf(this->rows[idx_chorus_frequency0], "%1.2f", chorus_frequency0);

  // Voice 1
  this->rows[idx_chorus_direct_gain1] = new char[16];
  sprintf(this->rows[idx_chorus_direct_gain1], "%1.3f", chorus_direct_gain1);

  this->rows[idx_chorus_feedback_gain1] = new char[16];
  sprintf(this->rows[idx_chorus_feedback_gain1], "%1.3f", chorus_feedback_gain1);

  this->rows[idx_chorus_base_delay1] = new char[16];
  sprintf(this->rows[idx_chorus_base_delay1], "%i", chorus_base_delay1);

  this->rows[idx_chorus_amplitude1] = new char[16];
  sprintf(this->rows[idx_chorus_amplitude1], "%i", chorus_amplitude1);

  this->rows[idx_chorus_frequency1] = new char[16];
  sprintf(this->rows[idx_chorus_frequency1], "%1.2f", chorus_frequency1);

  // Voice 2
  this->rows[idx_chorus_direct_gain2] = new char[16];
  sprintf(this->rows[idx_chorus_direct_gain2], "%1.3f", chorus_direct_gain2);

  this->rows[idx_chorus_feedback_gain2] = new char[16];
  sprintf(this->rows[idx_chorus_feedback_gain2], "%1.3f", chorus_feedback_gain2);

  this->rows[idx_chorus_base_delay2] = new char[16];
  sprintf(this->rows[idx_chorus_base_delay2], "%i", chorus_base_delay2);

  this->rows[idx_chorus_amplitude2] = new char[16];
  sprintf(this->rows[idx_chorus_amplitude2], "%i", chorus_amplitude2);

  this->rows[idx_chorus_frequency2] = new char[16];
  sprintf(this->rows[idx_chorus_frequency2], "%1.2f", chorus_frequency2);

  // Voice 3
  this->rows[idx_chorus_direct_gain3] = new char[16];
  sprintf(this->rows[idx_chorus_direct_gain3], "%1.3f", chorus_direct_gain3);

  this->rows[idx_chorus_feedback_gain3] = new char[16];
  sprintf(this->rows[idx_chorus_feedback_gain3], "%1.3f", chorus_feedback_gain3);

  this->rows[idx_chorus_base_delay3] = new char[16];
  sprintf(this->rows[idx_chorus_base_delay3], "%i", chorus_base_delay3);

  this->rows[idx_chorus_amplitude3] = new char[16];
  sprintf(this->rows[idx_chorus_amplitude3], "%i", chorus_amplitude3);

  this->rows[idx_chorus_frequency3] = new char[16];
  sprintf(this->rows[idx_chorus_frequency3], "%1.2f", chorus_frequency3);

  // Voice 4
  this->rows[idx_chorus_direct_gain4] = new char[16];
  sprintf(this->rows[idx_chorus_direct_gain4], "%1.3f", chorus_direct_gain4);

  this->rows[idx_chorus_feedback_gain4] = new char[16];
  sprintf(this->rows[idx_chorus_feedback_gain4], "%1.3f", chorus_feedback_gain4);

  this->rows[idx_chorus_base_delay4] = new char[16];
  sprintf(this->rows[idx_chorus_base_delay4], "%i", chorus_base_delay4);

  this->rows[idx_chorus_amplitude4] = new char[16];
  sprintf(this->rows[idx_chorus_amplitude4], "%i", chorus_amplitude4);

  this->rows[idx_chorus_frequency4] = new char[16];
  sprintf(this->rows[idx_chorus_frequency4], "%1.2f", chorus_frequency4);


  // Startscreen
  UpdateDisplay();

}

// Update entire display as main menu.
void Menu::UpdateDisplay() {
  Serial.print("UpdateDisplay\n\ttopRow:");
  Serial.println(topRow);
  lcd->clear();

  for (int i = 0; i < 4; i++) {
    lcd->setCursor(0, i);
    lcd->write(this->rows[i + topRow]);
  }
  // Serial.println(Echo->delayValue);
  UpdatePointers();
}

// Update rigtmost column of the display
// This includes the * to indicate current line highlighted and ^ + v to display up or down direction
void Menu::UpdatePointers() {
  // Reset column
  current_rightmost_column[0] = '^';
  current_rightmost_column[1] = '|';
  current_rightmost_column[2] = '|';
  current_rightmost_column[3] = 'v';

  // Place selector
  current_rightmost_column[selector] = '<';

  for (int row = 0; row < 4; row++) {
    lcd->setCursor(15, row);
    lcd->write(current_rightmost_column[row]);
  }
}

void Menu::MoveDown() {
  switch (selector) {
    case 0:
    case 1:
      selector++;
      break;
    case 2:
      if (topRow < (totalRows - 4)) {
        topRow++;
      } else {
        selector = 3;
      }
      break;
    case 3:
      break;
  }
  UpdateDisplay();
}

void Menu::MoveUp() {
  switch (selector) {
    case 0:
      break;
    case 1:
      if (topRow != 0) {
        topRow--;
      } else {
        selector--;
      }
      break;
    case 2:
    case 3:
      selector--;
      break;
  }
}

void Menu::Select() {
  Serial.print("Selected: ");
  // Update newest selected road
  selected_row = selector + topRow;
  Serial.print(selected);

  if (!selected) {                        // If nothing is selected
    switch (selected_row) {
      case idx_echo_text_header:      // 3 - Flip echo_enable and update display - WORKS!
        if (echo_enable) {
          this->rows[idx_echo_text_header] = "Echo     OFF -> ";
        } else {
          this->rows[idx_echo_text_header] = "Echo      ON -> ";
        }
        echo_enable = !echo_enable;
        break;
      case idx_flanger_text_header:   // 9 - Flip flanger and update display - WORKS!
        if (flanger_enable) {
          this->rows[idx_flanger_text_header] = "Flanger  OFF -> ";
        } else {
          this->rows[idx_flanger_text_header] = "Flanger   ON -> ";
        }
        flanger_enable = !flanger_enable;
        break;
      case idx_chorus_text_header:
        if (chorus_enable) {
          this->rows[idx_chorus_text_header] = "CHORUS   OFF -> ";
        } else {
          this->rows[idx_chorus_text_header] = "CHORUS    ON -> ";
        }
        chorus_enable = !chorus_enable;
        break;
      case idx_chorus_voice_line0:
        if (voice0_enable) {
          this->rows[idx_chorus_voice_line0] = "Voice 0  OFF -> ";
        } else {
          this->rows[idx_chorus_voice_line0] = "Voice 0   ON -> ";
        }
        voice0_enable = !voice0_enable;
        break;
      case idx_chorus_voice_line1:
        if (voice1_enable) {
          this->rows[idx_chorus_voice_line1] = "Voice 1  OFF -> ";
        } else {
          this->rows[idx_chorus_voice_line1] = "Voice 1   ON -> ";
        }
        voice1_enable = !voice1_enable;
        break;
      case idx_chorus_voice_line2:
        if (voice2_enable) {
          this->rows[idx_chorus_voice_line2] = "Voice 2  OFF -> ";
        } else {
          this->rows[idx_chorus_voice_line2] = "Voice 2   ON -> ";
        }
        voice2_enable = !voice2_enable;
        break;
      case idx_chorus_voice_line3:
        if (voice3_enable) {
          this->rows[idx_chorus_voice_line3] = "Voice 3  OFF -> ";
        } else {
          this->rows[idx_chorus_voice_line3] = "Voice 3   ON -> ";
        }
        voice3_enable = !voice3_enable;
        break;
      case idx_chorus_voice_line4:
        if (voice4_enable) {
          this->rows[idx_chorus_voice_line4] = "Voice 4  OFF -> ";
        } else {
          this->rows[idx_chorus_voice_line4] = "Voice 4   ON -> ";
        }
        voice4_enable = !voice4_enable;
        break;
      case (idx_echo_delay-1):
      case (idx_echo_gain-1):
      case (idx_echo_feedback_gain-1):

      case (idx_flanger_direct_gain-1):
      case (idx_flanger_feedback_gain-1):
      case (idx_flanger_base_delay-1):
      case (idx_flanger_amplitude-1):
      case (idx_flanger_frequency-1):

      case (idx_chorus_direct_gain0-1):
      case (idx_chorus_feedback_gain0-1):
      case (idx_chorus_base_delay0-1):
      case (idx_chorus_amplitude0-1):
      case (idx_chorus_frequency0-1):

      case (idx_chorus_direct_gain1-1):
      case (idx_chorus_feedback_gain1-1):
      case (idx_chorus_base_delay1-1):
      case (idx_chorus_amplitude1-1):
      case (idx_chorus_frequency1-1):

      case (idx_chorus_direct_gain2-1):
      case (idx_chorus_feedback_gain2-1):
      case (idx_chorus_base_delay2-1):
      case (idx_chorus_amplitude2-1):
      case (idx_chorus_frequency2-1):

      case (idx_chorus_direct_gain3-1):
      case (idx_chorus_feedback_gain3-1):
      case (idx_chorus_base_delay3-1):
      case (idx_chorus_amplitude3-1):
      case (idx_chorus_frequency3-1):

      case (idx_chorus_direct_gain4-1):
      case (idx_chorus_feedback_gain4-1):
      case (idx_chorus_base_delay4-1):
      case (idx_chorus_amplitude4-1):
      case (idx_chorus_frequency4-1):
        selected = true;
        break;
    }
  } else {
    selected = false;
  }
}

void Menu::Input(uint8_t state) {
  switch (state) {
    case 0: // Back
      // I mean... We could hide an easter egg right here??? @TODO
      break;
    case 1: // Up
      if (!selected) {
        MoveUp();
      } else {
        IncrementSelected();
      }
      break;
    case 2: // Down
      if (!selected) {
        MoveDown();
      } else {
        DecrementSelected();
      }
      break;
    case 3: // Select
      Select();
      break;
  }
  UpdateDisplay();
}

void Menu::IncrementSelected() {
  switch (selected_row) {
    case (idx_echo_delay-1):            // 4
      echo_delay_milliseconds += delta_echo_delay_milliseconds;
      sprintf(this->rows[idx_echo_delay], "%i", echo_delay_milliseconds);
      break;
    case (idx_echo_gain-1):             // 6
      echo_gain_times += delta_echo_gain_times;
      sprintf(this->rows[idx_echo_gain], "%1.3f", echo_gain_times);
      break;
    case (idx_echo_feedback_gain-1):
      echo_feedback_gain_times += delta_echo_feedback_gain_times;
      sprintf(this->rows[idx_echo_feedback_gain], "%1.3f", echo_feedback_gain_times);
      break;
    case (idx_flanger_direct_gain-1):   // 10
      flanger_direct_gain += delta_flanger_direct_gain;
      sprintf(rows[idx_flanger_direct_gain], "%1.3f", flanger_direct_gain);
      break;
    case (idx_flanger_feedback_gain-1): // 12
      flanger_feedback_gain += delta_flanger_feedback_gain;
      sprintf(rows[idx_flanger_feedback_gain], "%1.3f", flanger_feedback_gain);
      break;
    case (idx_flanger_base_delay-1):    // 14
      flanger_base_delay += delta_flanger_base_delay;
      sprintf(rows[idx_flanger_base_delay], "%i", flanger_base_delay);
      break;
    case (idx_flanger_amplitude-1):     // 16
      flanger_amplitude += delta_flanger_amplitude;
      sprintf(rows[idx_flanger_amplitude], "%i", flanger_amplitude);
      break;
    case (idx_flanger_frequency-1):     // 18
      flanger_frequency += delta_flanger_frequency;
      sprintf(rows[idx_flanger_frequency], "%1.3f", flanger_frequency);
      break;
    case (idx_chorus_direct_gain0-1):
      chorus_direct_gain0 += delta_chorus_direct_gain0;
      sprintf(rows[idx_chorus_direct_gain0], "%1.3f", chorus_direct_gain0);
      break;
    case (idx_chorus_feedback_gain0-1):
      chorus_feedback_gain0 += delta_chorus_feedback_gain0;
      sprintf(rows[idx_chorus_feedback_gain0], "%1.3f", chorus_feedback_gain0);
      break;
    case (idx_chorus_base_delay0-1):
      chorus_base_delay0 += delta_chorus_base_delay0;
      sprintf(rows[idx_chorus_base_delay0], "%i", chorus_base_delay0);
      break;
    case (idx_chorus_amplitude0-1):
      chorus_amplitude0 += delta_chorus_amplitude0;
      sprintf(rows[idx_chorus_amplitude0], "%i", chorus_amplitude0);
      break;
    case (idx_chorus_frequency0-1):
      chorus_frequency0 += delta_chorus_frequency0;
      sprintf(rows[idx_chorus_frequency0], "%1.3f", chorus_frequency0);
      break;
    case (idx_chorus_direct_gain1-1):
      chorus_direct_gain1 += delta_chorus_direct_gain1;
      sprintf(rows[idx_chorus_direct_gain1], "%1.3f", chorus_direct_gain1);
      break;
    case (idx_chorus_feedback_gain1-1):
      chorus_feedback_gain1 += delta_chorus_feedback_gain1;
      sprintf(rows[idx_chorus_feedback_gain1], "%1.3f", chorus_feedback_gain1);
      break;
    case (idx_chorus_base_delay1-1):
      chorus_base_delay1 += delta_chorus_base_delay1;
      sprintf(rows[idx_chorus_base_delay1], "%i", chorus_base_delay1);
      break;
    case (idx_chorus_amplitude1-1):
      chorus_amplitude1 += delta_chorus_amplitude1;
      sprintf(rows[idx_chorus_amplitude1], "%i", chorus_amplitude1);
      break;
    case (idx_chorus_frequency1-1):
      chorus_frequency1 += delta_chorus_frequency1;
      sprintf(rows[idx_chorus_frequency1], "%1.3f", chorus_frequency1);
      break;
    case (idx_chorus_direct_gain2-1):
      chorus_direct_gain2 += delta_chorus_direct_gain2;
      sprintf(rows[idx_chorus_direct_gain2], "%1.3f", chorus_direct_gain2);
      break;
    case (idx_chorus_feedback_gain2-1):
      chorus_feedback_gain2 += delta_chorus_feedback_gain2;
      sprintf(rows[idx_chorus_feedback_gain2], "%1.3f", chorus_feedback_gain2);
      break;
    case (idx_chorus_base_delay2-1):
      chorus_base_delay2 += delta_chorus_base_delay2;
      sprintf(rows[idx_chorus_base_delay2], "%i", chorus_base_delay2);
      break;
    case (idx_chorus_amplitude2-1):
      chorus_amplitude2 += delta_chorus_amplitude2;
      sprintf(rows[idx_chorus_amplitude2], "%i", chorus_amplitude2);
      break;
    case (idx_chorus_frequency2-1):
      chorus_frequency2 += delta_chorus_frequency2;
      sprintf(rows[idx_chorus_frequency2], "%1.3f", chorus_frequency2);
      break;
    case (idx_chorus_direct_gain3-1):
      chorus_direct_gain3 += delta_chorus_direct_gain3;
      sprintf(rows[idx_chorus_direct_gain3], "%1.3f", chorus_direct_gain3);
      break;
    case (idx_chorus_feedback_gain3-1):
      chorus_feedback_gain3 += delta_chorus_feedback_gain3;
      sprintf(rows[idx_chorus_feedback_gain3], "%1.3f", chorus_feedback_gain3);
      break;
    case (idx_chorus_base_delay3-1):
      chorus_base_delay3 += delta_chorus_base_delay3;
      sprintf(rows[idx_chorus_base_delay3], "%i", chorus_base_delay3);
      break;
    case (idx_chorus_amplitude3-1):
      chorus_amplitude3 += delta_chorus_amplitude3;
      sprintf(rows[idx_chorus_amplitude3], "%i", chorus_amplitude3);
      break;
    case (idx_chorus_frequency3-1):
      chorus_frequency3 += delta_chorus_frequency3;
      sprintf(rows[idx_chorus_frequency3], "%1.3f", chorus_frequency3);
      break;
    case (idx_chorus_direct_gain4-1):
      chorus_direct_gain4 += delta_chorus_direct_gain4;
      sprintf(rows[idx_chorus_direct_gain4], "%1.3f", chorus_direct_gain4);
      break;
    case (idx_chorus_feedback_gain4-1):
      chorus_feedback_gain4 += delta_chorus_feedback_gain4;
      sprintf(rows[idx_chorus_feedback_gain4], "%1.3f", chorus_feedback_gain4);
      break;
    case (idx_chorus_base_delay4-1):
      chorus_base_delay4 += delta_chorus_base_delay4;
      sprintf(rows[idx_chorus_base_delay4], "%i", chorus_base_delay4);
      break;
    case (idx_chorus_amplitude4-1):
      chorus_amplitude4 += delta_chorus_amplitude4;
      sprintf(rows[idx_chorus_amplitude4], "%i", chorus_amplitude4);
      break;
    case (idx_chorus_frequency4-1):
      chorus_frequency4 += delta_chorus_frequency4;
      sprintf(rows[idx_chorus_frequency4], "%1.3f", chorus_frequency4);
      break;
  }
}

void Menu::DecrementSelected() {
  switch (selected_row) {
    case (idx_echo_delay-1):            // 4
      echo_delay_milliseconds -= delta_echo_delay_milliseconds;
      sprintf(this->rows[idx_echo_delay], "%i", echo_delay_milliseconds);
      break;
    case (idx_echo_gain-1):             // 6
      echo_gain_times -= delta_echo_gain_times;
      sprintf(this->rows[idx_echo_gain], "%1.3f", echo_gain_times);
      break;
    case (idx_echo_feedback_gain-1):
      echo_feedback_gain_times -= delta_echo_feedback_gain_times;
      sprintf(this->rows[idx_echo_feedback_gain], "%1.3f", echo_feedback_gain_times);
      break;
    case (idx_flanger_direct_gain-1):   // 10
      flanger_direct_gain -= delta_flanger_direct_gain;
      sprintf(rows[idx_flanger_direct_gain], "%1.3f", flanger_direct_gain);
      break;
    case (idx_flanger_feedback_gain-1): // 12
      flanger_feedback_gain -= delta_flanger_feedback_gain;
      sprintf(rows[idx_flanger_feedback_gain], "%1.3f", flanger_feedback_gain);
      break;
    case (idx_flanger_base_delay-1):    // 14
      flanger_base_delay -= delta_flanger_base_delay;
      sprintf(rows[idx_flanger_base_delay], "%i", flanger_base_delay);
      break;
    case (idx_flanger_amplitude-1):     // 16
      flanger_amplitude -= delta_flanger_amplitude;
      sprintf(rows[idx_flanger_amplitude], "%i", flanger_amplitude);
      break;
    case (idx_flanger_frequency-1):     // 18
      flanger_frequency -= delta_flanger_frequency;
      sprintf(rows[idx_flanger_frequency], "%1.3f", flanger_frequency);
      break;
    case (idx_chorus_direct_gain0-1):
      chorus_direct_gain0 -= delta_chorus_direct_gain0;
      sprintf(rows[idx_chorus_direct_gain0], "%1.3f", chorus_direct_gain0);
      break;
    case (idx_chorus_feedback_gain0-1):
      chorus_feedback_gain0 -= delta_chorus_feedback_gain0;
      sprintf(rows[idx_chorus_feedback_gain0], "%1.3f", chorus_feedback_gain0);
      break;
    case (idx_chorus_base_delay0-1):
      chorus_base_delay0 -= delta_chorus_base_delay0;
      sprintf(rows[idx_chorus_base_delay0], "%i", chorus_base_delay0);
      break;
    case (idx_chorus_amplitude0-1):
      chorus_amplitude0 -= delta_chorus_amplitude0;
      sprintf(rows[idx_chorus_amplitude0], "%i", chorus_amplitude0);
      break;
    case (idx_chorus_frequency0-1):
      chorus_frequency0 -= delta_chorus_frequency0;
      sprintf(rows[idx_chorus_frequency0], "%1.3f", chorus_frequency0);
      break;
    case (idx_chorus_direct_gain1-1):
      chorus_direct_gain1 -= delta_chorus_direct_gain1;
      sprintf(rows[idx_chorus_direct_gain1], "%1.3f", chorus_direct_gain1);
      break;
    case (idx_chorus_feedback_gain1-1):
      chorus_feedback_gain1 -= delta_chorus_feedback_gain1;
      sprintf(rows[idx_chorus_feedback_gain1], "%1.3f", chorus_feedback_gain1);
      break;
    case (idx_chorus_base_delay1-1):
      chorus_base_delay1 -= delta_chorus_base_delay1;
      sprintf(rows[idx_chorus_base_delay1], "%i", chorus_base_delay1);
      break;
    case (idx_chorus_amplitude1-1):
      chorus_amplitude1 -= delta_chorus_amplitude1;
      sprintf(rows[idx_chorus_amplitude1], "%i", chorus_amplitude1);
      break;
    case (idx_chorus_frequency1-1):
      chorus_frequency1 -= delta_chorus_frequency1;
      sprintf(rows[idx_chorus_frequency1], "%1.3f", chorus_frequency1);
      break;
    case (idx_chorus_direct_gain2-1):
      chorus_direct_gain2 -= delta_chorus_direct_gain2;
      sprintf(rows[idx_chorus_direct_gain2], "%1.3f", chorus_direct_gain2);
      break;
    case (idx_chorus_feedback_gain2-1):
      chorus_feedback_gain2 -= delta_chorus_feedback_gain2;
      sprintf(rows[idx_chorus_feedback_gain2], "%1.3f", chorus_feedback_gain2);
      break;
    case (idx_chorus_base_delay2-1):
      chorus_base_delay2 -= delta_chorus_base_delay2;
      sprintf(rows[idx_chorus_base_delay2], "%i", chorus_base_delay2);
      break;
    case (idx_chorus_amplitude2-1):
      chorus_amplitude2 -= delta_chorus_amplitude2;
      sprintf(rows[idx_chorus_amplitude2], "%i", chorus_amplitude2);
      break;
    case (idx_chorus_frequency2-1):
      chorus_frequency2 -= delta_chorus_frequency2;
      sprintf(rows[idx_chorus_frequency2], "%1.3f", chorus_frequency2);
      break;
    case (idx_chorus_direct_gain3-1):
      chorus_direct_gain3 -= delta_chorus_direct_gain3;
      sprintf(rows[idx_chorus_direct_gain3], "%1.3f", chorus_direct_gain3);
      break;
    case (idx_chorus_feedback_gain3-1):
      chorus_feedback_gain3 -= delta_chorus_feedback_gain3;
      sprintf(rows[idx_chorus_feedback_gain3], "%1.3f", chorus_feedback_gain3);
      break;
    case (idx_chorus_base_delay3-1):
      chorus_base_delay3 -= delta_chorus_base_delay3;
      sprintf(rows[idx_chorus_base_delay3], "%i", chorus_base_delay3);
      break;
    case (idx_chorus_amplitude3-1):
      chorus_amplitude3 -= delta_chorus_amplitude3;
      sprintf(rows[idx_chorus_amplitude3], "%i", chorus_amplitude3);
      break;
    case (idx_chorus_frequency3-1):
      chorus_frequency3 -= delta_chorus_frequency3;
      sprintf(rows[idx_chorus_frequency3], "%1.3f", chorus_frequency3);
      break;
    case (idx_chorus_direct_gain4-1):
      chorus_direct_gain4 -= delta_chorus_direct_gain4;
      sprintf(rows[idx_chorus_direct_gain4], "%1.3f", chorus_direct_gain4);
      break;
    case (idx_chorus_feedback_gain4-1):
      chorus_feedback_gain4 -= delta_chorus_feedback_gain4;
      sprintf(rows[idx_chorus_feedback_gain4], "%1.3f", chorus_feedback_gain4);
      break;
    case (idx_chorus_base_delay4-1):
      chorus_base_delay4 -= delta_chorus_base_delay4;
      sprintf(rows[idx_chorus_base_delay4], "%i", chorus_base_delay4);
      break;
    case (idx_chorus_amplitude4-1):
      chorus_amplitude4 -= delta_chorus_amplitude4;
      sprintf(rows[idx_chorus_amplitude4], "%i", chorus_amplitude4);
      break;
    case (idx_chorus_frequency4-1):
      chorus_frequency4 -= delta_chorus_frequency4;
      sprintf(rows[idx_chorus_frequency4], "%1.3f", chorus_frequency4);
      break;
  }
}
// END IMPLEMENTATION of Menu
