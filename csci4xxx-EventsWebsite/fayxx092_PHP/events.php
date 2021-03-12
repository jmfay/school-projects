<!DOCTYPE html
PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en"
lang="en">
 
<head>
<title>Events Page</title>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<link
      rel="stylesheet"
      href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css"
    />
</head>
<body>
<div class="container">
      <table class="table" id="eventsTable">
        <thead>
          <tr>
            <th scope="col">Day</th>
            <th scope="col">Event</th>
            <th scope="col">Time</th>
            <th scope="col">
              Event Location <br />
              (Virtual or Physical)
            </th>
            <th scope="col">Phone Number</th>
            <th scope="col">
              Extra Info <br />
              (URL)
            </th>
          </tr>
        </thead>
        <tbody>
        <?php
            include_once 'database.php';
            /*
            $host = 'cse-larry.cse.umn.edu';
            $user = 'C4131F20U29';
            $password = '3338878';
            $database = 'C4131F20U29';
            $port = 3306;*/

            $conn = new mysqli($db_servername,$db_username,$db_password,$db_name);

            if ($conn->connect_error){
              die("Connection failed: " . $conn->connect_error);
            }
            
            $sql = "SELECT * FROM tbl_events;";
            
            $res = $conn->query($sql);
            ob_start();
            if ($res->num_rows > 0){
              while ($row = $res->fetch_assoc()) {
                print "<tr><td>" . $row['event_day'] . "</td><td>" . $row['event_event'] . "</td><td>" . $row['event_start'] . "-" . $row['event_end'] . 
                "</td><td>" . $row['event_location'] . "</td><td>" . $row['event_phone'] . "</td><td><a href = '" . $row['event_url'] . "' target='blank'>" . $row['event_info'] . "</a></td></tr>";
              }
            }
            if(isset($_POST['submit'])){
              if(!empty($_POST['columnName'])){
                $selected = $_POST['columnName'];
                $criteria = $_POST['searchStr'];
                $sql = "SELECT * FROM tbl_events WHERE " . $selected . " LIKE '%" . $criteria . "%';";
              }
              else {
                $sql = "SELECT * FROM tbl_events;";
              }
              $res = $conn->query($sql);
              if ($res->num_rows > 0){
                ob_end_clean();
                ob_start();
                while ($row = $res->fetch_assoc()) {
                  print "<tr><td>" . $row['event_day'] . "</td><td>" . $row['event_event'] . "</td><td>" . $row['event_start'] . "-" . $row['event_end'] . 
                  "</td><td>" . $row['event_location'] . "</td><td>" . $row['event_phone'] . "</td><td><a href = '" . $row['event_url'] . "' target='blank'>" . $row['event_info'] . "</a></td></tr>";
                }
              }
            }
            $conn->close();

          ?>
        </tbody>
      </table>
      <form action="" method="post">
          <label for="columnName">Column Name</label>
          <select name="columnName" id="columnName">
            <option></option>
            <option value="event_day">Day</option>
            <option value="event_event">Event</option>
            <option value="event_start">Start</option>
            <option value="event_location">Location</option>
            <option value="event_phone">Phone</option>
          </select>
          <br>
          <input type="text" id="searchStr" name="searchStr" />
          <br>
          <input type="submit" name="submit" value="Filter" />
    </form>
    </div>   
  </body>
</html>