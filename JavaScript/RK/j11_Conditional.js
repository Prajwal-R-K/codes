console.log("=== JavaScript Conditional Statements ===");

// 1. if Statement
console.log("\n1. if Statement:");
let age = 20;
if (age >= 18) {
    console.log("You are eligible to vote.");
}

// 2. if-else Statement
console.log("\n2. if-else Statement:");
let temperature = 30;
if (temperature > 35) {
    console.log("It's very hot outside.");
} else {
    console.log("The weather is pleasant.");
}

// 3. if-else if-else Statement
console.log("\n3. if-else if-else Statement:");
let marks = 85;
if (marks >= 90) {
    console.log("Grade: A+");
} else if (marks >= 80) {
    console.log("Grade: A");
} else if (marks >= 70) {
    console.log("Grade: B");
} else {
    console.log("Grade: C");
}

// 4. Ternary Operator
console.log("\n4. Ternary Operator:");
let number = 7;
let result = (number % 2 === 0) ? "Even" : "Odd";
console.log(`The number ${number} is ${result}.`);

// 5. switch Statement
console.log("\n5. switch Statement:");
let day = 3;
switch (day) {
    case 1:
        console.log("Monday");
        break;
    case 2:
        console.log("Tuesday");
        break;
    case 3:
        console.log("Wednesday");
        break;
    case 4:
        console.log("Thursday");
        break;
    case 5:
        console.log("Friday");
        break;
    default:
        console.log("Weekend");
}