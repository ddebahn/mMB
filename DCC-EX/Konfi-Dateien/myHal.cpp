//  Beispiel myHal.cpp Datei.
//
// Um diese Datei zu verwenden, kopieren Sie sie, um die Direktiven zu myHal.cpp und auszukommentieren und/oder
// Bearbeiten Sie sie, um Ihre Anforderungen zu erfüllen.  Wenn Sie nur bis zu 
// zwei MCP23017 GPIO Expander-Modulen und/oder bis zu zwei PCA9685 Servo-Modulen,
// dann benötigen Sie diese Datei nicht, da DCC++EX diese kostenlos konfiguriert!

// Beachten Sie, dass die Datei, wenn sie eine .cpp Erweiterung hat, in den Build kompiliert wird
// und die Funktion halSetup() WIRD aufgerufen.
//
// Um dies zu verhindern, benennen Sie die Datei vorübergehend in myHal.txt oder ähnliches um.
//

// Die Direktive #if verhindert Kompilierungsfehler für Uno und Nano, indem sie die 
// HAL-Direktiven aus dem Build.
#if !defined(IO_NO_HAL)

// Fügen Sie die Geräte hinzu, die Sie benötigen.
#include "IODevice.h"
//#include "IO_HALDisplay.h"	// Zusatzanzeigegeräte (LCD/OLED)
//#include "IO_HCSR04.h"    	// Ultraschall-Entfernungssensor
//#include "IO_VL53L0X.h"   	// Laser-Lichtlaufzeitsensor
//#include "IO_DFPlayer.h"  	// MP3-Soundplayer
//#include "IO_TouchKeypad.h  	// Touch-Tastatur mit 16 Tasten
//#include "IO_EXTurntable.h"   // Turntable-EX Drehteller-Controller
//#include "IO_EXFastClock.h"  	// FastClock-Treiber
//#include "IO_PCA9555.h"     	// 16-Bit-I/O-Expander (NXP und Texas Instruments).

//==========================================================================
// Die Funktion halSetup() wird von CS aufgerufen, wenn sie innerhalb des Builds vorhanden ist.
// Die Setup-Aufrufe sind zwischen der geschweiften Klammer open und close "{ ... }" enthalten.
// Kommentare (Zeilen, denen "//" vorangestellt ist) sind optional.
//==========================================================================

