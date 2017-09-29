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

```c++
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
	
* **`Declaration`**: It makes a name known to the program.
* **`Definition`** : It creates an associated entity. It provides name, type & storage and may also assign some initial value to the entity.
* Any Declaration that has an initializer is a definition.
* A Declaration can involve only a single base type.

* **`extern`** :  To obtain a declaration that is not definition we use the keyword `extern`.
	* An `extern` that has an initializer is a Definition.
	* Its an ERROR to privide an initializer on an `extern` **inside a function**.
```c++
extern int i; 		 // it declares but doesnot define i.
int j; 			 // it declares & defines j. 

extern int k = 1234; 	 // k = 1234; initlization overrides the extern keyword.

//---------------------------------
public void functionA(.....){
	......
	extern double my_double = 2.17;		// ERROR; initialization not allowed on an extern inside a function
	......
}
//---------------------------------
```

* Variables must be defined exactly once but can be declared multiple times.
* To use the same variable in multiple files, we must **declare** the variable in all files but **define** that variable in one-and-only-one file.

* **`IDENTIFIERS`**:
	* Can be composed of `letters`, `digits`, & `undersore character`.
	* Must begin with either `letter` or `underscore`.
	* User-defined identifiers cannot contain two `underscore` characters.
	* User-defined identifiers cannot begin with `underscore` followed by an UPPERCASE letter.
	* Identifiers defined **outside a function** may not begin with `underscore`.
	

```
C++ Keywords:

alignas		else		public			unsigned
alignof		enum		register		using
asm		explicit	reinterpret_cast	
auto		export		return			virtual
bool		extern		short			void
break		false		signed			volatile
case		float		sizeof			wchar_t
catch		for		static			while
char		friend		static_assert
char16_t	goto		static_cast
char32_t	if		struct
class		inline		switch
const		int		template
constexpr	long		this
const_cast	mutable		thread_local
continue	namespace	throw
decltype	new		true
default		noexcept	try
delete		nullptr		typedef
do		operator	typeid
double		private		typename
dynamic_cast	protected	union

//----------------------------------------------

C++ Alternative operator names:

and		not
and_eq		not_eq
bitand		or
bitor		or_eq
compl		xor
not		xor_eq

```
* The global scope has no name. Hence when the scope operator(`::`) has an empty lefthand side, it is a request to fetch the name on the right-hand side from the global scope.

* **COMPOUND TYPES**:
	* References
		* `rvalue`
		* `lvalue`
	* Pointers

* **Refrences**: A reference is NOT an object. It's just another name for an already existing object.

	When we define a refernce, instead of copying the initializer's value, we **bind** the refernce to its initializer.

	Once initialized, a refernce remains bound to its initial object.
	There is no way to rebind a refernce to refer to another object.
	As there is no way to rebind a refernce, **`references` must be initialized**.

```c++
int ival = 217;
int &refVal = ival;	// refVal refers to (is another name for) ival
int &refVal2;		// ERROR. references must be initialized.

// REFERENCE IS JUST AN ALIAS

// After a reference is defined, all operations on that reference are actually operations on the object to which it is bound

refVal = 2;	// assigns 2 to the object to which refVal is bound i.e. now, ival = 2;
int ii = refVal;	// same as ii = ival;

int &refVal3 = refVal;	// refVal3 refers to the object to which refVal is bound i.e. ival
int j = refVal3;	// initializes j to same value as ival

```
* The type of refernce and object must be the same.
* A plain refernce can be bound only to an `object`; not to a `literal` or `an expresion`.
* But, we can bind a `const reference` to a `literal`.

```c++
int &refVal4 = 10;	// ERROR. Reference can't be bount to a literal (10)
const int &ref = 217;	// OK: We can bind a const reference to a literal (217)
double m_dval = 3.14;
int &refVal5 = m_dval;	// ERROR. Reference and object types must match. initializer must be an int type
```

* Because we can't change the value of the `const` object after we create it must be initialized.

```c++
const int i =  get_size();	// OK. initialized at runtime
const int j = 32;		// OK. initialized at compile time
const int k;			// ERROR. k is uninitialized const
```
* To define a single instance of `const` variable that is accessible to other files, we use the `extern` keyword on both its **definition** and **declaration(s)**.
```c++
// file1.cpp 
// define and initializes a const, extern keyword specifies that bufSize is accessible to other files
extern const int bufSize = func();

