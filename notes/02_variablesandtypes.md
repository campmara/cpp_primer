# Variables and Basic Types

Types specify what certain groups of data mean and what operations we can perform on that data.

There are primitive types (characters, integers, floating point numbers, etc.), library-defined types, as well as user-defined types. This chapter will cover the built-in types and shows how C++ can support more complicated types.

## Primitive Types

The built-in types in C++ include arithmetic types as well as the `void` type. `void` has no value and no meaning, and you'll see it used as a return type in functions that don't need to return things, as well as with void pointers.

There are two categories of arithmetic types: *integral types* (including character and boolean types), and *floating-point* types.

Size values for arithmetic vary from compiler to compiler. The minimum sizes for these types, however, are as follows:

| type       | meaning                          | minimum bit size     |
|------------|----------------------------------|----------------------|
|bool        |boolean                           |N/A                   |
|char        |character                         |8 bits                |
|wchar_t     |wide character                    |16 bits               |
|char16_t    |unicode character                 |16 bits               |
|char32_t    |unicode character                 |32 bits               |
|short       |short integer                     |16 bits               |
|int         |integer                           |16 bits               |
|long        |long integer                      |32 bits               |
|long long   |long integer                      |64 bits               |
|float       |single-precision floating-point   |6 significant digits  |
|double      |double-precision floating-point   |10 significant digits |
|long double |extended-precision floating-point |10 significant digits |

A `bool` is either `true` or `false`.

A `char` is usually the same size as a machine byte, and is meant to represent the machine's basic character set. The other character types are used for internationalization and extended character sets. `wchar_t` is guaranteed to be large enough to hold any character in the machine's extended character set.

C++ guarantees that an `int` will be at least as large as a `short`, `long` at least as large as an `int`, and that `long long` will be at least as large as `long`.

### At The Machine Level

All of the values in our programs will be stored by the computer as a sequence of bits, each holding a 0 or a 1 (binary). Memory mostly operates with chunks of bits of sizes that are powers of 2. The smallest chunk of addressable memory is called a `byte`. The basic unit of storage, usually a small number of bytes, is known as a "word". 

On most machines:
* A `byte` is 8 bits.
* A `word` is 32 or 64 bits (or 4 / 8 bytes).

### On Floating-Point Types

Most compilers provide more digit precision than the minimum. Typically, `floats` are represented as 32-bit values (1 word), `doubles` are 64-bits (2 words), and `long doubles` are 96 or 128-bit values (3 or 4 words). Typically floats yield 7 significant digits, doubles yield 16, and long doubles tend to vary a lot!

### Signed or Unsigned

Except for bool and the extended character types, integral types are either *signed* or *unsigned*. This affects whether or not the value can be negative, as well as the range of numbers that value can be.

`unsigned` on its own means the same thing as `unsigned int`.

Unlike the integer types, `char`, `signed char`, and `unsigned char` are three distinct things. `char` usually will mean `unsigned char`, but this depended from compiler to compiler.

What type to use?
* Use an unsigned value when you know the value cannot be negative.
* Use int for integer arithmetic. `short` is too small and `long` often has the same size as int. If the data values you are using are larger than the minimum guaranteed size of an int, then use `long long`.
* Don't use `char` or `bool` in arithmetic expressions. Only use them to hold character or truth values. If you really need a tiny integer in an arithmetic expression, be sure to specify `signed` or `unsigned` chars since a normal `char` could mean either dependng on the hardware.
* Use `double` for floating point calculations. It offers better precision and on many machines, doubles are faster than floats. Don't really bother with the `long double` though. You usually won't need that much precision and working with that will incur a heavy runtime cost.

## Type Conversions

You can convert values from one type to another. Sometimes this happens automatically when we use an object of one type where another is expected.

```c++
bool b = 42;   // b is true.
int i = b;     // i has value 1.
i = 3.14;      // i has value 3.
double pi = i; // pi has value 3.0.
unsigned char c = -1; // assuming 8 bit chars, c has value 255
signed char c2 = 256; // assuming 8 bit chars, the value of c2 is undefined. (weird...I thought it would wrap around!)
```

When we assign one arithmetic type to another, what happens depends on the range of values that the types permit:
* With bools, 0 is false and any other value is true.
* When a bool is assigned to an arithmetic type, the value is 0 if false and 1 if true.
* When a floating point value is assigned to an integral type, the value is truncated (the part before the decimal point is stored).
* When an integral type is assigned to a floating point value, the fractional part is 0. Precision may be lost if the integer has more bits than the float can accomodate.
* 