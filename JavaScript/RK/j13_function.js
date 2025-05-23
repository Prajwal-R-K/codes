console.log("=== JavaScript Functions ===");

// 1. Function Declaration
console.log("\n1. Function Declaration:");
function greet(name) {
    return `Hello, ${name}!`;
}
console.log(greet("Alice"));

// 2. Function Expression
console.log("\n2. Function Expression:");
const add = function(a, b) {
    return a + b;
};
console.log("Addition:", add(5, 3));

// 3. Arrow Functions
console.log("\n3. Arrow Functions:");
const multiply = (x, y) => x * y;
console.log("Multiplication:", multiply(4, 6));

// 4. Default Parameters
console.log("\n4. Default Parameters:");
function greetWithDefault(name = "Guest") {
    return `Hello, ${name}!`;
}
console.log(greetWithDefault());
console.log(greetWithDefault("Bob"));

// 5. Rest Parameters
console.log("\n5. Rest Parameters:");
function sum(...numbers) {
    return numbers.reduce((total, num) => total + num, 0);
}
console.log("Sum:", sum(1, 2, 3, 4, 5));

// 6. Anonymous Functions
console.log("\n6. Anonymous Functions:");
const divide = function(a, b) {
    return b !== 0 ? a / b : "Cannot divide by zero";
};
console.log("Division:", divide(10, 2));

// 7. Immediately Invoked Function Expressions (IIFE)
console.log("\n7. IIFE:");
(function() {
    console.log("This function runs immediately after being defined.");
})();

// 8. Nested Functions
console.log("\n8. Nested Functions:");
function outerFunction(outerValue) {
    console.log("Outer Value:", outerValue);
    function innerFunction(innerValue) {
        console.log("Inner Value:", innerValue);
    }
    innerFunction(10);
}
outerFunction(5);

// 9. Callback Functions
console.log("\n9. Callback Functions:");
function processUserInput(input, callback) {
    callback(input.toUpperCase());
}
processUserInput("hello", (result) => console.log("Processed Input:", result));

// 10. Higher-Order Functions
console.log("\n10. Higher-Order Functions:");
const numbers = [1, 2, 3, 4, 5];
const squared = numbers.map(num => num ** 2);
console.log("Squared Numbers:", squared);

// 11. Function Returning Functions
console.log("\n11. Function Returning Functions:");
function createMultiplier(factor) {
    return (number) => number * factor;
}
const double = createMultiplier(2);
console.log("Double of 4:", double(4));

// 12. Object Methods
console.log("\n12. Object Methods:");
const calculator = {
    add(a, b) {
        return a + b;
    },
    subtract(a, b) {
        return a - b;
    }
};
console.log("Addition:", calculator.add(10, 5));
console.log("Subtraction:", calculator.subtract(10, 5));

// 13. Function Scope
console.log("\n13. Function Scope:");
function scopeTest() {
    let localVariable = "I am local";
    console.log(localVariable);
}
scopeTest();
// console.log(localVariable); // Uncaught ReferenceError: localVariable is not defined

// 14. Closures
console.log("\n14. Closures:");
function makeCounter() {
    let count = 0;
    return function() {
        count++;
        return count;
    };
}
const counter = makeCounter();
console.log("Counter:", counter());
console.log("Counter:", counter());

console.log("\n=== End of Functions Examples ===");
