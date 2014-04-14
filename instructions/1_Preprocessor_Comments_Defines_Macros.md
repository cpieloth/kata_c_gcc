Preprocessor: Comments, Macros & Defines
========================================

TODO (cpieloth): translate to english

gcc -E main.c > main.pp.c

Präprozessor
------------

Der Präprozessor wird automatisch vor der Übersetzung des Codes ausgeführt. Vereinfacht ausgedrückt nimmt er eine Textersetzung vor:
	* Entfernen von Kommentaren
	* Einfügen von Code aus anderen Dateien (#include)
	* Ersetzen von Makros (#define)
	* Auswerten von Bedingungen (#ifdef, #endif, ...)


Makro / define
--------------

Als Makro wird ein kleines Programmstück bezeichnet, welches durch den Präprozessor durch ein größeres Programmstück ersetzt wird. Zum Beispiel können so Methodenaufrufe verkürzt oder Konstanten gesetzt werden. Im Zusammenspiel mit Bedingungen können auch Code-Stellen während der Übersetzung ausgelassen werden.

Beispieldatei: 1_define/main.c

Um zu sehen wie der Präprozessor Makros ersetzt, wird folgender Befehl ausgeführt:
gcc -E main.c > main_pp_1.c
Anschließend kann der alte und der neue Code mit meld verglichen werden:
meld main.c main_pp_1.c &

Der Präprozessor hat bis auf DEBUG("some output"); alles ersetzt. Da DEBUG_ON nicht definiert ist, ist es auch nicht durch printf() ersetzt.

Ein Makro kann dem Compiler beim Übersetzen mitgegeben werden:
gcc -E -DDEBUG_ON main.c > main_pp_2.c
meld main.c main_pp_2.c & 