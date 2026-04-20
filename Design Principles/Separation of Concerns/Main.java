// Separated Concerns Implementation

// Database Concern
class UserRepository {
    public void saveUser(User user) {
        String query = "INSERT INTO users VALUES ('" + user.getName() + "', '" + user.getEmail() + "')";
        System.out.println("Database: Executing query - " + query);
    }
}

// Email Concern
class EmailService {
    public void sendWelcomeEmail(String email) {
        System.out.println("Email: Sending welcome email to " + email);
    }
}

// Logging Concern
class Logger {
    public void log(String message) {
        System.out.println("[LOG] " + System.currentTimeMillis() + " - " + message);
    }
}

// User Model
class User {
    private String name;
    private String email;

    public User(String name, String email) {
        this.name = name;
        this.email = email;
    }

    public String getName() { return name; }
    public String getEmail() { return email; }
}

// Orchestrator (Coordinates all concerns)
class UserService {
    private UserRepository repository;
    private EmailService emailService;
    private Logger logger;

    public UserService(UserRepository repository, EmailService emailService, Logger logger) {
        this.repository = repository;
        this.emailService = emailService;
        this.logger = logger;
    }

    public void registerUser(String name, String email) {
        logger.log("Starting user registration for " + email);

        User user = new User(name, email);
        repository.saveUser(user);

        emailService.sendWelcomeEmail(email);

        logger.log("User registration completed for " + email);
    }
}

public class Main {
    public static void main(String[] args) {
        // Create concerns
        UserRepository repository = new UserRepository();
        EmailService emailService = new EmailService();
        Logger logger = new Logger();

        // Create orchestrator with injected concerns
        UserService userService = new UserService(repository, emailService, logger);

        // Register user
        userService.registerUser("John Doe", "john@example.com");
    }
}
