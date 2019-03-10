#!/usr/bin/env python3
import numpy as np
import scipy.misc as smp

def split_array(line, n):
    return [line[i:i+n] for i in range(0, len(line), n)]

def main():
    with open('encoded.txt', 'r') as f:
        content = f.read().replace('\r', '').replace('\n', '')

    # split binary test to every 100 pixels
    arr = split_array(content, 100)
    print('\n'.join(arr))

    # https://stackoverflow.com/questions/434583/what-is-the-fastest-way-to-draw-an-image-from-discrete-pixel-values-in-python
    # Create a 1024x1024x3 array of 8 bit unsigned integers
    data = np.zeros( (100,100,3), dtype=np.uint8 )
    for x, line in enumerate(arr):
        for y, pixel in enumerate(line):
            if pixel == '1':
                data[x,y] = [255,255,255]
            else:
                data[x,y] = [0,0,0]

    img = smp.toimage( data )       # Create a PIL image
    img.show()                      # View in default viewer

if __name__ == '__main__':
    main()