// file2.cpp 
// here extern specifies that the definition of bufSize is not local its somewhere else
extern const int bufSize;	// same bufSize as defined in file1.cpp
```

* Unlike ordinary references, a **reference to `const`** cannot be used to change the object's value.

```c++
const int bufSize = 217;	// OK.
const int &ref1 = bufSize;	// OK. ref1 is a refernce to const variable bufSize
int &ref2 = bufSize		// ERROR. non-const reference can't refer to a const variable

ref1 = 2491;			// ERROR. refrence to const can't change the object's value
```

* Binding a `reference to const` to a non-`const` object is LEGAL; but the refernce can't be used to change the value of the non-`const` object.

```c++
int i = 217;

int &ref1 = i;		// ref1 is bound to 'i'. ref1 can be used to change the value of 'i'
const int &ref2 = i;	// ref2 is bound to 'i'. BUT ref2 can be used to change value of i
			// b'coz ref2 is a 'refernce to const'

ref1 = 2491;		// OK. ref1 is not const. now, "i = 2491"
ref2 = 1020;		// ERROR. ref2 is a 'refernce to const'. still "i = 2491"
```

* We can define **pointers** that point to either `const` or non-`const`.
* A **pointer to `const`** may not be used to change the object to which it points.
* We may store the address of a `const` object only in a **pointer to `const`**.
* Dereferncing a pointer gives the object to which the pointer points.

```c++
const double pi = 3.14;		// OK. pi is a const double; its value can't be changed
double *ptr = &pi;		// ERROR. non-const pointer(ptr) can't point to a const object (pi)
const double *cptr = &pi;	// OK. only const pointers can store the address of const object

*cptr = 2.17;			// ERROR. cant assign to *cptr
```

* **EXCEPTION**: We can use a **pointer to `const`** to point to a non-`const` object but, can't change the object's value through the pointer.

```c++
double pi = 3.14;	// OK. non-const object
const double *cptr = &pi;	// OK. but cant use cptr to change the value of pi
```
* Like **refernce to `const`**, a **pointer to `const`** says nothing about whether the object to which it points is a `const` or not.

* Unlike references, **pointers** are `object`. So, pointers can be `const` too.
* **`const` pointers**: Like any other `const` objects, a `const pointer` must be initialized & once initialized its value cannot be changed.

```c++
int errNumb = 0;
int *const pErr = &errNumb;	// pErr is a const pointer. pErr will always point to errNumb
const double pi = 3.14;
const double *const pip = &pi;	// pip is a const pointer to a const object
				// neither the value of the object addressed by 'pip' nor the address stored in 'pip' can be changed
				
*pip = 2.17;			// ERROR. pip points to a const object

if (*pErr){			// if the object to which pErr points (i.e. errNumb) is non-zero
	.....
	*pErr = 0;		// OK
	.....
}

```
* **`top-level` & `low-level` `const`**:
* `top-level const`: Used to indicate that the pointer inself is a `const`.
* `low-level const`: When a pointer refers to a `const` object, we refer to that `const` as a low-level `const`.
* The distinction b/w **top-level** and **low-level** matters when we copy an object. 
* When we copy an object, top-level `const` are ignored.
* Wen we copy an object both objects must have same low-level `const` qualifications. **Low-level `const` are never ignored.**

```c++
int i = 0;
int *const p1 = &i;		// const is top-level
const int ci = 42;		// const is top-level
const int *p2 = &ci;		// const is low-level
const int *const p3 = p2;	// rightmost const is top-level; leftmost const is low-level
const int &r = ci;		// const is low-level

//----------------------------------------------------------

i = ci;		// OK copying the value of ci; top-level const in 'ci' ignored
p2 = p3;	// OK. pointed-to type matches; top-level const in 'ci' ignored

//----------------------------------

// When we copy p3 we can ignore its top-level const but not the fact that it points to a const type
// Thus, we can't use p3 to initialize p4 (which points to plain int)

