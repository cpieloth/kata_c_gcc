5. Modularization
=================

TODO (cpieloth): translate

/*** Sonstiges ***/

Zur besseren Übersichtlichkeit und Wartung sollte der Code in logische Module unterteilt werden. Diese Module können mit den vorgestellten Mitteln in externe Code-Dateien ausgelagert werden. Da C keinen Namensraum oder Klassen wie C++ oder Java unterstützt, sollte für jedes Modul ein aussagekräftiges Präfix gewählt werden. Dieses Präfix ist allen globalen Variablen- und Methodennamen voranzustellen, um doppelte Deklarationen zu vermeiden.

Beispieldateien: 5_misc/*