# Decode This
Cryptography

## Challenge 

Ram has something to show you, which can be of great help. It definitely contains the piece of text "pctf" and whatever follows it is the flag. Can you figure out what it is?

Note: Enclose it in pctf{}

	ciphertext.txt
	encrypt.py

## Solution

### Code

Snippet of code

	key = [[int(random.random()*10000) for e in range(2)] for e in range(2)]

	i = 0
	ciphertext = ""

	while i <= (l-2):
	    x = ord(flag[i]) - 97
	    y = ord(flag[i+1]) - 97
	    z = (x*key[0][0] + y*key[0][1])%26 + 97
	    w = (x*key[1][0] + y*key[1][1])%26 + 97
	    ciphertext = ciphertext + chr(z) + chr(w)
	    i = i+2

	cipherfile = open('ciphertext.txt','w')
	cipherfile.write(ciphertext)

It is seen that the flag is being read and only alphabets are retained

	flag = ""
	for i in secret:
	    if i.isalpha():
	        flag += i
	l = len(flag)

Hence, let's assume the plaintext starts with `pctf`.


### Try out

Equations

	key = [[A, B], [C, D]]

	z-97 = (x*A + y*B) % 26
	w-97 = (x*C + y*D) % 26
	# where x, y is between 0 to 25 inclusive


Test for plaintext 'pc' to ciphertext 'vu':
	
	x = 15  # p
	y = 2   # c

	z-97 = 21 # v
	w-97 = 20 # u

	21 = (15A + 2B) % 26
	22 = (15C + 2D) % 26


Test for plaintext 'tf' to ciphertext 'qx':

	x = 19  # t
	y = 5   # 5
	
	z-97 = 16 # q
	w-97 = 23 # x

	16 = (19A + 5B) % 26
	23 = (19C + 5D) % 26

I tried to solve for ABCD by running a bruteforce.

	# get first instance that satisfies the equation (modulo 26)
	for A in range(10000):
		for B in range(10000):
			z0 = (x0*A + y0*B)%26 + 97
			z2 = (x2*A + y2*B)%26 + 97
			# if possible encryption key
			if (z0 == ord(enc[0])) and (z2 == ord(enc[2])):
				print(f"A={A}; B={B}")

We see that there are many results

	A=15; B=10
	A=15; B=36
	A=15; B=62
	A=15; B=88
	...
	A=41; B=...
	A=67; B=...
	A=93; B=...

We notice that A and B are simply multiples of 26...

We can safely ignore the multiples and take the first value since it is modulo 26 anyways. Thus `A=15; B=10`

---

After solving for ABCD, we can do a bruteforce of the plaintext and run it through the equation to match the ciphertext.

	$ python3 solve.py
	A=9; B=21
	C=12; D=11
	Found: A=9; B=21; C=12; D=11
	flag: pctfaqnrrfqhcscypuqthzmkxpesklxcpurfeubkqtrvekcyzwtrrrdprvzclxnbnlugduug

However this is not the flag.

Notice that the challenge says ***contains the piece of text "pctf" and whatever follows it is the flag.***. My initial assumption may not be accurate -- "pctf" can occur later on in the text.

To solve it, I simply ran a bruteforce of doing a substring offset. 

	$ python3 solve.py
	offset 0: pctfaqnrrfqhcscypuqthzmkxpesklxcpurfeubkqtrvekcyzwtrrrdprvzclxnbnlugduug
	offset 16: pctfybqggdkinztqpckvakbotfilyaigvsapchabilryepibklcibgci
	offset 18: pctfagxbworgkbidjbmsevpchhkyoysrfbbzjhhhodlfvpxjkgkrkg
	offset 28: pctfnrelggnppouxwseutjwjqhyluxzhezoryfosdfos
	offset 32: pctfumboexbjcqeqpurfzvpjbjfcnzhxztoeluoe
	offset 38: pctfilikeclimbinghillswhataboutyou
	offset 48: pctfvxdjhrhgtddfhdygfiyg
	offset 56: pctfzcnqnukmvlkm
	offset 58: pctfjlvrkyhuky

From this we can see the flag at offset 38

## Flag

	pctf{ilikeclimbinghillswhataboutyou}
