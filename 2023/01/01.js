const fs = require("fs");

fs.readFile("test.txt", (err, inputD) => {
  if (err) throw err;
  console.log(inputD.toString());
});
