#include <LiquidCrystal_I2C.h>
#include <string.h>             // Do i actually use this?
#include <stdio.h>              // Used for sprintf

#define DEBUG 1
#define DELTA_GAIN 0.01
#define DELTA_DELAY 1

class Menu {
  public:
    static const uint8_t totalRows = 83;
    uint8_t selector = 0;
    uint8_t topRow = 0;
    bool selected = false;
    uint8_t selected_row = 0;
    char *current_rightmost_column = (char*)malloc(5);

    char *header = "Effects Unit UI ";
    char *byline = "SP6 Group 643   ";
    char *dashes = "--------------- ";

    // ECHO
    bool echo_enable = false;
    char *echo_text_header = "Echo     OFF -> ";
    static const int idx_echo_text_header = 3;
    // Delay variables
    char *echo_text_delay = "Delay (ms)   -> ";
    static const int idx_echo_delay = 5;
    int echo_delay_milliseconds = 600;                                          // Adjustable
    const int delta_echo_delay_milliseconds = 1;                                // Adjustable
    // Forward Gain variables
    char *echo_text_gain = "Direct gain  -> ";
    static const int idx_echo_gain = 7;
    float echo_gain_times = 1.000;                                              // Adjustable
    float delta_echo_gain_times = 0.01;                                         // Adjustable
    // Feedback Gain variables
    char *echo_feedback_text_gain = "Feedback gain-> ";
    static const int idx_echo_feedback_gain = 9;
    float echo_feedback_gain_times = 1.000;                                     // Adjustable
    float delta_echo_feedback_gain_times = 0.01;                                // Adjustable
    // ECHO END


    // FLANGER
    bool flanger_enable = false;
    char *flanger_text_header = "Flanger  OFF -> ";
    static const int idx_flanger_text_header = 11;
    // Direct gain variables
    char *flanger_text_direct_gain = "Direct Gain  -> ";
    static const int idx_flanger_direct_gain = 13;
    float flanger_direct_gain = 1.00;                                           // Adjustable
    float delta_flanger_direct_gain = 0.005;                                    // Adjustable
    // Feedback gain variables
    char *flanger_text_feedback_gain = "Feedback Gain-> ";
    static const int idx_flanger_feedback_gain = 15;
    float flanger_feedback_gain = 0.75;                                         // Adjustable
    float delta_flanger_feedback_gain = 0.005;                                  // Adjustable
    // Base Delay variables
    char *flanger_text_base_delay = "BaseDelay(ms)-> ";
    static const int idx_flanger_base_delay = 17;
    int flanger_base_delay = 25;                                                // Adjustable
    int delta_flanger_base_delay = 1;                                     // Adjustable
    // Amplitude variables
    char *flanger_text_amplitude = "Amplitude(ms)-> ";
    static const int idx_flanger_amplitude = 19;
    int flanger_amplitude = 50;                                                 // Adjustable
    int delta_flanger_amplitude = 1;                                            // Adjustable
    // Frequency variables
    char *flanger_text_frequency = "Frequency(hz)-> ";
    static const int idx_flanger_frequency = 21;
    float flanger_frequency = 0.75;                                             // Adjustable
    float delta_flanger_frequency = 0.005;                                      // Adjustable
    // FLANGER END


    // CHORUS
    bool chorus_enable = false;
    char *chorus_text_header = "CHORUS   OFF -> ";
    static const int idx_chorus_text_header = 23;

