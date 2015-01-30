var fs = require('fs');

function countChars(str) {
    var charCount = {};
    var chars = str.split('');
    for (var i=0; i<chars.length; i++) {
        if (charCount[chars[i]]) {
            // This is a repeated char. Increment the count.
            charCount[chars[i]].count += 1
        } else {
            // First time this char is seen.
            // Start the counter, and log the initial position.
            charCount[chars[i]] = {};
            charCount[chars[i]].count = 1;
            charCount[chars[i]].position = i;
        }
    }
    return charCount;
}

function getFirstUniqueChar(str) {
    // Count characters
    var charCount = countChars(str);

    // Return first character with that appeared once
    var keys = Object.keys(charCount);
    var minPosition;
    var minPositionChar;
    for (var i=0;  i<keys.length; i++) {
        if (charCount[keys[i]].count === 1 && minPosition === undefined) {
            minPosition = charCount[keys[i]].position;
            minPositionChar = keys[i];
        } else if (charCount[keys[i]].count === 1 &&
            minPosition > charCount[keys[i]].position) {
            minPosition = charCount[keys[i]].position;
            minPositionChar = keys[i];
        }
    }
    return minPositionChar;
}

fs.readFile(process.argv[2], function(err, data) {
    if (err) throw err;
    var lines = data.toString().split('\n');
    for (var i=0; i<lines.length; i++) {
        console.log(getFirstUniqueChar(lines[i]));
    }
});