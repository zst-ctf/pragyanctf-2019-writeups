# Save Earth
Forensics

## Challenge 

In the mid 21st century, Ex-NASA pilot Cooper leaves his little daughter and goes an interstellar journey around the space to find an alternative planet (PLAN A) or to capture gravitational data and send it back to earth, which Scientists will use to save Earth. However Cooper finds himself stuck in a tesseract that spans across time, there is only one way he could transmit the data to his little girl.

We have obtained parts of what Cooper sent to his daughter, can you find the flag and save the earth?

Note: This question does not follow the flag format

## Solution

https://mweissbacher.com/blog/2012/10/01/csaw-ctf-qualifications-2012-networking-300/

File > Export Packet Dissections > As CSV


Print out the bytes using Python..

	 b''
	0102000000000000 b'\x01\x02\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0102000000000000 b'\x01\x02\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0101000000000000 b'\x01\x01\x00\x00\x00\x00\x00\x00'
	0102000000000000 b'\x01\x02\x00\x00\x00\x00\x00\x00'
	0101000000000000 b'\x01\x01\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0102000000000000 b'\x01\x02\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0101000000000000 b'\x01\x01\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0101000000000000 b'\x01\x01\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0102000000000000 b'\x01\x02\x00\x00\x00\x00\x00\x00'
	0101000000000000 b'\x01\x01\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0102000000000000 b'\x01\x02\x00\x00\x00\x00\x00\x00'
	0101000000000000 b'\x01\x01\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0104000000000000 b'\x01\x04\x00\x00\x00\x00\x00\x00'
	0102000000000000 b'\x01\x02\x00\x00\x00\x00\x00\x00'
	0102000000000000 b'\x01\x02\x00\x00\x00\x00\x00\x00'

3 unique commands 0101, 0102, 0104


## Flag

	??