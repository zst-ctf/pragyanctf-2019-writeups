import itertools

harry = b'd301da5536a5d8b8e2be50a7584127eb3704025f048cf72335f1b301b852b30a'

qr_code = [
	b'd301da5536a5d8b8e2be50a7584127eb3704025f048cf72335f1b301b852b30a',
    b'424b493442128adbeef5ce33f18c6c5996cdd97e4922644a4479bb4e05f8846f',
    b'1268bf4430c0b1a4c568a302da92421bc672aceb57fef3401f2434cfc3bf740b',
    b'b52781fd38b0185bd1a8a92a92dbf01c99eddbb50b86f65a882ad8a7fa313e9d',
    b'7c61f3ee00ab759a6853f041e74ae2378144a96b662230888d6ba6412c646190',
    b'd01f29e42de0ab1fb183a35d06a2ac6117acaad2b3017671846c7b380e83d6bb',
    b'e1af01e2f7887b63c068823cbcd812f91899678656456db71dfa9ab1fbb1bd26',
    b'510c9c8f6aaacebf16bb5fd9e2cd8c0845ec483bd49bf57fa4151e5b672c73b0',
    b'0dc60d55a411ccfd4a44e6a9799774dd6207dffdfcab4b442075ead165fa7ecb', # left padded with zero
    b'bd4f58a846bb9e47a7402e22df13002aef3bf3048011674269eaff39154c62bf',
]


def xor(a1, b1):
    encrypted = [(a ^ b) for (a, b) in zip(a1, b1)]
    return bytes(encrypted)

# 9 choose 4
combi = itertools.combinations(qr_code, 5)

for i, item in enumerate(combi):
	if not harry in item:
		continue
	a, b, c, d, e = item
	ab = xor(a, b)
	abc = xor(ab, c)
	abcd = xor(abc, d)
	abcde = xor(abcd, e)
	#abcdef = xor(abcde, f)

	key = abcde
	# key = xor(abcd, harry)

	#if b'`' in key:
	#	continue
	print(i, key)
	#quit()
