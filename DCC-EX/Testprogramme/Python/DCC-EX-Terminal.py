# Main

from PySide6.QtCore import QIODevice
from PySide6.QtSerialPort import QSerialPort, QSerialPortInfo
from PySide6.QtWidgets import QApplication, QMainWindow

import sys

import datetime
from ComPort import ComPort
from Terminalsteuerung import *

###############################################################

term_title = 'DCC-EX Terminal v1.00'

# COM-Port Angaben festlegen
nmax = 300  # max. Anzahl der COM-Ports, die in get_free_ports() verwendet werden
com_port_name = ''
default_baud_rate = '115200'

# Fenstergrösse
window_min_height = 600
window_min_width = 1200
term_min_width = 600

cmd_end = b'\r'

time_stamp = 1  # um einen Zeitstempel (1) hinzuzufügen oder nicht (0)
new_line = 1  # Setzen Sie add_time = 1 nach Erhalt von '\r' oder '\n'

# Namen der Tabellen des Notebooks
tab1Name = 'MEGA 2560'
tab2Name = 'Nano'
tab3Name = '---'
tab4Name = '---'
tab5Name = 'allg.'

###############################################################
# ---------- Aufbau der einzelnen Tabs ----------
# Tab-Taste [0, 1, 2, 3]:
# 0 - Beschriftung des Buttons
# 1 - Befehl zum Senden
# 2 - Schriftfarbe der Schaltfläche
# 3 - Hintergrundfarbe der Schaltfläche

