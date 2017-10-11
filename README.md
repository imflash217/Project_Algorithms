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

```cpp
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

```cpp
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

alignas			else			public				unsigned
alignof			enum			register			using
asm				explicit		reinterpret_cast	
auto			export			return				virtual
bool			extern			short				void
break			false			signed				volatile
case			float			sizeof				wchar_t
catch			for				static				while
char			friend			static_assert
char16_t		goto			static_cast
char32_t		if				struct
class			inline			switch
const			int				template
constexpr		long			this
const_cast		mutable			thread_local
continue		namespace		throw
decltype		new				true
default			noexcept		try
delete			nullptr			typedef
do				operator		typeid
double			private			typename
dynamic_cast	protected		union

//----------------------------------------------

C++ Alternative operator names:

and			not
and_eq		not_eq
bitand		or
bitor		or_eq
compl		xor
not			xor_eq

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

```cpp
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

```cpp
int &refVal4 = 10;	// ERROR. Reference can't be bount to a literal (10)
const int &ref = 217;	// OK: We can bind a const reference to a literal (217)
double m_dval = 3.14;
int &refVal5 = m_dval;	// ERROR. Reference and object types must match. initializer must be an int type
```

* Because we can't change the value of the `const` object after we create it must be initialized.

```cpp
const int i =  get_size();	// OK. initialized at runtime
const int j = 32;		// OK. initialized at compile time
const int k;			// ERROR. k is uninitialized const
```
* To define a single instance of `const` variable that is accessible to other files, we use the `extern` keyword on both its **definition** and **declaration(s)**.

```cpp
// file1.cpp 
// define and initializes a const, extern keyword specifies that bufSize is accessible to other files
extern const int bufSize = func();

// file2.cpp 
// here extern specifies that the definition of bufSize is not local its somewhere else
extern const int bufSize;	// same bufSize as defined in file1.cpp
```

* Unlike ordinary references, a **reference to `const`** cannot be used to change the object's value.

```cpp
const int bufSize = 217;	// OK.
const int &ref1 = bufSize;	// OK. ref1 is a refernce to const variable bufSize
int &ref2 = bufSize		// ERROR. non-const reference can't refer to a const variable

ref1 = 2491;			// ERROR. refrence to const can't change the object's value
```

* Binding a `reference to const` to a non-`const` object is LEGAL; but the refernce can't be used to change the value of the non-`const` object.

```cpp
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

```cpp
const double pi = 3.14;		// OK. pi is a const double; its value can't be changed
double *ptr = &pi;		// ERROR. non-const pointer(ptr) can't point to a const object (pi)
const double *cptr = &pi;	// OK. only const pointers can store the address of const object

*cptr = 2.17;			// ERROR. cant assign to *cptr
```

* **EXCEPTION**: We can use a **pointer to `const`** to point to a non-`const` object but, can't change the object's value through the pointer.

```cpp
double pi = 3.14;	// OK. non-const object
const double *cptr = &pi;	// OK. but cant use cptr to change the value of pi
```
* Like **refernce to `const`**, a **pointer to `const`** says nothing about whether the object to which it points is a `const` or not.

* Unlike references, **pointers** are `object`. So, pointers can be `const` too.
* **`const` pointers**: Like any other `const` objects, a `const pointer` must be initialized & once initialized its value cannot be changed.

```cpp
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

```cpp
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
```cpp
const int *p = nullptr;		// p is a pointer to a const int
constexpr int *q = nullptr;	// q is a const pointer to int
```
* `constexpr` imposes a top-level `const` on the objects it defines

```cpp
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

```cpp
typedef double wages;		// wages is a synonym for double
typedef wages base, *p;		// base is synonym for double, p is double*

using SI = Sales_Item;		// SI is a synonym for Sales_Item

// A type alias is a type name and can appear wherever a type name can appear
wages hourly, weekly;		// same as "double hourly, weekly"
SI item;			// same as "Sales_Item item;
```
```cpp
typedef char *pstring;		// pstring is "pointer to char" type
const pstring cstr = 0;		// cstr is a const of type 'pstring' i.e cstr a 'const pointer to a char'
const pstring *ps;		// ps is pointer that points to a const pstring (i.e ps is a pointer that points to a constant 'pointer to char')

