# The Order of the Phoenix
Cryptography

## Challenge 

	It's a new age Order of the Phoenix. The current members are:

	Harry
	Hermione
	Ron
	George
	Charlie
	Bill
	Ginny
	Fleur
	Luna
	Neville

	Each of them has a secret QR code associated with him/her which is given to you. At the entrance of the Grimmauld place, is a system to scan their QR codes.

	Any 5 or more of them can enter at once, but not less than 5. This is in place to prevent any rash decisions made by very few people regarding the matters concerning the Order.

	However, now is an emergency time. Malfoy is causing trouble again, and Harry needs to enter Grimmauld Place for which he needs to know the secret associated with the entry system to let him in. Help him out.

Bill.png
Charlie.png
Fleur.png
George.png
Ginny.png
Harry.png
Hermione.png
Luna.png
Neville.png
Ron.png

## Hint

Eleven scientists are working on a secret project.......?

## Solution

Parse all the QR codes

	qr_codes $ ls
	Bill.png     Charlie.png  Fleur.png    George.png   Ginny.png    Harry.png    Hermione.png Luna.png     Neville.png  Ron.png
	qr_codes $ zbarimg *.png
	QR-Code:a-424b493442128adbeef5ce33f18c6c5996cdd97e4922644a4479bb4e05f8846f
	QR-Code:8-1268bf4430c0b1a4c568a302da92421bc672aceb57fef3401f2434cfc3bf740b
	QR-Code:9-b52781fd38b0185bd1a8a92a92dbf01c99eddbb50b86f65a882ad8a7fa313e9d
	QR-Code:6-7c61f3ee00ab759a6853f041e74ae2378144a96b662230888d6ba6412c646190
	QR-Code:7-d01f29e42de0ab1fb183a35d06a2ac6117acaad2b3017671846c7b380e83d6bb
	QR-Code:1-d301da5536a5d8b8e2be50a7584127eb3704025f048cf72335f1b301b852b30a
	QR-Code:2-e1af01e2f7887b63c068823cbcd812f91899678656456db71dfa9ab1fbb1bd26
	QR-Code:4-510c9c8f6aaacebf16bb5fd9e2cd8c0845ec483bd49bf57fa4151e5b672c73b0
	QR-Code:3-dc60d55a411ccfd4a44e6a9799774dd6207dffdfcab4b442075ead165fa7ecb
	QR-Code:5-bd4f58a846bb9e47a7402e22df13002aef3bf3048011674269eaff39154c62bf
	scanned 10 barcode symbols from 10 images in 0.08 seconds

	qr_codes $ zbarimg Harry.png
	QR-Code:1-d301da5536a5d8b8e2be50a7584127eb3704025f048cf72335f1b301b852b30a
	scanned 1 barcode symbols from 1 images in 0.03 seconds

If we search the hint, we  find that Shamir's Secret Sharing is used.
- https://answers.yahoo.com/question/index?qid=20070416102553AA1KbWH
- https://thoughtcrook.wordpress.com/2013/12/27/a-math-problem/

### Shamir's Secret Sharing

Eventually, we find a [QR code secret sharing program](https://github.com/skewthreads/QR-secret-sharing
) that looks exactly like the challenge

	The_Order_of_the_Phoenix $ git clone https://github.com/skewthreads/QR-secret-sharing
	The_Order_of_the_Phoenix $ cd QR-secret-sharing/
	QR-secret-sharing $ pip install -t .pip -r requirements.txt 

And enter the secrets to get the flag

	$ python recover.py 
	Enter your share: 1-d301da5536a5d8b8e2be50a7584127eb3704025f048cf72335f1b301b852b30a
	[?] Enter next share: OK
	 > OK
	   I don't have another one

	Enter your share: 2-e1af01e2f7887b63c068823cbcd812f91899678656456db71dfa9ab1fbb1bd26
	[?] Enter next share: OK
	 > OK
	   I don't have another one

	Enter your share: 3-dc60d55a411ccfd4a44e6a9799774dd6207dffdfcab4b442075ead165fa7ecb
	[?] Enter next share: OK
	 > OK
	   I don't have another one

	Enter your share: 4-510c9c8f6aaacebf16bb5fd9e2cd8c0845ec483bd49bf57fa4151e5b672c73b0
	[?] Enter next share: OK
	 > OK
	   I don't have another one

	Enter your share: 5-bd4f58a846bb9e47a7402e22df13002aef3bf3048011674269eaff39154c62bf
	[?] Enter next share: OK
	 > OK
	   I don't have another one

	Enter your share: 6-7c61f3ee00ab759a6853f041e74ae2378144a96b662230888d6ba6412c646190
	[?] Enter next share: I don't have another one
	   OK
	 > I don't have another one

	Original message:
	pctf{sh4m1r3_w4s_4_gr34t_m4n}

## Flag

	pctf{sh4m1r3_w4s_4_gr34t_m4n}
