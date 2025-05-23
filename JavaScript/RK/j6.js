console.log("=== JavaScript Data Types ===");

// 1. String
console.log("\n1. String:");
let str = "Hello, World!";
console.log("Type of str:", typeof str); // Output: string
console.log("Value of str:", str); // Output: Hello, World!

// 2. Number
console.log("\n2. Number:");
let num = 42;
let decimal = 3.14;
console.log("Type of num:", typeof num); // Output: number
console.log("Value of num:", num); // Output: 42
console.log("Type of decimal:", typeof decimal); // Output: number
console.log("Value of decimal:", decimal); // Output: 3.14

// 3. Bigint
console.log("\n3. Bigint:");
let bigInt = 9007199254740991n; // Bigint literal with 'n'
console.log("Type of bigInt:", typeof bigInt); // Output: bigint
console.log("Value of bigInt:", bigInt); // Output: 9007199254740991n

// 4. Boolean
console.log("\n4. Boolean:");
let isJavaScriptFun = true;
console.log("Type of isJavaScriptFun:", typeof isJavaScriptFun); // Output: boolean
console.log("Value of isJavaScriptFun:", isJavaScriptFun); // Output: true

// 5. Undefined
console.log("\n5. Undefined:");
let undefinedVar;
console.log("Type of undefinedVar:", typeof undefinedVar); // Output: undefined
console.log("Value of undefinedVar:", undefinedVar); // Output: undefined

// 6. Null
console.log("\n6. Null:");
let nullVar = null;
console.log("Type of nullVar:", typeof nullVar); // Output: object (historical bug in JavaScript)
console.log("Value of nullVar:", nullVar); // Output: null

// 7. Symbol
console.log("\n7. Symbol:");
let symbol = Symbol("uniqueIdentifier");
console.log("Type of symbol:", typeof symbol); // Output: symbol
console.log("Value of symbol:", symbol); // Output: Symbol(uniqueIdentifier)

// 8. Object
console.log("\n8. Object:");
let obj = {
    name: "John",
    age: 30,
    isStudent: false,
};
console.log("Type of obj:", typeof obj); // Output: object
console.log("Value of obj:", obj); // Output: { name: 'John', age: 30, isStudent: false }

// Demonstrating Array (a type of object)
let arr = [1, 2, 3];
console.log("\nArray Example:");
console.log("Type of arr:", typeof arr); // Output: object
console.log("Value of arr:", arr); // Output: [1, 2, 3]

// Demonstrating Function (a type of object)
let func = function () {
    return "I am a function!";
};
console.log("\nFunction Example:");
console.log("Type of func:", typeof func); // Output: function
console.log("Value of func:", func()); // Output: I am a function!

console.log("\n=== End of Data Types Examples ===");