//-----------------------

const char *cstr = 0;		// ERROR: wrong interpretation of "const pastring cstr = 0"
```
* **ERROR** to interpret a declaration that uses a type alias by conceptually replacing the alias with its corresponding type.

* **`auto`** ordinarily ignore top-level `const`. If we want the deduced type to have top-level `const` we must say so explicitly.

* When we define several variables in the same statement, it's important to remeber that `reference` or `pointer` is part of a particular declarator not part of the base type of declaration.

```cpp
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

```cpp
decltype(f()) sum = a;		// sum has a type that is returned by f()

const int ci = 0, &cj = ci;
decltype(ci) x = 0;		// OK: x has type "const int"
decltype(cj) y = x;		// OK: y is refernce of type "const int&" and is bound to x (a "const int")
decltype(cj) z;			// ERROR: z is a refernce of type "const int&" and all refernces must be initialized

// decltype of a paranthesized variable is always a refernce
decltype((i)) d;		// ERROR: d has a type "int&" and hence must be initialized
decltype(i) e;			// OK: e is an (uninitialized) "int"
```
```cpp
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

```cpp
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

```cpp
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
```cpp
for (declaration : expression) statement;
```
* The body of **range `for`** must not change the size of the sequence over which it is iterating.

```cpp
string m_str("Rustom Potter");

// range for statement to print each character in a string
for (auto m_char : m_str) 
	cout << m_char << endl;
```
```cpp
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

```cpp
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

```cpp
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

```cpp
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
```cpp
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

```cpp
vector<int> v;
const vector<int> cv;
auto iter1 = v.begin();		// iter1 has type vector<int>::iterator
auto iter2 = cv.begin();	// iter2 has type vector<int>::const_iterator

auto iter3 = v.cbegin();	// iter3 has type vector<int>::const_iterator
```
* When we derefernce a `iterator`, we get the object that the `iterator` denotes.

```cpp
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

```cpp
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

```cpp
unsigned int cnt = 17;
string bad_Array[cnt];		// ERROR: "cnt" is not a constant expression

constexpr unsigned sz = 217;	// constant expression
string good_Array[sz];		// OK: "sz" is a constant expression i.e its value will be same all the time
string m_array[get_size()];	// OK if get_size() is a constant expression; ERROR otherwise
```
* When we **list-initialize** an array, we **can** omit the dimension
```cpp
const unsigned sz = 3;
int ia1[sz] = {0,1,2};			// OK: an array of 3 ints with elements {0,1,2}
int a2[] = {0,1,2};			// OK: an array of dimension 3 with elements {0, 1,2}
int a3[5] = {0,1,2};			// OK: same as a3[] = {0, 1, 2, 0, 0}
string a4[3] = {"Rustom", "Potter"};	// OK: same as a4[] = {"Rustom", "Potter", ""}
int a5[2] = {0,1,2};			// ERROR: too many initializers
```
* REMEMBER: `string` literals end with a null-character (`\0`).

```cpp
char a1[] = {'P', 'o', 't', 't', 'e', 'r'};		// Dimension = 6
char a2[] = {'P', 'o', 't', 't', 'e', 'r', '\0'};	// Dimension = 7 (explicit null-character)
char a3[] = "Potter";					// Dimesnion = 7 (null-character in string-literal is copied)

const char a4[6] = "Potter";				// ERROR: too many initializers (no room for including null-character in the string-literal)
```

* We cannot assign an `array` to another `array`.
* We cannot use an `array` to initialize another `array`.

```cpp
int a[] = {1,2,3};		// OK:
int a1[] = a;			// ERROR: can't use another array to initialize an array
a1 = a;				// ERROR: can't assign an array to another array.
```

* By default, type modifiers bind from right to left.
* In case of arrays, it can be easy to read array declarations from the **inside out** rather than **right to left**

