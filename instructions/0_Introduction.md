Introduction
============

TODO (cpieloth): translate to english

Dieser Beitrag richtet sich an Personen, die bereits Grundkenntnissen in der Programmiersprache C besitzen, jedoch wenig Erfahrung mit dem Compiler GCC und der Strukturierung von C-Code haben. Um den Textumfang gering zu halten, wird kein Code aufgelistet. Dieser ist als ZIP-Archiv beigefügt und sollte zusammen mit allen Anweisung parallel zum Lesen ausgeführt werden. Vor der Ausführung der Anweisungen sollte der zugehörige Code selbständig gelesen und verstanden werden.
Dieser kleine Kurs wurde auf Ubuntu 10.04 mit dem GNU C-Compiler (Version 4.4.4) und dem Diff-Betrachter meld (Version 1.3.2) erstellt. Die Code-Beispiele wurden bewusst sehr klein gehalten, um Raum für eigene Erkundungen zulassen.


Ablauf beim Kompilieren
-----------------------

Der vereinfachte Ablauf beim Kompilieren besteht aus folgenden Schritten:
	1. Einlesen der Code-Datei
	2. Verarbeitung des Codes durch den Präprozessor
	3. Übersetzen des Codes durch den Compiler
	4. ggf. Erzeugen von Objektdateien
	5. ggf. Binden der Objektdateien vom Linker zu einem lauffähigen Programm