int *p4 = p3;	// ERROR: p3 has a low-level const but p4 doesn't

//-------------------
p2 = p3;	// OK: both p2 and p3 points to the object of same const type

p2 = &i;	// OK. we can convert int* to const int*
int &r = ci;	// ERROR: 'ci' is a const; but r doesn't refer to const
const int &r2 = i;	// OK: can bind const int refernce to a plain int
```

* **`const ` expressions**: 
	* An expression whose value cannot be chnaged.
	* It value can be evaluated at compile time.
	* A `const` object that is initialized from a `const` expression is also a `const` expression
	
* **Variables defined inside a function ordinarily are not stored at fixed address**. Hence we can not use `constexpr` pointers to point to such variables.

* The address of any variable defined outside any function is a constant expression. So we can use `constexpr` pointers to point to such objects.

* When we specify a pointer in a `constexpr` declaration, the `constexpr` specifier applies to the pointer not the type to which the pointer points.
```c++
const int *p = nullptr;		// p is a pointer to a const int
constexpr int *q = nullptr;	// q is a const pointer to int
```
* `constexpr` imposes a top-level `const` on the objects it defines
```c++
constexpr int *np = nullptr;		// np is a const pointer to int that is a null
int j = 0;
constexpr int i = 217;			// i is a const int

// i & j must be defined outside any function
constexpr const int *p1 = &i;		// p1 is a const pointer to a const int i
constexpr int *p2 = &j;			// p2 is a const pointer to an int j
```
* A **type alias** is a name that is a synonym for another type.
* **Type alias** can be defined in the following two ways:
	* **`typedef`** keyword
	* **`using`** keyword
```c++
typedef double wages;		// wages is a synonym for double
typedef wages base, *p;		// base is synonym for double, p is double*

using SI = Sales_Item;		// SI is a synonym for Sales_Item

// A type alias is a type name and can appear wherever a type name can appear
wages hourly, weekly;		// same as "double hourly, weekly"
SI item;			// same as "Sales_Item item;
```
```c++
typedef char *pstring;		// pstring is "pointer to char" type
const pstring cstr = 0;		// cstr is a const of type 'pstring' i.e cstr a 'const pointer to a char'
const pstring *ps;		// ps is pointer that points to a const pstring (i.e ps is a pointer that points to a constant 'pointer to char')

//-----------------------

const char *cstr = 0;		// ERROR: wrong interpretation of "const pastring cstr = 0"
```
* **ERROR** to interpret a declaration that uses a type alias by conceptually replacing the alias with its corresponding type.

* **`auto`** ordinarily ignore top-level `const`. If we want the deduced type to have top-level `const` we must say so explicitly.

* When we define several variables in the same statement, it's important to remeber that `reference` or `pointer` is part of a particular declarator not part of the base type of declaration.

```c++
int i = 0;
const int ci =i;		// OK: ci has "top-level const"
auto k = ci, &l = i;		// OK: k is a "int" (top-level const are ignored while copying in auto), l is "int&"
auto &m = ci, *p = &ci		// OK: m is a "const int", p is a pointer to a "const int"

auto &n = i, *p2 = &ci;		// ERROR: type deduced from 'i' is 'int', but type deduced from '&ci' is 'const int'
```

* **`decltype`**:
	* `decltype` is the _only_ context in which the variable defined as `reference` is not treated as a synonym for the object to which it refers.
	* The compiler analyzes the expression to determine the type but doesnot evaluate the expression.
	* If `r` is a refernce then `decltype(r)` is a refernce type too.
	* `dereference operator(*)` is an example of an expression for which `decltype` returns a `reference`.
	* Enclosing the name of the variable in a paranthesis affects the type returned by `decltype`.
	* When we apply the `decltype` to a variable without any paranthesis, we get the type of the variable. 
	* If we wrap the variable's name in one or more paranthesis, the compiler will evaluate the operand as an expression.
	A variable is an expression if it can be the left-hand side of an assignment.
	Hence, in such cases `decltype` returs a `reference`.
	* **`decltype` of a paranthesized variable is always a reference**.

```c++
decltype(f()) sum = a;		// sum has a type that is returned by f()

