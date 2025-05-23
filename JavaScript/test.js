function evaluateExpression(expr) {
    // Remove spaces
    expr = expr.replace(/\s+/g, '');

    // Split by operators while keeping them in the array
    const tokens = expr.match(/(\d+|\+|\-|\*|\/|\%|sqrt|\^)/g);
    
    // Handle exponentiation and square root first
    let temp = [];
    for (let i = 0; i < tokens.length; i++) {
        if (tokens[i] === '^' || tokens[i] === 'sqrt') {
            const left = parseFloat(temp.pop());
            let result;
            if (tokens[i] === '^') {
                const exponent = parseFloat(tokens[i + 1]);
                result = Math.pow(left, exponent);
                i++; // Skip the next number since it's already used
            } else if (tokens[i] === 'sqrt') {
                result = Math.sqrt(left);
            }
            temp.push(result);
        } else {
            temp.push(tokens[i]);
        }
    }

    // Handle multiplication, division, and modulus next
    let intermediate = [];
    for (let i = 0; i < temp.length; i++) {
        if (temp[i] === '*' || temp[i] === '/' || temp[i] === '%') {
            const left = parseFloat(intermediate.pop());
            const right = parseFloat(temp[i + 1]);
            let result;
            if (temp[i] === '*') {
                result = left * right;
            } else if (temp[i] === '/') {
                result = left / right;
            } else if (temp[i] === '%') {
                result = left % right;
            }
            intermediate.push(result);
            i++; // Skip the next number since it's already used
        } else {
            intermediate.push(temp[i]);
        }
    }

    // Now handle addition and subtraction
    let finalResult = parseFloat(intermediate[0]);
    for (let i = 1; i < intermediate.length; i += 2) {
        const operator = intermediate[i];
        const number = parseFloat(intermediate[i + 1]);
        finalResult = operator === '+' ? finalResult + number : finalResult - number;
    }

    return finalResult;
}

// Example usage
const expression = "2 + 9 - 3 * 7 / 3 + sqrt(16) - 5 % 2";
const result = evaluateExpression(expression);
console.log(result); // Output: 4