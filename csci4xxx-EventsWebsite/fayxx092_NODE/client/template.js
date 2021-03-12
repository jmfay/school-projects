$(document).ready(function () {
  const xmlhttp = new XMLHttpRequest();
  const url = 'getUsername';
  xmlhttp.onreadystatechange = function () {
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
      const name = JSON.parse(xmlhttp.responseText);
      // modify username welcome span
      if (name) {
        const ret = 'Welcome, ' + name + '!';
        $('#userWelcome').text(ret);
      } else {
        $('#userWelcome').text('Welcome!');
      }
    }
  };
  xmlhttp.open('GET', url, true);
  xmlhttp.send();
});
