var fs = require('fs');

function fibonacci(num) {
  var fib_nums = [0, 1, 1];
  var i = num;
  
  i -= 2;
  while (i > 0) {
    // The next fibonacci number is the sum of the prior 2
    fib_nums.push(
        fib_nums[fib_nums.length - 2] +
        fib_nums[fib_nums.length - 1]
      );
    i--;
  }

  return fib_nums[num];
}

fs.readFile(process.argv[2], function(err, data) {
  var inputs = data.toString().split('\n');
  for (var i=0; i<inputs.length; i++) {
    var val = Number(inputs[i]);
    if (typeof val === 'number' && inputs[i].length > 0) {
      console.log(fibonacci(val));
    }
  }
});
