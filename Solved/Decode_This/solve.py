#!/usr/bin/env python3
import string

text = 'pctf'
enc = 'vuqxyugfyzfjgoccjkxlqvguczymjhpmjkyzoilsxlwtmccclwizqbetwthkkvilkruufwuu'


def test(text, enc):
	# calculate known plaintext and ciphertext
	x0 = ord(text[0+0]) - 97
	y0 = ord(text[0+1]) - 97

	x2 = ord(text[2+0]) - 97
	y2 = ord(text[2+1]) - 97

	for A in range(1000):
		for B in range(1000):
			z0 = (x0*A + y0*B)%26 + 97
			z2 = (x2*A + y2*B)%26 + 97
			# if possible encryption key
			if (z0 == ord(enc[0])) and (z2 == ord(enc[2])):
				print(f"A={A}; B={B}")


def decode(text, enc, verbose=True):
	'''
	x = ord(text[0]) - 97
	y = ord(text[1]) - 97
	z = (x*A + y*B)%26 + 97
	w = (x*C + y*D)%26 + 97
	'''

	# calculate known plaintext and ciphertext
	x0 = ord(text[0+0]) - 97
	y0 = ord(text[0+1]) - 97

	x2 = ord(text[2+0]) - 97
	y2 = ord(text[2+1]) - 97

	# get first instance of key that satisfies the equation (modulo 26)
	for A in range(26):
		for B in range(26):
			z0 = (x0*A + y0*B)%26 + 97
			z2 = (x2*A + y2*B)%26 + 97
			# if possible encryption key
			if (z0 == ord(enc[0])) and (z2 == ord(enc[2])):
				if verbose: print(f"A={A}; B={B}")
				A0 = A
				B0 = B

	for C in range(26):
		for D in range(26):
			w0 = (x0*C + y0*D)%26 + 97
			w2 = (x2*C + y2*D)%26 + 97
			# if possible encryption key
			if (w0 == ord(enc[1])) and (w2 == ord(enc[3])):
				if verbose: print(f"C={C}; D={D}")
				C0 = C
				D0 = D

	# These are the key values after modulo 26
	if verbose: print(f"Key: A={A0}; B={B0}; C={C0}; D={D0}")

	# decode by bruteforce of plaintext to match ciphertext
	flag = ''
	for i in range(0, len(enc), 2):
		for ch1 in string.ascii_lowercase:
			for ch2 in string.ascii_lowercase:
				x = ord(ch1) - 97
				y = ord(ch2) - 97
				z = ord(enc[i+0])
				w = ord(enc[i+1])

				ct_z = (x*A0 + y*B0)%26 + 97
				ct_w = (x*C0 + y*D0)%26 + 97

				# if match ciphertext then add to flag
				if ct_z == z and ct_w == w:
					# print(f'index {i}: {ch1} {ch2}')
					flag += ch1 + ch2

	if verbose: print(f'flag: {flag}')
	return flag

if __name__ == '__main__':
	
	# Part 1: bruteforce for A, B
	#test(text, enc)

	# Part 2: found out that A, B, C, D
	#         can be left in modulo 26
	#decode(text, enc):

	# Part 3: offset since pctf is not the starting
	for half_offset in range(len(enc) // 2):
		offset = half_offset * 2
		decoded = decode(text, enc[offset:], verbose=False)
		if decoded.startswith('pctf'):
			print(f'offset {offset}: {decoded}')
