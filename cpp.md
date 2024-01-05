# C++
- g++ file.cpp -o output
- Bibliothek: iostream
- :: Scope-Operator (Namespace)
- << Übergabe-Operator
- std::cout wie printf (std::cout << "Hello")
- std::endl (nicht ganz) wie \n (loescht auch speicher)
- using std::cout = std::cout -> cout
- using namespace std (in manchen Faellen vermeiden, top level oder in Fkt)
- Shell-Input int main(int argc, char* argv[])
- std::cin wie scanf (std::cin >> x)

# Was ist neu in C++
- bool, true, false
- Fkt default params (void f(int x, int y = 3);)
- fkt overloading
- Klassen und Objekte, Vererbung
- Zugriffskontrolle (private, public, protected)
- Methoden (z.b. void Triangle::getArea() {...}), können auch direkt implementiert werden
- struct = class, alles public
- std::string Klasse, string != char*, Methoden
- try, throw, catch
- std::abort() 
- this->attr 
- constructor, destructor
- method shorthand 
- Class nesting
- Templates
- C++ Standardcontainer list, queue, stack, deque, set, multiset, map, multimap, vector
- vector Template (#include<vector>)

- Vector-Klasse
- Matrix-Klasse
- Referenzen &
 - gleicher datentyp, def und init gleichzeitig
 - ermoeglicht "echtes" call by reference
 - ref als return type (nur bei methoden sinnvoll) 
- foreach, iteratoren
- const 