const int ci = 0, &cj = ci;
decltype(ci) x = 0;		// OK: x has type "const int"
decltype(cj) y = x;		// OK: y is refernce of type "const int&" and is bound to x (a "const int")
decltype(cj) z;			// ERROR: z is a refernce of type "const int&" and all refernces must be initialized

// decltype of a paranthesized variable is always a refernce
decltype((i)) d;		// ERROR: d has a type "int&" and hence must be initialized
decltype(i) e;			// OK: e is an (uninitialized) "int"
```
```c++
decltype((variable)) --------> reference (always)
decltype(variable) ----------> reference only if "variable is a reference"
```

* We can define a class inside a function but such classes have limited functionalities, hence classes are ordinarily not defined inside functions.

* There can be only one definition of **class** in any given source file.
* If we use a class in several different files, the class' definition must be the same.
* In order to make sure that the class definition is same in each file, classes are usually defined in **`header files`**.
* Typically classes are stored in headers whose name derives from the name of the class (like, `string` class is defined in `string.h` header file......etc)
* Whenever a header is updated, the source files that use the headers must be recompiled to get the new or changed declarations.

* The **Preprocessor** is a program that runs before the Compiler & changes the source text of our program.
* **Preprocessor variables** are used to guard against multiple inclusions.
* The **`#define`** directive takes a nake and define that as a **preprocessor** variable.
* The preporcessor variables can have states: **`defined`** or **`not defined`**.
	* **`#ifdef`** is `true` if the preprocessor variable is defined.
	* **`#ifndef`** is `true` if the preprocessor variable is not defined.
	If the test is true then everything following `#ifdef` or `#ifndef` is processed upto the matching `#endif`
* Preprocessor variables DO NOT respect C++ scoping rules.
* Preprocessor variables are usually written in all UPPERCASE to avoid name clashes with other variables in the header file.

----------------------------------------------------------------------------------------------

#### **`STRINGS, VECTORS & ARRAYS`**

* **`string`** : A variable-length sequence of characters.
* **`vector`** :  It holds the variable-length sequence of objects of any given type.
* **`scope-operator (::)`** It says that the Compiler should look in the scope of the left-hand operand for the name on the right-hand operand.
* Headers should not use `using` declarations. If a header has a `using` declaration then, every program that #include that header file will get the same `using` declaration. As a result, a program that did not intend to use a specified library name might encounter name conflicts.

```c++
string s1;			// default initialization, s1 is an empty string
string s2 = s1;			// copy initialization; s2 is a copy of s1
string s3 = "rustom potter";	// copy initialization; s3 is a copy of the string literal, not including the null '\0'
string s4(17, 's');		// direct initialization; s4 is sssssssssssssssss
```
* Like the input and output operations of built-in types, the string operator returns their left-hand operand as their result.

* Comparision rules for `string`:
	* **Rule 1** : If two `string`s (`s1, s2`) have different lengths and if every character in the shorter `string (s1)` is equal to the corresponding characters in the longer `string (s2)` then `s1 is less than s2`.
	* **Rule 2** : If any character at corresponding positions in the two strings (`s1, s2`) differs, then the result of string comparision is the result of **comparing the first characters at which the strings (`s1 & s2`) differ**.

* When we add `string` and `character/string literal`, atleast one operand to each **`+`** operator must be `string` type.

```c++
string s0 = "potter ";
string s5 = s0 + "! ";			// OK:
string s6 = "Rustom" + "! ";		// ERROR: Can't add two string-literals ("Rustom" + "! ")
string s7 = s0 + "Rustom" + "! ";	// OK: (s0 + "Rustom") returns a string type
string s8 = "Rustom" + " " + s0;	// ERROR: Can't add two string-literals ("Rustom" + " ")
```

* The C++ library incorporates the C library.
	* Headers in C have names of the form `name.h`.
	The C++ version of these headers are named `cname` (replacing the `.h` and putting a prefix `c` before the `name`)
	* The names defined in `cname` headers are defined in `std` namespace whereas those define din `.h` versions are not

* **range `for` statement** : 
```c++
for (declaration : expression) statement;
```
* The body of **range `for`** must not change the size of the sequence over which it is iterating.

