# Easy RSA
Cryptography

## Challenge 

Deeraj is experimenting with RSA. He is given the necessary RSA parameters. He realizes something is off, but doesn't know what. Can you help him figure it out?

[parameters.txt](parameters.txt)

## Solution

Weiner Attack, identify it as the exponent is very large.

Reuse code from [GryphonCTF 2017 - Crypto Hotdogs](https://github.com/zst123/gryphonctf-2017-writeups/tree/master/Solved/Crypto_Hotdogs)

	$ python3 solve.py 
	...
	Hacked!
	b'Here is your flag, pctf{Sup3r_st4nd4rd_W31n3r_4tt4ck}\n'

## Flag

	pctf{Sup3r_st4nd4rd_W31n3r_4tt4ck}
