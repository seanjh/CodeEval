var fs = require('fs');

function isEven(num) { return (num % 2) === 0; }
function isLetter(char) {
  return (char >= 'a' && char <= 'z') ||
    (char >= 'A' && char <= 'Z');
}
function getLetter(char, num) {
  if (isEven(num)) {
    return char.toLowerCase();
  } else {
    return char.toUpperCase();
  }
}

function roller_coaster_case(str) {
  var result = [];
  var letter_count = 0;
  for (var i=0; i<str.length; i++) {
    var str_char = str.charAt(i);
    if (isLetter(str_char)) {
      letter_count++;
      str_char = getLetter(str_char, letter_count);
    }
    result.push(str_char);
  }
  return result.join('');
}

fs.readFile(process.argv[2], function(err, data) {
  if (err) throw err;
  var lines = data.toString().split('\n');
  var result = [];
  for (var i=0; i<lines.length; i++) {
    result.push(roller_coaster_case(lines[i]));
  }
  console.log(result.join('\n'));
});