```c++
string m_str("Rustom Potter");

// range for statement to print each character in a string
for (auto m_char : m_str) 
	cout << m_char << endl;
```
```c++
cctype functions:

isalnum()		isalpha()		iscntrl()		isdigit()
isgraph()		islower()		ispunct()		isprint()
isspace()		isupper()		isxdigit()
tolower()		toupper()
```
* If we want to change the characters in a `string`, we must define the loop variables as a `reference type`

* The important part about **`&&` operator** is that it evalates the right-hand operand ONLY if the left-hand operand is `true`.
* **Templates** are not themselves classes or functions. Instead they can be thought of as instructions to the Compiler for generating classes or functions.
* `instantiation` : The process that the Compiler uses to create classes or functions from **templates**.
* When we use a template, we specify what kind of class or functions we want the Compiler to instantiate.
* A `vector` is a **class template.** not a `type`.
* `vector` can hold objects of any type. 
* Because, `references` are not `object`, we can't have `vector` of **references**.
* We can add elements to `vector` @runtime.
* Most common way of using `vector` is to initially define an empty `vector` and then all elements @runtime

```c++
// In this example, the compiler generates 4 different types of vector templates 
// vector<int>, vector<string>, vector<Sales_item>, vector<vector<int>>

vector<int> ivec;		// vector of int; initially empty
vector<string> svec;		// vector of string
vector<Sales_item> Sales_vec;	// vector of Sales_item
vector<vector<int>> file;	// vector whose elements are vectors of int

//----------------------------------------------
vector<int> ivec2(ivec);	// OK: copy elements of 'ivec' into 'ivec2'
vector<int> ivec3 = ivec;	// OK: copy elements of 'ivec' into 'ivec3'
vector<string>svec3 = ivec;	// ERROR: svec3 holds string, ivec holds int


```
* **`push_back`** : It takes a value and "pushes" that value as a new element onto the **back** of the `vector`.

```c++
vector<int> m_vec;		// empty vector
for (int i = 0; i<100; ++i){
	m_vec.push_back(i);	// append sequential ints to vector m_vec
}
// at the end of the for-loop, m_vec will have int from 0 to 99

//-----------------------------------------
// read string from the input stream and store them in a vector
string m_str;			// empty string
vector<string> m_strVec;	// empty string vector
while(cin >> m_str){
	m_strVec.push_back(m_str);	// stores each string into the string-vector
}
```
* We can't use **range `for`**, if the body of the loop adds elements to the `vector`.
* It's an error to subscript (`[]`) an element that does not exist; but it is an error that the Compiler is **unlikely to detect**. Instead, the value we get @runtime is undefined.

* **_Buffer overflow_** errors are the result of subscripting elements that don't exist.
* A good way to ensure that subscripts are in range is to avoid subscripting altogether by using a **range `for`** statement whenever possible.

* A valid `iterator` either denotes an element or denotes a position one past the last element in the container. All other iterator values are invalid.

* We can dereference a valid iterator to obtain the element denoted by the iterator. 
* Dereferencing an invalid iterator or and **off-the-end iterator** has undefined behaviour.

```c++
// Standard Container Iterator operations:

*iter		---------------		Returns a reference to the element returned by the iterator "iter"

iter->mem	---------------		Derefernces "iter" and fetches the member named "mem" from the 
					underlying element. equvalent to (*iter).mem

++iter		---------------		Increments "iter" to refer to the next element in the container
--iter		---------------		Decrements "iter" to refer to the previous element in the container

iter1 == iter2	---------------		Compares two iterators for equality.
iter1 != iter2	---------------		Compares two iterators for inequality.
					Two iterators are equal if they denote the same element or if they
					are the off-the-end iterator for the same container
```

* The library types that have iterators, define types named `iterator`  and `const_iterator` that represent actual iterator types:
```c++
vector<int>::iterator iter1;		// iter1 can read & write vector<int> elements
string::iterator iter2;			// iter2 can read & write characters in a string

vector<int>::const_iterator iter3;	// iter3 can ONLY read vector<int> elements
string::const_iterator iter4;		// iter4 can ONLY read characters in a string
```

