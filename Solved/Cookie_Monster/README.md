# Cookie Monster
Web

## Challenge 

Do prepare to see cookies lurking everywhere. http://159.89.166.12:13500/

## Solution

Everytime we refresh the page, the cookie changes.

	"flag=bc54f4d60f1cec0f9a6cb70e13f2127a"
	"flag=114d6a415b3d04db792ca7c0da0c7a55"
	"flag=b2984e12969ad3a3a2a4d334b8fb385a"
	"flag=6f570c477ab64d17825ef2d2dfcb6fe4"
	"flag=988287f7a1eb966ffc4e19bdbdeec7c3"
	"flag=0d4896d431044c92de2840ed53b6fbbd"
	"flag=f355d719add62ceea8c150e5fbfae819"
	"flag=12eccbdd9b32918131341f38907cbbb5"
	"flag=639307d281416ad0642faeaae1f098c4"
	"flag=96bc320e4d72edda450c7a9abc8a214f"
	"flag=c716fb29298ad96a3b31757ec9755763"
	"flag=51de5514f3c808babd19f42217fcba49"
	"flag=05cb7dc333ca611d0a8969704e39a9f0"
	"flag=bc781c76baf5589eef4fb7b9247b89a0"
	"flag=ff108b961a844f859bd7c203b7366f8e"
	"flag=2349277280263dff980b0c8a4a10674b"
	"flag=0b1cdc9fe1f929e469c5a54ffe0b2ed5"
	"flag=364641d04574146d9f88001e66b4410f"
	"flag=c758807125330006a4375357104f9a82"
	"flag=fcfdc12fb4030a8c8a2e19cf7b075926"
	"flag=440c5c247c708c6e46783e47e3986889"
	"flag=97a7bf81a216e803adfed8bd013f4b85"
	"flag=c1d12de20210d8c1b35c367536e1c255"
	"flag=a8655da06c5080d3f1eb6af7b514e309"
	"flag=bc54f4d60f1cec0f9a6cb70e13f2127a"
	"flag=114d6a415b3d04db792ca7c0da0c7a55"

Now if we use https://hashkiller.co.uk, we see that the hash is reverses to the flag.

	bc54f4d60f1cec0f9a6cb70e13f2127a MD5 pc 
	114d6a415b3d04db792ca7c0da0c7a55 MD5 tf 
	b2984e12969ad3a3a2a4d334b8fb385a MD5 {c 
	6f570c477ab64d17825ef2d2dfcb6fe4 MD5 0o 
	988287f7a1eb966ffc4e19bdbdeec7c3 MD5 ki 
	0d4896d431044c92de2840ed53b6fbbd MD5 3s 
	f355d719add62ceea8c150e5fbfae819 MD5 _@ 
	12eccbdd9b32918131341f38907cbbb5 MD5 re 
	639307d281416ad0642faeaae1f098c4 MD5 _y 
	96bc320e4d72edda450c7a9abc8a214f MD5 Um 
	c716fb29298ad96a3b31757ec9755763 MD5 _b 
	51de5514f3c808babd19f42217fcba49 MD5 Ut 
	05cb7dc333ca611d0a8969704e39a9f0 [No Match] 
	bc781c76baf5589eef4fb7b9247b89a0 MD5 HE 
	ff108b961a844f859bd7c203b7366f8e [No Match] 

However, there is no match for some cases...

Since all are 2 chars long, let's just bruteforce in python

	$ python3 solve.py 
	pctf{c0oki3s_@re_yUm_bUt_tHEy_@ls0_r3vEaL_@_l0t}pctf


## Flag

	pctf{c0oki3s_@re_yUm_bUt_tHEy_@ls0_r3vEaL_@_l0t}
