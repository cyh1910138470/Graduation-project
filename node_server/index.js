const fs = require('fs')

let data = fs.readFileSync('./test.json', {encoding: 'utf-8'})

// data = JSON.stringify(data)

console.log(data);
