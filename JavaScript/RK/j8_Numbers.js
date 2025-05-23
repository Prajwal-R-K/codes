console.log("=== JavaScript Numbers and Methods ===");

// 1. Number Basics
console.log("\n1. Number Basics:");
let num1 = 42; // Integer
let num2 = 3.14; // Floating-point
console.log("Integer (num1):", num1);
console.log("Floating-point (num2):", num2);
console.log("Type of num1:", typeof num1);
console.log("Type of num2:", typeof num2);

// 2. Special Numeric Values
console.log("\n2. Special Numeric Values:");
console.log("Positive Infinity:", Infinity);
console.log("Negative Infinity:", -Infinity);
console.log("Not-a-Number (NaN):", NaN);
console.log("Type of NaN:", typeof NaN); // Output: number

// 3. Arithmetic Operations
console.log("\n3. Arithmetic Operations:");
let a = 10, b = 3;
console.log("Addition (a + b):", a + b);
console.log("Subtraction (a - b):", a - b);
console.log("Multiplication (a * b):", a * b);
console.log("Division (a / b):", a / b);
console.log("Modulus (a % b):", a % b);
console.log("Exponentiation (a ** b):", a ** b);

// 4. Number Properties
console.log("\n4. Number Properties:");
console.log("Maximum Value:", Number.MAX_VALUE);
console.log("Minimum Value:", Number.MIN_VALUE);
console.log("Positive Infinity:", Number.POSITIVE_INFINITY);
console.log("Negative Infinity:", Number.NEGATIVE_INFINITY);
console.log("NaN:", Number.NaN);

// 5. Number Methods
console.log("\n5. Number Methods:");

// isNaN()
let val = "hello";
console.log("isNaN('hello'):", isNaN(val)); // Output: true

// isFinite()
let finiteNum = 100;
let infiniteNum = Infinity;
console.log("isFinite(100):", isFinite(finiteNum)); // Output: true
console.log("isFinite(Infinity):", isFinite(infiniteNum)); // Output: false

// parseInt()
let strNum = "123.45";
console.log("parseInt('123.45'):", parseInt(strNum)); // Output: 123

// parseFloat()
console.log("parseFloat('123.45'):", parseFloat(strNum)); // Output: 123.45

// toFixed()
let num = 3.14159;
console.log("num.toFixed(2):", num.toFixed(2)); // Output: 3.14

// toExponential()
console.log("num.toExponential(2):", num.toExponential(2)); // Output: 3.14e+0

// toPrecision()
console.log("num.toPrecision(3):", num.toPrecision(3)); // Output: 3.14

// Number()
let numFromString = Number("123");
console.log("Number('123'):", numFromString);

// 6. Number Object Methods
console.log("\n6. Number Object Methods:");

// isInteger()
console.log("Number.isInteger(42):", Number.isInteger(42)); // Output: true
console.log("Number.isInteger(3.14):", Number.isInteger(3.14)); // Output: false

// isNaN()
console.log("Number.isNaN(NaN):", Number.isNaN(NaN)); // Output: true
console.log("Number.isNaN(42):", Number.isNaN(42)); // Output: false

// isSafeInteger()
console.log("Number.isSafeInteger(9007199254740991):", Number.isSafeInteger(9007199254740991)); // Output: true
console.log("Number.isSafeInteger(9007199254740992):", Number.isSafeInteger(9007199254740992)); // Output: false

// 7. Working with BigInt
console.log("\n7. BigInt:");
let bigIntNum = 123456789012345678901234567890n; // BigInt literal
console.log("BigInt:", bigIntNum);
console.log("Type of BigInt:", typeof bigIntNum);
console.log("BigInt Addition:", bigIntNum + 10n); // BigInt operations must use BigInt literals

// 8. Rounding Methods
console.log("\n8. Rounding Methods:");
console.log("Math.round(3.5):", Math.round(3.5)); // Output: 4
console.log("Math.ceil(3.1):", Math.ceil(3.1)); // Output: 4
console.log("Math.floor(3.9):", Math.floor(3.9)); // Output: 3
console.log("Math.trunc(3.9):", Math.trunc(3.9)); // Output: 3

// 9. Random Numbers
console.log("\n9. Random Numbers:");
console.log("Random Number (0-1):", Math.random());
console.log("Random Integer (1-10):", Math.floor(Math.random() * 10) + 1);

// 10. Absolute and Power
console.log("\n10. Absolute and Power:");
console.log("Math.abs(-42):", Math.abs(-42)); // Output: 42
console.log("Math.pow(2, 3):", Math.pow(2, 3)); // Output: 8
console.log("Math.sqrt(16):", Math.sqrt(16)); // Output: 4

console.log("\n=== End of Numbers Examples ===");
