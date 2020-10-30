<?php

ini_set('display_errors', 1);
//https://riptutorial.com/es/php/example/20412/cifrado-simetrico

$dat = explode("." ,$_REQUEST['pagina']);

$data = base64_decode($dat[0]);
$iv = base64_decode($dat[1]);

$method = "aes-256-cbc"; 
$password = "123";

$iv_length = openssl_cipher_iv_length($method); // obtain required IV length
$strong = false; // set to false for next line
//$iv = openssl_random_pseudo_bytes($iv_length, $strong); // generate initialization vector

$dec_data = openssl_decrypt($data, $method, $password, true, $iv); 

print($dec_data);