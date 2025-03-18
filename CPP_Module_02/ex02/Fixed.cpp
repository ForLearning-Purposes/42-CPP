#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : fixedPointValue(0) {}

Fixed::Fixed(const int value) : fixedPointValue(0) {
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value) : fixedPointValue(0) {
    this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const Fixed& copy) { *this = copy; }

Fixed& Fixed::operator=(const Fixed& copy) {
    if (&copy == this) {
        return *this;
       }
    else
        this->fixedPointValue = copy.getRawBits();
    return *this;
}
//*****************************************************************//

//****Operators****//
//6 comparison operators: >, <, >=, <=, ==, !=
bool Fixed::operator>(const Fixed& fix) const {
    return (this->fixedPointValue > fix.getRawBits());
}

bool Fixed::operator<(const Fixed& fix) const {
    return (this->fixedPointValue < fix.getRawBits());
}

bool Fixed::operator>=(const Fixed& fix) const {
    return (this->fixedPointValue >= fix.getRawBits());
}

bool Fixed::operator<=(const Fixed& fix) const {
    return (this->fixedPointValue <= fix.getRawBits());
}

bool Fixed::operator==(const Fixed& fix) const {
    return (this->fixedPointValue == fix.getRawBits());
}

bool Fixed::operator!=(const Fixed& fix) const {
    return (this->fixedPointValue != fix.getRawBits());
}

//4 arithmetic operators: +, -, *, /
Fixed Fixed::operator+(const Fixed& fix) const {
    return Fixed(this->toFloat() + fix.toFloat());
}

Fixed Fixed::operator-(const Fixed& fix) const {
    return Fixed(this->toFloat() - fix.toFloat());
}

Fixed Fixed::operator*(const Fixed& fix) const {
    return Fixed(this->toFloat() * fix.toFloat());
}

Fixed Fixed::operator/(const Fixed& fix) const {
    return Fixed(this->toFloat() / fix.toFloat());
}

//4 increment/decrement operators: ++x, x++, --x, x--:

// Pre-increment (++x): Increase by 1
Fixed& Fixed::operator++(void) {
    this->fixedPointValue++; // this->fixedPointValue += (1 << this->fractionalBits);  // Increase by 256 (equivalent to 1.0 in fixed-point) which means 1 in real-world value
    return *this;
}
/*
Info:
We're not adding 1 in real-world value,
we're adding 1 in the raw integer representation,
which corresponds to 1 / 256 (0.00390625 in decimal).
*/

// Post-increment (x++): Increase but return old value
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->fixedPointValue++;
    return temp;
}

// Pre-decrement (--x): Decrease by 1
Fixed& Fixed::operator--(void) {
    this->fixedPointValue--;
    return *this;
}

// Post-decrement (x--): Decrease but return old value
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->fixedPointValue--;
    return temp;
}
//*****************************************************************//

//****Overloaded static functions****//
/*
min(Fixed&, Fixed&) → Returns a reference to the smaller of the two Fixed objects.
min(const Fixed&, const Fixed&) → Same as (1), but works with const references.
max(Fixed&, Fixed&) → Returns a reference to the larger of the two Fixed objects.
max(const Fixed&, const Fixed&) → Same as (3), but works with const references.
*/

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a <= b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a <= b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a >= b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a >= b) ? a : b;
}
//*****************************************************************//

//****Functions****//
float Fixed::toFloat( void ) const {
    return (float)this->fixedPointValue / (float)(1 << this->fractionalBits);
}

int Fixed::toInt( void ) const {
    return this->fixedPointValue >> this->fractionalBits;
}

int Fixed::getRawBits( void ) const {
    return this->fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    this->fixedPointValue = raw;
}
//*****************************************************************//

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
    output << fixed.toFloat(); //Operator za umetanje (Stream Insertion Operator)
    return (output);
}

/*
`std::ostream &`

- `std::ostream`: Ovo je klasa iz standardne biblioteke C++ koja se koristi za izlazne tokove, kao što su konzola ili fajlovi.
- `&`: Ovo označava referencu. U ovom slučaju, funkcija vraća referencu na `std::ostream` objekat. Korišćenje reference omogućava da se izbegne kopiranje objekta, što može biti efikasnije.

`operator<<`

- **`operator<<`**: Ovo je preopterećenje operatora `<<`. U C++,
    operatori kao što su `+`, `-`, `*`, `<<`, itd. mogu biti preopterećeni
    za rad sa korisnički definisanim tipovima podataka. U ovom slučaju,
    preopterećujemo operator `<<` da bismo omogućili ispis objekta tipa 
*/

/*
Naravno! U C++ jeziku, simboli `<<` i `>>` imaju različita značenja u zavisnosti od konteksta u kojem se koriste.

### `<<` Operator
1. **Operator za pomeranje ulevo (Bitwise Left Shift)**:
   - Kada se koristi sa celobrojnim tipovima, `<<` pomera bitove broja ulevo za određeni broj pozicija.
   - Na primer:
     ```cpp
     int x = 5; // 00000101 u binarnom
     int y = x << 1; // 00001010 u binarnom, što je 10 u decimalnom
     ```

2. **Operator za umetanje (Stream Insertion Operator)**:
   - Kada se koristi sa `std::ostream` objektima (kao što je `std::cout`), `<<` se koristi za umetanje podataka u tok (stream).
   - Na primer:
     ```cpp
     std::cout << "Hello, World!" << std::endl;
     ```

### `>>` Operator
1. **Operator za pomeranje udesno (Bitwise Right Shift)**:
   - Kada se koristi sa celobrojnim tipovima, `>>` pomera bitove broja udesno za određeni broj pozicija.
   - Na primer:
     ```cpp
     int x = 10; // 00001010 u binarnom
     int y = x >> 1; // 00000101 u binarnom, što je 5 u decimalnom
     ```

2. **Operator za izdvajanje (Stream Extraction Operator)**:
   - Kada se koristi sa `std::istream` objektima (kao što je `std::cin`), `>>` se koristi za izdvajanje podataka iz toka (stream).
   - Na primer:
     ```cpp
     int number;
     std::cin >> number;
     ```

### Vaš Kod
U vašem kodu:
```cpp
output << fixed.toFloat();
```
`<<` se koristi kao operator za umetanje (stream insertion operator) da bi se rezultat 

fixed.toFloat()

funkcije umetnuo u 

output

tok (stream).

### Funkcija 

toFloat

Funkcija 

toFloat
konvertuje fiksnu tačku (fixed-point) vrednost u `float` vrednost. Evo kako funkcija radi:
```cpp
float Fixed::toFloat( void ) const {
    return (float)this->fixedPointValue / (float)(1 << this->fractionalBits);
}
```
- `this->fixedPointValue` je celobrojna vrednost koja predstavlja fiksnu tačku.
- `this->fractionalBits` je broj bitova koji se koriste za frakcioni deo.
- `(1 << this->fractionalBits)` pomera bit `1` ulevo za `fractionalBits` pozicija, što efektivno daje vrednost `2^fractionalBits`.
- Konačno, celobrojna vrednost se deli sa `2^fractionalBits` da bi se dobila `float` vrednost.
*/