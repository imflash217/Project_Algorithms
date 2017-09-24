**`Q.[2.1]`** What are the differences between `int, long, long long`, and `short`? Between an `unsigned` and a `signed` type? Between a `float` and a `double`?

```c++
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
```c++
(a) ’a’, L’a’, "a", L"a"
(b) 10, 10u, 10L, 10uL, 012, 0xC
(c) 3.14, 3.14f, 3.14L
(d) 10, 10u, 10., 10e-2
```
```c++
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
```c++
int month = 9, day = 7;
int month = 09, day = 07;
```
```c++
$ int month = 9, day = 7;
@ here month & day are integers for DECIMAL values of 9 & 7 respectively.

$ int month = 09, day = 07;
@ Here month & day are integers for OCTAL values of 09 & 07 respectively.
```

**`Q. [2.9]`**Explain the following definitions. For those that are illegal, explain
what’s wrong and how to correct it.
```c++
(a) std::cin >> int input_value; 
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99; 
(d) int i = 3.14;
```
```c++
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

```c++
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

**`Q. [2.26]`** Which of the following are legal? For those that are illegal, explain why.
```c++
(a) const int buf; 
(b) int cnt = 0;
(c) const int sz = cnt; 
(d) ++cnt; ++sz;
```
```c++
$ const int buf;
  int cnt = 0;
  const int sz = cnt;
  ++cnt; ++sz;
 
@ const int buf;	// ERROR. const variables must be initialized
  int cnt = 0;		// OK. 
  const int sz = cnt;	// OK. const variable 'sz' is initialized to integer 'cnt'
  ++cnt;		// OK. cnt is an normal integer
  ++sz;			// ERROR. const variables cannot be changed.
```

**`Q. [2.30]`** For each of the following declarations indicate whether the object being declared has top-level or low-level const: 
```c++
const int v2 = 0; 
int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```
```c++
$ const int v2 = 0;
@ v2 ---- top-level const
  v2 is a variable of const type, its value can not be changed ever.
  
$ int v1 = v2;
@ v1 ---- neither
  v2 has top-level const and top-level const are ignored while copying. So correct code
  
$ int *p1 = &v1, &r1 = v1;
@ p1 ---- neither
  r1 ---- neither
  
$ const int *p2 = &v2, *const p3 = &i, &r2 = v2;
@ p1 ---- low-level const
  p3 ---- low-level const and top-level const
  r2 ---- low-level const
  
//-------------------------------------

r1 = v2;	// ERROR
p1 = p2;	// ERROR
p1 = p3		// ERROR
p2 = p1;	// ERROR
p2 = p3;	// OK

```


