    //Delay line 0
    char *chorus_voice_line0 = "Voice 0  OFF -> ";
    static const int idx_chorus_voice_line0 = 24;
    bool voice0_enable = false;
    // Direct gain variables
    char *chorus_text_direct_gain0 = "Direct Gain  -> ";
    static const int idx_chorus_direct_gain0 = 26;
    float chorus_direct_gain0 = 1.00;                                           // Adjustable
    float delta_chorus_direct_gain0 = 0.005;                                    // Adjustable
    // Feedback gain variables
    char *chorus_text_feedback_gain0 = "Feedback Gain-> ";
    static const int idx_chorus_feedback_gain0 = 28;
    float chorus_feedback_gain0 = 0.75;                                         // Adjustable
    float delta_chorus_feedback_gain0 = 0.005;                                  // Adjustable
    // Base Delay variables
    char *chorus_text_base_delay0 = "BaseDelay(ms)-> ";
    static const int idx_chorus_base_delay0 = 30;
    int chorus_base_delay0 = 25;                                                // Adjustable
    int delta_chorus_base_delay0 = 1;                                     // Adjustable
    // Amplitude variables
    char *chorus_text_amplitude0 = "Amplitude(ms)-> ";
    static const int idx_chorus_amplitude0 = 32;
    int chorus_amplitude0 = 50;                                                 // Adjustable
    int delta_chorus_amplitude0 = 1;                                            // Adjustable
    // Frequency variables
    char *chorus_text_frequency0 = "Frequency(hz)-> ";
    static const int idx_chorus_frequency0 = 34;
    float chorus_frequency0 = 0.75;                                             // Adjustable
    float delta_chorus_frequency0 = 0.005;                                      // Adjustable

    //Delay line 1
    char *chorus_voice_line1 = "Voice 1  OFF -> ";
    static const int idx_chorus_voice_line1 = 36;
    bool voice1_enable = false;
    // Direct gain variables
    char *chorus_text_direct_gain1 = "Direct Gain  -> ";
    static const int idx_chorus_direct_gain1 = 38;
    float chorus_direct_gain1 = 1.00;                                           // Adjustable
    float delta_chorus_direct_gain1 = 0.005;                                    // Adjustable
    // Feedback gain variables
    char *chorus_text_feedback_gain1 = "Feedback Gain-> ";
    static const int idx_chorus_feedback_gain1 = 40;
    float chorus_feedback_gain1 = 0.75;                                         // Adjustable
    float delta_chorus_feedback_gain1 = 0.005;                                  // Adjustable
    // Base Delay variables
    char *chorus_text_base_delay1 = "BaseDelay(ms)-> ";
    static const int idx_chorus_base_delay1 = 42;
    int chorus_base_delay1 = 25;                                                // Adjustable
    int delta_chorus_base_delay1 = 1;                                     // Adjustable
    // Amplitude variables
    char *chorus_text_amplitude1 = "Amplitude(ms)-> ";
    static const int idx_chorus_amplitude1 = 44;
    int chorus_amplitude1 = 50;                                                 // Adjustable
    int delta_chorus_amplitude1 = 1;                                            // Adjustable
    // Frequency variables
    char *chorus_text_frequency1 = "Frequency(hz)-> ";
    static const int idx_chorus_frequency1 = 46;
    float chorus_frequency1 = 0.75;                                             // Adjustable
    float delta_chorus_frequency1 = 0.005;                                      // Adjustable

    //Delay line 2
    char *chorus_voice_line2 = "Voice 2  OFF -> ";
    static const int idx_chorus_voice_line2 = 48;
    bool voice2_enable = false;
    // Direct gain variables
    char *chorus_text_direct_gain2 = "Direct Gain  -> ";
    static const int idx_chorus_direct_gain2 = 50;
    float chorus_direct_gain2 = 1.00;                                           // Adjustable
    float delta_chorus_direct_gain2 = 0.005;                                    // Adjustable
    // Feedback gain variables
    char *chorus_text_feedback_gain2 = "Feedback Gain-> ";
    static const int idx_chorus_feedback_gain2 = 52;
    float chorus_feedback_gain2 = 0.75;                                         // Adjustable
    float delta_chorus_feedback_gain2 = 0.005;                                  // Adjustable
    // Base Delay variables
    char *chorus_text_base_delay2 = "BaseDelay(ms)-> ";
    static const int idx_chorus_base_delay2 = 54;
    int chorus_base_delay2 = 25;                                                // Adjustable
    int delta_chorus_base_delay2 = 1;                                     // Adjustable
    // Amplitude variables
    char *chorus_text_amplitude2 = "Amplitude(ms)-> ";
    static const int idx_chorus_amplitude2 = 56;
    int chorus_amplitude2 = 50;                                                 // Adjustable
    int delta_chorus_amplitude2 = 1;                                            // Adjustable
    // Frequency variables
    char *chorus_text_frequency2 = "Frequency(hz)-> ";
    static const int idx_chorus_frequency2 = 58;
    float chorus_frequency2 = 0.75;                                             // Adjustable
    float delta_chorus_frequency2 = 0.005;                                      // Adjustable

