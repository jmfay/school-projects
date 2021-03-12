const express = require('express');
const app = express();

// helps in extracting the body portion of an incoming request stream
const bodyparser = require('body-parser');

// fs module - provides an API for interacting with the file system
const fs = require('fs');

// xml2js module provides a way to read xml database config
const xml2js = require('xml2js');

// helps in managing user sessions
const session = require('express-session');

// native js function for hashing messages with the SHA-256 algorithm
const crypto = require('crypto');

// include the mysql module
const mysql = require('mysql');

// apply the body-parser middleware to all incoming requests
app.use(bodyparser());

const parser = new xml2js.Parser({ explicitArray: false });

let con;

fs.readFile(__dirname + '/dbconfig.xml', function (err, data) {
  if (err) throw err;
  parser.parseString(data, function (err, result) {
    con = mysql.createPool(result.dbconfig);
  });
});

// connection to database

// use express-session
// in memory session is sufficient for this assignment
app.use(
  session({
    secret: 'SECRET_HERE',
    saveUninitialized: true,
    resave: false,
  })
);

// server listens on port 9586 for incoming connections
app.listen(process.env.PORT || 9001, () => console.log('Listening on port 9001!'));

// GET method route for the welcome page
app.get('/', function (req, res) {
  res.sendFile(__dirname + '/client/welcome.html');
});

// GET method route for the events page.
app.get('/events', function (req, res) {
  if (!req.session.value) {
    res.redirect('/login');
    return;
  }
  res.sendFile(__dirname + '/client/events.html');
});

// GET method route for the addEvent page.
app.get('/addEvent', function (req, res) {
  if (!req.session.value) {
    res.redirect('/login');
    return;
  }
  res.sendFile(__dirname + '/client/addEvent.html');
});

// GET method for stock page
app.get('/stock', function (req, res) {
  if (!req.session.value) {
    res.redirect('/login');
    return;
  }
  res.sendFile(__dirname + '/client/stock.html');
});

// GET method for admin page
app.get('/admin', function (req, res) {
  if (!req.session.value) {
    res.redirect('/login');
    return;
  }
  res.sendFile(__dirname + '/client/admin.html');
});

// GET method to return list of user ids, names, and logins
// The function queries the tbl_accounts table for the list of users and sends the response back to client
app.get('/adminGetUsers', function (req, res) {
  con.query('SELECT acc_id,acc_name,acc_login FROM tbl_accounts', function (err, result) {
    if (err) {
      console.log('adminGetUser error: ', err);
      return;
    }
    res.json(result);
  });
});

// POST method to insert new user into database
app.post('/adminNewUser', function (req, res) {
  const newInfo = req.body;
  const newName = newInfo.newName;
  const newLogin = newInfo.newLogin;
  const newPassword = crypto.createHash('sha256').update(newInfo.newPassword).digest('base64');

  // check if any of the parameters are just whitespace
  // return if so
  if (
    !newName.replace(/\s/g, '').length ||
    !newLogin.replace(/\s/g, '').length ||
    !newPassword.replace(/\s/g, '').length
  ) {
    res.json({ status: 'sql fail' });
  }
  // Query the database with login and hashed password
  // If any results, user aleady exists and can't be inserted
  const sql = 'SELECT acc_name FROM tbl_accounts WHERE acc_login = (?) AND acc_password = (?);';
  con.query(sql, [newLogin, newPassword], function (err, results) {
    if (err) {
      // SQL error
      console.log(err);
      res.json({ status: 'sql fail' });
      return;
    } else {
      if (results.length > 0) {
        res.json({ status: 'exists' });
        return;
      }

      // successful query, but no rows in response, insert new
      // user into database
      const data = {
        acc_name: newName,
        acc_login: newLogin,
        acc_password: newPassword,
      };

      con.query('INSERT tbl_accounts SET ?', data, function (err, result) {
        if (err) {
          console.log(err);
          res.json({ status: 'sql fail' });
          return;
        }
        res.json({ status: 'success' });
      });
    }
  });
});

