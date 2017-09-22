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

**Q.[2.3]** 






















