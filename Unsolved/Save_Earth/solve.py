#!/usr/bin/env python3
import csv

newmap = {
	0: "", # empty byte
	1: "", # none
	2: "PostFail",
	4: "a",
	5: "b",
	6: "c",
	7: "d",
	8: "e",
	9: "f",
	10: "g",
	11: "h",
	12: "i",
	13: "j",
	14: "k",
	15: "l",
	16: "m",
	17: "n",
	18: "o",
	19: "p",
	20: "q",
	21: "r",
	22: "s",
	23: "t",
	24: "u",
	25: "v",
	26: "w",
	27: "x",
	28: "y",
	29: "z",
	30: "1",
	31: "2",
	32: "3",
	33: "4",
	34: "5",
	35: "6",
	36: "7",
	37: "8",
	38: "9",
	39: "0",
	40: "Enter",
	41: "esc",
	42: "del",
	43: "tab",
	44: "space",
	45: "-",
	47: "[",
	48: "]",
	56: "/",
	57: "CapsLock",
	79: "RightArrow",
	80: "LeftArrow"
}

results = []
with open("SaveEarth.csv") as csvfile:
    reader = csv.reader(csvfile)
    for row in reader: # each row is a list
        results.append(row)

keystrokes = b''
morse_code = ''
# start from line 1 because line 0 is the header
for line in results[1:]:
	# Leftover Capture Data
	capture = line[6]
	# URB usec
	usec = int(line[7])

	print(capture, hex(usec))

	if capture.startswith('0102'):
		morse_code += '_'
	elif capture.startswith('0104'):
		morse_code += '.'
	elif capture.startswith('0101'):
		morse_code += ' '

	# convert to bytes
	'''
	# array = bytes.fromhex(capture)

	for b in array:
		keystrokes += newmap[b]
	'''

	# remove empty bytes
	#array = array.replace(b'\x00', b'')
	# print(capture, array)

print(morse_code)
