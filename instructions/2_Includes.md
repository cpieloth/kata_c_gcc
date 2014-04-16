Includes
========

TODO (cpieloth): translate to english


/*** include ***/
Mit Hilfe von #include kann Code aus anderen Dateien (Header-Dateien, Code-Dateien) innerhalb des Programmes eingefügt werden. Es gibt zwei Schreibweisen:
1. #include <DATEI> Die Datei wird im Standardpfad vom Betriebssystem gesucht, falls nicht anders angegeben (-I).
2. #include "DATEI" Die Datei wird im lokalen Pfad der Code-Datei gesucht.

Beispieldateien: 2_include/*

Die Datei foo.c wird in die Datei main.c eingefügt:
gcc -E main.c > main_pp_1.c
meld main.c main_pp_1.c

Beide Code-Dateien können problemlos übersetzt und ausgeführt werden:
gcc -o main main.c
gcc -o main_pp_1 main_pp_1.c
./main
./main_pp_1

Bei mehreren includes können Probleme auftreten, da Deklarationen mehrmals im Code vorkommen können. Der Präprozessor verareitet die Dateien korrekt:
gcc -E main_2.c > main_pp_2.c
meld main_2.c main_pp_2.c

Jedoch schlägt das Übersetzen fehl:
gcc -o main_2 main_2.c
gcc -o main_pp_2 main_pp_2.c

Diese Problem kann mit den zuvor kennengelernten Makros gelöst werden und wird vorallem bei Header-Dateien genutzt.
gcc -E main_3.c > main_pp_3.c
meld main_3.c main_pp_3.c
gcc -o main_3 main_3.c
gcc -o main_pp_3 main_pp_3.c 
