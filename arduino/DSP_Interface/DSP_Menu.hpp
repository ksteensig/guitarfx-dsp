#include <LiquidCrystal_I2C.h>
#include <string.h>             // Do i actually use this?
#include <stdio.h>              // Used for sprintf

#define DEBUG 1

class Menu;

class MenuItem_Echo {
public:
    String label = "Echo        -> ";
    Menu *parent;

    static const uint8_t totalRows = 6;
    uint8_t selector;
    uint8_t topRow;
    int delay_milli_seconds = 0;
    float gain_times = 0;

    char *header = "Echo menu       ";
    char *dashes = "--------------- ";
    char *delayText  = "Delay (ms)   -> ";
    char *delayValue;
    char *gainText  = "Gain (times) -> ";
    char *gainValue;
    char *rows[totalRows];

    //Constructor
    MenuItem_Echo(Menu *parentMenu);

    // Update entire display from this->rows and topRow.
    void UpdateDisplay();

    // Update rigtmost column of the display
    // This includes the * to indicate current line highlighted and ^ + v to display up or down direction
    void UpdatePointers();

    // Roll rows up
    void MoveDown();

    // Roll rows Down
    void MoveUp();

    // Select handler (opens subMenus)
    void Select();

    // Pick  integer value for delay
    void PickInteger();

    // Pick float value for gainText
    void PickFloat();
};


class MenuItem_Flanger {
public:
    // pointer to main menu
    Menu *parent;

    // Accessed by parent
    const String label = "Flanger     -> ";

    // Enables row control
    static const uint8_t totalRows = 12;
    uint8_t selector = 0;
    uint8_t topRow = 0;

    // Items to be sent to DSP
    float direct_gain = 0;
    float feedBack_gain = 0;
    int base_delay_ms = 0;
    int amplitude_delay_ms = 0;
    float frequency = 0;

    // Row Strings const
    char *header = "Flanger menu    ";
    char *dashes = "--------------- ";
    char *directGainText = "Direct Gain  -> ";
    char *feedBackGainText  = "Feedback Gain-> ";
    char *baseDelayText  = "BaseDelay(ms)-> ";
    char *amplitudeText  = "Amplitude(ms)-> ";
    char *frequencyText  = "Frequency(hz)-> ";

    //
    char *directGain_c = (char*)malloc(16);
    char *feedBackGain_c = (char*)malloc(16);
    char *baseDelay_c = (char*)malloc(16);
    char *amplitude_c = (char*)malloc(16);
    char *frequency_c = (char*)malloc(16);

    char *rows[totalRows] = {header, dashes, directGainText, directGain_c, feedBackGainText, feedBackGain_c, baseDelayText, baseDelay_c, amplitudeText, amplitude_c, frequencyText, frequency_c};

    //Constructor
    MenuItem_Flanger(Menu *parentMenu);

    // Update entire display from this->rows and topRow.
    void UpdateDisplay();

    // Update rigtmost column of the display
    // This includes the * to indicate current line highlighted and ^ + v to display up or down direction
    void UpdatePointers();

    // Roll rows up
    void MoveDown();

    // Roll rows Down
    void MoveUp();

    // Select handler (opens subMenus)
    void Select();
};


class Menu {
public:
    uint8_t subMenu = 0;
    static const uint8_t totalRows = 6;
    uint8_t selector = 0;
    uint8_t topRow = 0;
    char *current_rightmost_column = (char*)malloc(5);

    char *header = "Effects Unit UI ";
    char *byline = "SP6 Group 643   ";
    char *dashes = "--------------- ";


    char *echo_label = (char*)malloc(16);
    char *flanger_label = (char*)malloc(16);
    char *chorus_label = (char*)malloc(16);

    char *rows[totalRows] = {header, byline, dashes, echo_label, flanger_label, chorus_label};

    MenuItem_Echo *Echo;
    MenuItem_Flanger *Flanger;
    MenuItem_Flanger *Chorus;

    LiquidCrystal_I2C *lcd;
    // Constructor
    Menu(LiquidCrystal_I2C *lcdisplay);

    // Update entire display from this->rows and topRow.
    void UpdateDisplay();

    // Update rigtmost column of the display
    // This includes the * to indicate current line highlighted and ^ + v to display up or down direction
    void UpdatePointers();

    // Roll rows up
    void MoveDown();

    // Roll rows Down
    void MoveUp();

    // Select handler (opens subMenus)
    void Select();

    // Handler user input based on subMenu and selector
    void Input(uint8_t state);

};
