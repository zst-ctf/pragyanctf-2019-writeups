#!/usr/bin/env python3

###############################################################
# Read in public key
###############################################################
from Crypto.PublicKey import RSA
from Crypto.Util import asn1
from base64 import b64decode

e=217356749319385698521929657544628507680950813122965981036139317973675569442588326220293299168756490163223201593446006249622787212268918299733683908813777695992195006830244088685311059537057855442978678020950265617092637544349098729925492477391076560770615398034890984685084288600014953201593750327846808762513
n=413514550275673527863957027545525175432824699510881864021105557583918890022061739148026915990124447164572528944722263717357237476264481036272236727160588284145055425035045871562541038353702292714978768468806464985590036061328334595717970895975121788928626837881214128786266719801269965024179019247618967408217
c=337907824405966440030495671003069758278111764297629248609638912154235544001123799434176915113308593275372838266739188034566867280295804636556069233774555055521212823481663542294565892061947925909547184805760988117713501561339405677394457210062631040728412334490054091265643226842490973415231820626551757008360

print('n =', n)
print('e =', e)
print('c =', c)

###############################################################
# Do RSA Wiener Attack
###############################################################

'''
References:
    https://crypto.stackexchange.com/questions/777/in-rsa-do-i-calculate-d-from-e-or-e-from-d
    https://github.com/pablocelayes/rsa-wiener-attack

Formula:
    m = c^d % n
'''
import binascii

# Add git directory to path, so we can import easily
import sys
sys.path.insert(0, './rsa-wiener-attack')

# import the hack!
from RSAwienerHacker import hack_RSA
d = hack_RSA(e, n)

# decrypt
priv_key = RSA.construct((n, e, d))
m = priv_key.decrypt(c)
# pow(c, d) % n
# m = pow(c, d, n)

# https://stackoverflow.com/questions/4368676/is-there-a-way-to-pad-to-an-even-number-of-digits
def hex_pair(x):
    return ('0' * (len(x) % 2)) + x

m_hex = '{:x}'.format(m)
m_hex = hex_pair(m_hex)
msg = binascii.unhexlify(m_hex)
print(msg)

