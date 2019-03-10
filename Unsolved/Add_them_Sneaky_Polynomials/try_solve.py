#!/usr/bin/env python3
from sympy import *

def primes(n):
    primfac = []
    d = 2
    while d*d <= n:
        while (n % d) == 0:
            primfac.append(d)  # supposing you want multiple factors repeated
            n //= d
        d += 1
    if n > 1:
       primfac.append(n)
    return primfac

def make_equation(lhs, rhs):
    return f'-({lhs}) + ({rhs})';

p_eq = "x^406 + x^405 + x^402 + x^399 + x^397 + x^391 + x^390 + x^387 + x^386 + x^378 + x^374 + x^372 + x^371 + x^369 + x^367 + x^364 + x^360 + x^358 + x^357 + x^352 + x^350 + x^345 + x^344 + x^341 + x^336 + x^335 + x^334 + x^333 + x^331 + x^330 + x^329 + x^328 + x^327 + x^324 + x^322 + x^320 + x^314 + x^311 + x^308 + x^307 + x^303 + x^300 + x^299 + x^296 + x^295 + x^290 + x^289 + x^287 + x^279 + x^271 + x^266 + x^264 + x^262 + x^260 + x^257 + x^256 + x^252 + x^249 + x^248 + x^246 + x^243 + x^239 + x^238 + x^236 + x^233 + x^230 + x^227 + x^225 + x^223 + x^222 + x^220 + x^218 + x^216 + x^215 + x^209 + x^208 + x^207 + x^204 + x^202 + x^199 + x^190 + x^189 + x^185 + x^184 + x^180 + x^177 + x^176 + x^175 + x^172 + x^167 + x^166 + x^162 + x^160 + x^159 + x^155 + x^154 + x^149 + x^147 + x^143 + x^137 + x^135 + x^131 + x^129 + x^126 + x^124 + x^122 + x^116 + x^110 + x^108 + x^105 + x^104 + x^100 + x^99 + x^97 + x^94 + x^93 + x^90 + x^88 + x^87 + x^86 + x^85 + x^83 + x^75 + x^73 + x^69 + x^63 + x^62 + x^57 + x^54 + x^51 + x^44 + x^41 + x^38 + x^37 + x^36 + x^34 + x^29 + x^28 + x^26 + x^25 + x^21 + x^20 + x^19 + x^16 + x^15 + x^14 + x^13 + x^6 + x^5 + x^2"
q_eq = "x^399 + x^398 + x^396 + x^393 + x^392 + x^391 + x^388 + x^386 + x^384 + x^381 + x^377 + x^376 + x^368 + x^364 + x^360 + x^355 + x^354 + x^353 + x^352 + x^348 + x^346 + x^345 + x^344 + x^343 + x^335 + x^334 + x^329 + x^326 + x^325 + x^321 + x^318 + x^317 + x^315 + x^314 + x^311 + x^307 + x^306 + x^304 + x^300 + x^296 + x^293 + x^291 + x^282 + x^277 + x^270 + x^263 + x^261 + x^260 + x^256 + x^254 + x^253 + x^252 + x^251 + x^248 + x^245 + x^242 + x^241 + x^239 + x^238 + x^236 + x^232 + x^226 + x^225 + x^222 + x^220 + x^219 + x^214 + x^209 + x^208 + x^207 + x^206 + x^202 + x^200 + x^196 + x^191 + x^190 + x^186 + x^181 + x^180 + x^178 + x^177 + x^169 + x^168 + x^165 + x^164 + x^163 + x^162 + x^161 + x^159 + x^157 + x^156 + x^151 + x^149 + x^148 + x^147 + x^146 + x^144 + x^141 + x^140 + x^138 + x^137 + x^136 + x^134 + x^133 + x^132 + x^130 + x^129 + x^128 + x^126 + x^123 + x^121 + x^113 + x^109 + x^103 + x^101 + x^100 + x^95 + x^93 + x^91 + x^85 + x^84 + x^81 + x^74 + x^73 + x^71 + x^68 + x^67 + x^54 + x^52 + x^51 + x^50 + x^48 + x^46 + x^45 + x^43 + x^39 + x^35 + x^32 + x^31 + x^30 + x^29 + x^21 + x^15 + x^14 + x^9 + x^8 + x^5 + x^4 + x^2 + 1"
r_eq = "x^404 + x^402 + x^396 + x^389 + x^387 + x^386 + x^384 + x^382 + x^376 + x^373 + x^367 + x^366 + x^365 + x^362 + x^361 + x^358 + x^356 + x^355 + x^354 + x^353 + x^352 + x^349 + x^348 + x^347 + x^345 + x^343 + x^340 + x^334 + x^332 + x^331 + x^328 + x^327 + x^326 + x^322 + x^317 + x^316 + x^314 + x^313 + x^312 + x^310 + x^309 + x^308 + x^305 + x^304 + x^303 + x^301 + x^300 + x^299 + x^296 + x^295 + x^292 + x^291 + x^290 + x^288 + x^287 + x^286 + x^285 + x^283 + x^279 + x^278 + x^274 + x^271 + x^269 + x^268 + x^266 + x^265 + x^263 + x^261 + x^260 + x^259 + x^258 + x^256 + x^254 + x^252 + x^251 + x^250 + x^249 + x^244 + x^243 + x^242 + x^237 + x^236 + x^228 + x^225 + x^224 + x^223 + x^222 + x^221 + x^215 + x^214 + x^213 + x^212 + x^205 + x^201 + x^200 + x^199 + x^197 + x^193 + x^192 + x^191 + x^190 + x^189 + x^188 + x^187 + x^182 + x^180 + x^175 + x^174 + x^173 + x^167 + x^166 + x^163 + x^158 + x^156 + x^155 + x^153 + x^151 + x^150 + x^149 + x^143 + x^142 + x^140 + x^139 + x^136 + x^135 + x^133 + x^129 + x^126 + x^125 + x^123 + x^121 + x^118 + x^117 + x^116 + x^115 + x^113 + x^110 + x^106 + x^105 + x^104 + x^103 + x^102 + x^98 + x^95 + x^92 + x^89 + x^87 + x^85 + x^81 + x^80 + x^77 + x^76 + x^75 + x^74 + x^71 + x^70 + x^67 + x^66 + x^64 + x^63 + x^60 + x^59 + x^58 + x^56 + x^54 + x^53 + x^48 + x^44 + x^41 + x^39 + x^38 + x^35 + x^34 + x^31 + x^29 + x^28 + x^27 + x^22 + x^21 + x^20 + x^17 + x^14 + x^12 + x^11 + x^10 + x^9 + x^6 + x^4 + x^3 + x + 1"


