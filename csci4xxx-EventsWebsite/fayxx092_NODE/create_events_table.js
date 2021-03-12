const mysql = require('mysql');
// fs module - provides an API for interacting with the file system
const fs = require('fs');

// xml2js module provides a way to read xml database config
const xml2js = require('xml2js');
const parser = new xml2js.Parser({ explicitArray: false });

let con;


fs.readFile(__dirname + '/dbconfig.xml', function (err, data) {
  if (err) throw err;
  parser.parseString(data, function (err, result) {
    con = mysql.createConnection(result.dbconfig);
    con.connect(function (err) {
      if (err) throw err;
      console.log('Connected to database');
      const sql = `CREATE TABLE tbl_events(event_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
                                         event_day VARCHAR(30),
                                         event_event VARCHAR(300),
                                         event_start VARCHAR(30),
                                         event_end VARCHAR(30),
                                         event_location VARCHAR(1024),
                                         event_phone VARCHAR(30),
                                         event_info VARCHAR(1024),
                                         event_url VARCHAR(1024))`;
      con.query(sql, function (err, result) {
        if (err) {
          throw err;
        }
        console.log('Table created');
      });
    });
  });
});

/*con.connect(function (err) {
  if (err) {
    throw err;
  }*/


