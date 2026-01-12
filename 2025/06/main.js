import Bun from 'bun'

const testFile = Bun.file('./sample.txt')
const realFile = Bun.file('./input.txt')

// const data = (await testFile.text()).trim()
const data = (await realFile.text()).trim()

function partOne() {
  const grid = data.split('\n').map((str) => str.split(' ').filter(Boolean))
  let ans = 0
  for (let c = 0; c < grid[0].length; c++) {
    const sign = grid[grid.length - 1][c]
    console.log(sign)
    let tempAns = Number(grid[0][c])
    for (let r = 1; r < grid.length - 1; r++) {
      if (sign === '*') {
        tempAns *= Number(grid[r][c])
      } else if (sign === '+') {
        tempAns += Number(grid[r][c])
      }
    }
    ans += tempAns
  }
  console.log(ans)
}

function partTwo() {}

partTwo()
