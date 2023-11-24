# stdio.h
- printf(), scanf()

# Die ersten Sprachelemente
- Variablen, Deklaration, Initialisierung, Datentypen
- Arithmetische Operatoren
- Implizites/Explizites Type Casting

# Einfache Verzweigung
- Logische Operatoren 
- Logische Verkettung
- if-else

# Strukturierung mit Blöcken
- Lifetime und Scope
- Globale und lokale Variablen
- Blöcke/Scope

# Funktionen
- Funktionen
- Call by Value

# Kommentare
- einzeiliger Kommentar
- mehrzeiliger Kommentar

# Rekursionen
- Rekursive Funktionen
- Bisektionsverfahren

# Mathematische Funktionen
- math.h
- gcc ... -lm
- abs in stdlib.h

# Schleifen
- while
- ++, --
- do-while
- break

# Einfache Fehlerkontrolle
- gcc -c: nur Objekt-Code (Libraries ausgeschlossen)
- gcc -c -Wall: Alle Warnungen
- assert.h (assert(condition))

# Testen von Code
- Testen
- Toter Code
- in UE Tests erklären

# Daten speichern in Arrays
- Eindimensionale Arrays
- Zweidimensionale Arrays
- Arrays als Vektoren

# Zählschleifen
- for-Schleife
- break
- continue
- #define

# Aufwand von Algorithmen
- worst case!
- Big-O-Notation
- Binary search
- Aufwand
- Zeitmessung (time.h)
- Laufzeit

# Pointer
- Pointer
- Dereferenzieren
- &var, *ptr
- Call by Value/Reference
- Deklaration von Pointern mit "," vermeiden

# Elementare Datentypen
- char, int, float, double, pointer
- qualifier (nicht in EPROG): signed, unsigned, long, short
- functions: call by value uebergeben, return value nur void oder elementar
- "In C gibt es keine Arrays", int array[N] legt pointer an
- Pointerarithmetik
- sizeof

# Dynamische Speicherverwaltung
- stdlib.h: malloc, free, realloc, NULL
- malloc(size) allokiert uninitialisierten Speicher, returns NULL bei Fehler bei der allokierung
- free(pointer) gibt speicher frei (Wichtig: Pointer auf NULL setzen)
- realloc(pointer, newsize) allokiert bereits allokierten speicher mit einer neuen groesse, bleibt pointer bei Fehler
- Wichtig: Base Pointer (return von malloc, calloc, ...) nicht veraendern, auf NULL checken, SPEICHER FREIGEBEN, 

# Anwendung fuer Pointer: Eine Vektor Bibilothek
- gcc file1.c file2.c ... (erstellt 1 executable)
- Preprocessor (#include, #define)
- Bibliotheken = vorkompilierter Code
- gcc -c file.c erzeugt Objekt-Code
- Header-File headerfile.h
- #ifndef NAME, #define NAME, #include, Deklarationen, #endif
- #include<...> (Standardverzeichnis), #include "..." (Angabe Verzeichnis)
- gcc -c headerfile.c -> headerfile.o

# Strings
- char-Arrays
- statisch, dynamisch
- sprintf, sscanf (in stdio.h)
- atof, atoi (stdlib.h)
- strchr, memchr, strcmp, memcmp, strcpy, memcpy, strlen (string.h)

# Funktionspointer
- Funktionspointer ```<return value>(*name)(<input>)```
- Beim Aufruf kein dereferenzieren notwendig