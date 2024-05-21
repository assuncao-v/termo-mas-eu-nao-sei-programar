const fs = require('fs');

// const string = fs.readFileSync("palavras.txt", {encoding: "utf-8"}).split("\r\n").filter((value, i) => (value.length == 5 && value[0] != value[0].toUpperCase() && value.match(/[a-z]{5,5}/) && value.match(/(a.*a.*a)|(e.*e.*e)|(i.*i.*i)|(o.*o.*o)|(u.*u.*u)/))).map((value) => ("\"" + value + "\"")).join(',\n');

// const string = 

const string = fs.readFileSync("palavras.txt", {encoding: "utf-8"}).split("\n").map((value) => value.trim()).map((value, i) => {return `/* ${value} */\ncase ${i}:\nfirstLetter = '${value[0]}';\nsecondLetter = '${value[1]}';\nthirdLetter = '${value[2]}';\nfourthLetter = '${value[3]}';\nfifthLetter = '${value[4]}';\nbreak;`}).join('\n\n');

console.log(string);

fs.writeFileSync("text.txt", string);