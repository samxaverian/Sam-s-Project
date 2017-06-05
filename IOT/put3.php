<?php
$data1 = $_GET['d1'];
$data2 = $_GET['d2'];
$data3 = $_GET['d3'];
$myfile = fopen("1.txt", "w+") or die("Unable to open file!");
fwrite($myfile, $data1);
fwrite($myfile, "\n");
fwrite($myfile, $data2);
fwrite($myfile, "\n");
fwrite($myfile, $data3);

fclose($myfile);
echo "success"
?>


