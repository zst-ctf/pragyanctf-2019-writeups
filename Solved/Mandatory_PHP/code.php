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
Bye...