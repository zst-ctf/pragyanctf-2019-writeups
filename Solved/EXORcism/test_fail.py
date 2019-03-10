#!/usr/bin/env python3
from functools import reduce
import operator


def split_array(line, n):
    return [line[i:i+n] for i in range(0, len(line), n)]

def jump_array(arr, n):
    # https://stackoverflow.com/questions/1442782/python-program-to-split-a-list-into-two-lists-with-alternating-elements
    return [arr[i::n] for i in range(n)]

def main():
    with open('encoded.txt', 'r') as f:
        content = f.read().replace('\r', '').replace('\n', '')

    # split binary test to every 8 bits
    bin_arr = split_array(content, 8)
    print('bin_arr:', bin_arr)

    # convert to integer
    int_arr = list(map(lambda x: int(x, 2), bin_arr))
    int_arr_len = len(int_arr)
    #print('int_arr:', int_arr)
    print('len:', int_arr_len)

    quit()
    for jump_size in range(1, 3000):
        # only process if prefect division
        if int_arr_len % jump_size != 0:
            continue

        print('jump:', jump_size) 
        arr = jump_array(int_arr, jump_size)
        print(arr)

        arr_reduced = [reduce(operator.xor, item) for item in arr]
        #print(arr_reduced)

        text = list(map(chr, arr_reduced))
        text = ''.join(text)
        print(text)

if __name__ == '__main__':
    main()
