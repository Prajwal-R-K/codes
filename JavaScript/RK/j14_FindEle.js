console.log("=== Finding HTML Elements ===");

// 1. Finding HTML Elements by ID
console.log("\n1. Finding HTML Elements by ID:");
const elementById = document.getElementById("unique-element");
console.log("Element with ID 'unique-element':", elementById);

// 2. Finding HTML Elements by Tag Name
console.log("\n2. Finding HTML Elements by Tag Name:");
const elementsByTagName = document.getElementsByTagName("p");
console.log("All <p> elements:", elementsByTagName);
console.log("First <p> element:", elementsByTagName[0]);

// 3. Finding HTML Elements by Class Name
console.log("\n3. Finding HTML Elements by Class Name:");
const elementsByClassName = document.getElementsByClassName("highlight");
console.log("Elements with Class 'highlight':", elementsByClassName);

// 4. Finding HTML Elements by CSS Selectors
console.log("\n4. Finding HTML Elements by CSS Selectors:");
const firstElement = document.querySelector(".highlight"); // First element with the class
console.log("First .highlight element:", firstElement);

const allElements = document.querySelectorAll(".highlight"); // All elements with the class
console.log("All .highlight elements:", allElements);

// 5. Finding HTML Elements by HTML Object Collections
console.log("\n5. Finding HTML Elements by HTML Object Collections:");
const forms = document.forms; // All forms in the document
console.log("All <form> elements:", forms);

const specificForm = document.forms["searchForm"]; // A form with a specific name
console.log("Form with name 'searchForm':", specificForm);

const images = document.images; // All images in the document
console.log("All <img> elements:", images);

// Bonus: Traversing and Using the Found Elements
console.log("\nBonus: Traversing and Using the Found Elements:");
Array.from(elementsByClassName).forEach((element, index) => {
    console.log(`Element ${index + 1}:`, element);
    element.style.color = "blue"; // Change the style of the elements
});
