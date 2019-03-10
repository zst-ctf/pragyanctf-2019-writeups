# Feed_me
Binary

## Challenge 

Can you cook the most delicious recipe?

nc 159.89.166.12 9800

[challenge1](challenge1)

## Solution

Decompile in Hopper.
> [decompiled.c](decompiled.c)

---

There is a for-loop checking something.

    // ...

        var_94 = 0x0;
	    goto loc_ba7;
	loc_ba7:
	    if (sign_extend_64(var_94) < strlen(&var_6E)) goto loc_b57;

    // ...

	loc_b57:
	    if (((*(int8_t *)(rbp + sign_extend_32(var_94) + 0xffffffffffffff92) & 0xff) <= 0x2f) || ((*(int8_t *)(rbp + sign_extend_32(var_94) + 0xffffffffffffff92) & 0xff) > 0x39)) goto loc_b79;

	loc_ba0:
	    var_94 = var_94 + 0x1;
	    goto loc_ba7;

	loc_b79:
	    if ((*(int8_t *)(rbp + sign_extend_32(var_94) + 0xffffffffffffff92) & 0xff) == 0x2d) goto loc_ba0;

	loc_b8a:
	    puts("Invalid input :( ");
	    rax = 0x0;
	    goto loc_ccd;

	// ...


From this we know that

- var_94: for-loop counter
- loc_ba7: for-loop until string length (ie. for-loop each char of the array)
- loc_b57: check if item of array is of chars `0123456789`.
	+ If yes, increment for-loop counter (loc_ba0)
	+ else goto loc_b79
- loc_b79: check if item of array is char `-`
	+ if yes, increment for-loop counter (loc_ba0)
	+ else invalid input (loc_b8a)

> To summarise, it is just a forloop to check if ***all chars are numbers and dashes***

---

Once the condition of `loc_ba7` is fulfilled, it falls through to this code

	// ...
	puts("Can you cook my favourite food using these ingredients :)");
    printf("%d ; %d ; %d ;\n", var_90, var_8C, var_88);
    __isoc99_scanf(0xde2, &var_6E); // var_6E = input[0]
    // ...

	loc_ba7:
	    if (sign_extend_64(var_94) < strlen(&var_6E)) goto loc_b57;

	loc_bc1:
	    var_84 = atoi(&var_6E); // input[0]
	    var_80 = atoi(&var_64);	// input[10]
	    var_7C = atoi(&var_5A); // input[20]
	    if (var_90 != var_80 + var_84) goto loc_cbe; // fail

	loc_c08:
	    if (var_8C != var_7C + var_80) goto loc_cb2; // fail

	loc_c1c:
	    if (var_88 != var_84 + var_7C) goto loc_ca6; // fail

	loc_c2f:
	    var_78 = fopen("flag.txt", 0xdf7);
	    if (var_78 != 0x0) goto loc_c77;

Variables

- var_6E: the input buffer array
- var_84, var_80, var_7C: convert to integers at index [0], [10], [20] respectively
- var_90, var_8C, var_88: printed out numbers

Conditions to be fulfilled

- (var_90 == var_80 + var_84)
- (var_8C == var_7C + var_80)
- (var_88 == var_84 + var_7C)

---

We can use Sympy to solve the conditions.

Hence the payload should be in this format - each answer should span 10 bytes.

	[Answer 1][Answer 2][Answer 3]

Additionally, remember that the numbers must be padded with null-bytes.
Since we want atoi() to only read the first number it sees.

Put in into [a script](solve_sympy.py).

	$ python3 solve_sympy.py 
	Received: Can you cook my favourite food using these ingredients :)
	Received: -3904 ; -6806 ; -17328 ;
	{var_90: -3904, var_8C: -6806, var_88: -17328, var_84: -7213, var_80: 3309, var_7C: -10115}

	-7213 3309 -10115
	Received: That's yummy.... Here is your gift:
	pctf{p1zz4_t0pp3d_w1th_p1n34ppl3_s4uc3}

## Flag

	pctf{p1zz4_t0pp3d_w1th_p1n34ppl3_s4uc3}
