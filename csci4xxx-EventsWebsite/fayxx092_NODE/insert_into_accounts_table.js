const mysql = require('mysql');
const crypto = require('crypto');
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
      const rowToBeInserted = {
        acc_name: '', // replace with acc_name chosen by you OR retain the same value
        acc_login: '', // replace with acc_login chosen by you OR retain the same vallue
        acc_password: crypto.createHash('sha256').update('').digest('base64'), // replace with acc_password chosen by you OR retain the same value
      };

      con.query('INSERT tbl_accounts SET ?', rowToBeInserted, function (err, result) {
        if (err) {
          throw err;
        }
        console.log('Value inserted');
      });

    });
  });
});

/*con.connect(function (err) {
  if (err) {
    throw err;
  }*/

