console.log("=== JavaScript Operators Examples ===");

// 1. Arithmetic Operators
console.log("\n1. Arithmetic Operators:");
let a = 10,b = 5;
console.log("Addition (a + b):", a + b);
console.log("Subtraction (a - b):", a - b);
console.log("Multiplication (a * b):", a * b);
console.log("Division (a / b):", a / b);
console.log("Modulus (a % b):", a % b);
console.log("Exponentiation (a ** b):", a ** b);
console.log("Increment (++a):", ++a); // Pre-increment
console.log("Decrement (--b):", --b); // Pre-decrement

// 2. Assignment Operators
console.log("\n2. Assignment Operators:");
let x = 10;
console.log("Assignment (x = 10):", x);
x += 5; // Equivalent to x = x + 5
console.log("Add and assign (x += 5):", x);
x *= 2; // Equivalent to x = x * 2
console.log("Multiply and assign (x *= 2):", x);

// 3. Comparison Operators
console.log("\n3. Comparison Operators:");
let p = 20, q = "20";
console.log("Equal (p == q):", p == q);
console.log("Not Equal (p != q):", p != q);
console.log("Strict Equal (p === q):", p === q); // Checks value and type
console.log("Strict Not Equal (p !== q):", p !== q);
console.log("Greater Than (p > q):", p > q);
console.log("Less Than or Equal (p <= q):", p <= q);

// 4. String Operators
console.log("\n4. String Operators:");
let str1 = "Hello", str2 = "World!";
console.log("Concatenation (str1 + ' ' + str2):", str1 + " " + str2);
str1 += " JavaScript"; // Append and assign
console.log("Append and assign (str1 += ' JavaScript'):", str1);

// 5. Logical Operators
console.log("\n5. Logical Operators:");
let cond1 = true, cond2 = false;
console.log("AND (cond1 && cond2):", cond1 && cond2);
console.log("OR (cond1 || cond2):", cond1 || cond2);
console.log("NOT (!cond1):", !cond1);

// 6. Bitwise Operators
console.log("\n6. Bitwise Operators:");
let m = 5, n = 3; // 5 = 0101, 3 = 0011 in binary
console.log("Bitwise AND (m & n):", m & n); // 1
console.log("Bitwise OR (m | n):", m | n); // 7
console.log("Bitwise XOR (m ^ n):", m ^ n); // 6
console.log("Bitwise NOT (~m):", ~m); // -6
console.log("Left Shift (m << 1):", m << 1); // 10
console.log("Right Shift (m >> 1):", m >> 1); // 2

// 7. Ternary Operator
console.log("\n7. Ternary Operator:");
let age = 18;
let isAdult = age >= 18 ? "Yes, an adult" : "No, not an adult";
console.log("Is adult (age >= 18 ? 'Yes' : 'No'):", isAdult);

// 8. Type Operators
console.log("\n8. Type Operators:");
let variable = "Hello";
console.log("Type of variable (typeof variable):", typeof variable); // "string"
console.log("Is instance of String (variable instanceof String):", variable instanceof String); // false

console.log("\n=== End of Operators Examples ===");

console.log("=== Logical Assignment Operators ===");

// Logical AND assignment (&&=)
console.log("\n1. Logical AND Assignment (x &&= y):");
let x1 = true;
let y = "Hello";
x1 &&= y; // If x is true, assign y to x
console.log("x (true && 'Hello'):", x1); // Output: "Hello"

x1 = false;
x1 &&= y; // If x is false, keep x as false
console.log("x (false && 'Hello'):", x1); // Output: false

// Logical OR assignment (||=)
console.log("\n2. Logical OR Assignment (x ||= y):");
let a1 = false;
let b1 = "World";
a1 ||= b1; // If a is false, assign b to a
console.log("a (false || 'World'):", a1); // Output: "World"

a1 = "Value";
a1 ||= b1; // If a is truthy, keep its value
console.log("a ('Value' || 'World'):", a); // Output: "Value"

// Nullish Coalescing assignment (??=)
console.log("\n3. Nullish Coalescing Assignment (x ??= y):");
let p1 = null;
let q1 = 42;
p1 ??= q1; // If p is null or undefined, assign q to p
console.log("p (null ?? 42):", p1); // Output: 42

p1 = 0; // 0 is not null or undefined
p1 ??= q1; // Since p is defined, keep its value
console.log("p (0 ?? 42):", p1); // Output: 0

console.log("\n=== End of Logical Assignment Operators Examples ===");
