# Help Rabin
Cryptography

## Challenge 

Rabin has received a text from someone special, but it's all in ciphertext and he is unable to make head or tail of it. He requested her for a little hint, and she sent him the encryption algorithm. He's still unable to decode the text. Not wanting to look dumb to her again, he needs your help in figuring out what she's written for him. So help him out.

## Solution

[Rabin cryptosystem](https://en.wikipedia.org/wiki/Rabin_cryptosystem#Decryption). Identified by seeing that the exponent of m is 2 (`m*m = m^2`).

	m = m**e
	c = (m*m)%n

Read public key

	 $ openssl pkey -inform PEM -pubin -in publickey.pem -text
	-----BEGIN PUBLIC KEY-----
	MIGcMA0GCSqGSIb3DQEBAQUAA4GKADCBhgKBgGFb4JhyeuYQ3pwQSBnzoffMWzFE
	gQs41PTVG74R2cog8ofu0CNrztH+RDozWi8zx6isaPCfxfOL/jdKkgfTBz1ALHpl
	owtg91sQ5DopZzCqItMlJ/cgPsm+zGp6DdcKXOPR1fKo25ho6KRTTu9wXyxqgybI
	ilNrgnyIvAAFInrJAgEB
	-----END PUBLIC KEY-----
	Public-Key: (1023 bit)
	Modulus:
	    61:5b:e0:98:72:7a:e6:10:de:9c:10:48:19:f3:a1:
	    f7:cc:5b:31:44:81:0b:38:d4:f4:d5:1b:be:11:d9:
	    ca:20:f2:87:ee:d0:23:6b:ce:d1:fe:44:3a:33:5a:
	    2f:33:c7:a8:ac:68:f0:9f:c5:f3:8b:fe:37:4a:92:
	    07:d3:07:3d:40:2c:7a:65:a3:0b:60:f7:5b:10:e4:
	    3a:29:67:30:aa:22:d3:25:27:f7:20:3e:c9:be:cc:
	    6a:7a:0d:d7:0a:5c:e3:d1:d5:f2:a8:db:98:68:e8:
	    a4:53:4e:ef:70:5f:2c:6a:83:26:c8:8a:53:6b:82:
	    7c:88:bc:00:05:22:7a:c9
	Exponent: 1 (0x1)

Extract modulus

	$ openssl pkey -inform PEM -pubin -in publickey.pem -text |
		tail -10 | head -9 |
		tr -d ' ' | tr -d ':' | tr -d '\n'

	615be098727ae610de9c104819f3a1f7cc5b3144810b38d4f4d51bbe11d9ca20f287eed0236bced1fe443a335a2f33c7a8ac68f09fc5f38bfe374a9207d3073d402c7a65a30b60f75b10e43a296730aa22d32527f7203ec9becc6a7a0dd70a5ce3d1d5f2a8db9868e8a4534eef705f2c6a8326c88a536b827c88bc0005227ac9

I will be reusing my code from [X-MAS CTF 2018: Hanukkah](https://github.com/zst123/xmasctf-2018-writeups/tree/master/Solved/Hanukkah).

Now we have the modulus and ciphertext, we are only left with cracking the primes.

Notice that the primes chosen are close to each other. The 2nd prime is the next prime from the 1st.

	# from encrypt.py
	p = getPrime(512)
	q = nextPrime(p+1)

Hence, we can use the square root of N and search for the nearest prime as in my code

	# Calculate primes
	mid_point = gmpy2.isqrt(pubkey)
	p = gmpy2.next_prime(mid_point)
	q = pubkey // p
	n = pubkey

Solve

	$ python3 solve.py 
	>> Found p = 8268478798627496550868057067863302848395658194493470189583465530982345058367642548587735876643165276333944105562045538477589025350029252013031979923054823
	>> Found q = 8268478798627496550868057067863302848395658194493470189583465530982345058367642548587735876643165276333944105562045538477589025350029252013031979923054799
	b'a[\xe0\x98rz\xe6\x10\xde\x9c\x10H\x19\xf3\xa1\xf7\xcc[1D\x80\xc2\xd3[\xd4\x82\xba[\xa8k\x9e\x00{\x18yc\xbfKUb\x89#\xcd\xc9\xee\xca\x13S9\x8c\x06\x8b\x7fQ\x8b&\xdd\xd0\xd8"\x99^\xe6\xd7\xd1\xc8Y\xf13\xea\xf3~:\xae\x82\xd6\xbeF\xcb;\xbe\x94\x04\xdf\x91\xad\xd9\xa9UYJ\x00\x9ea\x98<}et\x8bn\xbb(\x05t=\xd7\xfc\xbb\x0e-\xbe\x0bQ\xb3i\x15\xeb8#\x19\x13G\xcc\x91\xad\xfd\xbf'

	b'Hey Rabin, would you like to be the front end to my back end? Here is your flag: pctf{R4b1n_1s_th3_cut3st}\n'


## Flag

	pctf{R4b1n_1s_th3_cut3st}
