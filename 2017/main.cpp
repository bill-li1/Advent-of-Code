#include <iostream>
#include <algorithm>

using namespace std;

// Function to compute Manhattan distance
int manhattan_distance(int target) {
    if (target == 1) return 0; // The center of the spiral

    // Find the layer (n) in which the target number resides
    int layer = 0;
    while ((2 * layer + 1) * (2 * layer + 1) < target) {
        layer++;
    }

    // The maximum value at the current layer
    int max_value = (2 * layer + 1) * (2 * layer + 1);
    int side_length = 2 * layer;

    // Midpoints of each side
    int bottom_right = max_value;
    int bottom_left = bottom_right - side_length;
    int top_left = bottom_left - side_length;
    int top_right = top_left - side_length;

    int mid_bottom = bottom_right - layer;
    int mid_left = bottom_left - layer;
    int mid_top = top_left - layer;
    int mid_right = top_right - layer;

    // Find the closest midpoint
    int closest_midpoint = min({
        abs(target - mid_bottom),
        abs(target - mid_left),
        abs(target - mid_top),
        abs(target - mid_right)
    });

    // Manhattan Distance = Layer number + distance from closest midpoint
    return layer + closest_midpoint;
}

int main() {
    int target = 347991;
    cout << "Manhattan Distance for " << target << " is: " << manhattan_distance(target) << endl;
    return 0;
}