// POST method to update the credentials of an existing user
app.post('/adminUpdateUser', function (req, res) {
  const newInfo = req.body;
  const id = newInfo.id;
  const newName = newInfo.name;
  const newLogin = newInfo.login;
  const newPassword = crypto.createHash('sha256').update(newInfo.password).digest('base64');
  let newPassFlag = false;
  if (newInfo.password) {
    newPassFlag = true;
  }

  // double check to make sure Name and Login aren't empty
  // redundant since checked clientside but might as well
  if (!newName.replace(/\s/g, '').length || !newLogin.replace(/\s/g, '').length) {
    res.json({ flag: false });
    return;
  }

  let sql = 'UPDATE tbl_accounts SET acc_name = ?, acc_login = ?';
  const data = [newName, newLogin];
  // check if password passed in isn't just empty/whitespace
  // include password stuff in query/data if new one was provided
  if (newPassFlag) {
    data.push(newPassword);
    sql += ', acc_password = ?';
  }
  data.push(id);
  sql += ' WHERE acc_id = ?;';
  // console.log(sql);
  // console.log(data);
  // begin updating entry with new credentials, report success/failure
  con.query(sql, data, function (err, result) {
    if (err) {
      console.log(err);
      res.json({ flag: false });
      return;
    }
    // console.log(result);
    res.json({ flag: true });
  });
});

// POST method to remove a user
// server receives ID of who to remove and reports back success or failure
app.post('/adminRemoveUser', function (req, res) {
  const info = req.body;
  if (info.login === req.session.user) {
    res.json({ status: 'self' });
    return;
  }
  const data = { acc_login: info.login };
  const sql = 'DELETE FROM tbl_accounts WHERE ?';
  con.query(sql, data, function (err, result) {
    // query failure
    if (err) {
      console.log(err);
      res.json({ status: 'sql fail' });
      return;
    }
    // affectedRows means something was actually deleted
    if (result.affectedRows == 1) {
      res.json({ status: 'success' });
    } else {
      // if no affectedRows, no user with passed in login
      res.json({ status: 'no user' });
    }
  });
});

// GET method route for the login page.
app.get('/login', function (req, res) {
  if (req.session.value) {
    res.redirect('/events');
  } else {
    res.sendFile(__dirname + '/client/login.html');
  }
});

// GET method to retrieve username
app.get('/getUsername', function (req, res) {
  if (req.session.value) {
    res.json(req.session.user);
  } else {
    res.json('');
  }
});

// GET method to return the list of events
// The function queries the tbl_events table for the list of events and sends the response back to client
app.get('/getListOfEvents', function (req, res) {
  con.query('SELECT * FROM tbl_events', function (err, result) {
    if (err) {
      console.log('error: ', err);
      return;
    }
    res.json(result);
  });
});

// POST method to insert details of a new event to tbl_events table
app.post('/postEvent', function (req, res) {
  const eventFields = req.body;
  const sql =
    'INSERT INTO `tbl_events` (`event_day`,`event_event`,`event_start`,`event_end`,`event_location`,`event_phone`,`event_info`,`event_url`) VALUES (?,?,?,?,?,?,?,?);';
  const data = Object.values(eventFields);
  console.log(data);
  con.query(sql, data, function (err, results, fields) {
    if (err) {
      console.log(err);
      res.json({ status: 'sql fail' });
    } else {
      res.redirect('/events');
    }
  });
});

// POST method to validate user login
// upon successful login, user session is created
app.post('/sendLoginDetails', function (req, res) {
  console.log('Received login request');
  const loginInfo = req.body;
  const login = loginInfo.login;
  const pwd = crypto.createHash('sha256').update(loginInfo.password).digest('base64');

  const sql =
    'SELECT acc_name AS name FROM tbl_accounts WHERE acc_login = (?) AND acc_password = (?);';
  const data = [login, pwd];
  con.query(sql, data, function (err, results, fields) {
    if (err) throw err;
    // Query the database with login and hashed password
    // Provided there is no error, and the results set is assigned to a variable named rows:
    if (results.length > 0) {
      req.session.user = login;
      req.session.value = 1;
      res.json({ status: 'success' });
    } else {
      // improper login
      res.json({ status: 'fail' });
    }
  });
});

// log out of the application
// destroy user session
app.get('/logout', function (req, res) {
  if (!req.session.value) {
    res.send('Session not started, can not logout!');
  } else {
    console.log('Successfully Destroyed Session!');
    req.session.destroy();
    res.redirect('/login');
  }
});

// middle ware to serve static files
app.use('/client', express.static(__dirname + '/client'));

// function to return the 404 message and error to client
app.get('*', function (req, res) {
  res.sendStatus(404);
});
