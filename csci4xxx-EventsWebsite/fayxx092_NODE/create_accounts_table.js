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
      const sql = `CREATE TABLE tbl_accounts(acc_id INT NOT NULL AUTO_INCREMENT,
                                       acc_name VARCHAR(20),
                                       acc_login VARCHAR(20),
                                       acc_password VARCHAR(50), PRIMARY KEY (acc_id))`;
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