void halSetup() {

  //=======================================================================
  // Die folgenden Direktiven definieren zusätzliche Anzeigegeräte.
  // Diese können zusätzlich zur Systemanzeige definiert werden ((Anzeige
  // Nummer 0), die in der config.h definiert ist.
  // Ein Schreibvorgang in eine Zeile, die über die Länge des Bildschirms hinausgeht, wird überschrieben
  // die untere Zeile, es sei denn, die Zeilennummer ist 255; in diesem Fall wird die 
  // Der Bildschirminhalt scrollt nach oben, bevor der Text in den
  // Fazit.
  //=======================================================================
  // 
  // Erstellen eines OLED-Anzeigegeräts mit einer Auflösung von 128 x 32 Pixeln als Anzeige Nummer 1 
  // (Zeile 0 wird von EX-RAIL 'SCREEN(1, 0, "text")' geschrieben).

  //HALDisplay<OLED>::create(1, 0x3d, 128, 32);

  // Erstellen eines 20x4 LCD-Anzeigegeräts als Anzeigenummer 2 
  // (Zeile 0 wird von EX-RAIL 'SCREEN(2, 0, "text")' geschrieben).

  // HALDisplay<LiquidCrystal>::create(2, 0x27, 20, 4);


  //=======================================================================
  // Benutzer-Add-Ins
  //=======================================================================
  // Benutzer-Add-Ins können erstellt werden, wenn Sie etwas tun möchten, das 
  // Kann nicht in EX-RAIL durchgeführt werden, verdient aber keinen HAL-Treiber.  Das 
  // user-Add-In ist eine C++-Funktion, die regelmäßig von der
  // HAL-Subsystem.

  // Beispiel: Die Funktion wird einmal pro Sekunde ausgeführt und zeigt an, 
  // auf Bildschirm #3 die ersten acht Einträge (bei einer 8-zeiligen Anzeige)
  // aus der Lokgeschwindigkeitstabelle.
  
  // Fügen Sie den folgenden Codeblock in myHal.cpp AUSSERHALB des 
  //   halSetup() function:
  //
  // void updateLocoScreen() {
  //   for (int i=0; i<8; i++) {
  //     if (DCC::speedTable[i].loco > 0) {
  //       int speed = DCC::speedTable[i].speedCode;
  //       char direction = (speed & 0x80) ? 'R' : 'F';
  //       speed = speed & 0x7f;
  //       if (speed > 0) speed = speed - 1;
  //       SCREEN(3, i, F("Loco:%4d %3d %c"), DCC::speedTable[i].loco,
  //         speed, direction);
  //     }
  //   }
  // }
  //
  // Fügen Sie die folgende Zeile IN die Funktion halSetup() ein:
  //
  // UserAddin::create(updateLocoScreen, 1000);
  //


  //=======================================================================
  // Die folgende Direktive definiert ein PCA9685 PWM-Servo-Treibermodul.
  //=======================================================================
  // Die Parameter sind: 
  //   Erster Vpin = 100
  //   Mehrere VPINs = 16 (numeriert 100 - 115)
  //   I2C-Adresse von Modul = 0x40

  //PCA9685::create(100, 16, 0x40);


  //=======================================================================
  // Die folgende Direktive definiert ein MCP23017 I2C-GPIO-Extender-Modul mit 16 Ports.
  //=======================================================================
  // Die Parameter sind: 
  //   Erster Vpin = 196
  //   Mehrere VPINs = 16 (numeriert 196 - 211)
  //   I2C-Adresse von Modul = 0x22

 MCP23017::create(196, 16, 0x22);


  // Alternatives Formular, das es dem INT-Pin des Moduls ermöglicht, einen Scan anzufordern
  // indem Sie den Arduino-Pin 40 auf Masse ziehen.  Bedeutet, dass der I2C nicht abgefragt wird
  // Die ganze Zeit, nur wenn eine Veränderung stattfindet. INT-Pins mehrerer Module
  // kann mit demselben Arduino-Pin verbunden werden.

  //MCP23017::create(196, 16, 0x22, 40);


  //=======================================================================
  // Die folgende Direktive definiert ein MCP23008 I2C-GPIO-Extender-Modul mit 8 Ports.
  //=======================================================================
  // Die Parameter sind: 
  //   Erster Vpin = 300
  //   Mehrere VPINs=8 (numeriert 300 - 307)
  //   I2C-Adresse von Modul = 0x22

  //MCP23008::create(300, 8, 0x22);


  //=======================================================================
  // Die folgende Direktive definiert ein PCF8574 I2C-GPIO-Extender-Modul mit 8 Ports.
  //=======================================================================
  // Die Parameter sind: 
  //   Erster Vpin = 200
  //   Mehrere VPINs = 8 (numeriert 200 - 207)
  //   I2C-Adresse von Modul = 0x23

  //PCF8574::create(200, 8, 0x23);


  // Alternatives Formular mit INT-Pin (siehe oben)

  //PCF8574::create(200, 8, 0x23, 40);


  //=======================================================================
  // Die folgende Direktive definiert ein PCF8575 I2C-GPIO-Extender-Modul mit 16 Ports.
  //=======================================================================
  // Die Parameter sind: 
  //   Erster Vpin = 200
  //   Mehrere VPINs = 16 (numeriert 200 - 215)
  //   I2C-Adresse von Modul = 0x23

  //PCF8575::create(200, 16, 0x23);


  // Alternatives Formular mit INT-Pin (siehe oben)

  //PCF8575::create(200, 16, 0x23, 40);

  //=======================================================================
  // Die folgende Richtlinie definiert ein HCSR04 Ultraschall-Entfernungsmessgerät.
  //=======================================================================
  // Die Parameter sind: 
  //   Vpin = 2000 (nur eine VPIN pro Direktive)
  //   Mehrere VPINs = 1
  //   Arduino-Pin verbunden mit TRIG=30
  //   Arduino-Pin verbunden mit ECHO=31
  //   Minimaler Auslöser range = 20cm (VPIN goes to 1 when <20cm)
  //   Maximaler Auslöser range=25cm (VPIN goes to 0 when >25cm)
  // Hinweis: Mehrere Geräte können mit einem anderen ECHO-Pin konfiguriert werden
  // für jeden.  Der TRIG-Pin kann von mehreren Geräten gemeinsam genutzt werden.
  // Beachten Sie, dass der "Ping" eines Geräts von einem anderen Gerät empfangen werden kann
  // Gerät und positionieren Sie diese entsprechend!

  //HCSR04::create(2000, 30, 31, 20, 25);
  //HCSR04::create(2001, 30, 32, 20, 25);


  //=======================================================================
  // Die folgende Direktive definiert einen einzelnen VL53L0X einen Time-of-Flight-Bereichssensor.
  //=======================================================================
  // Die Parameter sind:
  //   VPIN = 5000
  //   Mehrere VPINs = 1
  //   I2C-Adresse = 0x29 (Standard für diesen Chip)
  //   Minimaler Auslöser range = 200mm (VPIN geht an 1 wann <20cm)
  //   Maximaler Auslöser range = 250mm (VPIN geht an 0 wann >25cm)

  //VL53L0X::create(5000, 1, 0x29, 200, 250); 

  // Fügen Sie für mehrere VL53L0X Module einen weiteren Parameter hinzu, bei dem es sich um einen VPIN handelt, der mit dem verbunden ist.
  // XSHUT-Pin des Moduls.  Auf diese Weise können die Module beim Start
  // mit unterschiedlichen I2C-Adressen.  In diesem Fall wird die Adresse 0x29 nur während
  // Initialisierung, um jedes Gerät der Reihe nach mit der gewünschten eindeutigen I2C-Adresse zu konfigurieren.
  // In den folgenden Beispielen sind die XSHUT-Pins der Module mit den ersten beiden Pins von 
  // das erste MCP23017-Modul (164 und 165), aber es können stattdessen Arduino-Pins verwendet werden.
  // Das erste Modul erhält hier die I2C-Adresse 0x30 und das zweite ist 0x31.

  //VL53L0X::create(5000, 1, 0x30, 200, 250, 164); 
  //VL53L0X::create(5001, 1, 0x31, 200, 250, 165); 


  //=======================================================================
  // Spiele mp3-Dateien von einer Micro-SD-Karte mit einem DFPlayer MP3-Modul ab.
  //=======================================================================
  // Parameter: 
  //   10000   = erste zugewiesene VPIN.
  //   10      = Anzahl der zugewiesenen VPINs.
  //   Serial1 = Name der seriellen Schnittstelle (normalerweise Serial1 oder Serial2).
  // Mit diesen Parametern können bis zu 10 Dateien auf den Pins 10000-10009 abgespielt werden.
  // Die Wiedergabe wird von EX-RAIL mit SET(10000) für die erste mp3-Datei, SET(10001), gestartet
  // für die zweite Feile usw.  Das Spiel kann auch durch das Schreiben eines Analogons gestartet werden
  // Wert an den ersten Pin anhängen, z.B. ANOUT(10000,23,0,0) spielt die 23. mp3-Datei ab.
  // ANOUT(10000,23,30,0) macht das Gleiche und setzt die Lautstärke auf 
  // 30 (Maximalwert).
  // Die Wiedergabe wird durch RESET(10000) (oder eine andere zugewiesene VPIN) gestoppt.
  // Die Lautstärke kann auch eingestellt werden, indem ein analoger Wert auf den zweiten Pin für den Player geschrieben wird. 
  // z.B. ANOUT(10001,30,0,0) setzt die Lautstärke auf maximal (30).
  // Das EX-RAIL-Skript kann durch Aufruf von WAITFOR(pin) überprüfen, ob die Wiedergabe abgeschlossen ist, wodurch nur zum
  // Folgende Zeile, wenn der Spieler nicht mehr beschäftigt ist.
  // Zum Beispiel.
  //    SEQUENCE(1)
  //      AT(164)           // Warten Sie, bis der Sensor an Pin 164 angeschlossen ist, um aktiviert zu werden
  //      SET(10003)        // Vierte MP3-Datei abspielen
  //      LCD(4, "Playing") // Meldung auf LCD/OLED anzeigen
  //      WAITFOR(10003)    // Warten Sie, bis die Wiedergabe beendet ist
  //      LCD(4, "")        // Lösche LCD/OLED-Linie 
  //      FOLLOW(1)         // Zurück zum Anfang

  // DFPlayer::create(10000, 10, Serial1);

  //=======================================================================
  // Kapazitive Touch-Tastatur mit 16 Pads basierend auf TP229 IC.
  //=======================================================================
  // Parameter unten:
  //   11000 = erste zugewiesene VPIN
  //   16 = Anzahl der zugewiesenen VPINs
  //   25 = lokale GPIO-Pinnummer für das Taktsignal
  //   24 = lokale GPIO-Pinnummer für Datensignal
  //
  // Durch Drücken der Tastenfelder mit den Nummern 1-16 wird jeder der nominierten digitalen VPINs angezeigt 
  // (in diesem Fall 11000-11015), um aktiviert zu werden.

  // TouchKeypad::create(11000, 16, 25, 24);

  //=======================================================================
  // Die folgende Direktive definiert eine EX-Turntable-Drehtellerinstanz.
  //=======================================================================
  // EXTurntable::create(VPIN, Number of VPINs, I2C Address)
  //
  // Die Parameter sind:
  //   VPIN = 600
  //   Mehrere VPINs=1 (Beachten Sie, dass es keinen Grund gibt, dies zu ändern)
  //   I2C Adresse =0 x60
  //
  // Beachten Sie, dass die I2C-Adresse im EX-Turntable-Code definiert ist und 0x60 die Standardeinstellung ist.

  //EXTurntable::create(600, 1, 0x60);


  //=======================================================================
  // Die folgende Direktive definiert eine EX-IOExpander-Instanz.
  //=======================================================================
  // EXIOExpander::create(VPIN, Number of VPINs, I2C Address)
  //
  // Die Parameter sind:
  //   VPIN = ein verfügbarer Vpin
  //   Mehrere VPINs = Anzahl der Pins (muss mit dem verwendeten Gerät gemäß Dokumentation übereinstimmen)
  //   I2C Adresse = eine verfügbare I2C-Adresse (Standard-0x65)
  //
  // Beachten Sie, dass die I2C-Adresse im EX-IOExpander-Code definiert ist und 0x65 die Standardeinstellung ist.
  // Das Beispiel ist für einen Arduino Nano.

  //EXIOExpander::create(800, 18, 0x65);


  //=======================================================================
  // Die folgende Direktive definiert eine Drehgeberinstanz.
  //=======================================================================
  // Die Parameter sind: 
  //   firstVpin = Erstes verfügbares Vpin zur Zuweisung
  //   numPins = Die Anzahl der zuzuweisenden Vpins kann entweder 1 oder 2 betragen
  //   i2cAddress = Verfügbare I2C-Adresse (Standard 0x70)

  //RotaryEncoder::create(firstVpin, numPins, i2cAddress);
  //RotaryEncoder::create(700, 1, 0x70);
  //RotaryEncoder::create(701, 2, 0x71);

  //=======================================================================
  // Die folgende Direktive definiert eine EX-FastClock-Instanz.
  //=======================================================================
  // EXFastCLock::create(I2C Address)
  //
  // Die Parameter sind:
  //   
  //   I2C address=0x55 (decimal 85)
  //
  // Beachten Sie, dass die I2C-Adresse im EX-FastClock-Code definiert ist und 0x55 die Standardeinstellung ist.

 
  //   EXFastClock::create(0x55);

}

#endif