    //Delay line 3
    char *chorus_voice_line3 = "Voice 3  OFF -> ";
    static const int idx_chorus_voice_line3 = 60;
    bool voice3_enable = false;
    // Direct gain variables
    char *chorus_text_direct_gain3 = "Direct Gain  -> ";
    static const int idx_chorus_direct_gain3 = 62;
    float chorus_direct_gain3 = 1.00;                                           // Adjustable
    float delta_chorus_direct_gain3 = 0.005;                                    // Adjustable
    // Feedback gain variables
    char *chorus_text_feedback_gain3 = "Feedback Gain-> ";
    static const int idx_chorus_feedback_gain3 = 64;
    float chorus_feedback_gain3 = 0.75;                                         // Adjustable
    float delta_chorus_feedback_gain3 = 0.005;                                  // Adjustable
    // Base Delay variables
    char *chorus_text_base_delay3 = "BaseDelay(ms)-> ";
    static const int idx_chorus_base_delay3 = 66;
    int chorus_base_delay3 = 35;                                                // Adjustable
    int delta_chorus_base_delay3 = 1;                                     // Adjustable
    // Amplitude variables
    char *chorus_text_amplitude3 = "Amplitude(ms)-> ";
    static const int idx_chorus_amplitude3 = 68;
    int chorus_amplitude3 = 50;                                                 // Adjustable
    int delta_chorus_amplitude3 = 1;                                            // Adjustable
    // Frequency variables
    char *chorus_text_frequency3 = "Frequency(hz)-> ";
    static const int idx_chorus_frequency3 = 70;
    float chorus_frequency3 = 0.75;                                             // Adjustable
    float delta_chorus_frequency3 = 0.005;                                      // Adjustable

    //Delay line 4
    char *chorus_voice_line4 = "Voice 4  OFF -> ";
    static const int idx_chorus_voice_line4 = 72;
    bool voice4_enable = false;
    // Direct gain variables
    char *chorus_text_direct_gain4 = "Direct Gain  -> ";
    static const int idx_chorus_direct_gain4 = 74;
    float chorus_direct_gain4 = 1.00;                                           // Adjustable
    float delta_chorus_direct_gain4 = 0.005;                                    // Adjustable
    // Feedback gain variables
    char *chorus_text_feedback_gain4 = "Feedback Gain-> ";
    static const int idx_chorus_feedback_gain4 = 76;
    float chorus_feedback_gain4 = 0.75;                                         // Adjustable
    float delta_chorus_feedback_gain4 = 0.005;                                  // Adjustable
    // Base Delay variables
    char *chorus_text_base_delay4 = "BaseDelay(ms)-> ";
    static const int idx_chorus_base_delay4 = 78;
    int chorus_base_delay4 = 45;                                                // Adjustable
    int delta_chorus_base_delay4 = 1;                                     // Adjustable
    // Amplitude variables
    char *chorus_text_amplitude4 = "Amplitude(ms)-> ";
    static const int idx_chorus_amplitude4 = 80;
    int chorus_amplitude4 = 50;                                                 // Adjustable
    int delta_chorus_amplitude4 = 1;                                            // Adjustable
    // Frequency variables
    char *chorus_text_frequency4 = "Frequency(hz)-> ";
    static const int idx_chorus_frequency4 = 82;
    float chorus_frequency4 = 0.75;                                             // Adjustable
    float delta_chorus_frequency4 = 0.005;


