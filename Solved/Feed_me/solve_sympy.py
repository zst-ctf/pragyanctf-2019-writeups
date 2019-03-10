#!/usr/bin/env python3
import socket
import sympy
from sympy import Symbol


def make_equation(lhs, rhs):
    return f'-({lhs}) + ({rhs})';


def get_payload(a, b, c):
    eqn = []
    vars = ['var_90', 'var_8C', 'var_88', "var_84", "var_80", "var_7C"]

    # var_90, var_8C, var_88
    # a, b, c = (-19014, -392, -4790)
    eqn.append(make_equation('var_90', str(a)))
    eqn.append(make_equation('var_8C', str(b)))
    eqn.append(make_equation('var_88', str(c)))

    '''
    Solve these:
    - (var_90 == var_80 + var_84)
    - (var_8C == var_7C + var_80)
    - (var_88 == var_84 + var_7C)
    '''
    eqn.append(make_equation('var_90', 'var_80 + var_84'))
    eqn.append(make_equation('var_8C', 'var_7C + var_80'))
    eqn.append(make_equation('var_88', 'var_84 + var_7C'))

    ans = sympy.solve(eqn, vars)
    print(ans)
    print()

    # pad with null bytes to separate out the strings
    # according to index [0], [10], [20]
    var_84 = str(ans[Symbol('var_84')]).ljust(10, '\x00')
    var_80 = str(ans[Symbol('var_80')]).ljust(10, '\x00')
    var_7C = str(ans[Symbol('var_7C')]).ljust(10, '\x00')
    print(var_84, var_80, var_7C)

    # combine strings
    payload = ''.join([var_84, var_80, var_7C])
    return payload


def main():
    s = socket.socket()
    s.connect(('159.89.166.12', 9800))

    while True:
        data = s.recv(2048).decode().strip()
        if not data:
            continue
        print('Received:', data)

        if ';' in data:
            numb = data.split(';')
            payload = get_payload(numb[0], numb[1], numb[2])
            s.send(payload.encode() + b'\n')

if __name__ == '__main__':
    main()
