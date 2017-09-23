# `C++`:
* In some languages like `Smalltalk` & `Python`, typechecking is done `@ Runtime`.

* `C++` is a **staticaly-typed language**, and type-checking is done **`@ Compile time`**.

Perhaps, the most important feature in `C++` is `CLASS`, which allows users to define their own type.

* **`C++ built-in primitive Types`**:
	
	* **`Arithmetic Types`**:
		* `Integral types`: Character & Boolean types
		* `Floating-point types`: 	
	* **`void`**: 
	
```
C++ Arithmetic Types:
							
1. bool -------- Boolean ------------- NA

2. char -------- Character ----------- 8 bits
3. wchar_t ----- Wide Character ------ 16 bits
4. wchar16_t --- Unicode Character --- 16 bits
5. wchar32_t --- Unicode Character --- 32 bits

6. short ------- Short Integer ------- 16 bits
7. int --------- Integer ------------- 16 bits
8. long -------- Long Integer -------- 32 bits
9. long long --- Long Integer -------- 64 bits

10. float ---------- Single precision floating point ----- 6 significant digits (generally 32 bits)
11. double --------- Double precision floating point ----- 10 significant digits (generally 64 bits)
12. long double ---- Extended precision floating point --- 10 significant digits

These are the minimum required precision of float, double, long double. 
But the actual bits depend on the compilers.
```
* A `char` is guaranteed to be big enough to hold numeric values of the machine's basic character set. So, `char` is same size as machine's single `byte`.

* Except for `bool` and `extended character types`; the `integral types` may be either **`Signed or Unsigned`**.
* By default, `int, short, long, long long` are **`signed`**.
* Use `double` for floating-point computations
* `float` usually does not have enough precision & 
* Cost of double-precision calculation v/s single-precision is negligible. 
Infact in some machines, double-precision calculations are faster.
* If we assign an out-of-range value for an object of **`unsigned`** type, the result is the remainder of value modulo the number of values the target type can hold.
* If we assigned an out-of-range value to an object of **`signed`** type, the result is **undefined**. The program might appear to work or crash or take garbage values.
* If we used both `unsigned` and `int` in an arithmetic operation, then the `int` is implictly converted to `unsigned`.

```
unsigned u = 10;
int i = -42;
std::cout << i + i << endl;	// prints -84
std::cout << u + i << endl;	// if 32 bit ints; prints 4294967264
```

* Integer `literals` that begin with `0` are called `octal`.
* Integer `literals` that begin with `0x` or `0X` are called `Hexadecimal`.
```
20	// decimal
024	// octal
0x43	// hexadecimal
0X43	// hexadecimal
```
* By default, `deciaml literals are signed`; while `octal` and `hexadecimal` literals can be either signed or unsigned.
* **There are no literals of type `short`**.

* **`Decimal` literals**:
	* `int`
	* `long`
	* `long long`
	
* **`Octal` & `Hexadecimal` literals**:
	* `int`, `unsigned int`
	* `long`, `unsigned long`
	* `long long`, `unsigned long long`


* By default, the `floating-point literal` has type `double`.
```
'a' ----- a character literal
"a" ----- a string literal
```
* in C++, the compiler appends a `'\0'` to every `string literal`.

```cpp
Escape Sequences in C++ :

newline	--------- \n	double quote ------ \"
vertical tab ---- \v	single quote ------ \'
horizontal tab -- \h	question mark ----- \?
backslash ------- \\	formfeed ---------- \f
backspace ------- \b	carriage return --- \r
```
* `true` and `false` are **bool literals**.
* `nullptr` is a **pointer literal**.
* C++ programers tedn to refer to `variables` as **variables** or **objects** interchangeably.

* **Default Variable Initialization** :
	* The value of an object of built-in type that is not explicitly initialized depends on **where it is defined**.
	* Variables defined **outside a function body** are initialized to **`zero`**.
	* Variables defined **inside a function body** are **`unitialized`**.
	* Uninitialized objects of built-in type defined inside a function body have undefined value.
	

	































	
	