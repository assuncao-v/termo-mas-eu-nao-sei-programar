const fs = require('fs');

const string = fs.readFileSync("palavras.txt", {encoding: "utf-8"}).split("\r\n").filter((value, i) => (value.length == 5 && value[0] != value[0].toUpperCase() && value.match(/[a-z]{5,5}/))).map((value) => ("\"" + value + "\"")).join(',\n');

fs.writeFileSync("palavras.txt", string);