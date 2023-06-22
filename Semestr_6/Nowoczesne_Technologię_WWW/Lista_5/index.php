<?php include 'header.php'; ?>
<?php include 'menu.php'; ?>

<!-- Page-specific content goes here -->
<?php include 'visitCount.php'; ?>
<div class="page-content">
   <h1>About Me</h1>
   <p>
       Hello, my name is Igor Urbanowicz. I am a passionate student of algorithmic computer science.
   </p>
   <p>
       I have a strong interest in problem-solving and algorithm design. I enjoy exploring various data structures and algorithms to find efficient solutions to complex computational problems.
   </p>
   <p>
       My studies have provided me with a solid foundation in programming languages, data analysis, and software development. I am constantly seeking new challenges and opportunities to enhance my skills and knowledge in the field of computer science.
   </p>
   <p>
       Apart from my academic pursuits, I also enjoy participating in coding competitions and engaging in open-source projects. These experiences have allowed me to collaborate with other talented individuals and further refine my problem-solving abilities.
   </p>
   <p>
       I am excited about the endless possibilities that algorithmic computer science offers, and I am eager to contribute to the development of innovative solutions that can make a positive impact in the world.
   </p>
</div>

<h2>My Compiler</h2>
    <p>
        Our compiler is a powerful tool that transforms high-level programming code into executable machine code.
        It plays a crucial role in the software development process by translating human-readable instructions into a
        language that computers can understand and execute. With advanced optimization techniques, our compiler generates
        efficient and optimized code, resulting in faster and more reliable software. It supports various programming
        languages and provides comprehensive error checking and debugging capabilities, making it an indispensable tool
        for developers seeking to create robust and high-performance applications.
    </p>
    <h2>Tic-Tac-Toe</h2>
    <p>
        Tic-Tac-Toe, also known as noughts and crosses, is a classic paper-and-pencil game enjoyed by players of all ages.
        It involves two players taking turns to mark their chosen symbol, usually X or O, on a 3x3 grid. The objective is
        to create a straight line of three matching symbols horizontally, vertically, or diagonally. Despite its simple
        rules, Tic-Tac-Toe offers strategic gameplay that requires players to anticipate their opponent's moves and make
        strategic decisions. Our Tic-Tac-Toe game provides a user-friendly interface and engaging gameplay, allowing
        players to enjoy this timeless game either against an AI opponent or with a friend in a friendly competition.
    </p>
<?php
session_start(); // Start or resume the session

$inactiveTimeLimit = 5 * 60; // 5 minutes (in seconds)
if (isset($_SESSION['last_activity'])) {
    $elapsedTime = time() - $_SESSION['last_activity'];
    if ($elapsedTime > $inactiveTimeLimit) {
        session_destroy();
        exit;
        }
    }
$_SESSION['last_activity'] = time();

// Handle user registration form submission
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['register'])) {
    $username = $_POST['username'];
    $password = $_POST['password'];
    
    // Insert the new user into the database
    $query = "INSERT INTO users (username, password) VALUES ('$username', '$password')";
    $result = $conn->query($query);
    
    if ($result) {
        echo 'User registered successfully!';
    } else {
        echo 'User registration failed.';
    }
}

// Handle login form submission
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['login'])) {
    $username = $_POST['username'];
    $password = $_POST['password'];
    
    // Retrieve the user from the database
    $query = "SELECT * FROM users WHERE username = '$username' AND password = '$password'";
    $result = $conn->query($query);
    
    if ($result && $result->num_rows > 0) {
        // User is authenticated
        $user = $result->fetch_assoc();
        $_SESSION['username'] = $username; // Store the username in the session
        $_SESSION['user_id'] = $user['id']; // Store the user ID in the session
        echo 'Login successful!';
    } else {
        // Invalid username or password
        echo 'Invalid credentials.';
    }
}

// Handle comment form submission
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['submit_comment'])) {
    $userId = $_SESSION['user_id']; // Retrieve the logged-in user ID
    $projectId = $_POST['project_id'];
    $commentText = $_POST['comment'];
    
    // Insert the comment into the comments table
    $query = "INSERT INTO comments (project_id, user_id, comment) VALUES ('$projectId', '$userId', '$commentText')";
    $result = $conn->query($query);
    
    if ($result) {
        echo 'Comment submitted successfully!';
    } else {
        echo 'Failed to submit comment.';
    }
}

?>

<?php if (isset($_SESSION['username'])): ?>
    <p>Logged in as: <?php echo $_SESSION['username']; ?></p>
<?php endif; ?>

<form action="index.php" method="POST">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required>
  
  <label for="password">Password:</label>
  <input type="password" id="password" name="password" required>
  
  <input type="submit" name="register" value="Register">
</form>

<form action="index.php" method="POST">
  <label for="username">Username:</label>
  <input type="text" id="username" name="username" required>
  
  <label for="password">Password:</label>
  <input type="password" id="password" name="password" required>
  
  <input type="submit" name="login" value="Login">
</form>


<?php if (isset($_SESSION['username'])): ?>
    <form action="index.php" method="POST">
        <label for="project">Select Project:</label>
        <select name="project_id" id="project_id">
            <option value="1">Compiler</option>
            <option value="2">Tic-Tac-Toe</option>
        </select>
        <textarea name="comment" placeholder="Enter your comment" required></textarea>
        <input type="submit" name="submit_comment" value="Submit Comment">
    </form>
<?php endif; ?>

<?php
$projectId = 1; 
$query = "SELECT * FROM comments WHERE project_id = '$projectId'";
$result = $conn->query($query);

if ($result && $result->num_rows > 0) {
    echo '<h2>Comments for Compiler: </h2>';
    
    while ($row = $result->fetch_assoc()) {
        $commentText = $row['comment'];
        $commentUserId = $row['user_id']; // Get the user ID from the comments table
        $query = "SELECT username FROM users WHERE id = '$commentUserId'";
        $userResult = $conn->query($query);

        if ($userResult && $userResult->num_rows > 0) {
            $userRow = $userResult->fetch_assoc();
            $commentUser = $userRow['username']; // Retrieve the username
        } else {
            $commentUser = 'Unknown'; // Set a default value if the username is not found
        } 
        
        echo '<p>';
        echo 'User: ' . $commentUser . '<br>';
        echo 'Comment: ' . $commentText;
        echo '</p>';
    }
} else {
    echo 'No comments found.';
}
?>

<?php
$projectId = 2;
$query = "SELECT * FROM comments WHERE project_id = '$projectId'";
$result = $conn->query($query);

if ($result && $result->num_rows > 0) {
    echo '<h2>Comments for Tic-Tac-Toe:</h2>';
    
    while ($row = $result->fetch_assoc()) {
        $commentText = $row['comment'];
        $commentUserId = $row['user_id']; // Get the user ID from the comments table
        $query = "SELECT username FROM users WHERE id = '$commentUserId'";
        $userResult = $conn->query($query);

        if ($userResult && $userResult->num_rows > 0) {
            $userRow = $userResult->fetch_assoc();
            $commentUser = $userRow['username']; // Retrieve the username
        } else {
            $commentUser = 'Unknown'; // Set a default value if the username is not found
        } 
        
        echo '<p>';
        echo 'User: ' . $commentUser . '<br>';
        echo 'Comment: ' . $commentText;
        echo '</p>';
    }
} else {
    echo 'No comments found.';
}
?>

<?php include 'footer.php'; ?>
