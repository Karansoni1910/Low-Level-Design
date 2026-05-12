// Separation of Concerns: Different classes handle different responsibilities

// Database Concern
class UserRepository {
    saveUser(user: User): void {
        const query = `INSERT INTO users VALUES ('${user.getName()}', '${user.getEmail()}')`;
        console.log("Database: Executing query - " + query);
    }
}

// Email Concern
class EmailService {
    sendWelcomeEmail(email: string): void {
        console.log("Email: Sending welcome email to " + email);
    }
}

// Logging Concern
class Logger {
    log(message: string): void {
        console.log(`[LOG] ${Date.now()} - ${message}`);
    }
}

// User Model
class User {
    private name: string;
    private email: string;

    constructor(name: string, email: string) {
        this.name = name;
        this.email = email;
    }

    getName(): string {
        return this.name;
    }

    getEmail(): string {
        return this.email;
    }
}

// Orchestrator (Coordinates all concerns)
class UserService {
    private repository: UserRepository;
    private emailService: EmailService;
    private logger: Logger;

    constructor(
        repository: UserRepository,
        emailService: EmailService,
        logger: Logger
    ) {
        this.repository = repository;
        this.emailService = emailService;
        this.logger = logger;
    }

    registerUser(name: string, email: string): void {
        this.logger.log(`Starting user registration for ${email}`);

        const user = new User(name, email);
        this.repository.saveUser(user);

        this.emailService.sendWelcomeEmail(email);

        this.logger.log(`User registration completed for ${email}`);
    }
}

// Usage
const repository = new UserRepository();
const emailService = new EmailService();
const logger = new Logger();

const userService = new UserService(repository, emailService, logger);

userService.registerUser("John Doe", "john@example.com");
