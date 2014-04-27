Header
======

TODO (cpieloth): translate

/*** Header ***/

In Header-Dateien können Methoden-, Variablen- und Typ-Deklarationen aufgelistet werden. Header enthalten keinen oder nur wenig Code. Sie werden genutzt um Implementierungen von der Schnittstelle zu kapseln. Als Beispiel dient eine Bibliothek zur Zeitmessung. Die Datei timer.h dient dem Programmierer als Schnittstelle. In ihr sind die Methoden und Variablen definiert. Die Implementierung ist in die Datei timer.c ausgelagert, da auf Windows und Linux evt. andere Systemaufrufe zur Zeitmessung genutzt werden sollen (weiteres unter Linker & Objekt-Dateien).

Beispieldateien: 3_header/*

Der Präprozessor fügt die Header-Datei ohne Fehler ein. Die Übersetzung schlägt fehl, da keine Implementierung angegeben ist:
gcc -E main.c > main_pp_1.c
meld main.c main_pp_1.c
gcc -o main main.c /* Fehler */
gcc -o main main.c timer.c /* Implementierung von timer.h in timer.c gefunden */

Wie zuvor bei include erwähnt, können Konflikte auftreten, wenn mehrere Dateien eine Header-Datei nutzen:
gcc -o main_2 main_2.c timer.c

Mit Hilfe von Makros und Bedingungen können diese Konflikte gelöst werden:
gcc -o main_3 main_3.c timer.c 
