#include "DSP_Menu.hpp"

// BEGIN IMPLEMENTATION MenuItem_Echo
// Constructor
MenuItem_Echo::MenuItem_Echo(Menu *parentMenu){
    this->parent = parentMenu;
    delayValue = new char[16];
    sprintf(delayValue, "%d ", 48);

}

// Update entire display from this->rows and topRow.
void MenuItem_Echo::UpdateDisplay() {
    /*
    parent->lcd->clear();

    for(int i = 0; i < 4; i++){
        parent->lcd->setCursor(0, i);
        parent->lcd->write(this->rows[i+topRow]);
        Serial.println(rows[i+topRow]);
    }

    UpdatePointers();*/
}

// Update rigtmost column of the display
void MenuItem_Echo::UpdatePointers(){
    // Reset column
    parent->current_rightmost_column[0] = '^';
    parent->current_rightmost_column[1] = '|';
    parent->current_rightmost_column[2] = '|';
    parent->current_rightmost_column[3] = 'v';

    // Place selector
    parent->current_rightmost_column[selector] = '<';

    for (int row = 0; row < 4; row++){
        parent->lcd->setCursor(15, row);
        parent->lcd->write(parent->current_rightmost_column[row]);
    }
}

// Handle selector and topRow, then UpdateDisplay
void MenuItem_Echo::MoveDown(){
    switch (selector) {
        case 0:
            selector++;
            break;
        case 1:
            selector++;
            break;
        case 2:
            if (topRow < (totalRows-4)){
                topRow++;
            }else{
                selector = 3;
            }
            break;
        case 3:
            break;
    }
    UpdateDisplay();
}

// Handle selector and topRow, then UpdateDisplay
void MenuItem_Echo::MoveUp(){
    switch (selector) {
        case 0:
            break;
        case 1:
            if (topRow != 0) {
                topRow--;
            }else{
                selector--;
            }
            break;
        case 2:
        case 3:
            selector--;
            break;
    }
    UpdateDisplay();
}


void MenuItem_Echo::Select(){

}


void MenuItem_Echo::PickInteger(){

}


void MenuItem_Echo::PickFloat(){

}

// END IMPLEMENTATION of MenuItem_Echo

// BEGIN IMPLEMENTATION of MenuItem_Flanger
// Constructor
MenuItem_Flanger::MenuItem_Flanger(Menu *parentMenu){
    this->parent = parentMenu;
}

// Update entire display from this->rows and topRow.
void MenuItem_Flanger::UpdateDisplay(){
    /*
    parent->lcd->clear();

    for(int i = 0; i < 4; i++){
        parent->lcd->setCursor(0, i);
        parent->lcd->write(this->rows[i+topRow]);
    }

    UpdatePointers();
*/}

// Update rigtmost column of the display
// This includes the * to indicate current line highlighted and ^ + v to display up or down direction
void MenuItem_Flanger::UpdatePointers(){
    // Reset column
    parent->current_rightmost_column[0] = '^';
    parent->current_rightmost_column[1] = '|';
    parent->current_rightmost_column[2] = '|';
    parent->current_rightmost_column[3] = 'v';

    // Place selector
    parent->current_rightmost_column[selector] = '<';

    for (int row = 0; row < 4; row++){
        parent->lcd->setCursor(15, row);
        parent->lcd->write(parent->current_rightmost_column[row]);
    }
}

// Roll rows up
void MenuItem_Flanger::MoveDown(){
    switch (selector) {
        case 0:
            selector++;
            break;
        case 1:
            selector++;
            break;
        case 2:
            if (topRow < (totalRows-4)){
                topRow++;
            }else{
                selector = 3;
            }
            break;
        case 3:
            break;
    }
    UpdateDisplay();
}

// Roll rows Down
void MenuItem_Flanger::MoveUp(){
    switch (selector) {
        case 0:
            break;
        case 1:
            if (topRow != 0) {
                topRow--;
            }else{
                selector--;
            }
            break;
        case 2:
        case 3:
            selector--;
            break;
    }
    UpdateDisplay();
}

// Select handler (opens subMenus)
void MenuItem_Flanger::Select(){

}

// END IMPLEMENTATION of MenuItem_Flanger



