// YAGNI Principle: You Aren't Gonna Need It
// Only implement what is needed, not speculative features

class PasswordValidator {
    isValid(password: string): boolean {
        if (password === null || password === "") return false;
        return password.length >= 8;
    }
}

// Usage
const validator = new PasswordValidator();
console.log(validator.isValid("short"));        // false
console.log(validator.isValid("longenough"));   // true
console.log(validator.isValid("12345678"));     // true
console.log(validator.isValid(""));             // false