    char *rows[totalRows] = {                     // No. - Action to be performed
      header,                                     // 0 X Nothing
      byline,                                     // 1 X Nothing
      dashes,                                     // 2 X Nothing
      echo_text_header,                           // 3 - Enable/Disable
      echo_text_delay,                            // 4 - Change delay
      NULL, // echo_delay_milliseconds            // 5 - Nothing
      echo_text_gain,                             // 6 - Change gain
      NULL, // echo_text_gain                     // 7 - Nothing
      echo_feedback_text_gain,                    // 8 - Change feedback gain
      NULL, // echo_feedback_text_gain            // 9 - Nothing
      dashes,                                     //10 - Nothing
      flanger_text_header,                        //11 - Enable/Disable
      flanger_text_direct_gain,                   //12 - Change direct gain
      NULL, // flanger_text_direct_gain_value     //13 - Nothing
      flanger_text_feedback_gain,                 //14 - Change feedback gain
      NULL, // flanger_text_feedback_gain_value   //15 - Nothing
      flanger_text_base_delay,                    //16 - Change base delay
      NULL, // flanger_text_base_delay_value,     //17 - Nothing
      flanger_text_amplitude,                     //18 - Change amplitude
      NULL, // flanger_text_amplitude_value,      //19 - Nothing
      flanger_text_frequency,                     //20 - Change frequency
      NULL, // flanger_text_frequency_value,      //21 - Nothing
      dashes,                                     //22 - Nothing
      chorus_text_header,                         //23 - Enable/Disable
      chorus_voice_line0,                         //24 - Enable/Disable
      chorus_text_direct_gain0,                   //25 - Change gain
      NULL,                                       //26 - Nothing
      chorus_text_feedback_gain0,                 //27 - Change feedback gain
      NULL,                                       //28 - Nothing
      chorus_text_base_delay0,                    //29 - Change base delay  - Nothing
      NULL,                                       //30 - Change amplitude delay
      chorus_text_amplitude0,                     //31 - Nothing
      NULL,                                       //32 - Change modulation frequency
      chorus_text_frequency0,                     //33 - Nothing
      NULL,                                       //34 - Nothing
      dashes,                                     //35 - Nothing
      chorus_voice_line1,                         //36 - Enable/Disable
      chorus_text_direct_gain1,                   //37 - Change gain
      NULL,                                       //38 - Nothing
      chorus_text_feedback_gain1,                 //39 - Change feedback gain
      NULL,                                       //40 - Nothing
      chorus_text_base_delay1,                    //41 - Change base delay
      NULL,                                       //42 - Nothing
      chorus_text_amplitude1,                     //43 - Change amplitude delay
      NULL,                                       //44 - Nothing
      chorus_text_frequency1,                     //45 - Change modulation frequency
      NULL,                                       //46 - Nothing
      dashes,                                     //47 - Nothing
      chorus_voice_line2,                         //48 - Enable/Disable
      chorus_text_direct_gain2,                   //49 - Change gain
      NULL,                                       //50 - Nothing
      chorus_text_feedback_gain2,                 //51 - Change feedback gain
      NULL,                                       //52 - Nothing
      chorus_text_base_delay2,                    //53 - Change base delay
      NULL,                                       //54 - Nothing
      chorus_text_amplitude2,                     //55 - Change amplitude delay
      NULL,                                       //56 - Nothing
      chorus_text_frequency2,                     //57 - Change modulation frequency
      NULL,                                       //58 - Nothing
      dashes,                                     //59 - Nothing
      chorus_voice_line3,                         //60 - Enable/Disable
      chorus_text_direct_gain3,                   //61 - Change gain
      NULL,                                       //62 - Nothing
      chorus_text_feedback_gain3,                 //63 - Change feedback gain
      NULL,                                       //64 - Nothing
      chorus_text_base_delay3,                    //65 - Change base delay
      NULL,                                       //66 - Nothing
      chorus_text_amplitude3,                     //67 - Change amplitude delay
      NULL,                                       //68 - Nothing
      chorus_text_frequency3,                     //69 - Change modulation frequency
      NULL,                                       //70 - Nothing
      dashes,                                     //71 - Nothing
      chorus_voice_line4,                         //72 - Enable/Disable
      chorus_text_direct_gain4,                   //73 - Change gain
      NULL,                                       //74 - Nothing
      chorus_text_feedback_gain4,                 //75 - Change feedback gain
      NULL,                                       //76 - Nothing
      chorus_text_base_delay4,                    //77 - Change base delay
      NULL,                                       //78 - Nothing
      chorus_text_amplitude4,                     //79 - Change amplitude delay
      NULL,                                       //80 - Nothing
      chorus_text_frequency4,                     //81 - Change modulation frequency
      NULL,                                       //82 - Nothing
    };

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

    // Incrementer
    void IncrementSelected();

    // Decrementer
    void DecrementSelected();

};