// BEGIN IMPLEMENTATION of MenuItem_Chorus

// END IMPLEMENTATION of MenuItem_Chorus



// BEGIN IMPLEMENTATION of Menu
Menu::Menu(LiquidCrystal_I2C *lcdisplay){
    // Initialize MenuItems
    this->Echo = new MenuItem_Echo(this);
    this->Flanger = new MenuItem_Flanger(this);
    this->Chorus = new MenuItem_Flanger(this);

    // Get labels from MenuItems
    Echo->label.toCharArray(this->echo_label, 16);
    Flanger->label.toCharArray(this->flanger_label, 16);
    Chorus->label.toCharArray(this->chorus_label, 16);

    // Save LCD object as part of this object
    this->lcd = lcdisplay;
    this->lcd->begin(16, 4);

    // Startscreen
    UpdateDisplay();

}

// Update entire display as main menu.
void Menu::UpdateDisplay(){
    Serial.print("topRow:");
    Serial.println(topRow);
    Serial.print("header:");
    Serial.println(header);
    lcd->clear();

    for(int i = 0; i < 4; i++){
        lcd->setCursor(0, i);
        lcd->write(rows[i+topRow]);
    }
    // Serial.println(Echo->delayValue);
    UpdatePointers();
}

// Update rigtmost column of the display
// This includes the * to indicate current line highlighted and ^ + v to display up or down direction
void Menu::UpdatePointers(){
    // Reset column
    current_rightmost_column[0] = '^';
    current_rightmost_column[1] = '|';
    current_rightmost_column[2] = '|';
    current_rightmost_column[3] = 'v';

    // Place selector
    current_rightmost_column[selector] = '<';

    for (int row = 0; row < 4; row++){
        lcd->setCursor(15, row);
        lcd->write(current_rightmost_column[row]);
    }
}

void Menu::MoveDown(){
    switch (selector) {
        case 0:
            selector++;
            break;
        case 1:
            selector++;
            break;
        case 2:
            if (topRow < (totalRows-4)){
                topRow++;
            }else{
                selector = 3;
            }
            break;
        case 3:
            break;
    }
    UpdateDisplay();
}

void Menu::MoveUp(){
    switch (selector) {
        case 0:
            break;
        case 1:
            if (topRow != 0) {
                topRow--;
            }else{
                selector--;
            }
            break;
        case 2:
        case 3:
            selector--;
            break;
    }
    UpdateDisplay();
}

void Menu::Select(){
    uint8_t row = selector + topRow;

}

void Menu::Input(uint8_t state){
    Serial.print("submenu:state - ");
    Serial.print(subMenu);
    Serial.print(':');
    Serial.println(state);
    switch(subMenu) {
        case 0:                     // MAIN
            switch (state) {
                case 0: // Back
                    // I mean... We could hide an easter egg right here??? @TODO
                    break;
                case 1: // Up
                    MoveUp();
                    break;
                case 2: // Down
                    MoveDown();
                    break;
                case 3: // Select
                    Select();
                    break;
            }
        case 1:                     // ECHO
            switch (state) {
                case 0: // Back
                    subMenu = 0;
                    UpdateDisplay();
                    break;
                case 1: // Up
                    Echo->MoveUp();
                    break;
                case 2: // Down
                    Echo->MoveDown();
                    break;
                case 3: // Select
                    Echo->Select();
                    break;
            }
        case 2:                     // FLANGER
            switch (state) {
                case 0: // Back
                    subMenu = 0;
                    UpdateDisplay();
                    break;
                case 1: // Up
                    Flanger->MoveUp();
                    break;
                case 2: // Down
                    Flanger->MoveDown();
                    break;
                case 3: // Select
                    Flanger->Select();
                    break;
            }
        case 3:                     // CHORUS
            switch (state) {
                case 0: // Back
                    subMenu = 0;
                    UpdateDisplay();
                    break;
                case 1: // Up
                    Chorus->MoveUp();
                    break;
                case 2: // Down
                    Chorus->MoveDown();
                    break;
                case 3: // Select
                    Chorus->Select();
                    break;
            }
    }
}
// END IMPLEMENTATION of Menu
