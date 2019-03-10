# Super Secure Vault
Binary

## Challenge 

Open the Vault to get the treasure.

vault

## Solution


```C
// char arg0[] = "27644437104591489104652716127"
int getNum(int arg0, int arg1, int arg2) {
    var_8 = 0x0;
    for (i = arg1; i < arg2 + arg1; i++) {
        //var_8 = arg0[i] + 2 * var_8 + 2 * (var_8 * 4) - 0x30
        var_8 = (arg0[i] - 0x30) + 10*var_8 ;
    }
    return var_8;
}
```

getNum:

- char array passed in is always "27644437104591489104652716127"
- returns an integer, taken from the array starting index arg1 of length index arg2.
- ie. ***convert substring of index arg1 to arg2 exclusive into an integer***


```C
int mod(int arg0, int arg1) {
    var_18 = 0x0;
    for (i = 0; i < strlen(arg0); i++) {
        ch = arg0[i]
        var_18 = (ch-0x30 + 10*var_18) % arg1;
    }
    return var_18;
}
```




## Flag

	??