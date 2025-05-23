console.log("=== JavaScript Objects ===");

// 1. Creating Objects
console.log("\n1. Creating Objects:");
const person = {
    name: "Alice",
    age: 30,
    city: "New York",
    greet: function() {
        console.log(`Hello, my name is ${this.name}.`);
    }
};
console.log("Person Object:", person);

// 2. Accessing Properties
console.log("\n2. Accessing Properties:");
console.log("Name:", person.name); // Dot notation
console.log("City:", person["city"]); // Bracket notation

// 3. Modifying Properties
console.log("\n3. Modifying Properties:");
person.age = 31;
console.log("Updated Age:", person.age);

// 4. Adding New Properties
console.log("\n4. Adding New Properties:");
person.country = "USA";
console.log("Updated Person Object:", person);

// 5. Deleting Properties
console.log("\n5. Deleting Properties:");
delete person.city;
console.log("After Deleting City:", person);

// 6. Object Methods
console.log("\n6. Object Methods:");
person.greet();

// 7. Nested Objects
console.log("\n7. Nested Objects:");
const company = {
    name: "Tech Corp",
    location: {
        city: "San Francisco",
        country: "USA"
    },
    employees: [
        { name: "John", role: "Developer" },
        { name: "Jane", role: "Designer" }
    ]
};
console.log("Company Object:", company);
console.log("City:", company.location.city);
console.log("First Employee's Role:", company.employees[0].role);

// 8. Iterating Over Objects
console.log("\n8. Iterating Over Objects:");
console.log("Using for...in:");
for (let key in person) {
    console.log(`${key}: ${person[key]}`);
}

console.log("\nUsing Object.keys:");
Object.keys(person).forEach(key => console.log(`${key}: ${person[key]}`));

console.log("\nUsing Object.entries:");
Object.entries(person).forEach(([key, value]) => console.log(`${key}: ${value}`));

// 9. Checking Properties
console.log("\n9. Checking Properties:");
console.log("Has 'name':", person.hasOwnProperty("name"));
console.log("'age' in person:", "age" in person);

// 10. Cloning Objects
console.log("\n10. Cloning Objects:");
const personClone = { ...person };
console.log("Cloned Object:", personClone);

// 11. Merging Objects
console.log("\n11. Merging Objects:");
const additionalInfo = { hobbies: ["reading", "traveling"] };
const mergedPerson = { ...person, ...additionalInfo };
console.log("Merged Object:", mergedPerson);

// 12. Freezing and Sealing Objects
console.log("\n12. Freezing and Sealing Objects:");
const sealedObject = Object.seal({ a: 1, b: 2 });
sealedObject.b = 3; // Can modify existing properties
console.log("Sealed Object (after modification):", sealedObject);
// sealedObject.c = 4; // Error: Can't add new properties

const frozenObject = Object.freeze({ x: 10, y: 20 });
// frozenObject.y = 30; // Error: Can't modify frozen objects
console.log("Frozen Object:", frozenObject);

// 13. Object Destructuring
console.log("\n13. Object Destructuring:");
const { name, age } = person;
console.log(`Name: ${name}, Age: ${age}`);

// 14. Object Methods (Advanced)
console.log("\n14. Object Methods:");
console.log("Object Keys:", Object.keys(person));
console.log("Object Values:", Object.values(person));
console.log("Object Entries:", Object.entries(person));

// 15. Using this Keyword
console.log("\n15. Using this Keyword:");
const car = {
    brand: "Tesla",
    model: "Model S",
    start() {
        console.log(`${this.brand} ${this.model} is starting.`);
    }
};
car.start();

console.log("\n=== End of Objects Examples ===");
