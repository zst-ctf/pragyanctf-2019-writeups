#!/usr/bin/env python3
import hashlib

hashes = [
    "bc54f4d60f1cec0f9a6cb70e13f2127a",
    "114d6a415b3d04db792ca7c0da0c7a55",
    "b2984e12969ad3a3a2a4d334b8fb385a",
    "6f570c477ab64d17825ef2d2dfcb6fe4",
    "988287f7a1eb966ffc4e19bdbdeec7c3",
    "0d4896d431044c92de2840ed53b6fbbd",
    "f355d719add62ceea8c150e5fbfae819",
    "12eccbdd9b32918131341f38907cbbb5",
    "639307d281416ad0642faeaae1f098c4",
    "96bc320e4d72edda450c7a9abc8a214f",
    "c716fb29298ad96a3b31757ec9755763",
    "51de5514f3c808babd19f42217fcba49",
    "05cb7dc333ca611d0a8969704e39a9f0",
    "bc781c76baf5589eef4fb7b9247b89a0",
    "ff108b961a844f859bd7c203b7366f8e",
    "2349277280263dff980b0c8a4a10674b",
    "0b1cdc9fe1f929e469c5a54ffe0b2ed5",
    "364641d04574146d9f88001e66b4410f",
    "c758807125330006a4375357104f9a82",
    "fcfdc12fb4030a8c8a2e19cf7b075926",
    "440c5c247c708c6e46783e47e3986889",
    "97a7bf81a216e803adfed8bd013f4b85",
    "c1d12de20210d8c1b35c367536e1c255",
    "a8655da06c5080d3f1eb6af7b514e309",
    "bc54f4d60f1cec0f9a6cb70e13f2127a",
    "114d6a415b3d04db792ca7c0da0c7a55"
]

flag = ''
for h in hashes:
    for ch1 in range(256):
        for ch2 in range(256):
            text = chr(ch1) + chr(ch2)
            h1 = hashlib.md5(text.encode()).hexdigest()
            if h1 == h:
                flag += text

print(flag)
