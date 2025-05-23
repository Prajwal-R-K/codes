console.log("=== JavaScript Loops ===");

// 1. for Loop
console.log("\n1. for Loop:");
for (let i = 1; i <= 5; i++) {
    console.log(`Iteration ${i}`);
}

// 2. while Loop
console.log("\n2. while Loop:");
let count = 1;
while (count <= 5) {
    console.log(`Count: ${count}`);
    count++;
}

// 3. do-while Loop
console.log("\n3. do-while Loop:");
let num = 1;
do {
    console.log(`Number: ${num}`);
    num++;
} while (num <= 5);

// 4. for...of Loop
console.log("\n4. for...of Loop:");
const fruits = ["apple", "banana", "cherry"];
for (let fruit of fruits) {
    console.log(fruit);
}

// 5. for...in Loop
console.log("\n5. for...in Loop:");
const person = { name: "Alice", age: 25, city: "New York" };
for (let key in person) {
    console.log(`${key}: ${person[key]}`);
}

// 6. Nested Loops
console.log("\n6. Nested Loops:");
for (let i = 1; i <= 3; i++) {
    console.log(`Outer Loop ${i}`);
    for (let j = 1; j <= 2; j++) {
        console.log(`  Inner Loop ${j}`);
    }
}

// 7. break Statement
console.log("\n7. break Statement:");
for (let i = 1; i <= 10; i++) {
    if (i === 5) break; // Exit the loop when i equals 5
    console.log(i);
}

// 8. continue Statement
console.log("\n8. continue Statement:");
for (let i = 1; i <= 10; i++) {
    if (i % 2 === 0) continue; // Skip even numbers
    console.log(i);
}

// 9. Iterating Arrays with Loops
console.log("\n9. Iterating Arrays:");
const numbers = [10, 20, 30, 40, 50];

// Using for loop
console.log("Using for loop:");
for (let i = 0; i < numbers.length; i++) {
    console.log(numbers[i]);
}

// Using forEach
console.log("Using forEach:");
numbers.forEach(num => console.log(num));

// 10. Using map() for Transformation
console.log("\n10. Using map():");
const squaredNumbers = numbers.map(num => num ** 2);
console.log("Squared Numbers:", squaredNumbers);

// 11. Using reduce() for Aggregation
console.log("\n11. Using reduce():");
const sum = numbers.reduce((acc, val) => acc + val, 0);
console.log("Sum of Numbers:", sum);

// 12. Infinite Loop (With Caution - Commented Out)
// console.log("\n12. Infinite Loop:");
// while (true) {
//     console.log("This will run forever. Press Ctrl+C to stop.");
// }

// 13. Looping Over Strings
console.log("\n13. Looping Over Strings:");
const text = "hello";
for (let char of text) {
    console.log(char);
}

// 14. Using labeled break in Nested Loops
console.log("\n14. labeled break:");
outer: for (let i = 1; i <= 3; i++) {
    for (let j = 1; j <= 3; j++) {
        if (i === 2 && j === 2) {
            console.log("Breaking out of outer loop");
            break outer;
        }
        console.log(`i: ${i}, j: ${j}`);
    }
}

// 15. Iterating Over Sets
console.log("\n15. Iterating Over Sets:");
const mySet = new Set([1, 2, 3, 4, 5]);
for (let value of mySet) {
    console.log(value);
}

// 16. Iterating Over Maps
console.log("\n16. Iterating Over Maps:");
const myMap = new Map([
    ["name", "Alice"],
    ["age", 25],
    ["city", "New York"]
]);
for (let [key, value] of myMap) {
    console.log(`${key}: ${value}`);
}

console.log("\n=== End of Loops Examples ===");
