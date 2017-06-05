<?php
// $myfile = fopen("1.txt", "r") or die("Unable to openfile!"); echo "<html>"; echo "<head>";
$con = mysql_connect("localhost","Sam","password");
if(!$con)
	die("can not connect".mysql_error());
mysql_select_db("baby",$con);
$sql = "select * from baby";
$mydata = mysql_query($sql,$con);
 echo "<title> IOT
Server 1</title>"; echo "</head>"; echo "<body background='http://cdn.wallpapersafari.com/56/48/WEuzVS.jpg'><br><br><br><center><font face='Comic Sans MS' size='5'>";
echo "<h4>BABY MONITORING SYSTEM<h4>";
 echo "<table
border=1px height=300px width=700px>"; echo "<tr bgcolor='#abc2e8'>";
  echo "<th><h2>TEMPERATURE</h2></th>";
 echo "<th><h2>MOISTURE</h2></th>";
 echo "<th><h2>VOICE</h2></th>";
  echo "<th><h2>DAY</h2></th>";
 echo "<th><h2>TIME</h2></th>";

  echo "</tr>";
 //echo "<tr><center>"; $temp = fread($myfile,filesize("1.txt"));
//$arr=explode("\n", $temp); foreach ( $arr as $item ) {
 while($record = mysql_fetch_array($mydata))
 {
 	echo "<tr>";
 echo "<td><center><h3>".$record['TEMPERATURE']."</h3></center></td>";
  echo "<td><center><h3>".$record['MOISTURE']."</h3></center></td>";
 echo "<td><center><h3>".$record['VOICE']."</h3></center></td>";
 echo "<td><center><h3>".$record['DAY']."</h3></center></td>";
 echo "<td><center><h3>".$record['TIME']."</h3></center></td>";
echo "</tr>";
}
//echo "<center></tr></font>"; fclose($myfile);
mysql_close($con);
 $url1=$_SERVER['REQUEST_URI'];
    header("Refresh: 1; URL=$url1"); ?>
