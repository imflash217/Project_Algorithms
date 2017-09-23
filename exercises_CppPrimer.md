**`Q.[2.1]`** What are the differences between `int, long, long long`, and `short`? Between an `unsigned` and a `signed` type? Between a `float` and a `double`?

```
$ int, long, long long & short:
@ Each one of the above types have different storage capacities:
	int -------- 16 bits
	long ------- 32 bits
	long long--- 64 bits
	short ------ 16 bits
	The sizeof(short) = 16 bits for all compilers. 
	While the sizes of int(16-32 bits), long(32-64 bits) & long long (64-128 bits) varies depending on compilers.
------------------------------------	

$ unsigned and signed types:
@ unsigned types can represent only +ve values.
  signed types can represent both +ve & -ve values.
------------------------------------

$ float and double:
@ float ----- single precision ----- 6 significant digits (generally 32 bits)
  double ---- double precision ----- 10 significant digits (generally 64 bits)
   
   These are the minimum specified requirements, but the actual precision depends on the compilers too.  
```
**`Q.[2.2]`** To calculate a mortgage payment, what types would you use for the rate,
principal, and payment? Explain why you selected each type.

```
@ rate -------- float (32 bits)
  principal --- int (16 bits)
  payment ----- double (32 bits)

```

**`Q.[2.5]`** Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:
(a) ’a’, L’a’, "a", L"a"
(b) 10, 10u, 10L, 10uL, 012, 0xC
(c) 3.14, 3.14f, 3.14L
(d) 10, 10u, 10., 10e-2

```
$ 'a', L'a', "a", L"a" :
@ 'a' ------ a character literal --- type char
  L'a' ----- a character literal --- type wchar_t
  "a" ------ a string literal ------ type char (array of constant chars)
  L"a" ----- a string literal ------ type wchar_t (array of constant wchar_t)
-----------------------------

$ 10, 10u, 10L, 10uL, 012, 0xC :
@ 10 ------- int -------------- 16 bits
  10u ------ unsigned int ----- 16 bits
  10L ------ long ------------- 32 bits
  10uL ----- unsigned long ---- 32 bits
  012 ------ int -------------- octal literal 
  0xC ------ int -------------- hexadeciaml literal
----------------------------------------------

$ 3.14, 3.14f, 3.14L :
@ 3.14 ----- double (floating point literal are double by default)
  3.14f ---- float
  3.14L ---- long double
----------------------------------------------

$ 10, 10u, 10.0, 10e-2 :
@ 10 -------- int 
  10u ------- unsigned int
  10.0 ------ double (floating point literal are double by default)
  10e-2 ----- double (floating point literal are double by default)
```

**`Q. [2.6]`** What, if any, are the differences between the following definitions:
int month = 9, day = 7;
int month = 09, day = 07;

```
$ int month = 9, day = 7;
@ here month & day are integers for DECIMAL values of 9 & 7 respectively.

$ int month = 09, day = 07;
@ Here month & day are integers for OCTAL values of 09 & 07 respectively.
```

**`Q. [2.9]`**Explain the following definitions. For those that are illegal, explain
what’s wrong and how to correct it.
(a) std::cin >> int input_value; 
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99; 
(d) int i = 3.14;

```
$ std::cin >> int input_value;
@ CORRECT. Here, we are defining input_vale as int.

$ int i = {3.14};
@ WRONG. List initialization is illegal if their is a data loss. Here, we are assigning a floating point value to an int type.

$ double salary = wage = 9999.99;
@ WRONG. 'wage' is not defined; so 'salary = wage' assignment is wrong.

$ int  i = 3.14;
@ CORRECT. An int object can be assigned a floating point value; however its value will be truncated.
```

**`Q. [2.10]`** What are the initial values, if any, of each of the following variables?

```
$ 	std::string global_str;
	int global_int;
	int main()
	{
		int local_int;
		std::string local_str;
	}


@ global_str --> empty
  global_int = 0
  local_int --> uninitialized / undefined value
  local_str --> uninitialized / undefined value
```





































