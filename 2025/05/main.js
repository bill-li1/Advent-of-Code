import Bun from 'bun'

const testFile = Bun.file('./sample.txt')
const realFile = Bun.file('./input.txt')

// const data = (await testFile.text()).trim()
const data = (await realFile.text()).trim()

function partOne() {
  const ranges = []
  let count = 0
  data.split(`\n`).forEach((line) => {
    if (line.includes('-')) {
      const [start, end] = line.split('-')
      ranges.push([Number(start), Number(end)])
    } else {
      const cur = Number(line)
      for (const [start, end] of ranges) {
        if (cur >= start && cur <= end) {
          count++
          break
        }
      }
    }
  })
  console.log(count)
}

function partTwo() {
  let currentRange = []
  let count = 0
  const dataArr = data.split(`\n`)
  const ranges = []
  for (const line of dataArr) {
    if (line.includes('-')) {
      const [start, end] = line.split('-')
      ranges.push([Number(start), Number(end)])
    } else {
      break
    }
  }
  ranges.sort((a, b) => {
    return a[0] >= b[0]
  })
  for (const range of ranges) {
    if (!currentRange.length) {
      currentRange = range
      continue
    }
    if (range[0] <= currentRange[1]) {
      currentRange[1] = Math.max(currentRange[1], range[1])
    } else {
      count += currentRange[1] - currentRange[0] + 1
      currentRange = range
    }
  }
  count += currentRange[1] - currentRange[0] + 1
  console.log(count)
}

partTwo()
