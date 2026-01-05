import Bun from 'bun'

const testFile = Bun.file('./sample.txt')
const realFile = Bun.file('./input.txt')

// const data = (await testFile.text()).trim()
const data = (await realFile.text()).trim()

function partOne() {
  let ans = 0
  const banks = data.split('\n')
  banks.forEach((bank) => {
    let largest = 0
    let secondLargest = 0
    let largestIdx = 0
    for (let i = 0; i < bank.length - 1; i++) {
      const num = Number(bank[i])
      if (num > largest) {
        largest = num
        largestIdx = i
      }
    }
    for (let i = largestIdx + 1; i < bank.length; i++) {
      const num = Number(bank[i])
      if (num > secondLargest) {
        secondLargest = num
      }
    }
    //console.log(largest, secondLargest, largest + secondLargest)
    ans += Number(largest * 10 + secondLargest)
  })
  console.log(ans)
}

function partTwo() {
  let ans = 0
  const banks = data.split('\n')
  banks.forEach((bank) => {
    let idx = -1
    let val = 0
    for (let i = 0; i < 12; i++) {
      const remaining = 12 - i - 1
      let largest = 0
      for (let i = idx + 1; i < bank.length - remaining; i++) {
        const num = Number(bank[i])
        if (num > largest) {
          largest = num
          idx = i
        }
      }
      val *= 10
      val += largest
    }
    ans += val
    console.log(val)
  })
  console.log(ans)
}

partTwo()