* A **`const_iterator`** behaves like a `const` pointer. It can read but can't write the element it denotes.
* If a `vector` or `string` is `const`; we can use only its `const_iterator` type.
* Each _container class_ defines a type named `iterator`; that `iterator` type supports the actions of a (conceptual) iterator.

* The type returned by `begin` or `end` depends on whether the `object` on which they operate is `const` or not. If the object is `const` then `begin` and `end` returns `const_iterator`; if they are not `const` then they return `iterator`.

* **`cbegin()` and `cend()`** : regardless of whether the `vector`(or string) is `const` or not; they always return `const_iterator` type.

```c++
vector<int> v;
const vector<int> cv;
auto iter1 = v.begin();		// iter1 has type vector<int>::iterator
auto iter2 = cv.begin();	// iter2 has type vector<int>::const_iterator

auto iter3 = v.cbegin();	// iter3 has type vector<int>::const_iterator
```
* When we derefernce a `iterator`, we get the object that the `iterator` denotes.
```c++
vector<string> m_sVec;

//.....some initialization of m_sVec
//.....
// iter is a iteration into vector<string> m_sVec

auto iter = m_sVec.begin();

// derefernce and member access
(*iter).empty();	// OK: dereferences iter and calls the empty() member on the resulting object
*iter.empty();		// ERROR: attempts to fetch the member named empty on the resulting object
			// 	but iter is an iterator and has no member named empty
```

* **`->` operator**: The `->` (arrow) operator combines **dereference** and **member-access** into single operation.
	* **`iter->mem`** is equivalent to **`(*iter).mem`**

```c++
// Arrow operator (->) is equivalent to 'dereference & member-access'

iter->empty();		// OK: the ARROW-operator
(*iter).empty();	// OK: derefernce and member access
```

* **`vector` operations that invalidate iterators**:B'coz `vector`s can grow dinamically:
	* we cannot add elements to `vector` inside a **range `for`** loop.
	* any operation (like `push_back()` that changes size of a vector potentially invalidates all iterators into that `vector`.
	
* So, loops that use iterators should not add elements to the container to which the iterator refers.

* As with `vector`s, **`array`** holds `object`. There are no **arrays** of references.
* When we define an `array` we must specify a type for the array. We **can't** use `auto` to deduce the type from the list of initializers.

* The dimension of the array must be known at Compile time i.e dimension must be a **constant expression**.

```c++
unsigned int cnt = 17;
string bad_Array[cnt];		// ERROR: "cnt" is not a constant expression

constexpr unsigned sz = 217;	// constant expression
string good_Array[sz];		// OK: "sz" is a constant expression i.e its value will be same all the time
string m_array[get_size()];	// OK if get_size() is a constant expression; ERROR otherwise
```
* When we **list-initialize** an array, we **can** omit the dimension
```c++
const unsigned sz = 3;
int ia1[sz] = {0,1,2};			// OK: an array of 3 ints with elements {0,1,2}
int a2[] = {0,1,2};			// OK: an array of dimension 3 with elements {0, 1,2}
int a3[5] = {0,1,2};			// OK: same as a3[] = {0, 1, 2, 0, 0}
string a4[3] = {"Rustom", "Potter"};	// OK: same as a4[] = {"Rustom", "Potter", ""}
int a5[2] = {0,1,2};			// ERROR: too many initializers
```
* REMEMBER: `string` literals end with a null-character (`\0`).

```c++
char a1[] = {'P', 'o', 't', 't', 'e', 'r'};		// Dimension = 6
char a2[] = {'P', 'o', 't', 't', 'e', 'r', '\0'};	// Dimension = 7 (explicit null-character)
char a3[] = "Potter";					// Dimesnion = 7 (null-character in string-literal is copied)

const char a4[6] = "Potter";				// ERROR: too many initializers (no room for including null-character in the string-literal)
```

* :warning: We cannot assign an `array` to another `array`.
:warning: * We cannot use an `array` to initialize another `array`.

```c++
int a[] = {1,2,3};		// OK:
int a1[] = a;			// ERROR: can't use another array to initialize an array
a1 = a;				// ERROR: can't assign an array to another array.
```














































	
	