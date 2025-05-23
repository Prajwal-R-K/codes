console.log("=== JavaScript Strings and Methods ===");

// 1. Creating Strings
console.log("\n1. Creating Strings:");
let str1 = "Hello, World!";
let str2 = 'JavaScript Strings';
let str3 = `Template Literals are awesome!`;
console.log("String 1:", str1);
console.log("String 2:", str2);
console.log("String 3:", str3);

// 2. String Properties
console.log("\n2. String Properties:");
console.log("Length of str1:", str1.length);

// 3. Common String Methods
console.log("\n3. String Methods:");

// charAt()
console.log("charAt(0) of str1:", str1.charAt(0)); // Output: "H"

// charCodeAt()
console.log("charCodeAt(0) of str1:", str1.charCodeAt(0)); // Output: 72 (ASCII value of 'H')

// concat()
let concatenated = str1.concat(" ", str2);
console.log("Concatenated String:", concatenated);

// includes()
console.log("str1 includes 'World':", str1.includes("World")); // Output: true

// endsWith()
console.log("str1 ends with '!':", str1.endsWith("!")); // Output: true

// indexOf()
console.log("Index of 'World' in str1:", str1.indexOf("World")); // Output: 7

// lastIndexOf()
let repeatStr = "This is a test. This is only a test.";
console.log("Last index of 'test':", repeatStr.lastIndexOf("test")); // Output: 27

// localeCompare()
console.log("Comparing 'apple' and 'banana':", "apple".localeCompare("banana")); // Output: -1 (because 'apple' comes before 'banana')

// match()
let regex = /[A-Z]/g;
console.log("Matching uppercase letters in str1:", str1.match(regex)); // Output: ['H', 'W']

// repeat()
console.log("Repeating 'Hello' 3 times:", "Hello".repeat(3)); // Output: HelloHelloHello

// replace()
console.log("Replacing 'World' with 'JavaScript':", str1.replace("World", "JavaScript")); // Output: Hello, JavaScript!

// replaceAll()
console.log("Replacing all instances of 'test':", repeatStr.replaceAll("test", "exam")); // Output: This is a exam. This is only a exam.

// slice()
console.log("Slice (7, 12) from str1:", str1.slice(7, 12)); // Output: World

// split()
console.log("Splitting str1 by ',':", str1.split(",")); // Output: ["Hello", " World!"]

// startsWith()
console.log("str1 starts with 'Hello':", str1.startsWith("Hello")); // Output: true

// substring()
console.log("Substring (7, 12) of str1:", str1.substring(7, 12)); // Output: World

// toLowerCase()
console.log("str1 in lowercase:", str1.toLowerCase()); // Output: hello, world!

// toUpperCase()
console.log("str1 in uppercase:", str1.toUpperCase()); // Output: HELLO, WORLD!

// trim()
let paddedStr = "   Hello, JavaScript!   ";
console.log("Trimmed String:", paddedStr.trim()); // Output: "Hello, JavaScript!"

// trimStart() and trimEnd()
console.log("Trimmed Start:", paddedStr.trimStart()); // Output: "Hello, JavaScript!   "
console.log("Trimmed End:", paddedStr.trimEnd()); // Output: "   Hello, JavaScript!"

// valueOf()
let strObject = new String("String Object");
console.log("Value of String Object:", strObject.valueOf()); // Output: String Object

// 4. Template Literals
console.log("\n4. Template Literals:");
let name = "Alice";
let age = 25;
console.log(`Hello, my name is ${name} and I am ${age} years old.`);

console.log("\n=== End of String Examples ===");
