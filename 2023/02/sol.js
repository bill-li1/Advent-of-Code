const fs = require("fs");
const readline = require("readline");

async function sol1() {
  const fileStream = fs.createReadStream("input.txt");
  let total = 0;

  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity,
  });

  for await (const line of rl) {
    let valid = true;
    const [game, score] = line.split(":");
    const gameNumber = Number(game.split(" ")[1]);
    const denoms = score.split(";");
    for (const denom of denoms) {
      const colors = denom.split(",");
      for (const color of colors) {
        const [_temp, value, name] = color.split(" ");
        const invalid =
          (name === "red" && value > 12) ||
          (name === "green" && value > 13) ||
          (name === "blue" && value > 14);
        if (invalid) {
          valid = false;
        }
      }
    }
    if (valid) {
      total += gameNumber;
    }
  }
  console.log(total);
}

async function sol2() {
  const fileStream = fs.createReadStream("input.txt");
  let total = 0;

  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity,
  });

  for await (const line of rl) {
    let minVal = {
      red: 0,
      green: 0,
      blue: 0,
    };
    const [_game, score] = line.split(":");
    const denoms = score.split(";");
    for (const denom of denoms) {
      const colors = denom.split(",");
      for (const color of colors) {
        const [_temp, value, name] = color.split(" ");
        minVal[name] =
          Number(value) > minVal[name] ? Number(value) : minVal[name];
      }
    }
    total += minVal.red * minVal.green * minVal.blue;
  }
  console.log(total);
}

sol2();
