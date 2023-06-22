<!DOCTYPE html>
<html>
<head>
  <title>My Portfolio</title>
  <!-- Include MathJax library -->
  <script async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/latest.js?config=TeX-MML-AM_CHTML" crossorigin="anonymous"></script>
</head>
<body>
  <h1>My Portfolio</h1>
  
  <h2>Interpolation using Lagrange Polynomials</h2>
  
  <p>
    Interpolation is a technique used to estimate the value of a function between known data points. One of the methods for interpolation is Lagrange interpolation, which allows us to construct a polynomial that passes through the given data points.
  </p>
  
  <p>
    Let's consider a set of t different points (x<sub>i</sub>, y<sub>i</sub>) for an unknown polynomial f of degree less than t. We can calculate the coefficients of the polynomial using the following formula:
  </p>
  
  <div>
    <p>
      \( f(x) = \sum_{i=1}^{t} \left( y_i \prod_{j \neq i}^{t} \frac{x - x_j}{x_i - x_j} \right) \mod p \)
    </p>
  </div>
  
  <!-- Rest of your portfolio content... -->
  
</body>
</html>