```cpp
int *parray[10];			// OK: parray is an array of 10 pointers-to-int
int &rarray[10] = /* ? */;		// ERROR: reference is not an object & arrays can hold only objects

int (*Parray)[10] = &arr;		//OK: Parray "points" to an array of 10 ints; Parray is a pointer
int (&Rarray)[10] = arra;		//OK: Rarray "refers" to an array of 10 ints; Rarray is a reference

int *(&m_array)[10] = ptrs;		//OK: m_array is a refernce to an array of 10 pointers-to-int; m_array is a refernce
int &(*m_array2)[10] = /* ? */;		//ERROR: arrays cannot hold refernces (b'coz references are not objects)

```
* When we use a variable to subscript an array, we normally should define that variable to have **`size_t`** type.
* **`size_t`** is a machine-specific `unsigned type` that is guaranteed to be large enough to hold the size of any object in memory. 
* `size_t` is defined in `cstddef` C++ header. Use `#include <cstddef>` statement.

* In C++, when we use an `array`, the Compiler ordinarily converts the array to a pointer.
* When we use an `object` of array type, we are really using a `pointer` to the first element of the array.
* **operations on `array` are actually operations on `pointer`**.
* When we use an `array` as an initializer for a variable defined using **`auto`**, the deduced type is a `pointer` not an `array`. But, if we use `decltype` then this issue doesn't arrise.

```cpp
int ia[] = {0,1,2,3,4,5,6,7,8,9};	// ia is an array of ints
auto ia2(ia);				// ia2 has type int* (a pointer to ia[0] element)
					// same as: auto ia2(&ia[0]);

ia2 = 217;				// ERROR: can't assign an int to a pointer

//---------------------
int *ptr;				// a pointer
decltype(ia) ia3 = {11, 12, 17, 223};	// ia3 is an array
ia3 = p;				// ERROR: can't assign a pointer to an array
ia3[2] = 217;				// OK: assigns 217 to the ia3[2] position

```

* Pointers to `array` elements support the same operations as **iterators** on `vector` or `string`.
* As with `iterators`, subtracting two pointers give us the distance b/w two pointers; but the pointers must point to the elements in the same array:

```cpp
auto n = end(arr) - begin(arr);		//OK:
auto m = end(arr) - begin(arr2);	//ERROR if arr, arr2 are not same; can't subtract pointers from two different array
```

* The result of subtracting two pointers is a library type named **`ptrdiff_t`**.
* `ptrdiff_t` is a `signed intergral type` and is machine-specific.
* Unlike subscripts for `vector` and `string`, the index of the built-in subscript operator is not an `unsigned` type.

* We can't initialize an `array` from another `array`.
* We can't initialize an `array` from a `vector`.
* But, we can initialize a `vector` from an `array`.

```cpp
int int_array[] = {0, 1, 2, 3, 4, 5};

vector<int> ivec(begin(int_array), end(int_array));	// ivec has same elements as int_array

vector<int> subVec(begin(int_array) + 1, begin(int_array)+4);	// copies int_array[1], int_array[2], int_array[3]

```

* ADVICE: Use library types instead of arrays. Modern C++ program should use `vector`, `string` and `iterators` instead of built-in `array`s and `pointer`s

* **`Multidimensional Arrays`**:
	* Strictly speaking, there are no multidimensional arrays in C++.
	* Commonly, **multidimensional array = (array of arrays)**.

--------------------------------------------------------------------------

* **`lvalue`, `rvalue`** : 
	* `lvalue` could stand on the left-hand side of the operand while `rvalue` could not.
	* In C++, an `lvalue` expressions yields an `object` or a `function`.
* When we use an object as:
	* `lvalue` : we use object's **identity** (its location in memory).
	* `rvalue` : we use object's **value** (its contents).
* We can use an `lvalue` when an `rvalue` is required.
* But we cannot use a `rvalue` when an `lvalue` (i.e a location) is required.

* **Precedence & Associativity**:
	* Operands of operators with higher **precedence** group more tighly.
	* **Associativity** guarantees how to group operands with same _precedence_.

* The `arithmetic operators` are left-associative i.e. _operators at same precedence group left-to-right_.


* Precedence specifies how the operands are grouped, it says nothing about the **order** in which the operands are evaluated. In most cases, the orderis largely undefined.
* The order of operand evaluation is determined by the Compiler to avoid pitfalls in programs.

```cpp
int A = f1() * f2();

// We know that f1() and f2() are called before the multiplication is carried.
// But we don't know whether f1() is called first or f2(). The behaviour of calling is undefined.
```

* For operators that donot specify evaluation order, its an `ERROR` for an expression to **_refer to and change the same object_**.