'''
p_eq = p_eq.split(' + ')
q_eq = q_eq.split(' + ')
r_eq = r_eq.split(' + ')

# prime factorise
for item in p_eq:
	exp = int(item.split('^')[1])
	prime_exp = primes(exp)
	prime_exp = list(map(str, prime_exp))
	prime_exp = '*'.join(prime_exp)
	print(prime_exp)
'''

'''
p_eq = p_eq.split(' + ')
q_eq = q_eq.split(' + ')
r_eq = r_eq.split(' + ')

# remove duplicates
sum_eq = set(p_eq + q_eq + r_eq)

for symbol in sum_eq:
	if (symbol in p_eq and
		symbol in q_eq and
		symbol in r_eq):
		p_eq.remove(symbol)
		q_eq.remove(symbol)
		r_eq.remove(symbol)
		print("Removed:", symbol)

print('p =', ' + '.join(p_eq))
print('q =', ' + '.join(q_eq))
print('r =', ' + '.join(r_eq))
'''

sum_eq = p_eq + ' + ' + q_eq + ' + ' + r_eq
print('simplify', simplify(sum_eq))

'''
p_eq1 = factor(p_eq)
q_eq1 = factor(q_eq)
r_eq1 = factor(r_eq)
print('p', p_eq1)
print('q', q_eq1)
print('r', r_eq1)
'''