# --------------- TAB1-TASTEN ---------------
T1_0 = [['DCC-EX einschalten', '<1>', '', '#00dd00'],
        ['DCC-EX ausschalten', '<0>', '', 'red'],
        ['Q', '<Q>', '', 'yellow'],
        ['S', '<S>', '', 'yellow'],
        ['JR', '<JR>', '', 'yellow'],
        ['T', '<T>', '', 'yellow'],
        ['D RAM', '<D RAM>', '', 'yellow'],
        ['D HAL Show', '<D HAL Show>', '', 'pink'],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', '']]

T1_1 = [['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', '']]

T1_2 = [['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', ''],
        ['-', '', '', '']]

T1 = [T1_0, T1_1, T1_2]

# --------------- TAB2-TASTEN ---------------
T2_0 = [['D HAL Show', '<D HAL Show>', '', 'pink'],
        ['V', '<V>', '', 'green'],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', '']]

T2_1 = [['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', '']]

T2_2 = [['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', '']]

T2 = [T2_0, T2_1, T2_2]

# --------------- TAB3-TASTEN ---------------
T3_0 = [['', '', '', '']]

T3_1 = [['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', '']]

T3_2 = [['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', '']]

T3 = [T3_0, T3_1, T3_2]

# --------------- TAB4-TASTEN ---------------
T4_0 = [['', '', '', '']]

T4_1 = [['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', '']]

T4_2 = [['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', ''],
        ['', '', '', '']]

T4 = [T4_0, T4_1, T4_2]

# --------------- TAB5-TASTEN ---------------
T5 = [['', '', '', '']]

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle(term_title)

        # Zentrales Widget
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        hbox = QHBoxLayout(central_widget)
        # Begriffe erstellen
        self.term = QTextEdit()
        self.term.setReadOnly(True)
        self.term.setMinimumWidth(term_min_width)

        hbox.addWidget(self.term)
        # vbox erstellen (vertikales Layout)
        vbox = QVBoxLayout()
        # vbox zum Hauptfenster hinzufügen
        hbox.addLayout(vbox)
        # Erstellen von Steuerelementen und Binden von Handlern
        self.controls = Controls()
        self.controls.clear_btn.clicked.connect(self.clear_term)
        self.controls.copy_btn.clicked.connect(self.copy)
        self.controls.cut_btn.clicked.connect(self.cut)
        self.controls.info_btn.clicked.connect(self.ports_info)
        self.controls.free_btn.clicked.connect(self.get_free_ports)
        self.controls.time_box.toggled.connect(self.time_box_toggled)
        self.controls.time_box.setChecked(True)
        # Comport einstellen
        self.port = ComPort(com_port_name, default_baud_rate)
        self.port.ser.readyRead.connect(self.on_port_rx)
        self.port.ser.errorOccurred.connect(self.port_error)

        # Notizbuch erstellen
        self.notebook = Notebook()
        # Hinzufügen von Tabellen zum Notizbuch
        self.notebook.add_tab_btn(tab1Name, T1, self.send)
        self.notebook.add_tab_btn(tab2Name, T2, self.send)
        self.notebook.add_tab_btn(tab3Name, T3, self.send)
        self.notebook.add_tab_btn(tab4Name, T4, self.send)
        self.notebook.add_tab_edit(tab5Name, 10, T5, self.send_any)
        # Hinzufügen von Steuerelementen zum Seitenbereich
        vbox.addWidget(self.port)
        vbox.addWidget(self.controls)

        vbox.addWidget(self.notebook)

    def send(self, btn):
        global cmd_end
        cmd_to_send = btn.get_cmd()
        if cmd_to_send:
            if isinstance(cmd_to_send, str):  # wenn es sich bei der Art der cmd_to_send um eine <string>
                self.write(cmd_to_send.encode('ascii') + cmd_end)
            else:
                print('send(): Beim Senden an UART ist etwas schief gelaufen (ASCII-Codierung fehlgeschlagen)!')

# ---------- Button -> Senden ----------
    def send_any(self):
        global cmd_end
        if self.port.com_opened:
            ref = self.sender()  # Abrufen des erstellten Objekts Empfangenes Signal
            cmd_to_send = ref.parent().any_field.text()  # Abrufen von Text aus any_field mit übergeordnetem Element
            if cmd_to_send:
                self.write(cmd_to_send.encode('ASCII') + cmd_end)

# ---------- Button -> Portinfo ----------
    def ports_info(self):
        ser_info = QSerialPortInfo()
        ports = ser_info.availablePorts()
        self.term.insertPlainText('\r' + '-' * 18 + ' Port Infos ' + '-' * 18 + '\r')
        for ser in ports:
            self.term.insertPlainText(ser.portName() + '\r')
            self.term.insertPlainText(ser.description() + '\r')
            if ser.hasVendorIdentifier():
                self.term.insertPlainText('VID: ' + hex(ser.vendorIdentifier()) + '\r')
            if ser.hasProductIdentifier():
                self.term.insertPlainText('PID: ' + hex(ser.productIdentifier()) + '\r')
            self.term.insertPlainText('Manufacturer: ' + ser.manufacturer() + '\r')
            self.term.insertPlainText('-' * 50 + '\r')
        self.statusBar().showMessage('Port Infos')
        self.term.ensureCursorVisible()

# ---------- Button -> Free ----------
    def get_free_ports(self):
        n = 0
        self.term.insertPlainText('\r' + '-' * 17 + ' Freie Ports ' + '-' * 17 + '\r')
        temp_port = QSerialPort()
        while n < nmax:
            n = n + 1
            temp_port.setPortName('COM' + str(n))
            res = temp_port.open(QIODevice.ReadWrite)
            if res:  # Der Hafen wurde erfolgreich geöffnet
                self.term.insertPlainText('COM' + str(n) + '\r')
                temp_port.close()
        self.term.insertPlainText('-' * 50 + '\r')
        self.statusBar().showMessage('Freie Ports')
        self.term.ensureCursorVisible()

# ---------- Button -> in den Tabs betätigt ----------
    def write(self, data):
        self.port.write(data)

# ---------- Button -> Löschen ----------
    def clear_term(self):
        try:
            self.term.clear()  # Durchsichtiges Terminal
            self.statusBar().showMessage('Terminal gelöscht')
        except Exception:
            self.statusBar().showMessage('Terminal konnte nicht gelöscht werden!')

# ---------- Button -> Kopieren ----------
    def copy(self):
        try:
            curs = self.term.textCursor()  # Cursor, der verwendet wird, wenn die Auswahl aller
            self.term.selectAll()  # Alle auswählen
            self.term.copy()  # In die Zwischenablage kopieren
            self.term.setTextCursor(curs)  # Auswahl aufheben
            self.statusBar().showMessage('Erfolgreich vom Terminal kopiert')
        except Exception:
            self.statusBar().showMessage('Fehler beim Kopieren vom Terminal!')

# ---------- Button -> Ausschneiden ----------
    def cut(self):
        try:
            self.term.selectAll()  # Alle auswählen
            self.term.copy()  # In die Zwischenablage kopieren
            self.term.clear()  # Durchsichtiges Terminal
            self.statusBar().showMessage('Erfolgreich vom Terminal ausgeschnitten')
        except Exception:
            self.statusBar().showMessage('Fehler beim Schneiden vom Terminal!')

# ---------- Programm beenden ----------
    def closeEvent(self, event):
        self.port.close_port()
        event.accept()

    @staticmethod
    def nice_hex(binstr):  # Binärzeichenfolge in eine lesbare HEX-ähnliche Zeichenkette konvertieren: F1 34 0A 5D 00 7A...
        nicestr = ''
        for x in binstr:
            nicestr = nicestr + bytes([x]).hex().upper() + ' '
        return nicestr[:-1]

    @staticmethod
    def show_hex(ch):  # Byte in lesbares HEX-ähnliches Symbol umwandeln wie: <0x1A>
        return '<0x' + ch.hex().upper() + '>'

    def decode_and_format(self, binstr):  # Arten von binstr: <class 'PySide6.QtCore.QByteArray'>, <class 'bytes'>
        global time_stamp
        global new_line
        ascii_str = ''
        # für i in range(0, binstr.size()):
        for i in binstr:
            if isinstance(i, int):  # Wenn type of binstr <bytes> ist, dann ist type of i <int>!
                i = bytes([i])  # konvertieren <int> in <bytes>
            if i == b'\x00':  # Wenn self.term.insertPlainText('\x00') erhalten wir Ausnahme: ValueError: eingebettetes Nullzeichen
                ascii_symbol = '<0x00>'  # Ersetzen Sie das Byte 0x00 durch die Zeichenkette '<0x00>'
            else:
                try:
                    ascii_symbol = i.decode("ascii")
                except Exception:
                    ascii_symbol = self.show_hex(i)
            if ascii_symbol == '\r' or ascii_symbol == '\n':
                new_line = 1
                ascii_symbol = ''  # Entfernen Sie '\r' und '\n', um keine leeren Zeilen zu drucken
            else:
                if new_line:
                    ascii_str = ascii_str + '\r'
                    new_line = 0
                    if time_stamp:
                        curr_time = datetime.datetime.now()
                        ascii_str = ascii_str + curr_time.strftime('%H:%M:%S:%f')[:12] + '    '
            ascii_str = ascii_str + ascii_symbol
        return ascii_str

    def on_port_rx(self):
        num_rx_bytes = self.port.ser.bytesAvailable()
        rx_bytes = self.port.ser.read(num_rx_bytes)
        data = self.decode_and_format(rx_bytes)
        try:
            self.term.insertPlainText(data)
            self.term.ensureCursorVisible()
        except Exception:
            self.statusBar().showMessage('on_port_rx: ERROR')

    def time_box_toggled(self, checked):
        global time_stamp
        if checked:
            time_stamp = 1
        else:
            time_stamp = 0

    def indicate_port_error(self,
                            err):  # Die getrennte Funktion zur Anzeige ist eine gute Idee, wenn wir mehr als eine serielle Schnittstelle haben
        if err == QSerialPort.SerialPortError.NoError:
            err_msg = 'OK'
        elif err == QSerialPort.SerialPortError.DeviceNotFoundError:
            err_msg = 'device not found'
        elif err == QSerialPort.SerialPortError.PermissionError:
            err_msg = 'permission error'
        elif err == QSerialPort.SerialPortError.OpenError:
            err_msg = 'open error'
        elif err == QSerialPort.SerialPortError.NotOpenError:
            err_msg = 'not open error'
        elif err == QSerialPort.SerialPortError.WriteError:
            err_msg = 'write error'
        elif err == QSerialPort.SerialPortError.ReadError:
            err_msg = 'read error'
        elif err == QSerialPort.SerialPortError.ResourceError:
            err_msg = 'resource error'
        elif err == QSerialPort.SerialPortError.UnsupportedOperationError:
            err_msg = 'unsupported operation'
        elif err == QSerialPort.SerialPortError.TimeoutError:
            err_msg = 'timeout error'
        elif err == QSerialPort.SerialPortError.UnknownError:
            err_msg = 'unknown error'
        else:
            err_msg = 'undefined error'
        self.statusBar().showMessage('Serieller Anschluss: ' + err_msg)

    def port_error(self):
        self.indicate_port_error(self.port.ser.error())

def main():
    app = QApplication([])
    main_win = MainWindow()
    main_win.resize(window_min_width, window_min_height)
    main_win.show()
    sys.exit(app.exec())

if __name__ == '__main__':
    main()