```cpp
int i = 0;
cout << i << ", " << ++i << endl;		// ERROR: UNDEFINED behaviour

// B'coz the Compiler might evaluate ++i before i or otherwise. 
// B'coz this code has undefine behaviour the program is an error irrespective of what the compiler compiles
```

* `Operators` that guarantee the order in which the operands are evaluated:
	* **logical AND-operator (`&&`)** : left-operand is evaluated first. right-operand is evaluated only if left-operand is `true`
	* **logical OR-operator (`||`)**
	* **conditional-operator (`? :`)**
	* **comma-operator (`,`)**

* ADVICE: If you change an operand ; don't use the same operand elsewhere in the **same expression**.

* The operands to `modulo-operator (%)` must have **integral** type.
* Except for when (`-m`) overflows; the following rules holds true always:
	* `(-m) / n` and `m / (-n)` are both equal to `-(m / n)`
	* `(-m) % n` is equal to `-(m % n)`
	* `m % (-n)` is equal to `m % n`

* **Relational Operators** take operands of `arithmetic` or `pointer` types.
* **Logical Operators** take operands of any type that can be converted to `bool`.

* The `logical AND (&&)` and `logical OR (||)` operators always evaluate their left-hand operand first. Moreover, the right-hand operand is evaluated iff the left-hand operand does not determine the result. This strategy is called `short-circuit evaluation`.

* **short-circuit evaluation** : 
	* The right side of `&&` is evaluated only if left side is `true`.
	* The right side of `||` is evaluated only if left side is `false`.
	
* It's a bad idea to use the boolean literals `true` and `false` as operands in a comparision. These literals should be used only to compare to an object of `bool` type.

* The left-hand operand of the `assignment operator ( = )` must be a modifiable `lvalue`.
* The `assignment operator ( = )` is **right-associative**.

* **Compound assignment** :

```
+= , -= , *= , /= , %=			// Arithmetic operators

<<= , >>= , &= , ^= , |=		// bitwise operators
```

* When we use _compund assignment_, the left-hand operand is evaluated only **once**. 
But, if we use ordinary assignment, the left-hand operand is evaluated **twice** (once in the operation on right-hand side and again as the operand on the left-hand side). Apart from performance issue there is no b ig deal about using either.

* **prefix** (`++i`) 
	* yields the incremented value
	* returns the `object` itself as an `lvalue`
* **postfix** (`i++`) 
	* yields the original (unincremented) value
	* returns a copy of the object's original value as an `rvalue`

* The precedence of `postfix increment (i++)` is higher than that of `derefernce` operator.
* `*ptr++` is equivalent to `*(ptr++)`. This expression first computes `ptr++` and then yields the copy of the **previous** value of `ptr`.

* **Member Access** :
	* **`dot operator (.)`**
	* **`arrow operator (->)`**
	
* The `arrow operator (->)` requires a **pointer** operand and yields an `lvalue`.
* The `dot operator (.)` yields an `lvalue` if the object from which the member is fetched is an `lvalue`; otherwise it yields an `rvalue`.

* **Conditional Operator `(?:)`** : `cond ? expr1 : expr2`
	* The result of `conditional operator (?:)` is `lvalue` if both operators are `lvalue` or if they can convert to a common `lvalue` type. Otherwise the result is an `rvalue`.

* **`switch` statement** : 
	* `case labels` must be `integral constant expressions`
	* ERROR for any two `case labels` to have the same value
	* `label` may not stand alone; it must precede a statement or another case label
	* When execution jumps to a particular `case`, any code that occured inside the `switch` before that label is ignored.

```cpp
char ch = getVal();
int ival = 217;
const int cival = 17;
const double cdval = 2.17;

switch (ch){
	case ival :		// ERROR : ival is not a constant expression
	case 2.1798 : 		// ERROR : non-integer case labels not allowed
	case cdval :		// ERROR : non-integer case labels not allowed
	
	case 2 :		// OK : integer literals are allowed
	case 'potter' : 	// OK : constant expressions allowed
	case cival :		// OK : 'const int' allowed
	
	// ..........
	default : 
}

```
* Execution flows across `case labels`. After a `case label` is matched, execution starts at that level and continues across all remaining cases **or** untill the program explicitly interrupts it using `break` statement.

