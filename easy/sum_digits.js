fs = require('fs');
fs.readFile(process.argv[2], function(err, data) {
  if (err) throw err;
  var sum = 0;
  var values = data.toString().split('');
  for (i=0; i<values.length; i++) {
    if (values[i] === '\n') {
      console.log(sum);
      sum = 0;
    } else {
      // console.log('val: ' + values[i]);
      sum += Number(values[i]);
    }
  }
  });
