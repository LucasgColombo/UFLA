<?php
include("./config.php");
$con = mysqli_connect($host, $login, $senha, $bd);
$sql = "DELETE FROM pessoa WHERE CPF=".$_GET["CPF"];
mysqli_query($con, $sql);
header("location: ./index.php");
?>