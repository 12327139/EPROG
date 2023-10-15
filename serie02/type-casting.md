# Type-Casting
Unter Type-Casting versteht man die Umwandlung des Datentyps einer Variable in einen anderen.

Man unterscheidet zwischen explizitem und implizitem Type-Casting. Implizites Type-Casting kommt z.B. bei der Division eines Integers mit einem Double oder bei der Zuweisung des Wertes einer Variable durch eine andere mit anderem Datentyp. 

Implizites Type-Casting geschieht automatisch beim jeweiligen Anwendungsfall. Um explizit zu casten benötit man den type-casting operator "(type)". Man sollte explizites Type-Casting verwenden um einen Überblick zu behalten wo casts passieren um ein unvorhergesehenes Verhalten des Programmes zu verhindern oder um Bugs einfacher zu erkennen. 

Der Shell-Output des Codes ist der folgende:
```
erg1 = 3.600000
erg2 = 0.400000
erg3 = 0.000000
erg4 = 1
```

- erg1: x / y = 0 -> 0 + 3.6 = 3.6
- erg2: 2. / 5.4 = 0.4 (0.370... ungenau wg Gleitkomma)
- erg3: 3 / 5 = 0 (0.6 Kommastellen abgeschnitten)
- erg4: 3 / 2 = 1 (1.5 Kommastellen abgeschnitten)