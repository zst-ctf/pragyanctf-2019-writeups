# Spoiler
Cryptography

## Challenge 

Bran Stark, wants to convey an important information to the Sansa back at winterfell. He sends her a message. The message however, is encrypted though.

Can you find out what Bran is trying to convey??

[key.pdf](key.pdf)

## Solution

In the PDF we see only the text. It is a hex string of 22 bytes (ie. 44 chars).

	3a2c3a35152538272c2d213e332e3c25383030373a15

Do a strings on the PDF.

	$ strings key.pdf 
	...
	%%EOF0000006a0000006f0000006e000000730000006e0000006f000000770000006900000073000000640000007200000061000000670000006f0000006e00000062000000790000006200000069000000720000007400000068

We can extract an important lines at the end of the file

	Text at EOF:
	0000006a0000006f0000006e000000730000006e0000006f000000770000006900000073000000640000007200000061000000670000006f0000006e00000062000000790000006200000069000000720000007400000068

Clean up the text at EOF and convert it to ASCII.

	>>> x = '0000006a0000006f0000006e000000730000006e0000006f000000770000006900000073000000640000007200000061000000670000006f0000006e00000062000000790000006200000069000000720000007400000068'

	>>> bytes.fromhex(x)
	b'\x00\x00\x00j\x00\x00\x00o\x00\x00\x00n\x00\x00\x00s\x00\x00\x00n\x00\x00\x00o\x00\x00\x00w\x00\x00\x00i\x00\x00\x00s\x00\x00\x00d\x00\x00\x00r\x00\x00\x00a\x00\x00\x00g\x00\x00\x00o\x00\x00\x00n\x00\x00\x00b\x00\x00\x00y\x00\x00\x00b\x00\x00\x00i\x00\x00\x00r\x00\x00\x00t\x00\x00\x00h'

	>>> bytes.fromhex(x).replace(b'\x00', b'')
	b'jonsnowisdragonbybirth'

And we realise that the length of this string is also 22 bytes.

Try XOR cipher.

	def xor(a1, b1):
	    encrypted = [ (a ^ b) for (a,b) in zip(a1, b1) ]
	    return bytes(encrypted)

	>>> a = b'jonsnowisdragonbybirth'
	>>> b = bytes.fromhex('3a2c3a35152538272c2d213e332e3c25383030373a15')

	>>> xor(a, b)
	b'PCTF{JON_IS_TARGARYEN}'

## Flag

	PCTF{JON_IS_TARGARYEN}
