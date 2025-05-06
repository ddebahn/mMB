# Terminalsteuerung

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QWidget, QPushButton, QHBoxLayout, QVBoxLayout, QCheckBox
from PySide6.QtWidgets import QTabWidget, QTextEdit, QGridLayout, QButtonGroup, QLineEdit, QGroupBox
        

class Controls(QGroupBox):
    def __init__(self):
        super().__init__()
        self.setTitle('Steuerung')
        # Layout hinzufügen
        layout = QGridLayout(self)
        # Schaltflächen erstellen usw.
        self.time_box = QCheckBox('Zeit hinzufügen', self)
        layout.addWidget(self.time_box, 0, 0)
        #
        self.clear_btn = QPushButton('Terminal löschen')

        layout.addWidget(self.clear_btn, 1, 0)
        #
        self.copy_btn = QPushButton('Kopieren')

        layout.addWidget(self.copy_btn, 0, 2)
        #
        self.cut_btn = QPushButton('Ausschneiden')

        layout.addWidget(self.cut_btn, 1, 2)
        #
        self.info_btn = QPushButton('Port Infos')

        layout.addWidget(self.info_btn, 0, 3)
        #
        self.free_btn = QPushButton('Freie Ports')

        layout.addWidget(self.free_btn, 1, 3)


class SendAny(QWidget):
    def __init__(self):
        super().__init__()
        # Layout hinzufügen
        layout = QHBoxLayout(self)
        layout.setContentsMargins(0, 0, 0, 0)
        #
        self.any_field = QLineEdit()
        self.any_field.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.any_field)
        #
        self.any_btn = QPushButton('Senden')

        layout.addWidget(self.any_btn)


class NewButton(QPushButton):
    cmd = ''

    def __init__(self, lbl):
        super().__init__()
        self.setText(lbl)
        self.setMinimumHeight(20)

    def set_cmd(self, cmd):
        self.cmd = cmd

    def get_cmd(self):
        return self.cmd


class Notebook(QTabWidget):
    # Schriftfarbe
    def_btn_fg_color = 'black'
    def_btn_bg_color = '#eeeeee'
    btn_font_family = 'Titillium'
    btn_font_size = '12px'

    def __init__(self):
        super().__init__()

    # Methode zum Hinzufügen von Tabellen mit Schaltflächen
    def add_tab_btn(self, tab_name, btn_data, handler):
        # Neue Tabelle erstellen
        tab = QWidget()
        self.addTab(tab, tab_name)
        layout = QGridLayout(tab)
        # Gruppe "Schaltflächen hinzufügen"
        group = QButtonGroup(self)
        group.buttonClicked.connect(handler)
        c = 0        # Definiert die Anzahl der Spalten der Schaltflächen im Raster
        for col in btn_data:
            i = 0        # Zähler zum Festlegen der Anzahl der Zeilen der Schaltflächen im Raster
            for btn in col:
                if btn[0]:                         # Wenn die Beschriftung der Schaltfläche nicht leer ist
                    b = NewButton(btn[0])          # Schaltflächenobjekt erstellen
                    b.set_cmd(btn[1])              # Befehl der Schaltfläche festlegen
                    group.addButton(b)
                    layout.addWidget(b, i, c)
                    if not btn[2]: btn[2] = self.def_btn_fg_color   # Wenn die Vordergrundfarbe nicht definiert ist, verwenden Sie die Standardfarbe.
                    if not btn[3]: btn[3] = self.def_btn_bg_color   # Wenn die Hintergrundfarbe nicht definiert ist, verwenden Sie die Standardfarbe
                    b.setStyleSheet('background-color: ' + btn[3] + '; ' +
                                    'color: ' + btn[2] + '; ' +
                                    'font-family: ' + self.btn_font_family + '; ' +
                                    'font-size: ' + self.btn_font_size + ';')
                i = i + 1   # Nächste Zeile
            c = c + 1       # nächste Spalte

    # Methode zum Hinzufügen von Tabellen mit bearbeitbaren Feldern
    def add_tab_edit(self, tab_name, num_of_fields, tab_data, handler):
        # Neue Tabelle erstellen
        tab = QWidget()
        self.addTab(tab, tab_name)
        layout = QVBoxLayout(tab)
        for each in range(num_of_fields):
            fld = SendAny()
            fld.any_btn.clicked.connect(handler)

            layout.addWidget(fld)
            try:
                fld.any_field.setText(tab_data[each])
            except Exception:
                pass

