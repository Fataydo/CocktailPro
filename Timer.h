//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H

#include <ctime>
#include <iostream>

/**
* @class Timer
* @brief Diese Klasse ist dazu da, die Stoppuhr zu simulieren.
* Die Stoppuhr sorgt dafür, dass die Cocktails mit nötigen Zeit
* gemischt werden.
*/



class Timer {
public:

  /**
  * @brief diese Methode beschleunigt das Mischverfahren
  * @param [in] turbo um welchen Faktor das Mischverfahren
  * beschleunigt werden soll
  */
    void set_Turbo(int turbo);
    /**
    * @brief diese Methode erzeugt einen Timer, falls
    * ein Timer schon exestiert, wird er zurück gegeben.
    *
    */
    static Timer * getInstance();

    /**
     * 	~Timer( )
     *     {
     *         instanceFlag = false;
     *     };
     */

     /**
     * @brief diese Methode lässt den Timer warten
     * @param [in] milliseconds Wie viele millsekunden soll
     * gewartet werden.
     */
    void sleep(long milliseconds);

private:

  /**
  * @brief Varible die mit True oder False anzeigt
  * ob bereits ein Timer exestiert.
  */
    static bool instanceFlag;
    /**
    * @brief Varible um den Timer auf ein dynamischen
    * Speicher herzustellen
    */
    static Timer * theTimer;
    /**
    * @brief Varible um die Geschwindikgeit des
    * Timeres zu beeinflussen.
    */
    int booster;
    /**
    * @brief inline Konstruktor, der variablen initialisiert
    * die, die Timer Klasse auch ohne aktiven Timer haben sollte.
    */
    Timer() : booster(1), time_counter(0), last_time(0), this_time(0) {
    };
    /**
    * @brief Varible die, die Zähler des Timers darstellt
    */
    double time_counter;
    /**
    * @brief Eine Clock die anzeigt, wann der Timer zuletzt benutzt
    * wurde
    */
    std::clock_t last_time;
    /**
    * @brief momentane Zeit, wird erst in sleep() auf
    * etwas anderes als 0 gesetzt.
    */
    std::clock_t this_time;


};

#endif
