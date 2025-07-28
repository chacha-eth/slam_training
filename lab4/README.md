## 🔗 Feature Matching Lab

This lab focuses on matching feature descriptors across image pairs. Feature matching is a core step in many computer vision and SLAM tasks, enabling correspondence estimation between frames for motion tracking and mapping.

### 🤝 Algorithms Covered

- **Brute-Force Matcher**  
  Compares every descriptor from one image with all descriptors from another. Works with both binary (e.g., ORB, BRIEF) and float (e.g., SIFT, SURF) descriptors.

- **FLANN** (Fast Library for Approximate Nearest Neighbors)  
  Efficient for large-scale and high-dimensional descriptors like SIFT and SURF.

- **BFMatcher with Cross-Check**  
  Ensures that matches are mutual (i.e., descriptor A matches B and vice versa) to improve robustness.

- **KNN Matching + Ratio Test (Lowe’s Ratio)**  
  Retrieves k-nearest matches (usually k=2) and filters good matches based on descriptor distance ratio to reduce false matches.

- **Others**  
  Advanced or custom matching strategies can be integrated depending on the use case.

### 🎯 Objectives

- Implement matching pipelines using different descriptors and matchers.
- Visualize and evaluate matching quality under different image transformations.
- Compare matcher performance in terms of speed, accuracy, and robustness.

---

📁 The lab includes matching visualizations, distance histograms, and accuracy evaluations to help understand the trade-offs between different approaches.
