const input = require('fs').readFileSync('./jejuCoding/input20.txt').toString().split(' ');

const a = input[0];
const b = input[1];

console.log(a/b, a%b);