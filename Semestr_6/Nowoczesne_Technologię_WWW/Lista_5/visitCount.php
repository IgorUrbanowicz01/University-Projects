<?php
// Function to establish a database connection
function connectToDatabase() {
    $servername = 'localhost';
    $username = 'root';
    $password = 'igor01111';
    $dbname = 'lista5';
    
    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    
    // Check connection
    if ($conn->connect_error) {
        die('Connection failed: ' . $conn->connect_error);
    }
    
    return $conn;
}

// Function to check if the visit counter cookie is set
function isVisitCounterSet() {
    return isset($_COOKIE['visit_counter']);
}

// Function to set the visit counter cookie
function setVisitCounter() {
    // Set the cookie to expire in 24 hours
    $expiry = time() + (2);
    setcookie('visit_counter', 'visited', $expiry);
}

// Function to check if the visitor's IP has already visited today
function hasVisitedToday($conn) {
    // Retrieve the visitor's IP address
    $ip = $_SERVER['REMOTE_ADDR'];
    
    // Retrieve the current date in YYYY-MM-DD format
    $currentDate = date('Y-m-d');
    
    // Prepare and execute the SQL statement
    $stmt = $conn->prepare('SELECT * FROM visit_logs WHERE ip = ? AND visit_date = ?');
    $stmt->bind_param('ss', $ip, $currentDate);
    $stmt->execute();
    
    // Fetch the result
    $result = $stmt->get_result();
    
    // Check if the IP exists in the database for the current date
    if ($result->num_rows > 0) {
        return true; // IP has visited today
    }
    
    return false; // IP has not visited today
}

// Function to log the visitor's IP and visit date
function logVisit($conn) {
    // Retrieve the visitor's IP address
    $ip = $_SERVER['REMOTE_ADDR'];
    
    // Retrieve the current date in YYYY-MM-DD format
    $currentDate = date('Y-m-d');
    
    // Prepare and execute the SQL statement
    $stmt = $conn->prepare('INSERT INTO visit_logs (ip, visit_date) VALUES (?, ?)');
    $stmt->bind_param('ss', $ip, $currentDate);
    $stmt->execute();
}

// Function to increase the visit counter
function increaseCounter($conn) {
    $counterQuery = 'UPDATE visit_counter SET counter = counter + 1';
    $conn->query($counterQuery);
}

// Establish a database connection
$conn = connectToDatabase();

// Check if the visit counter cookie is already set
if (isVisitCounterSet()) {
    // Check if the visitor's IP has already visited today
    if (!hasVisitedToday($conn)) {
        // Increase the visit counter
        increaseCounter($conn);
        
        // Set the visit counter cookie and log the visit
        setVisitCounter();
        logVisit($conn);
    }
}

// Retrieve the visit counter value
$counterQuery = 'SELECT counter FROM visit_counter';
$result = $conn->query($counterQuery);

// Check for errors during the query execution
if (!$result) {
    die('Query error: ' . $conn->error);
}

// Check if any rows were fetched
if ($result->num_rows > 0) {
    $counter = $result->fetch_assoc()['counter'];
} else {
    $counter = 0; // Default counter value if no rows are fetched
}

?>

<!-- Rest of your HTML code -->

<p>Visit Counter: <?php echo $counter; ?></p>
