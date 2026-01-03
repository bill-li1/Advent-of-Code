import Bun from 'bun'

const testFile = Bun.file('./sample.txt')
const realFile = Bun.file('./input.txt')

// const data = (await testFile.text()).trim()
const data = (await realFile.text()).trim()

function partOne() {
  const ranges = data.split(',')
  let ans = 0
  ranges.forEach((range) => {
    const [startStr, endStr] = range.split('-')
    const start = Number(startStr)
    const end = Number(endStr)
    for (let i = start; i <= end; i++) {
      const str = String(i)
      const half = str.length / 2
      const firstHalf = str.slice(0, half)
      const secondHalf = str.slice(half)
      // console.log(firstHalf, secondHalf)
      if (firstHalf === secondHalf) {
        ans += i
      }
    }
  })
  console.log(ans)
}

function partTwo() {
  const isValid = (str: string) => {
    const half = str.length / 2
    for (let strLen = 1; strLen <= half; strLen++) {
      if (str.length % strLen === 0) {
        let flag = true
        for (let i = 0; i < str.length; i++) {
          const matchStrIdx = i % strLen
          if (str[i] !== str[matchStrIdx]) {
            flag = false
            break
          }
        }
        if (flag) {
          console.log(str.slice(0, strLen), str)
          return true
        }
      }
    }
    return false
  }

  const ranges = data.split(',')
  let ans = 0
  ranges.forEach((range) => {
    const [startStr, endStr] = range.split('-')
    const start = Number(startStr)
    const end = Number(endStr)
    for (let i = start; i <= end; i++) {
      const str = String(i)
      if (isValid(str)) {
        ans += i
      }
    }
  })
  console.log(ans)
}

partTwo()
