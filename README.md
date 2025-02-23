# Spherical Coordinates Point Class

## Project Description
This project implements a **Point class in spherical coordinates** that supports various arithmetic operations.  
The spherical coordinates system represents points using three parameters:
- **Radius (r)** – Distance from the origin.
- **Inclination (θ, theta)** – Angle from the positive z-axis.
- **Azimuth (φ, phi)** – Angle from the positive x-axis in the x-y plane.

### Key Features:
- **Basic Arithmetic Operations**:
  - Addition (`+`, `+=`) and subtraction (`-`, `-=`) of points.
  - Scalar multiplication (`*`, `*=`).
- **Conversion Methods**:
  - Convert between **spherical** and **Cartesian (x, y, z)** coordinates.
- **Distance Calculation**:
  - Compute the Euclidean distance between two points.
  
## Project Structure
- `PointLib/` – Source code files with implementation of point in spheriacal coordinates
- `PointUnitTest/` – Unit tests
- `README.md` – Project documentation

## Implementation Details
- **Encapsulation**: Proper use of `public` and `private` members.
- **Mathematical Validity**: Ensures angles remain within valid ranges (`0 ≤ θ ≤ π`, `0 ≤ φ < 2π`).
- **Stream Operators**: Supports `<<` and `>>` for outputting and inputing the point representation.
- **Unit Tests**: Verifies correctness of key functionalities.
