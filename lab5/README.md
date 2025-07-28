## 🚫 Outlier Detection Lab

This lab focuses on identifying and removing incorrect feature matches (outliers) that may arise due to noise, repeated patterns, or descriptor ambiguities. Removing outliers is essential for reliable geometric estimation in visual SLAM and structure-from-motion.

### 🧮 Algorithms Covered

- **RANSAC** (Random Sample Consensus)  
  Robust model fitting technique used to estimate transformations (e.g., homography, fundamental matrix) while discarding inconsistent matches.

- **LMedS** (Least Median of Squares)  
  A robust estimator that minimizes the median of squared residuals, offering an alternative to RANSAC for outlier rejection.

- **MSAC** (M-Estimator SAmple Consensus)  
  A variant of RANSAC that uses a soft cost function to penalize outliers less harshly, leading to better convergence in some cases.

- **LORANSAC** (Locally Optimized RANSAC)  
  Combines RANSAC with local optimization steps to refine inlier sets and improve model accuracy.

- **Distance Thresholding**  
  A simple but often effective method for filtering matches based on descriptor distance or geometric distance (e.g., epipolar constraint).

- **Symmetric Matching Check**  
  Retains only matches that are mutually consistent in both directions (A → B and B → A).

### 🎯 Objectives

- Implement outlier filtering techniques on matched feature sets.
- Understand the impact of outliers on geometric estimation.
- Compare the effectiveness of different robust estimation strategies.

---

📁 The lab includes interactive visualizations showing inliers vs. outliers, transformation estimation results, and filtering performance metrics.
