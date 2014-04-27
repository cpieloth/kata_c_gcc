Linker & Objects
================

TODO (cpieloth): translate

/*** Linker & Objektdateien ***/
Objektdateien und der Linker werden genutzt, wenn externe Bibliotheken nur als Binärpakete vorhanden sind oder der Entwickler nicht jedes mal den Code einer verwendeten Bibliothek neukompilieren will. In diesen Fall können Objektdateien (*.o) oder Shared Libraries (*.so, *.dll) erstellt werden und beim Kompilieren gelinkt werden. So können z.B. auch beim Kompilieren unterschiedliche Implementierungen gelinkt werden.

Beispieldateien: 4_linker_objects/*

Erstellen von Objektdateien:
gcc -c timer_unix.c
gcc -c timer_win.c

Das Übersetzen der Anwendung schlägt fehl, da keine Implementierung angegeben ist. Diese kann entweder, wie zuvor, als Code-Datei oder als bereits übersetzte Objektdatei angegeben werden:
gcc -o main main.c /* Fehler */
gcc -o main_unix main.c timer_unix.o
gcc -o main_windows main.c timer_win.o 