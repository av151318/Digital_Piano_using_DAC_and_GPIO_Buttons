    /*
 * soundDriver.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Daniel Vasquez
 *
     To use SoundDriver.h:
     validate proper practice and include soundDriver.h in your source file you intend to deploy
     Music Note definitions are included here to be used later in code.
     SineWave is defined in the source file for Systick to access

     initialize with sound_init()
     use sound_play() to set the reload value for ISR
     The new reload value will traverse the sinewave array next and produce the next tone
     sound_play() takes an argument in source file definiton.

     This intended to make the music tone easy.
     the argument can be the input the note intedned to be play
     ex: sound_play(F) will load ISR reload value with the Frequency mapped to the note F

     Common issues include:
     Observed note precision.
     outputting F is observed as 350Hz rather than 349Hz
     this issue can be due a few things.
     Consider:
         5-10% Voltage error range of pins output of DAC
         the precision instruments used to measure DAC output
 *
 */

#ifndef SOUNDDRIVER_H_
#define SOUNDDRIVER_H_

// Define musical notes for their corresponding timer reload values
#define C  523   // 523 Hz
#define B  494   // 494 Hz
#define Bb 466   // 466 Hz
#define A  440   // 440 Hz
#define Ab 415   // 415 Hz
#define G  392   // 392 Hz
#define Gb 370   // 370 Hz
#define F  349   // 349 Hz
#define E  330   // 330 Hz
#define Eb 311   // 311 Hz
#define D  294   // 294 Hz
#define Db 277   // 277 Hz
#define C2 262   // 262 Hz
#define OFF 0

// sinewave defined in soundDriver.C
extern const uint8_t sineWave[32];

void sound_init();
void sound_play();
#endif /* SOUNDDRIVER_H_ */
