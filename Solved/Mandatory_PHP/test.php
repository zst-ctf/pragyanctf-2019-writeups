<?php 

$a='testing';
echo "orig: $a\n";

$a=hash("sha256",$a); 
echo "hash: $a\n";

$a=(log10($a**(0.5)))**2; 
echo "calc: $a\n";

$c='1';
$d='1e10000';
$cond1 = $c>0&&$d>0;
$cond2 = $d>$c;
$cond3 = $a==$c*$c+$d*$d;
$valcc = $c*$c;
$valdd = $d*$d;
echo "cond1: $cond1\n";
echo "cond2: $cond2\n";
echo "cond3: $cond3\n";
echo "valcc: $valcc\n";
echo "valdd: $valdd\n";

if($c>0&&$d>0&&$d>$c&&$a==$c*$c+$d*$d) 
	echo "true\n";
else
	echo "false\n";
//$s1="true"; 
//else 

?> 