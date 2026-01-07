import Bun from 'bun'

const testFile = Bun.file('./sample.txt')
const realFile = Bun.file('./input.txt')

const data = (await testFile.text()).trim()
// const data = (await realFile.text()).trim()

const directions = [
  [-1, -1],
  [-1, 0],
  [-1, 1],
  [0, -1],
  [0, 1],
  [1, -1],
  [1, 0],
  [1, 1],
]

function partOne() {
  const map = data.split('\n')
  let count = 0
  for (let r = 0; r < map.length; r++) {
    for (let c = 0; c < map[r].length; c++) {
      if (map[r][c] === '@') {
        let rolls = 0
        directions.forEach((dir) => {
          const newR = r + dir[0]
          const newC = c + dir[1]
          if (
            newR >= 0 &&
            newR < map.length &&
            newC >= 0 &&
            newC < map[r].length &&
            map[newR][newC] === '@'
          ) {
            rolls++
          }
        })
        if (rolls < 4) {
          count++
        }
      }
    }
  }
  console.log({ count })
}

function partTwo() {
  // let map = data.split('\n')
  let map = data.split('\n').map((line) => line.split(''))
  let count = 0

  function remove() {
    let flag = false
    for (let r = 0; r < map.length; r++) {
      for (let c = 0; c < map[r].length; c++) {
        if (map[r][c] === '@') {
          let rolls = 0
          directions.forEach((dir) => {
            const newR = r + dir[0]
            const newC = c + dir[1]
            if (
              newR >= 0 &&
              newR < map.length &&
              newC >= 0 &&
              newC < map[r].length &&
              map[newR][newC] === '@'
            ) {
              rolls++
            }
          })
          if (rolls < 4) {
            map[r][c] = '.'
            count++
            flag = true
          }
        }
      }
    }
    return flag
  }

  while (true) {
    const removed = remove()
    if (!removed) break
  }

  console.log(count)
}

partTwo()
