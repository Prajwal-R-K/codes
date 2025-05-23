console.log("=== JavaScript Arrays and Methods ===");

// 1. Creating Arrays
console.log("\n1. Creating Arrays:");
let arr1 = [1, 2, 3, 4, 5]; // Using array literal
let arr2 = new Array(5); // Creating an empty array with length 5
let arr3 = Array.of(10, 20, 30); // Creating an array with specified elements
console.log("Array 1:", arr1);
console.log("Array 2:", arr2);
console.log("Array 3:", arr3);

// 2. Accessing and Modifying Elements
console.log("\n2. Accessing and Modifying Elements:");
console.log("First element of arr1:", arr1[0]);
arr1[0] = 100; // Modifying the first element
console.log("Modified arr1:", arr1);

// 3. Common Array Properties
console.log("\n3. Common Array Properties:");
console.log("Length of arr1:", arr1.length); // Length of the array

// 4. Common Array Methods
console.log("\n4. Array Methods:");

// push()
console.log("\nPush Example:");
arr1.push(6);
console.log("After push(6):", arr1);

// pop()
console.log("\nPop Example:");
arr1.pop();
console.log("After pop():", arr1);

// shift()
console.log("\nShift Example:");
arr1.shift();
console.log("After shift():", arr1);

// unshift()
console.log("\nUnshift Example:");
arr1.unshift(200);
console.log("After unshift(200):", arr1);

// concat()
console.log("\nConcat Example:");
let newArr = arr1.concat([7, 8, 9]);
console.log("After concat([7, 8, 9]):", newArr);

// join()
console.log("\nJoin Example:");
console.log("Joined arr1 with '-':", arr1.join("-"));

// slice()
console.log("\nSlice Example:");
console.log("Slice (1, 3) of arr1:", arr1.slice(1, 3));

// splice()
console.log("\nSplice Example:");
arr1.splice(2, 1, 300); // Remove 1 element at index 2 and insert 300
console.log("After splice(2, 1, 300):", arr1);

// indexOf() and lastIndexOf()
console.log("\nIndexOf Example:");
console.log("Index of 300 in arr1:", arr1.indexOf(300));

// includes()
console.log("\nIncludes Example:");
console.log("arr1 includes 300:", arr1.includes(300));

// reverse()
console.log("\nReverse Example:");
console.log("Reversed arr1:", arr1.reverse());

// sort()
console.log("\nSort Example:");
let unsorted = [3, 1, 4, 1, 5, 9];
unsorted.sort(); // Lexicographical sort by default
console.log("Sorted array:", unsorted);

// Sorting numbers numerically
unsorted.sort((a, b) => a - b);
console.log("Numerically sorted array:", unsorted);

// map()
console.log("\nMap Example:");
let squared = arr1.map(x => x ** 2);
console.log("Squared elements of arr1:", squared);

// filter()
console.log("\nFilter Example:");
let filtered = arr1.filter(x => x > 100);
console.log("Elements of arr1 > 100:", filtered);

// reduce()
console.log("\nReduce Example:");
let sum = arr1.reduce((acc, val) => acc + val, 0);
console.log("Sum of elements in arr1:", sum);

// find() and findIndex()
console.log("\nFind Example:");
console.log("First element > 100 in arr1:", arr1.find(x => x > 100));
console.log("Index of first element > 100 in arr1:", arr1.findIndex(x => x > 100));

// every() and some()
console.log("\nEvery and Some Example:");
console.log("Every element in arr1 > 0:", arr1.every(x => x > 0));
console.log("Some elements in arr1 > 100:", arr1.some(x => x > 100));

// flat()
console.log("\nFlat Example:");
let nestedArr = [1, [2, [3, [4]]]];
console.log("Flattened array (depth 2):", nestedArr.flat(2));

// flatMap()
console.log("\nFlatMap Example:");
let flatMapped = arr1.flatMap(x => [x, x * 2]);
console.log("FlatMapped arr1:", flatMapped);

// 5. Iterating over Arrays
console.log("\n5. Iterating over Arrays:");

// for loop
console.log("Using for loop:");
for (let i = 0; i < arr1.length; i++) {
    console.log(arr1[i]);
}

// for...of loop
console.log("Using for...of loop:");
for (let item of arr1) {
    console.log(item);
}

// forEach()
console.log("Using forEach:");
arr1.forEach(item => console.log(item));

console.log("\n=== End of Array Examples ===");
