class PasswordValidator {
    public boolean isValid(String password) {
        // Your implementation here
        if(password == null || password.isEmpty()) return false;
        return password.length() < 8 ? false : true;
    }
}

public class Main {
    public static void main(String[] args) {
        PasswordValidator validator = new PasswordValidator();
        System.out.println(validator.isValid("short"));
        System.out.println(validator.isValid("longenough"));
        System.out.println(validator.isValid("12345678"));
        System.out.println(validator.isValid(""));
    }
}