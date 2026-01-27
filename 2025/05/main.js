import Bun from 'bun'

const testFile = Bun.file('./sample.txt')
const realFile = Bun.file('./input.txt')

const data = (await testFile.text()).trim()
// const data = (await realFile.text()).trim()

function partOne() {
  const ranges = []
  data.split(`\n`).forEach((line) => {
    if (line.includes('-')) {
      ranges.push([])
    }
  })
}

partOne()
