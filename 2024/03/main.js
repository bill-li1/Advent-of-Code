let s = await Bun.file("input.txt").text();
//let s =
//  "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))";

while (s.search(/don't()/) > 0) {
  const prev = s.substring(0, s.search(/don't\(\)/));
  let after = s.substring(s.search(/don't\(\)/), s.length);
  let dop = after.search(/do\(\)/);
  if (dop < 0) {
    dop = after.length - 4;
  }
  after = after.substring(dop + 4, after.length);
  s = prev + after;
  console.log(s);
}
//while (i < s.length) {
//  const prev = s.substring(i, s.search(/don't/));
//  const after = s.substring(s.search(/don't/), s.length);
//  console.log(s.substring(i, s.search(/don't/)));
//}
//
const regexp = /mul\(\d{1,3},\d{1,3}\)/g;
const findNumbers = /\d{1,3}/g;
const arr = s.match(regexp);
let ans = 0;
for (let i = 0; i < arr.length; i++) {
  const nums = arr[i].match(findNumbers);
  ans += Number(nums[0]) * Number(nums[1]);
}
console.log(ans);