* B'coz C++ is free-form; case labels need not appear on a new line.

```cpp

switch (ch) {
	case 'a' : case 'e' : case 'i' : case : 'o' case 'u' :
		++vowelCount;
		break;
}

// same as above code

switch (ch) {
	case 'a' : 
	case 'e' :
	case 'i' :
	case 'o' : 
	case 'u' :
		++vowelCount;
		break;
}
```
* **Iterative Statements**:
	* **`while`** : tests _condition_ before execution
		* Variables defined in a `while` condition or `while` body are _created and destroyed_ on each iteration.		
	* **`for`** : tests _condition_ before execution
		* _init-statements_ can define several objects. However, _init-statement_ can be only a single declaration statement; so all the variables must have the same base _type_.
		* Omitting _condition_ is equivalent to writing `true` as a condition.
	* **range `for` statement** : 
	* **`do while`** : _executes_ then tests _condition_
		* _condition_ cannot be empty
		* Variables used in condition **must** be defined outside the `do while` statement

* **Range `for` statement**:
	* `expression` must represent a sequence such as : _braced initializer list_, an `array`, or an object of type such as `vector` or `string` that has `begin()` and `end()` members that return `iterators`.
	* declaration defines a variable. It must be possible to convert each element of the sequence t`variable`'s type. Prefer to use `auto` in such cases.
	* If we want to write to the elements of the sequence, the loop variable must be a `reference` type.
	* We cannot use **range `for`** to **add/remove** elements of `vector` (or any other container).
	
```cpp
// Range for loop
for (declaration : expression){
	statement;
}
```

```cpp
vector<int> iVec = {1,2,3,4,5,6,7,8,9};

// Range for loop
for(auto &ref : iVec){
	ref *= 2;		// multiplying the elements of the vector by 2; need to define the loop-variable as a reference
}

// Same as ablove code
for (auto beg = iVec.begin(), end = iVec.end(); beg != end; ++beg){
	auto &ref = *beg;	// ref must be a reference so we can change the element of iVec
	ref *= 2;
}
```
* We cannot use **range `for`** to **add/remove** elements of `vector` (or any other container) because in a `range for` the value of `end()` is **cached** and adding/removing elements might invalidate the the `end` value.

```cpp
do {
	//........
	mumble(foo);
} while (int foo = get_foo());		// ERROR : declaration of 'foo'(which is used inside the statement) cannot be done in condition

```

* ** Jump statements** :They interrupt the flow of execution
	* **`break`**
	* **`continue`**
	* **`goto`**
	* **`return`**

* **`break`** statement terminates nearest enclosing `while`, `do while`, `for` or `switch` statements.

* A **`break`** can appear only within an iteration statement or `switch` statement.

```cpp
string buf;

while(cin >> buf && !buf.empty()){
	switch (buf[0]){
		case '-':
			for(auto iter = buf.begin()+1; iter != buf.end(); ++iter){
				if(*iter == ' '){
					break;		// break #1, terminates the for loop
				}
				//.......			
			}
			// break #1 transfers control here
			//.........
			//.......
		
			break;				// break #2, terminates the switch loop
			
		case '+':
			//.........
			
		case '/':
			//.........
	}
	// break #2 transfers control here
}
```
* A **`continue` statement** terminates the **current iteration** of the nearest enclosing loop and immediately begins the next iteration.

* A **`continue`** statement can appear only in `for`, `while` or `do while` loop.

* Unlike a `break`, a **`continue`** may appear inside a `switch` block only if that `switch` is embedded inside an _iterative_ statement.

* Impacts of `continue` in
	* `while` or `do while` loop: _next iteration continues by evaluating the condition_
	* Traditional `for` loop: _next iteration continues by evaluating the `expression` in the `for`-header_
	* Range `for` loop: _next iteration continues by initializing the **control variable** from the next element in the sequence_

```cpp
// Only words that begin with an underscore (_) will be processed

string buf;

while(cin >> buf && !buf.empty()){
	if(buf[0] != '_'){
		continue;			// read the next inout from I/O stream
	}
	// still here? means the word starts with an underscore (_)....process buf
	//..........
	//......
}
```

* A **`goto`** statement provides an unconditional jump from the `goto` to **another labeled-statement in the same function**

