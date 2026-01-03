import Bun from 'bun'

const testFile = Bun.file('./01/sample.txt')
const realFile = Bun.file('./01/input.txt')
const data = await realFile.text()

const lines = data.split('\n')

function partOne() {
    let count = 0
    let dial = 50
    lines.forEach((line) => {
        if (line.length === 0) {
            return
        }
        let direction = line.slice(0, 1)
        let change = Number(line.slice(1)) % 100
        if (direction === 'L') {
            change *= -1
        }
        dial += change
        if (dial < 0) {
            dial += 100
        }
        dial = dial % 100

        if (dial === 0) {
            count++
        }
    })
    console.log(count)
}

function partTwo() {
    let count = 0
    let dial = 50
    lines.forEach((line) => {
        if (line.length === 0) {
            return
        }
        let direction = line.slice(0, 1)
        let totalChange = Number(line.slice(1))
        count += Math.floor(totalChange / 100)
        let change = totalChange % 100
        if (direction === 'L') {
            change *= -1
        }
        const isZero = dial === 0
        dial += change
        if (dial < 0) {
            console.log('test 1')
            count += isZero ? 0 : 1
            dial += 100
        } else if (dial >= 100) {
            console.log('test 2')
            count++
            dial = dial % 100
        } else if (dial === 0) {
            console.log('test 3')
            count++
        }
        console.log(dial)
    })
    console.log(count)
}

partTwo()
