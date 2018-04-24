
/**
 * https://en.wikipedia.org/wiki/Shoelace_formula
 */
double
polygon_area(double X[], double Y[], int n) {
    double area = 0.0;
 
    // Calculate value of shoelace formula
    int j = n - 1;
    
    for (int i = 0; i < n; i++) {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  // j is previous vertex to i
    }
 
    // Return absolute value
    return abs(area / 2.0);
}
