console.log("=== JavaScript Variables and Their Properties ===");

// Scope
console.log("\n1. Scope:");
if (true) {
    var varScoped = "I am function/global scoped (var)";
    let letScoped = "I am block scoped (let)";
    const constScoped = "I am block scoped (const)";
    console.log(varScoped); // Accessible
    console.log(letScoped); // Accessible
    console.log(constScoped); // Accessible
}
console.log(varScoped); // Accessible outside block
try {
    console.log(letScoped); // Error
} catch (error) {
    console.log("letScoped is not accessible outside the block.");
}
try {
    console.log(constScoped); // Error
} catch (error) {
    console.log("constScoped is not accessible outside the block.");
}

// Re-declaration
console.log("\n2. Re-declaration:");
var reVar = "I am var";
var reVar = "I can be re-declared";
console.log(reVar); // No error

try {
    let reLet = "I am let";
   // let reLet = "I cannot be re-declared"; // Error
} catch (error) {
    console.log("Error: let variables cannot be re-declared.");
}

try {
    const reConst = "I am const";
    //const reConst = "I cannot be re-declared"; // Error
} catch (error) {
    console.log("Error: const variables cannot be re-declared.");
}

// Update
console.log("\n3. Update:");
var updateVar = "I am var";
updateVar = "I can be updated";
console.log(updateVar); // Updated

let updateLet = "I am let";
updateLet = "I can also be updated";
console.log(updateLet); // Updated

try {
    const updateConst = "I am const";
    updateConst = "I cannot be updated"; // Error
} catch (error) {
    console.log("Error: const variables cannot be updated.");
}

// Hoisting
console.log("\n4. Hoisting:");
try {
    console.log(hoistedVar); // undefined (due to hoisting)
    var hoistedVar = "I am hoisted!";
    console.log(hoistedVar); // Accessible after initialization
} catch (error) {
    console.log("Error:", error.message);
}

try {
    console.log(hoistedLet); // Error: Cannot access before initialization
    let hoistedLet = "I am not hoisted (let)";
} catch (error) {
    console.log("Error: let variables are not hoisted.");
}

try {
    console.log(hoistedConst); // Error: Cannot access before initialization
    const hoistedConst = "I am not hoisted (const)";
} catch (error) {
    console.log("Error: const variables are not hoisted.");
}

console.log("\n=== End of Variable Properties Example ===");
