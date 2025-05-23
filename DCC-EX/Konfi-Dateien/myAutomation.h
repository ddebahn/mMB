// myAutomation.h - Generated by EX-Installer v0.0.18 for EX-CommandStation v5.0.9-Prod

// Anzeige Einstellung
AUTOSTART
// SCREEN(0, 4, "                    ")
// SCREEN(0, 5, "  Board: MEGA 2560  ")
SCREEN(0, 6, "    RailControl     ")
SCREEN(0, 7, "     Stellwerk      ")

// SET_TRACK(A,MAIN)
// SET_TRACK(B,PROG)
DONE

// Servo Einstellung
SERVO_TURNOUT(100, 100, 350, 250, Slow)     // DCC - Adresse 100
SERVO_TURNOUT(101, 101, 350, 210, Slow)     // DCC - Adresse 101

// Arduino Nano als IO-Expander
HAL(EXIOExpander, 800, 18, 0x65)            // DCC - Adresse ab 800
HAL(EXIOExpander, 818, 18, 0x68)            // DCC - Adresse ab 818

// ROSTER(999,"Lokname","F0/F1/*F2/F3/F4/F5/F6/F7/F8/usw.")
//	999 - ist die DCC-Adresse der Lok
//	Lokname - ist alles, was Sie als Namen dieser Lok in den Drosselklappen-Apps sehen möchten
//	F0 F1 F3 ... F27. - sind die Namen, die Sie für die Funktionen sehen möchten, die für diese Lok spezifisch sind
//	*F2 - Beachten Sie, dass die Funktionsbeschriftung mit einem Sternchen (*) beginnt,
//		  wenn die Funktion "momentan" und nicht "einrastend" (Ein/Aus) ist.
//		  Das häufigste Beispiel dafür ist die Hupe/ Pfeife, die häufig auf F2 geschaltet ist.

// meine Loks
ROSTER(3,"VT 98","Licht/Motorsound/Innenraumbeleuchtung/Führerstandstüre auf-zu/Zugzielanzeiger/Rangiergang - Rangierbeleuchtung 1/Spitzenlicht abdimmen (Lokführergruß)/Handbremse anlegen-lösen/Vorwärmgerät/Bremse anlegen-lösen/Druckluftpfeife kurz/Druckluftpfeife lang/Führerstandsfenster auf-zu/Druckluft ablassen/Notbremse/Schaffnerpfif/Sanden/Kuppeln ab--ankuppeln/Bremsgeräuch deaktivieren/Schienenstöße ein-aus/Kurvenquietschen an-aus/Zugbeleuchtung Lok zieht/Zugbeleuchtung Lok schiebt/Soundfader (Tunnelmodus)//////")
ROSTER(5,"BR 333","Licht/Kupplungen////////////////////////////")
ROSTER(6,"BR 212","Licht/Hauptfahrgeräusch/Signalton 1 kurz/Glocke/Rangiergang/Kupplung vorn,Licht vorn AUS/Kupplung hinten, Licht hinten AUS/Licht Führerstand/Ausblenden/Signalton 1 lang/Kompressor/Lüfter/Dampfheizkessel/Hilfsdiesel/Bremsgeräusch/Kupplungsgeräusch + Luft //////////////")
ROSTER(7,"BR 216","Licht/Motor/Zugbeleuchtung: Lok zieht/*Zugbeleuchtung: Lok schiebt/*Kuppeln/*Maschinenraumbeleuchtung/*Rangiergang/Lautstärkeregelung/*Führerstandsbeleuchtung 1/*Führerstandsbeleuchtung 2/Lokführergruß /Horn hoch/Horn tief/Zugheizung/Hilfsluftkompressor/*Führerstandstür/*Führerstandsfenster/Handbremse/Schienenstöße/Kurvenquietschen/Lok tanken (nur mit ausgeschaltetem Motor, F1 aus)/*Scheibenwischer/*Ton aus///////")


