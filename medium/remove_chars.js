var fs = require('fs');

function getDropChars(str) {
    var parts = str.split(', ');
    return parts.pop().split('');
}

function isDropChar(oneChar, dropChars) {
    for (var i=0; i<dropChars.length; i++) {
        if (dropChars[i] === oneChar) {
            return true;
        }
    }
    return false;
}

function removeDropChars(line, dropChars) {
    var result = [];
    var i = 0;
    while (line.charAt(i) !== ',') {
        if (!isDropChar(line.charAt(i), dropChars)) {
            result.push(line.charAt(i));
        }
        i++;
    }
    return result.join('');
}

function removeCharacters(line) {
    var dropChars = getDropChars(line);
    return removeDropChars(line, dropChars);
}

fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== "") {
        console.log(removeCharacters(line));
    }
});