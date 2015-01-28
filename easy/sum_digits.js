fs = require('fs');
fs.readFile(process.argv[2], function(err, data) {
  if (err) throw err;
  var sum = 0;
  var vals = data.toString().split('');
  for (i=0; i<vals.length; i++) {
    if (Number.isInteger(vals[i])) {
      sum += Number.parseInt(vals[i]);
    }
  }
  console.log(sum);
});
