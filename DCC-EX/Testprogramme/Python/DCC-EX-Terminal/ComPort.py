# ComPort

from PySide6.QtCore import QIODevice, Qt, Slot
from PySide6.QtSerialPort import QSerialPort
from PySide6.QtWidgets import QPushButton, QComboBox, QGridLayout, QLineEdit, QLabel, QGroupBox


class ComPort(QGroupBox):  # QWidget
    def __init__(self, name='', baud_rate='115200'):
        super().__init__()
        self.setTitle('Serieller Anschluss ' + name)
        # Layout hinzufügen
        layout = QGridLayout(self)
        # Baudraten
        self.b_rates = ['9600', '14400', '19200', '28800', '33600', '38400', '57600', '115200', '230400', '460800', '921600']
        self.nmax = 300  # max. Anzahl der COM-Ports
        self.port_timeout = 0.5  # Zeitüberschreitung des COM-Ports
        # Schaltflächen erstellen usw.
        self.info_label = QLabel('Port geschlossen')
        self.info_label.setStyleSheet('color: red;')
        self.info_label.setMinimumWidth(100)
        self.info_label.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.info_label, 0, 0)
        #
        self.port_number_label = QLabel('Port Nummer: ')
        # self.port_number_label.setMinimumWidth(90)
        self.port_number_label.setAlignment(Qt.AlignRight)
        layout.addWidget(self.port_number_label, 0, 1)
        #
        self.port_field = QLineEdit()
        self.port_field.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.port_field, 0, 2)
        #
        self.open_btn = QPushButton('Verbinden')
        self.open_btn.setStyleSheet('background-color: #00dd00;')
        layout.addWidget(self.open_btn, 0, 3)
        self.open_btn.clicked.connect(self.open_port)
        #
        self.baud_rate_label = QLabel('Baudrate: ')
        self.baud_rate_label.setAlignment(Qt.AlignRight)
        layout.addWidget(self.baud_rate_label, 1, 1)
        #
        self.baud_rates = QComboBox()
        self.baud_rates.addItems(self.b_rates)
        if self.b_rates.count(baud_rate):
            self.baud_rates.setCurrentIndex(self.b_rates.index(baud_rate))  # Standardelement festlegen
        layout.addWidget(self.baud_rates, 1, 2)
        #
        self.close_btn = QPushButton('Trennen')
        self.close_btn.setStyleSheet('background-color: red;')
        layout.addWidget(self.close_btn, 1, 3)
        self.close_btn.clicked.connect(self.close_port)
        # serieller Anschluss
        self.com_opened = 0
        # self.baud_rate = int(baud_rate)
        self.ser = QSerialPort()
        self.ser.errorOccurred.connect(self.ser_error)

# ---------- Button -> Verbinden - Port öffnen ----------
    def open_port(self):
        n = 0
        if self.com_opened == 0:
            com_num = self.port_field.text()    # eingegebene Portnummer
            br = self.baud_rates.currentText()
            self.ser.setBaudRate(int(br))
            # Portnummer eingegeben
            if com_num:
                # ja
                if com_num.isdigit():
                    self.ser.setPortName('COM' + com_num)
                    self.ser.open(QIODevice.ReadWrite)
                    if self.ser.isOpen():
                        self.info_label.setText('Port: ' + com_num + ' geöffnet')
                        self.info_label.setStyleSheet('color: #00dd00;')  # grün
                        self.com_opened = 1
                    else:
                        self.info_label.setText('Kann nicht geöffnet werder!')
                        self.info_label.setStyleSheet('color: red;')
                        self.com_opened = 0
                else:
                    self.info_label.setText('Nur Ziffern!')
                    self.info_label.setStyleSheet('color: red;')
            else:   # nein
                    # erste freie Portnummer suchen und öffnen
                while (n < self.nmax) and (self.com_opened == 0):
                    n = n + 1
                    self.ser.setPortName('COM' + str(n))
                    res = self.ser.open(QIODevice.ReadWrite)
                    if res:  # erfolgreich geöffnet
                        self.info_label.setText('Port: ' + str(n) + ' geöffnet')
                        self.info_label.setStyleSheet('color: #00dd00;')  # grün
                        self.com_opened = 1
                if self.com_opened == 0:
                    self.info_label.setText('Kann nicht geöffnet werder!')
                    self.info_label.setStyleSheet('color: red;')

# ---------- Button -> Verbinden und prüfen ob Port geschlossen ist ----------
    def close_port(self):
        if self.com_opened:
            self.ser.close()
            self.info_label.setText('Port geschlossen')
            self.info_label.setStyleSheet('color: red;')
            self.com_opened = 0

    @Slot()
    def ser_error(self):
        err = self.ser.error()
        if err == QSerialPort.SerialPortError.NoError:  # wenn die Fehlermeldung "Kein Fehler" lautet
            pass
        else:
            self.close_port()  # Port schließen, wenn ein Fehler aufgetreten ist...

    def write(self, data):
        if self.com_opened:
            self.ser.write(data)
