<?php
  $dbconfig = simplexml_load_file(__DIR__ . '/dbconfig.xml') or die("Error: Cannot create object");
  
  $db_servername = $dbconfig->host;
  $db_username = $dbconfig->user;
  $db_password = $dbconfig->password;
  $db_name = $dbconfig->database;
?>




