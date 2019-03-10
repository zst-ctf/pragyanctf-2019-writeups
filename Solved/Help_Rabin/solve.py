from Crypto.Util.number import isPrime
import gmpy2

gmpy2.get_context().precision=1000

ct = gmpy2.mpz('0x4f741fe93dd7e383ff527caa9a2f27d27fd74b53b62123837b74a2b024d0fbbe052f3b330ce5208ba989fc68e2f5235ac4e9dd9e091e7cb80c02745d9b2aad10cab9431590ae63117ce539ebf747b4bc81f2a293aea52f0b1fee746158dc45d0c8d60769a8a8e671fb049b52669a010a1ca6f5de851d715bf1821d8771bbeb47')
pubkey = gmpy2.mpz('0x615be098727ae610de9c104819f3a1f7cc5b3144810b38d4f4d51bbe11d9ca20f287eed0236bced1fe443a335a2f33c7a8ac68f09fc5f38bfe374a9207d3073d402c7a65a30b60f75b10e43a296730aa22d32527f7203ec9becc6a7a0dd70a5ce3d1d5f2a8db9868e8a4534eef705f2c6a8326c88a536b827c88bc0005227ac9')

# Calculate primes
mid_point = gmpy2.isqrt(pubkey)
p = gmpy2.next_prime(mid_point)
q = pubkey // p
n = pubkey

print('>> Found p =', p)
print('>> Found q =', q)

# Assert the results
assert (n == (p * q))
assert (isPrime(p) and isPrime(q))
assert (p.bit_length() == 512)
assert (q.bit_length() == 512)
assert not (p%4 != 3 or q%4 !=3)


# Decrypt functions
def egcd(a, b):
    # Extended Euclidean algorithm: ax + by == gcd(a, b)
    # This function returns a tuple of (gcd, x, y)
    if a == 0:
        return (b, 0, 1)
    g, y, x = egcd(b%a,a)
    return (g, x - (b//a) * y, y)

def decrypt_rabin(c, p, q):
    n = p * q

    # Given p % 4 == 3, q % 4 == 3
    # Equation is: Mp = c^(1/4 * (p+1)) mod p
    Mp = pow(c, (p + 1) // 4, p)
    Mq = pow(c, (q + 1) // 4, q)

    # By applying the extended Euclidean algorithm,
    # we wish to find Yp and Yq such that Yp*p + Yq*q = 1
    gcd, Yp, Yq = egcd(p, q)
    if gcd != 1:
        raise Exception('No modular inverse')

    # By Chinese remainder theorem, the four square roots
    # are calculated
    r = (Yp * p * Mq + Yq * q * Mp) % n
    neg_r = n - r

    s = (Yp * p * Mq - Yq * q * Mp) % n
    neg_s = n - r

    # One of these square roots is the original plaintext m
    return [r, neg_r, s, neg_s]

def hex_pair(x):
    x = '%02x' % x
    return ('0' * (len(x) % 2)) + x

# Decrypt messages, I also swapped p and q because it
# results in different outputs
plaintext = []
plaintext.extend(decrypt_rabin(ct, p, q))
plaintext.extend(decrypt_rabin(ct, q, p))
for m in plaintext:
    print(bytes.fromhex(hex_pair(m)))
    print()