```cpp
goto label;		// label is an idenitifer that identifies the satatement
```

* **labeled statement** : Any statement that is preceded by an _identifier_ followed by `colon ( : )`

```cpp
label: return;		// labeled statement; label = label
end: return;		// labeled statement; label = end
```

* `label identifiers` are independent of the names used for variables and other identifiers
* Similar to `switch` statement, a `goto` cannot tranfer control from a point where an initialized variable is out-of scope to a point where that variable is in scope.

* Jumping backwards to a point before a variable is defined; destroys the variable and constructs it again.

* **`Exceptions`** are `run-time` anomalies.

* **`runtime_error`** is a standard library eception and is defined in the **`stdexcept`** header

* As with any block, the `variables` declared inside the `try` block are inaccessible outside the block -- in particular they are not accessible to the `catch` clauses.

* Each of the library exception classes defines a member function named **`what()`**

* If no appropriate `catch` is found then the execution is transferred to a library function named **`terminate`** which is guaranteed to stop further execution of the program.

* If a program has no `try` blocks and an exception occurs then **`terminate`** is called and the program is exited.

-----------------------------------------------------------------------------------------

* **Functions** may be **overloaded**, meaning the same name may refer to several different functions.
* A `function`'s call does two things:
	* Initializes the function's parameters with the corresponding arguments
	* Transfers control to that function
	* Execution of the calling function is **suspended**(not terminated) and execution of the called function begins

* The `return` statement does two things:
	* Return the value 
	* Transfers the control out of the called function to the calling function

* Although we know which argument initializes which parameter; the order in which the arguments are evaluated completely depends on the Compiler.

* The type of the `argument` and `parameter` must match (or be convertible to the required type).
* Local variables at the outermost scope of the `function` may not use the same name as any parameter.
* The return type of a function may not be an `array` type or a `function` type. However, it may return a `pointer`-to-array or `pointer`-to-function.

* In C++, `name` has **scope** and `object` has **lifetime**
* The **scope** of a `name` is the _part of the program's text_ in which that `name` is _visible_.
* The **lifetime** of an `object` is the _time during the program's execution_ that the object exists.
* **`local variables`** :
	* Parameters and variables defined inside a function body are called _local variables_
	* They **hide** declarations of the same name in an outer space
	* The **lifetime** of a local variable depends on how it is defined
* Objects defined outside _any function_ exist throughout the program's execution.
* **Automatic Objects** :  
	* Objects that exist only while a block is executing are known as _automatic objects_
	* After execution exits a block, the value of the automatic objects created in that block is _undefined_
	* **Parameters** are automatic objects.
	* Automatic objects corresponding to local variables are initialized if their definition contains an initializer; otherwise it is default initialized.

* `Reference parameters` allow a `function` to change the value of one or more of its `arguments`.
* `Reference parameters` that are not changed inside a function should be _references to_ `const`.
* We can pass either a `const` or a non-`const` object to a parameter that has a **top-level `const`**
* **top-level** `const` on parameters are ignored
* We cannot pass a `const` object, or a `literal`, or an object that requires conversion to a **plain reference type**.

* **We cannot copy an `array`.** So, we cannot pass an array by value. 
* When we use an `array`, it is (usually) converted to a `pointer`. So, when we pass an array to a function we are actually passing a pointer to the array's first element.

```cpp
// despite appearances all the three declarations of 'func' are equivalent
// each function has a single parameter of type 'int *'
// when the Compiler checks a call to 'func', it only checks that the argument has type 'const int*'

void func(const int *);
void func(const int[]);
void func(const int[10]);


int i = 0, j[2] = {1, 2};

func(&i);		// OK: &i is a (int *)
func(j);		// OK: j is converted to (int *) that points to j[0]

```

* If we pass an array to a function that `argument` is automatically converted to a `pointer-to-the-first-element` in the array; the size of the array is irrelevant.

* Functions with varying `parameters`: C++ has following ways to write a function that takes varying no. of arguments:
	* If all the arguments have the same type, we can pass a library type named **`initializer_list`**.
	* If the arguments' type vary we can write a special type of function, known as **variadic template**
	* **ellipsis** (this facility is normally used in programs that need to interface with C programs)





